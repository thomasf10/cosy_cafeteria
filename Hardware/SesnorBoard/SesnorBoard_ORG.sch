EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 11988 8268
encoding utf-8
Sheet 1 1
Title "Sensor board"
Date "2020-02-14"
Rev "00"
Comp "Cossy Cafeteria"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 4200 1550 0    70   ~ 0
SDA
Wire Wire Line
	4100 1050 4100 950 
Text Label 4100 1050 0    10   ~ 0
3.3V
Wire Wire Line
	3900 1050 3900 950 
Text Label 3900 1050 0    10   ~ 0
3.3V
Wire Wire Line
	6250 1550 6350 1550
Wire Wire Line
	6250 1950 6450 1950
Wire Wire Line
	6450 1950 6750 1950
Wire Wire Line
	6750 1950 6750 2050
Wire Wire Line
	6750 1950 6750 1550
Wire Wire Line
	6450 2050 6450 1950
Connection ~ 6750 1950
Connection ~ 6450 1950
Text Label 4200 1650 0    70   ~ 0
SCL
Wire Wire Line
	4100 1750 4100 1450
Text Label 4200 1750 0    70   ~ 0
INT_AMG8833
Wire Wire Line
	3900 1850 3900 1450
Connection ~ 3900 1850
Wire Wire Line
	5050 1950 4950 1950
Wire Wire Line
	4950 1950 4950 2450
Text Label 5050 1950 0    10   ~ 0
GND
Wire Wire Line
	6750 2350 6750 2450
Text Label 6750 2350 0    10   ~ 0
GND
Wire Wire Line
	7050 2850 7050 2900
Text Label 7050 2850 0    10   ~ 0
GND
Wire Wire Line
	7350 2350 7350 2450
Text Label 7350 2350 0    10   ~ 0
GND
Wire Wire Line
	6450 2450 6450 2350
Text Label 6450 2450 0    10   ~ 0
GND
Wire Wire Line
	6250 1850 7050 1850
Wire Wire Line
	7050 1850 7050 2050
Wire Wire Line
	7050 2350 7050 2450
Wire Wire Line
	6250 1650 7350 1650
Wire Wire Line
	7350 1650 7350 2050
