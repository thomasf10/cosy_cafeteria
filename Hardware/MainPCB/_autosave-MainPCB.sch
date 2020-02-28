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
L Device:R R?
U 1 1 5E59146F
P 5150 3200
F 0 "R?" H 5220 3246 50  0000 L CNN
F 1 "R" H 5220 3155 50  0000 L CNN
F 2 "" V 5080 3200 50  0001 C CNN
F 3 "~" H 5150 3200 50  0001 C CNN
	1    5150 3200
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:BQ297xy U?
U 1 1 5E592112
P 6050 2950
F 0 "U?" H 6050 3317 50  0000 C CNN
F 1 "BQ297xy" H 6050 3226 50  0000 C CNN
F 2 "Package_SON:WSON-6_1.5x1.5mm_P0.5mm" H 6050 3300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/bq2970.pdf" H 5800 3150 50  0001 C CNN
	1    6050 2950
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:MCP73831-2-OT U?
U 1 1 5E5930ED
P 7200 3550
F 0 "U?" H 7200 4031 50  0000 C CNN
F 1 "MCP73831-2-OT" H 7200 3940 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 7250 3300 50  0001 L CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 7050 3500 50  0001 C CNN
	1    7200 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
