EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "3.5\" RetroPanel Module (RS-232)"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Handles the circuitry for connecting to the Arduino over RS-232."
$EndDescr
$Comp
L Interface_UART:MAX232 U1
U 1 1 635FEBCE
P 5450 4025
F 0 "U1" H 5450 4475 50  0000 C CNN
F 1 "MAX232" H 5450 4375 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 5500 2975 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/max232.pdf" H 5450 4125 50  0001 C CNN
	1    5450 4025
	-1   0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 635FEBD4
P 6900 3275
F 0 "C5" H 6992 3321 50  0000 L CNN
F 1 "100nF" H 6992 3230 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 6900 3275 50  0001 C CNN
F 3 "~" H 6900 3275 50  0001 C CNN
	1    6900 3275
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 635FEBDA
P 5450 5225
F 0 "#PWR0104" H 5450 4975 50  0001 C CNN
F 1 "GND" H 5455 5052 50  0000 C CNN
F 2 "" H 5450 5225 50  0001 C CNN
F 3 "" H 5450 5225 50  0001 C CNN
	1    5450 5225
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 635FEBE0
P 5450 2675
F 0 "#PWR0105" H 5450 2525 50  0001 C CNN
F 1 "+5V" H 5450 2815 50  0000 C CNN
F 2 "" H 5450 2675 50  0000 C CNN
F 3 "" H 5450 2675 50  0000 C CNN
	1    5450 2675
	1    0    0    -1  
$EndComp
Text GLabel 4575 4125 0    50   Output ~ 0
RS232_TX
Wire Wire Line
	4575 4125 4650 4125
Text GLabel 4575 4525 0    50   Input ~ 0
RS232_RX
Wire Wire Line
	4575 4525 4650 4525
Wire Wire Line
	4475 3125 4475 3175
Wire Wire Line
	4475 3375 4475 3425
Wire Wire Line
	4475 3425 4650 3425
Wire Wire Line
	4475 3125 4650 3125
Wire Wire Line
	4050 3375 4050 3625
Wire Wire Line
	4050 3625 4650 3625
$Comp
L power:+5V #PWR0112
U 1 1 635FEBFC
P 4050 3175
F 0 "#PWR0112" H 4050 3025 50  0001 C CNN
F 1 "+5V" H 4050 3315 50  0000 C CNN
F 2 "" H 4050 3175 50  0000 C CNN
F 3 "" H 4050 3175 50  0000 C CNN
	1    4050 3175
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C4
U 1 1 635FEC02
P 6425 3275
F 0 "C4" H 6517 3321 50  0000 L CNN
F 1 "1uF" H 6517 3230 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 6425 3275 50  0001 C CNN
F 3 "~" H 6425 3275 50  0001 C CNN
	1    6425 3275
	1    0    0    -1  
$EndComp
Wire Wire Line
	6425 3125 6425 3175
Wire Wire Line
	6425 3375 6425 3425
Wire Wire Line
	6425 3425 6250 3425
Wire Wire Line
	6425 3125 6250 3125
Wire Wire Line
	4050 3925 4650 3925
$Comp
L power:GND #PWR0113
U 1 1 635FEC14
P 4050 5225
F 0 "#PWR0113" H 4050 4975 50  0001 C CNN
F 1 "GND" H 4055 5052 50  0000 C CNN
F 2 "" H 4050 5225 50  0001 C CNN
F 3 "" H 4050 5225 50  0001 C CNN
	1    4050 5225
	1    0    0    -1  
$EndComp
NoConn ~ 4650 4325
NoConn ~ 4650 4725
NoConn ~ 6250 4325
NoConn ~ 6250 4725
Text GLabel 6325 4525 2    50   Output ~ 0
TTL_RX
Wire Wire Line
	6325 4525 6250 4525
Text GLabel 6325 4125 2    50   Input ~ 0
TTL_TX
Wire Wire Line
	6325 4125 6250 4125
Wire Wire Line
	5450 2675 5450 2750
Wire Wire Line
	5450 2750 6900 2750
Wire Wire Line
	6900 2750 6900 3175
$Comp
L power:GND #PWR0114
U 1 1 635FEC25
P 6900 3375
F 0 "#PWR0114" H 6900 3125 50  0001 C CNN
F 1 "GND" H 6905 3202 50  0000 C CNN
F 2 "" H 6900 3375 50  0001 C CNN
F 3 "" H 6900 3375 50  0001 C CNN
	1    6900 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2825 5450 2750
Connection ~ 5450 2750
$Comp
L rs232_conn:RS232 J11
U 1 1 635FEC2D
P 7925 4000
F 0 "J11" H 7975 4450 50  0000 C CNN
F 1 "RS-232" H 7975 4375 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x05_P2.54mm_Vertical" H 7925 4000 50  0001 C CNN
F 3 "~" H 7925 4000 50  0001 C CNN
	1    7925 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 635FEC33
P 7575 4300
F 0 "#PWR0117" H 7575 4050 50  0001 C CNN
F 1 "GND" H 7580 4127 50  0000 C CNN
F 2 "" H 7575 4300 50  0001 C CNN
F 3 "" H 7575 4300 50  0001 C CNN
	1    7575 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7575 4300 7575 4000
NoConn ~ 7725 4200
Wire Wire Line
	7725 3800 7650 3800
Wire Wire Line
	7650 3800 7650 3700
Wire Wire Line
	7650 3700 8300 3700
Wire Wire Line
	8300 3700 8300 3900
Wire Wire Line
	8300 3900 8225 3900
Wire Wire Line
	8300 3900 8300 4000
Wire Wire Line
	8300 4000 8225 4000
Connection ~ 8300 3900
Text GLabel 7650 3900 0    50   Output ~ 0
RS232_RX
Wire Wire Line
	7650 3900 7725 3900
Wire Wire Line
	7575 4000 7725 4000
Wire Wire Line
	7725 4100 7650 4100
Wire Wire Line
	7650 4100 7650 4300
Wire Wire Line
	7650 4300 8300 4300
Wire Wire Line
	8300 4300 8300 4100
Wire Wire Line
	8300 4100 8225 4100
Text GLabel 8375 3800 2    50   Input ~ 0
RS232_TX
Wire Wire Line
	8375 3800 8225 3800
$Comp
L Device:CP_Small C3
U 1 1 63604F05
P 4475 3275
F 0 "C3" H 4567 3321 50  0000 L CNN
F 1 "1uF" H 4567 3230 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 4475 3275 50  0001 C CNN
F 3 "~" H 4475 3275 50  0001 C CNN
	1    4475 3275
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C2
U 1 1 63605C30
P 4050 5050
F 0 "C2" H 4142 5096 50  0000 L CNN
F 1 "1uF" H 4142 5005 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 4050 5050 50  0001 C CNN
F 3 "~" H 4050 5050 50  0001 C CNN
	1    4050 5050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 5225 4050 5150
Wire Wire Line
	4050 3925 4050 4950
$Comp
L Device:CP_Small C1
U 1 1 6360D4AB
P 4050 3275
F 0 "C1" H 4142 3321 50  0000 L CNN
F 1 "1uF" H 4142 3230 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 4050 3275 50  0001 C CNN
F 3 "~" H 4050 3275 50  0001 C CNN
	1    4050 3275
	-1   0    0    1   
$EndComp
Text Notes 4475 5850 0    50   ~ 0
C1-C4 may be 100nF monolithic capacitors when\nused with MAX232A IC. When used with the common\ncheaper alternatives such as MAX232CPE, these need\nto be 1uF polarized electrolytic capacitors.
$EndSCHEMATC