$Comp
L SesnorBoard-eagle-import:3.3V #U$03
U 1 1 6E1B97F5
P 4100 850
F 0 "#U$03" H 4100 850 50  0001 C CNN
F 1 "3.3V" H 4040 890 42  0000 L BNN
F 2 "" H 4100 850 50  0001 C CNN
F 3 "" H 4100 850 50  0001 C CNN
	1    4100 850 
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:3.3V #U$04
U 1 1 649D799B
P 3900 850
F 0 "#U$04" H 3900 850 50  0001 C CNN
F 1 "3.3V" H 3840 890 42  0000 L BNN
F 2 "" H 3900 850 50  0001 C CNN
F 3 "" H 3900 850 50  0001 C CNN
	1    3900 850 
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$05
U 1 1 BCE09641
P 3900 2550
F 0 "#U$05" H 3900 2550 50  0001 C CNN
F 1 "GND" H 3840 2450 42  0000 L BNN
F 2 "" H 3900 2550 50  0001 C CNN
F 3 "" H 3900 2550 50  0001 C CNN
	1    3900 2550
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$06
U 1 1 CE08125E
P 4950 2550
F 0 "#U$06" H 4950 2550 50  0001 C CNN
F 1 "GND" H 4890 2450 42  0000 L BNN
F 2 "" H 4950 2550 50  0001 C CNN
F 3 "" H 4950 2550 50  0001 C CNN
	1    4950 2550
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C1
U 1 1 E7D47EA7
P 6750 2250
F 0 "C1" V 6660 2299 50  0000 C CNN
F 1 "10uF" V 6840 2299 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6750 2250 50  0001 C CNN
F 3 "" H 6750 2250 50  0001 C CNN
	1    6750 2250
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C2
U 1 1 AC671DB5
P 7050 2250
F 0 "C2" V 6960 2299 50  0000 C CNN
F 1 "1uF" V 7140 2299 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7050 2250 50  0001 C CNN
F 3 "" H 7050 2250 50  0001 C CNN
	1    7050 2250
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C3
U 1 1 4017C25B
P 7350 2250
F 0 "C3" V 7260 2299 50  0000 C CNN
F 1 "2.2uF" V 7440 2299 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7350 2250 50  0001 C CNN
F 3 "" H 7350 2250 50  0001 C CNN
	1    7350 2250
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R2
U 1 1 5A764C0D
P 7050 2650
F 0 "R2" H 7050 2750 50  0000 C CNN
F 1 "22" H 7050 2650 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 7050 2650 50  0001 C CNN
F 3 "" H 7050 2650 50  0001 C CNN
	1    7050 2650
	0    -1   -1   0   
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$07
U 1 1 63C62AE7
P 7050 3000
F 0 "#U$07" H 7050 3000 50  0001 C CNN
F 1 "GND" H 6990 2900 42  0000 L BNN
F 2 "" H 7050 3000 50  0001 C CNN
F 3 "" H 7050 3000 50  0001 C CNN
	1    7050 3000
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$08
U 1 1 59F585D1
P 6750 2550
F 0 "#U$08" H 6750 2550 50  0001 C CNN
F 1 "GND" H 6690 2450 42  0000 L BNN
F 2 "" H 6750 2550 50  0001 C CNN
F 3 "" H 6750 2550 50  0001 C CNN
	1    6750 2550
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$09
U 1 1 9E0009A5
P 7350 2550
F 0 "#U$09" H 7350 2550 50  0001 C CNN
F 1 "GND" H 7290 2450 42  0000 L BNN
F 2 "" H 7350 2550 50  0001 C CNN
F 3 "" H 7350 2550 50  0001 C CNN
	1    7350 2550
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R1
U 1 1 DE04AF3C
P 4100 1250
F 0 "R1" H 4100 1350 50  0000 C CNN
F 1 "10K" H 4100 1250 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 4100 1250 50  0001 C CNN
F 3 "" H 4100 1250 50  0001 C CNN
	1    4100 1250
	0    -1   -1   0   
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R5
U 1 1 40871C63
P 3900 1250
F 0 "R5" H 3900 1350 50  0000 C CNN
F 1 "10K" H 3900 1250 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 3900 1250 50  0001 C CNN
F 3 "" H 3900 1250 50  0001 C CNN
	1    3900 1250
	0    -1   -1   0   
$EndComp
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C6
U 1 1 8451312A
P 6450 2250
F 0 "C6" V 6360 2299 50  0000 C CNN
F 1 "0.1uF" V 6540 2299 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6450 2250 50  0001 C CNN
F 3 "" H 6450 2250 50  0001 C CNN
	1    6450 2250
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U$026
U 1 1 61545C92
P 6450 2550
F 0 "#U$026" H 6450 2550 50  0001 C CNN
F 1 "GND" H 6390 2450 42  0000 L BNN
F 2 "" H 6450 2550 50  0001 C CNN
F 3 "" H 6450 2550 50  0001 C CNN
	1    6450 2550
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Gas:CCS811 U2
U 1 1 5E59C18B
P 8150 4800
F 0 "U2" H 7400 4300 50  0000 C CNN
F 1 "CCS811" H 7500 4200 50  0000 C CNN
F 2 "Package_LGA:AMS_LGA-10-1EP_2.7x4mm_P0.6mm" H 8150 4200 50  0001 C CNN
F 3 "http://ams.com/eng/Products/Environmental-Sensors/Air-Quality-Sensors/CCS811" H 8150 4600 50  0001 C CNN
	1    8150 4800
	1    0    0    -1  
$EndComp
Text Label 7250 4700 0    50   ~ 0
SDA
Text Label 7250 4800 0    50   ~ 0
SCL
$Comp
L SesnorBoard-eagle-import:GND #0101
U 1 1 5E5BAE95
P 8150 5600
F 0 "#0101" H 8200 5650 50  0001 C CNN
F 1 "GND" H 8100 5550 42  0000 L CNN
F 2 "" H 8150 5600 50  0001 C CNN
F 3 "" H 8150 5600 50  0001 C CNN
	1    8150 5600
	1    0    0    -1  
$EndComp
Text Label 7250 4600 0    50   ~ 0
nINT
Wire Wire Line
	7250 4700 7750 4700
Wire Wire Line
	7250 4800 7750 4800
Wire Wire Line
	3900 1850 3900 2450
