EESchema Schematic File Version 4
LIBS:MainPCB-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Power_Management:TPS22917DBV U4
U 1 1 5E605F7A
P 9350 1550
F 0 "U4" H 9350 1917 50  0000 C CNN
F 1 "TPS22919" H 9350 1826 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 9350 2050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps22917.pdf" H 9400 850 50  0001 C CNN
	1    9350 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR031
U 1 1 5E6074EA
P 9350 1900
F 0 "#PWR031" H 9350 1650 50  0001 C CNN
F 1 "GND" H 9355 1727 50  0000 C CNN
F 2 "" H 9350 1900 50  0001 C CNN
F 3 "" H 9350 1900 50  0001 C CNN
	1    9350 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 1900 9350 1850
$Comp
L Device:R R11
U 1 1 5E608101
P 10000 1650
F 0 "R11" H 10070 1696 50  0000 L CNN
F 1 "680" H 10070 1605 50  0000 L CNN
F 2 "" V 9930 1650 50  0001 C CNN
F 3 "~" H 10000 1650 50  0001 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 1450 10000 1450
Wire Wire Line
	10000 1450 10000 1500
Wire Wire Line
	10000 1800 10000 1850
Wire Wire Line
	10000 1850 9850 1850
Wire Wire Line
	9850 1850 9850 1550
Wire Wire Line
	9850 1550 9750 1550
$Comp
L power:+3.3V #PWR?
U 1 1 5E60BCC8
P 8450 1350
AR Path="/5E60BCC8" Ref="#PWR?"  Part="1" 
AR Path="/5E6059B5/5E60BCC8" Ref="#PWR029"  Part="1" 
F 0 "#PWR029" H 8450 1200 50  0001 C CNN
F 1 "+3.3V" H 8465 1523 50  0000 C CNN
F 2 "" H 8450 1350 50  0001 C CNN
F 3 "" H 8450 1350 50  0001 C CNN
	1    8450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1350 8450 1450
$Comp
L Device:CP C10
U 1 1 5E60C590
P 8450 1650
F 0 "C10" H 8568 1696 50  0000 L CNN
F 1 "1u" H 8568 1605 50  0000 L CNN
F 2 "" H 8488 1500 50  0001 C CNN
F 3 "~" H 8450 1650 50  0001 C CNN
	1    8450 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5E60D5F3
P 8450 1900
F 0 "#PWR030" H 8450 1650 50  0001 C CNN
F 1 "GND" H 8455 1727 50  0000 C CNN
F 2 "" H 8450 1900 50  0001 C CNN
F 3 "" H 8450 1900 50  0001 C CNN
	1    8450 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1900 8450 1800
Wire Wire Line
	8450 1500 8450 1450
Connection ~ 8450 1450
$Comp
L Device:CP C15
U 1 1 5E6BFE15
P 10400 1700
F 0 "C15" H 10518 1746 50  0000 L CNN
F 1 "10u" H 10518 1655 50  0000 L CNN
F 2 "" H 10438 1550 50  0001 C CNN
F 3 "~" H 10400 1700 50  0001 C CNN
	1    10400 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E6C0589
P 10400 1900
F 0 "#PWR0102" H 10400 1650 50  0001 C CNN
F 1 "GND" H 10405 1727 50  0000 C CNN
F 2 "" H 10400 1900 50  0001 C CNN
F 3 "" H 10400 1900 50  0001 C CNN
	1    10400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 1900 10400 1850
Wire Wire Line
	10000 1450 10400 1450
Wire Wire Line
	10400 1450 10400 1550
Connection ~ 10000 1450
Wire Wire Line
	8450 1450 8950 1450
NoConn ~ 8950 1550
$Comp
L RF_Module:ESP32-WROOM-32D U5
U 1 1 5E61BBD7
P 3000 4350
F 0 "U5" H 3100 5800 50  0000 C CNN
F 1 "ESP32-WROOM-32D" H 3400 5700 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 3000 2850 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf" H 2700 4400 50  0001 C CNN
	1    3000 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5E61C5A4
P 3000 5950
F 0 "#PWR0103" H 3000 5700 50  0001 C CNN
F 1 "GND" H 3005 5777 50  0000 C CNN
F 2 "" H 3000 5950 50  0001 C CNN
F 3 "" H 3000 5950 50  0001 C CNN
	1    3000 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0104
