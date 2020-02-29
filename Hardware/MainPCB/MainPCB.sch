EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Battery_Management:BQ24075 U1
U 1 1 5E5A7039
P 5750 4250
F 0 "U1" H 5750 5031 50  0000 C CNN
F 1 "BQ24075" H 5750 4940 50  0000 C CNN
F 2 "Package_DFN_QFN:VQFN-16-1EP_3x3mm_P0.5mm_EP1.6x1.6mm" H 6000 3700 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/bq24075.pdf" H 5950 4450 50  0001 C CNN
	1    5750 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E5A99E6
P 7550 3950
F 0 "R1" H 7620 3996 50  0000 L CNN
F 1 "R" H 7620 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0612_1632Metric" V 7480 3950 50  0001 C CNN
F 3 "~" H 7550 3950 50  0001 C CNN
	1    7550 3950
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:BQ297xy U2
U 1 1 5E5AA681
P 6900 3050
F 0 "U2" H 6900 3417 50  0000 C CNN
F 1 "BQ29700" H 6900 3326 50  0000 C CNN
F 2 "Package_SON:WSON-6_1.5x1.5mm_P0.5mm" H 6900 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/bq2970.pdf" H 6650 3250 50  0001 C CNN
	1    6900 3050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:FDS9926A Q1
U 1 1 5E5AD09A
P 7900 3100
F 0 "Q1" H 8104 3146 50  0000 L CNN
F 1 "FDS9926A" H 8104 3055 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8100 3025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/FD/FDS9926A.pdf" H 7900 3100 50  0001 L CNN
	1    7900 3100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:FDS9926A Q1
U 2 1 5E5AEB96
P 8100 3700
F 0 "Q1" H 8304 3746 50  0000 L CNN
F 1 "FDS9926A" H 8304 3655 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8300 3625 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/FD/FDS9926A.pdf" H 8100 3700 50  0001 L CNN
	2    8100 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