Wire Wire Line
	4200 1550 4550 1550
Wire Wire Line
	4200 1650 4750 1650
Wire Wire Line
	4100 1750 5050 1750
Wire Wire Line
	3900 1850 5050 1850
Wire Wire Line
	9100 5200 9400 5200
$Comp
L SesnorBoard-eagle-import:GND #0102
U 1 1 5E5F4D6B
P 9600 5500
F 0 "#0102" H 9650 5550 50  0001 C CNN
F 1 "GND" H 9550 5450 42  0000 L CNN
F 2 "" H 9600 5500 50  0001 C CNN
F 3 "" H 9600 5500 50  0001 C CNN
	1    9600 5500
	1    0    0    -1  
$EndComp
Text Label 10500 5200 2    50   ~ 0
nINT_CCS811
$Comp
L 74xGxx:NC7SVU04P5X U3
U 1 1 5E5F224B
P 9600 5200
F 0 "U3" H 9800 5100 50  0000 L CNN
F 1 "NC7SVU04P5X" H 9800 5000 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 9600 4950 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NC7SVU04-D.pdf" H 9600 5200 50  0001 C CNN
	1    9600 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 5200 9950 5200
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R16
U 1 1 5E628D64
P 9950 4950
F 0 "R16" H 9950 5050 50  0000 C CNN
F 1 "10K" H 9950 4950 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 9950 4950 50  0001 C CNN
F 3 "" H 9950 4950 50  0001 C CNN
	1    9950 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9950 5150 9950 5200
Connection ~ 9950 5200
Wire Wire Line
	9950 4750 9600 4750
Wire Wire Line
	9600 4750 9600 5000
Connection ~ 9600 4750
Wire Wire Line
	6950 4900 6950 5000
Text Label 6500 5100 0    50   ~ 0
nWAKE
Wire Wire Line
	6500 5100 6950 5100
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R11
U 1 1 5E639501
P 7450 5000
F 0 "R11" H 7450 5100 50  0000 C CNN
F 1 "4k7" H 7450 5000 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 7450 5000 50  0001 C CNN
F 3 "" H 7450 5000 50  0001 C CNN
	1    7450 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5000 7750 5000
Wire Wire Line
	6950 5000 7250 5000
Wire Wire Line
	9950 5200 10500 5200
Text Notes 7350 5550 0    50   ~ 0
I²C-address 0x5B
Text Notes 5150 2450 0    50   ~ 0
I²C- address 0x69
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R13
U 1 1 5E65E6DF
P 7750 4200
F 0 "R13" H 7750 4300 50  0000 C CNN
F 1 "100K" H 7750 4200 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 7750 4200 50  0001 C CNN
F 3 "" H 7750 4200 50  0001 C CNN
	1    7750 4200
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R14
U 1 1 5E6606AE
P 7200 4200
F 0 "R14" H 7200 4300 50  0000 C CNN
F 1 "100k" H 7200 4200 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 7200 4200 50  0001 C CNN
F 3 "" H 7200 4200 50  0001 C CNN
	1    7200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4200 7500 4200
$Comp
L SesnorBoard-eagle-import:GND #0103
U 1 1 5E664638
P 6950 4350
F 0 "#0103" H 7000 4400 50  0001 C CNN
F 1 "GND" H 6900 4300 42  0000 L CNN
F 2 "" H 6950 4350 50  0001 C CNN
F 3 "" H 6950 4350 50  0001 C CNN
	1    6950 4350
	1    0    0    -1  
$EndComp
Connection ~ 7500 4200
Wire Wire Line
	7500 4200 7550 4200
Wire Wire Line
	7500 4500 7750 4500
Wire Wire Line
	6950 4250 6950 4200
Wire Wire Line
	6950 4200 7000 4200
Wire Wire Line
	7500 4500 7500 4200
Wire Wire Line
	7250 4600 7750 4600
Wire Wire Line
	8150 4200 7950 4200
Connection ~ 8150 4200
Wire Wire Line
	8150 4200 8150 4300
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R15
U 1 1 5E581DA6
P 6950 5400
F 0 "R15" H 6950 5500 50  0000 C CNN
F 1 "10k" H 6950 5400 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 6950 5400 50  0001 C CNN
F 3 "" H 6950 5400 50  0001 C CNN
	1    6950 5400
	0    1    1    0   
