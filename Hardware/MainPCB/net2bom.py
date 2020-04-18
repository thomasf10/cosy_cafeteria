# encoding:utf-8
#
# improved BOM for kicad
# liubenyuan <byliu@fmmu.edu.cn>

from __future__ import absolute_import, division, with_statement, print_function
import xlsxwriter
import os
import sys
from time import sleep

try:
    netlist = sys.argv[1]
except IndexError:
    for item in os.listdir(os.curdir):
        if item.endswith('.net'):
            netlist = os.path.join(os.curdir, item)
            print(netlist)
bom_file = 'bom.xls'

# Important: personal fields
# All you need to edit is enable these fields in KiCAD
fields = ['Rating', 'PartNumber', 'Description']

component_dict = dict()
try:
    with open(netlist, 'rU') as fp:
        for line in fp:
            line = line.strip()
            # comp name should not have white spaces
            if line.startswith('(comp '):
                ref = ''.join(list(line.split(' ')[-1])[:-1])
                component_dict[ref] = dict()
                component_dict[ref]['reference'] = ref
                # init field with default values
                for f in fields:
                    component_dict[ref][f] = ''
            # valus should not have white spaces
            if line.startswith('(value '):
                value = ''.join(list(line.split(' ')[-1])[:-1])
                component_dict[ref]['value'] = value
            # footprint names should not have white spaces
            if line.startswith('(footprint '):
                footprint = ''.join(list(line.split(' ')[-1])[:-1]).split(':')[-1]
                component_dict[ref]['footprint'] = footprint
            #
            # Personal fields is optional
            for f in fields:
                glob = '(field (name {})'.format(f)
                glob_sep = '{})'.format(f)
                if line.startswith(glob):
                    # chop first white space and trailing ')'
                    rt = ''.join(list(line.split(glob_sep)[-1])[1:-1])
                    while rt[-1] is ')':
                        rt = rt[:-1]
                    rt = rt.strip('"')
                    component_dict[ref][f] = rt
            # end of a component
            if line.startswith('(tstamp '):
                pass
except NameError:
    print('Net List Not Found! Exiting...')
    sleep(1)
    quit()

bom_dict = dict()
for ref, params in component_dict.items():
    index_str = params['value'] + params['footprint'] + params['Rating']
    bom_dict.setdefault(index_str, {})
    bom_dict[index_str].setdefault('reference', []).append(params['reference'])
    bom_dict[index_str].setdefault('value', set()).add(params['value'])
    bom_dict[index_str].setdefault('footprint', set()).add(params['footprint'])
    # personal fields
    for f in fields:
        bom_dict[index_str].setdefault(f, set()).add(params[f])

workbook = xlsxwriter.Workbook(bom_file)
sheet = workbook.add_worksheet('BOM')

# write header
default_header = ['Index', 'Reference', 'Value', 'Footprint', 'Count']
header = default_header + fields
for index, tab in enumerate(header):
    sheet.write(0, index, tab)

# write data
row = 1
for index_col, params in bom_dict.items():
    sheet.write(row, 0, row)
    sheet.write(row, 1, ','.join(params['reference']))
    sheet.write(row, 2, ','.join(params['value']))
    sheet.write(row, 3, ','.join(params['footprint']))
    sheet.write(row, 4, len(params['reference']))
    # remove '' from personal fields
    for i, f in enumerate(fields):
        params[f].discard('')
        sheet.write(row, 5+i, ','.join(params[f]))
    row += 1

workbook.close()