U 1 1 5E61CAEC
P 3000 2150
F 0 "#PWR0104" H 3000 2000 50  0001 C CNN
F 1 "+3.3V" H 3000 2300 50  0000 C CNN
F 2 "" H 3000 2150 50  0001 C CNN
F 3 "" H 3000 2150 50  0001 C CNN
	1    3000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5750 3000 5950
$Comp
L power:GND #PWR0105
U 1 1 5E61E5E4
P 3450 2400
F 0 "#PWR0105" H 3450 2150 50  0001 C CNN
F 1 "GND" V 3455 2272 50  0000 R CNN
F 2 "" H 3450 2400 50  0001 C CNN
F 3 "" H 3450 2400 50  0001 C CNN
	1    3450 2400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C14
U 1 1 5E61FDBD
P 3200 2550
F 0 "C14" V 3050 2550 50  0000 C CNN
F 1 "100nF" V 3350 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3238 2400 50  0001 C CNN
F 3 "~" H 3200 2550 50  0001 C CNN
	1    3200 2550
	0    -1   1    0   
$EndComp
Wire Wire Line
	3350 2250 3350 2400
Wire Wire Line
	3450 2400 3350 2400
Connection ~ 3350 2400
Wire Wire Line
	3350 2400 3350 2550
Wire Wire Line
	3000 2150 3000 2250
Wire Wire Line
	3050 2550 3000 2550
Connection ~ 3000 2550
Wire Wire Line
	3000 2550 3000 2950
Wire Wire Line
	3050 2250 3000 2250
Connection ~ 3000 2250
Wire Wire Line
	3000 2250 3000 2550
$Comp
L power:+3.3V #PWR0106
U 1 1 5E621E2A
P 2150 2550
F 0 "#PWR0106" H 2150 2400 50  0001 C CNN
F 1 "+3.3V" H 2165 2723 50  0000 C CNN
F 2 "" H 2150 2550 50  0001 C CNN
F 3 "" H 2150 2550 50  0001 C CNN
	1    2150 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5E622A83
P 1400 3150
F 0 "#PWR0107" H 1400 2900 50  0001 C CNN
F 1 "GND" V 1405 3022 50  0000 R CNN
F 2 "" H 1400 3150 50  0001 C CNN
F 3 "" H 1400 3150 50  0001 C CNN
	1    1400 3150
	0    1    1    0   
$EndComp
$Comp
L Device:C C12
U 1 1 5E623365
P 1900 3000
F 0 "C12" V 1648 3000 50  0000 C CNN
F 1 "100nF" V 1739 3000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1938 2850 50  0001 C CNN
F 3 "~" H 1900 3000 50  0001 C CNN
	1    1900 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 5E623E53
P 2150 2750
F 0 "R10" H 2220 2796 50  0000 L CNN
F 1 "10k" H 2220 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2080 2750 50  0001 C CNN
F 3 "~" H 2150 2750 50  0001 C CNN
	1    2150 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 EN
U 1 1 5E6246CF
P 1850 3250
F 0 "EN" H 1850 3000 50  0000 C CNN
F 1 "SW_DIP_x01" H 1850 3100 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_Push_1P1T_NO_6x6mm_H9.5mm" H 1850 3250 50  0001 C CNN
F 3 "~" H 1850 3250 50  0001 C CNN
	1    1850 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 BOOT
U 1 1 5E624DDA
P 4150 3150
F 0 "BOOT" H 4150 3417 50  0000 C CNN
F 1 "SW_DIP_x01" H 4150 3326 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_Push_1P1T_NO_6x6mm_H9.5mm" H 4150 3150 50  0001 C CNN
F 3 "~" H 4150 3150 50  0001 C CNN
	1    4150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 3150 2150 3150
Wire Wire Line
	2150 3150 2150 3250
Wire Wire Line
	2150 3150 2150 3000
Connection ~ 2150 3150
Wire Wire Line
	2050 3000 2150 3000
Connection ~ 2150 3000
Wire Wire Line
	2150 3000 2150 2900
Wire Wire Line
	1750 3000 1550 3000
Wire Wire Line
	1550 3000 1550 3150
Wire Wire Line
	1550 3150 1400 3150
Connection ~ 1550 3150
Wire Wire Line
	1550 3150 1550 3250