$EndComp
$Comp
L SesnorBoard-eagle-import:GND #U0101
U 1 1 5E58240A
P 6950 5850
F 0 "#U0101" H 7000 5900 50  0001 C CNN
F 1 "GND" H 6900 5800 42  0000 L CNN
F 2 "" H 6950 5850 50  0001 C CNN
F 3 "" H 6950 5850 50  0001 C CNN
	1    6950 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 5750 6950 5600
Wire Wire Line
	6950 5200 6950 5100
Text Label 9100 5200 0    50   ~ 0
nINT
$Comp
L Device:Thermistor_NTC TH1
U 1 1 5E5AB03A
P 8850 4600
F 0 "TH1" H 8948 4646 50  0000 L CNN
F 1 "100K" H 8948 4555 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 8850 4650 50  0001 C CNN
F 3 "~" H 8850 4650 50  0001 C CNN
	1    8850 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7750 5100 6950 5100
Connection ~ 6950 5100
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5E5FBFAE
P 2300 4300
F 0 "J2" H 2300 4050 50  0000 C CNN
F 1 "microphoon connection" H 2300 4600 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 2300 4300 50  0001 C CNN
F 3 "~" H 2300 4300 50  0001 C CNN
	1    2300 4300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3300 4200 2500 4200
$Comp
L SesnorBoard-eagle-import:GND #U$0102
U 1 1 5E5FFBAE
P 3300 4400
F 0 "#U$0102" H 3300 4400 50  0001 C CNN
F 1 "GND" H 3240 4300 42  0000 L BNN
F 2 "" H 3300 4400 50  0001 C CNN
F 3 "" H 3300 4400 50  0001 C CNN
	1    3300 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4300 2500 4300
Text Label 3050 4400 2    50   ~ 0
AUDIO_OUT
Wire Wire Line
	3050 4400 2500 4400
$Comp
L Diode:PMEG4050EP D1
U 1 1 5E607A7B
P 3200 5000
F 0 "D1" H 3200 4784 50  0000 C CNN
F 1 "RB081LAM-20" H 3200 4875 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-128" H 3200 4825 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMEG4050EP.pdf" H 3200 5000 50  0001 C CNN
	1    3200 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 5000 3450 5000
Wire Wire Line
	3450 5000 3650 5000
Connection ~ 3450 5000
Wire Wire Line
	3450 5500 3650 5500
$Comp
L SesnorBoard-eagle-import:GND #U$0103
U 1 1 5E61156D
P 3450 5650
F 0 "#U$0103" H 3450 5650 50  0001 C CNN
F 1 "GND" H 3390 5550 42  0000 L BNN
F 2 "" H 3450 5650 50  0001 C CNN
F 3 "" H 3450 5650 50  0001 C CNN
	1    3450 5650
	1    0    0    -1  
$EndComp
Connection ~ 3450 5500
Text Label 2500 5000 0    50   ~ 0
AUDIO_OUT
Text Label 4300 5000 2    50   ~ 0
DETECTOR_OUT
Wire Wire Line
	4300 5000 3650 5000
Wire Wire Line
	3050 5000 2500 5000
Connection ~ 3650 5000
Wire Wire Line
	8150 5300 8150 5500
Wire Wire Line
	8550 4700 8650 4700
Wire Wire Line
	8650 4700 8650 4600
Wire Wire Line
	8650 4600 8550 4600
Wire Wire Line
	8700 4600 8650 4600
Connection ~ 8650 4600
Wire Wire Line
	9150 4600 9150 4900
Wire Wire Line
	9150 4900 8550 4900
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C21
U 1 1 5E60868F
P 3450 5300
F 0 "C21" V 3360 5349 50  0000 C CNN
F 1 "0.1uF" V 3540 5349 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3450 5300 50  0001 C CNN
F 3 "" H 3450 5300 50  0001 C CNN
	1    3450 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 5000 3450 5100
Text Notes 2850 5450 0    50   ~ 0
Tau = 10 ms
Wire Notes Line
	4550 6050 4550 3700
Wire Notes Line
	4550 3700 1850 3700
Wire Notes Line
	5450 3900 5450 6100
Wire Notes Line
	5450 6100 10650 6100
Wire Notes Line
	10650 6100 10650 3900
