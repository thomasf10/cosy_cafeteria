import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib.ticker import ScalarFormatter # specifiek gebruikt in dit voorbeeld
import numpy as np
import math
import pandas as pd
import csv
from scipy import integrate

golden_mean = (math.sqrt(5)-1.0)/2.0
# adjust parameters to your liking
width = 5                       #inches
height = width * golden_mean    #inches
fontsize = 11                   #pt
axis_linewidth = 0.4            #pt

####### set parameters for latex #######
mpl.use("pgf")
mpl.rcParams.update({
        'backend': 'ps',
        'axes.labelsize': fontsize,
        'axes.titlesize': fontsize,
        'legend.fontsize': fontsize,
        'xtick.labelsize': fontsize,
        'ytick.labelsize': fontsize,
        'axes.linewidth' : axis_linewidth,
        'text.usetex': True,
        "pgf.rcfonts": False,
        "pgf.texsystem": "lualatex",
        #'font.family': 'serif',
        "pgf.preamble": [
            r"\usepackage[utf8x]{inputenc}",    # use utf8 fonts
            r"\usepackage[T1]{fontenc}",        # plots will be generated
            r"\usepackage[detect-all]{siunitx}" # to use si units
        ]
    })


x=[]
y=[]

#open csv file with the data
with open('data_1e_meting.csv', 'r') as csvfile:
    line_count = 0
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        if line_count < 1:  # lijn zonder data
            print('lijn zonder data')
            line_count += 1
        else:
            x.append(float(row[0]))
            y.append(float(row[1])*1000)

y_int = (integrate.cumtrapz(y, x, initial=0)/3600)
'''
#choose plotting type
plt.plot(x,y, label = 'mA') #normal plot
plt.plot(x, y_int, label = 'mAh')#integral plot
plt.legend(loc='upper left', frameon=False);#add legend'''
print(y_int[len(y_int)-1])

fig, ax1 = plt.subplots()

color = 'tab:blue'
ax1.set_xlabel('Tijd (s)')
ax1.set_ylabel('mA', color=color)
ax1.plot(x, y, color=color)
ax1.tick_params(axis='y', labelcolor=color)

ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

color = 'tab:red'
ax2.set_ylabel('mAh', color=color)  # we already handled the x-label with ax1
ax2.plot(x, y_int, color=color)
ax2.tick_params(axis='y', labelcolor=color)
#plt.hist(y,x, histtype='bar') #histogram
#plt.stem(x, y, markerfmt=" ", use_line_collection=True) #stem plot

#select range
#plt.axis([-1,2,0,300]) #enter range of the plot

#add labels/title
plt.title('Verbruik') # title
plt.xlabel('tijd [s]') # x axis
#plt.ylabel('Verbruik [mA]') # y axis

#save fig

plt.savefig('1e_meting2_int.pdf', bbox_inches='tight')
print("done")