Wire Wire Line
	2150 2600 2150 2550
$Comp
L power:GND #PWR0108
U 1 1 5E6292E3
P 4500 3150
F 0 "#PWR0108" H 4500 2900 50  0001 C CNN
F 1 "GND" V 4505 3022 50  0000 R CNN
F 2 "" H 4500 3150 50  0001 C CNN
F 3 "" H 4500 3150 50  0001 C CNN
	1    4500 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 3150 4450 3150
Wire Wire Line
	3850 3150 3600 3150
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 5E62A9A4
P 4150 3500
F 0 "J3" H 4178 3526 50  0000 L CNN
F 1 "UART" H 4178 3435 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4150 3500 50  0001 C CNN
F 3 "~" H 4150 3500 50  0001 C CNN
	1    4150 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3250 3850 3250
Wire Wire Line
	3850 3250 3850 3400
Wire Wire Line
	3850 3400 3950 3400
Wire Wire Line
	3600 3450 3800 3450
Wire Wire Line
	3800 3450 3800 3500
Wire Wire Line
	3800 3500 3950 3500
$Comp
L power:GND #PWR0109
U 1 1 5E62D20E
P 3950 3600
F 0 "#PWR0109" H 3950 3350 50  0001 C CNN
F 1 "GND" H 3955 3427 50  0000 C CNN
F 2 "" H 3950 3600 50  0001 C CNN
F 3 "" H 3950 3600 50  0001 C CNN
	1    3950 3600
	1    0    0    -1  
$EndComp
Text GLabel 3800 4650 2    50   Input ~ 0
SCL
Text GLabel 3800 4550 2    50   Input ~ 0
SDA
Text GLabel 1350 4100 2    50   Input ~ 0
SDA
Text GLabel 1350 4200 2    50   Input ~ 0
SCL
Wire Wire Line
	3600 4550 3800 4550
Wire Wire Line
	3600 4650 3800 4650
$Comp
L power:+3.3V #PWR0110
U 1 1 5E637941
P 1500 4000
F 0 "#PWR0110" H 1500 3850 50  0001 C CNN
F 1 "+3.3V" V 1515 4128 50  0000 L CNN
F 2 "" H 1500 4000 50  0001 C CNN
F 3 "" H 1500 4000 50  0001 C CNN
	1    1500 4000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5E63843C
P 1500 4300
F 0 "#PWR0111" H 1500 4050 50  0001 C CNN
F 1 "GND" V 1505 4172 50  0000 R CNN
F 2 "" H 1500 4300 50  0001 C CNN
F 3 "" H 1500 4300 50  0001 C CNN
	1    1500 4300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 4000 1350 4000
Wire Wire Line
	1500 4300 1350 4300
Text GLabel 1350 4400 2    50   Input ~ 0
Int_AMG8833
Text GLabel 1350 4500 2    50   Input ~ 0
Int_CCSB11
Text GLabel 1350 4600 2    50   Input ~ 0
nWake
Text GLabel 1350 4700 2    50   Input ~ 0
AUX
Text GLabel 1350 4800 2    50   Input ~ 0
Detector_out
$Comp
L Connector:Conn_01x09_Female J2
U 1 1 5E62DF3B
P 1150 4400
F 0 "J2" H 1042 3775 50  0000 C CNN
F 1 "Conn_01x09_Female" H 1042 3866 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 1150 4400 50  0001 C CNN
F 3 "~" H 1150 4400 50  0001 C CNN
	1    1150 4400
	-1   0    0    1   
$EndComp
Text GLabel 3600 4950 2    50   Input ~ 0
Int_AMG8833
Text GLabel 3600 5050 2    50   Input ~ 0
Int_CCSB11
Text GLabel 3600 5150 2    50   Input ~ 0
nWake
Text GLabel 3600 5250 2    50   Input ~ 0
Detector_out
Text GLabel 3600 5350 2    50   Input ~ 0
AUX
$Comp
L Device:C C13
U 1 1 5E61F2EF
P 3200 2250
F 0 "C13" V 2948 2250 50  0000 C CNN
F 1 "10µF" V 3039 2250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3238 2100 50  0001 C CNN
F 3 "~" H 3200 2250 50  0001 C CNN
	1    3200 2250
	0    1    1    0   
$EndComp
$EndSCHEMATC