Wire Notes Line
	10650 3850 5450 3850
Wire Notes Line
	7750 3150 3400 3150
Wire Notes Line
	3400 3150 3400 650 
Wire Notes Line
	3400 650  7750 650 
Wire Notes Line
	7750 650  7750 3150
Text Notes 7100 3300 0    50   ~ 0
IR-sensor cricuit
Text Notes 10000 6300 0    50   ~ 0
CCS-811 circuit
Text Notes 4000 6200 0    50   ~ 0
Audio detector
$Comp
L SesnorBoard-eagle-import:CAP_CERAMIC_1206 C11
U 1 1 5E64425F
P 5700 4350
F 0 "C11" V 5610 4399 50  0000 C CNN
F 1 "4.7µF" V 5790 4399 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5700 4350 50  0001 C CNN
F 3 "" H 5700 4350 50  0001 C CNN
	1    5700 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4600 9000 4600
Wire Wire Line
	8600 4200 8150 4200
Wire Wire Line
	9150 4200 9150 4600
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R12
U 1 1 5E62DEF9
P 8800 4200
F 0 "R12" H 8800 4300 50  0000 C CNN
F 1 "100k" H 8800 4200 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 8800 4200 50  0001 C CNN
F 3 "" H 8800 4200 50  0001 C CNN
	1    8800 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	9150 4200 9000 4200
$Comp
L SesnorBoard-eagle-import:GND #0104
U 1 1 5E65802F
P 5700 4650
F 0 "#0104" H 5750 4700 50  0001 C CNN
F 1 "GND" H 5650 4600 42  0000 L CNN
F 2 "" H 5700 4650 50  0001 C CNN
F 3 "" H 5700 4650 50  0001 C CNN
	1    5700 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4550 5700 4450
Connection ~ 9150 4600
Text Notes 5800 4600 0    30   ~ 0
Place C11 as close as possible \nto the supply pin VDD (6)
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R21
U 1 1 5E6052B8
P 3650 5250
F 0 "R21" H 3650 5350 50  0000 C CNN
F 1 "100k" H 3650 5250 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 3650 5250 50  0001 C CNN
F 3 "" H 3650 5250 50  0001 C CNN
	1    3650 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 5000 3650 5050
Wire Wire Line
	3450 5550 3450 5500
Wire Wire Line
	3650 5450 3650 5500
Wire Wire Line
	3450 5400 3450 5500
Wire Notes Line
	1850 3700 1850 6050
Wire Notes Line
	1850 6050 4550 6050
$Comp
L SesnorBoard-eagle-import:AMG8833 U1
U 1 1 6A1E14AE
P 5650 1750
F 0 "U1" H 5150 2300 59  0000 L BNN
F 1 "AMG8833" H 5150 1150 59  0000 L BNN
F 2 "AMG8833_REV-B:AMG8833" H 5650 1750 50  0001 C CNN
F 3 "" H 5650 1750 50  0001 C CNN
	1    5650 1750
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:3.3V #U$0104
U 1 1 5E69F37D
P 4550 850
F 0 "#U$0104" H 4550 850 50  0001 C CNN
F 1 "3.3V" H 4490 890 42  0000 L BNN
F 2 "" H 4550 850 50  0001 C CNN
F 3 "" H 4550 850 50  0001 C CNN
	1    4550 850 
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:3.3V #U$0105
U 1 1 5E69F6DA
P 4750 850
F 0 "#U$0105" H 4750 850 50  0001 C CNN
F 1 "3.3V" H 4690 890 42  0000 L BNN
F 2 "" H 4750 850 50  0001 C CNN
F 3 "" H 4750 850 50  0001 C CNN
	1    4750 850 
	1    0    0    -1  
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R3
U 1 1 5E69F7FF
P 4550 1250
F 0 "R3" H 4550 1350 50  0000 C CNN
F 1 "2k2" H 4550 1250 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 4550 1250 50  0001 C CNN
F 3 "" H 4550 1250 50  0001 C CNN
	1    4550 1250
	0    -1   -1   0   
$EndComp
$Comp
L SesnorBoard-eagle-import:RESISTOR_1206 R4
U 1 1 5E69FBAF
P 4750 1250
F 0 "R4" H 4750 1350 50  0000 C CNN
F 1 "2k2" H 4750 1250 40  0000 C CNB
F 2 "Resistor_SMD:R_1206_3216Metric" H 4750 1250 50  0001 C CNN
F 3 "" H 4750 1250 50  0001 C CNN
	1    4750 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4550 950  4550 1050
Wire Wire Line
	4750 950  4750 1050
Wire Wire Line
	4750 1450 4750 1650
Connection ~ 4750 1650
Wire Wire Line
	4750 1650 5050 1650
Wire Wire Line
	4550 1450 4550 1550
Connection ~ 4550 1550
Wire Wire Line
	4550 1550 5050 1550
Wire Wire Line
	5700 4050 5700 4150
$Comp
L SesnorBoard-eagle-import:3.3V #U$0108
U 1 1 5E7314BB
P 6950 4800
F 0 "#U$0108" H 6950 4800 50  0001 C CNN
F 1 "3.3V" H 6890 4840 42  0000 L BNN
F 2 "" H 6950 4800 50  0001 C CNN
F 3 "" H 6950 4800 50  0001 C CNN
	1    6950 4800
	1    0    0    -1  
$EndComp
Text Label 3300 4200 2    50   ~ 0
AUDIO_3V3
Text Label 2250 2150 2    50   ~ 0
CCS811_3V3
Wire Wire Line
	2250 2150 1450 2150
$Comp
L Connector_Generic:Conn_01x11 J1
U 1 1 5E5DEA34
P 1250 2650
F 0 "J1" H 1250 2000 50  0000 C CNN
F 1 "Mainboard connection" H 1250 3300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x11_P2.54mm_Vertical" H 1250 2650 50  0001 C CNN
F 3 "~" H 1250 2650 50  0001 C CNN
	1    1250 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 2250 2250 2250
Wire Wire Line
	1450 2350 2250 2350
Wire Wire Line
	2250 2450 1450 2450
Wire Wire Line
	1450 2550 2400 2550
Wire Wire Line
	2250 2650 1450 2650
Wire Wire Line
	2250 2750 1450 2750
Wire Wire Line
	2250 2850 1450 2850
Text Label 2250 2850 2    50   ~ 0
DETECTOR_OUT
Text Label 2250 2750 2    50   ~ 0
nWAKE
Text Label 2250 2650 2    50   ~ 0
nINT_CCS811
Text Label 2250 2450 2    50   ~ 0
INT_AMG8833
$Comp
L SesnorBoard-eagle-import:GND #U$015
U 1 1 0C3EC839
P 2400 2650
F 0 "#U$015" H 2400 2650 50  0001 C CNN
F 1 "GND" H 2340 2550 42  0000 L BNN
F 2 "" H 2400 2650 50  0001 C CNN
F 3 "" H 2400 2650 50  0001 C CNN
	1    2400 2650
	1    0    0    -1  
$EndComp
Text Label 2250 2350 2    70   ~ 0
SCL
Text Label 2250 2250 2    70   ~ 0
SDA
$Comp
L SesnorBoard-eagle-import:3.3V #U$0101
U 1 1 5E691E29
P 2400 2850
F 0 "#U$0101" H 2400 2850 50  0001 C CNN
F 1 "3.3V" H 2340 2890 42  0000 L BNN
F 2 "" H 2400 2850 50  0001 C CNN
F 3 "" H 2400 2850 50  0001 C CNN
	1    2400 2850
	1    0    0    -1  
$EndComp
Text Label 6350 800  3    50   ~ 0
AMG8833_3V3
Wire Wire Line
	6750 1550 6350 1550
Wire Wire Line
	6350 800  6350 1550
Connection ~ 6350 1550
Text Label 8150 4050 0    50   ~ 0
CCS811_3V3
Wire Wire Line
	8150 4050 8150 4200
Text Label 9600 4150 3    50   ~ 0
CCS811_3V3
Wire Wire Line
	9600 4150 9600 4750
Text Label 5700 4050 0    50   ~ 0
CCS811_3V3
Text Label 2250 3050 2    50   ~ 0
AUDIO_3V3
Wire Wire Line
	2250 3150 1450 3150
Text Label 2250 3150 2    50   ~ 0
AMG8833_3V3
Wire Wire Line
	2250 3050 1450 3050
Wire Wire Line
	1450 2950 2400 2950
$EndSCHEMATC
