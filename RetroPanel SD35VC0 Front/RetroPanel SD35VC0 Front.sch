EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RetroPanel SD35VC0 (Front)"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "3.5\" RetroPanel, Front panel when used with SD35VC0"
$EndDescr
$Comp
L mounting:Mounting_Pin M1
U 1 1 6282631C
P 10725 575
F 0 "M1" H 10725 675 50  0001 C CNN
F 1 "Mounting_Pin" H 10725 500 50  0001 C CNN
F 2 "mounting:M3_pin" H 10725 575 50  0001 C CNN
F 3 "~" H 10725 575 50  0001 C CNN
	1    10725 575 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pin M2
U 1 1 62826824
P 10850 575
F 0 "M2" H 10850 675 50  0001 C CNN
F 1 "Mounting_Pin" H 10850 500 50  0001 C CNN
F 2 "mounting:M3_pin" H 10850 575 50  0001 C CNN
F 3 "~" H 10850 575 50  0001 C CNN
	1    10850 575 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pin M3
U 1 1 62826D8F
P 10975 575
F 0 "M3" H 10975 675 50  0001 C CNN
F 1 "Mounting_Pin" H 10975 500 50  0001 C CNN
F 2 "mounting:M3_pin" H 10975 575 50  0001 C CNN
F 3 "~" H 10975 575 50  0001 C CNN
	1    10975 575 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pin M4
U 1 1 62827110
P 11100 575
F 0 "M4" H 11100 675 50  0001 C CNN
F 1 "Mounting_Pin" H 11100 500 50  0001 C CNN
F 2 "mounting:M3_pin" H 11100 575 50  0001 C CNN
F 3 "~" H 11100 575 50  0001 C CNN
	1    11100 575 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 6282AADA
P 11100 1250
F 0 "#PWR0111" H 11100 1000 50  0001 C CNN
F 1 "GND" H 11105 1077 50  0000 C CNN
F 2 "" H 11100 1250 50  0001 C CNN
F 3 "" H 11100 1250 50  0001 C CNN
	1    11100 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10725 725  10725 800 
Wire Wire Line
	10725 800  10850 800 
Wire Wire Line
	11100 800  11100 725 
Wire Wire Line
	10850 725  10850 800 
Connection ~ 10850 800 
Wire Wire Line
	10850 800  10975 800 
Wire Wire Line
	10975 725  10975 800 
Connection ~ 10975 800 
Wire Wire Line
	10975 800  11100 800 
Connection ~ 11100 800 
$Comp
L Switch:SW_DPDT_x2 SW1
U 1 1 62E3B89C
P 6125 3850
F 0 "SW1" H 6125 4135 50  0000 C CNN
F 1 "TURBO" H 6125 4044 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 6125 3850 50  0001 C CNN
F 3 "~" H 6125 3850 50  0001 C CNN
	1    6125 3850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW1
U 2 1 62E3C504
P 6125 4500
F 0 "SW1" H 6125 4785 50  0000 C CNN
F 1 "TURBO" H 6125 4694 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 6125 4500 50  0001 C CNN
F 3 "~" H 6125 4500 50  0001 C CNN
	2    6125 4500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 1 1 62E3F52F
P 3625 3850
F 0 "SW2" H 3625 4135 50  0000 C CNN
F 1 "POWER" H 3625 4044 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 3625 3850 50  0001 C CNN
F 3 "~" H 3625 3850 50  0001 C CNN
	1    3625 3850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 2 1 62E3FA35
P 3625 4500
F 0 "SW2" H 3625 4785 50  0000 C CNN
F 1 "POWER" H 3625 4694 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 3625 4500 50  0001 C CNN
F 3 "~" H 3625 4500 50  0001 C CNN
	2    3625 4500
	1    0    0    -1  
$EndComp
Text GLabel 3275 3850 0    50   Output ~ 0
SW_PWR1
NoConn ~ 3825 3750
Wire Wire Line
	3825 4600 3900 4600
NoConn ~ 3825 4400
Text GLabel 5850 3850 0    50   Output ~ 0
SW_TURBO1
Wire Wire Line
	5850 3850 5925 3850
NoConn ~ 6325 3750
NoConn ~ 5925 4500
NoConn ~ 6325 4400
Wire Wire Line
	3275 3850 3350 3850
Wire Wire Line
	3350 3850 3350 4500
Wire Wire Line
	3350 4500 3425 4500
Connection ~ 3350 3850
Wire Wire Line
	3350 3850 3425 3850
Wire Wire Line
	3900 4600 3900 3950
Wire Wire Line
	3900 3950 3825 3950
Text GLabel 3975 4600 2    50   Output ~ 0
SW_PWR2
Wire Wire Line
	3900 4600 3975 4600
Connection ~ 3900 4600
Text Notes 2775 5175 0    50   ~ 0
This is only suitable for use with ATX to AT conversions,\nthe switch needs to be a 6pin latching type. AT power\nsupplies use high voltage here, so it is not suitable for\nthat purpuse.
Wire Wire Line
	6325 4600 6400 4600
Wire Wire Line
	6400 4600 6400 3950
Wire Wire Line
	6400 3950 6325 3950
Text GLabel 6475 4600 2    50   Output ~ 0
SW_TURBO2
Wire Wire Line
	6400 4600 6475 4600
Connection ~ 6400 4600
Text Notes 5300 5025 0    50   ~ 0
Latching 6pin turbo switch, with LED indicator\n(if required).
Text GLabel 4675 4325 3    50   Output ~ 0
LED_PWR2
Text GLabel 4675 4025 1    50   Input ~ 0
LED_PWR1
$Comp
L Device:LED D1
U 1 1 635B6CCE
P 4675 4175
F 0 "D1" V 4714 4057 50  0000 R CNN
F 1 "POWER" V 4623 4057 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 4675 4175 50  0001 C CNN
F 3 "~" H 4675 4175 50  0001 C CNN
	1    4675 4175
	0    -1   -1   0   
$EndComp
Text GLabel 7175 4325 3    50   Output ~ 0
LED_TURBO2
Text GLabel 7175 4025 1    50   Input ~ 0
LED_TURBO1
$Comp
L Device:LED D2
U 1 1 635C68A8
P 7175 4175
F 0 "D2" V 7214 4057 50  0000 R CNN
F 1 "TURBO" V 7123 4057 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 7175 4175 50  0001 C CNN
F 3 "~" H 7175 4175 50  0001 C CNN
	1    7175 4175
	0    -1   -1   0   
$EndComp
Text GLabel 8975 3425 0    50   Input ~ 0
SW_PWR1
Text GLabel 8975 3525 0    50   Input ~ 0
SW_PWR2
Text GLabel 8975 3625 0    50   Output ~ 0
LED_PWR1
Text GLabel 8975 3725 0    50   Input ~ 0
LED_PWR2
Text GLabel 8975 5225 0    50   Input ~ 0
SW_TURBO1
Text GLabel 8975 5325 0    50   Input ~ 0
SW_TURBO2
Text GLabel 8975 5025 0    50   Output ~ 0
LED_TURBO1
Text GLabel 8975 5125 0    50   Input ~ 0
LED_TURBO2
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 63693A74
P 10725 800
F 0 "#FLG0101" H 10725 875 50  0001 C CNN
F 1 "PWR_FLAG" V 10725 927 50  0001 L CNN
F 2 "" H 10725 800 50  0001 C CNN
F 3 "~" H 10725 800 50  0001 C CNN
	1    10725 800 
	0    -1   -1   0   
$EndComp
Connection ~ 10725 800 
Wire Wire Line
	8975 3425 9050 3425
Wire Wire Line
	8975 3525 9050 3525
Wire Wire Line
	8975 3625 9050 3625
Wire Wire Line
	8975 3725 9050 3725
Wire Wire Line
	8975 5225 9050 5225
Wire Wire Line
	8975 5325 9050 5325
Wire Wire Line
	8975 5025 9050 5025
Wire Wire Line
	8975 5125 9050 5125
$Comp
L mounting:Mounting_Pad M5
U 1 1 637825FA
P 10975 950
F 0 "M5" H 10975 1050 50  0001 C CNN
F 1 "Mounting_Pad" H 10975 875 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10975 950 50  0001 C CNN
F 3 "~" H 10975 950 50  0001 C CNN
	1    10975 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	11100 800  11100 1175
Connection ~ 11100 1175
Wire Wire Line
	11100 1175 11100 1250
$Comp
L mounting:Mounting_Pad M7
U 1 1 63790274
P 10850 950
F 0 "M7" H 10850 1050 50  0001 C CNN
F 1 "Mounting_Pad" H 10850 875 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10850 950 50  0001 C CNN
F 3 "~" H 10850 950 50  0001 C CNN
	1    10850 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10975 1100 10975 1175
Connection ~ 10975 1175
Wire Wire Line
	10975 1175 11100 1175
Wire Wire Line
	10850 1100 10850 1175
$Comp
L mounting:Mounting_Pad M10
U 1 1 637AD750
P 10725 950
F 0 "M10" H 10725 1050 50  0001 C CNN
F 1 "Mounting_Pad" H 10725 875 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10725 950 50  0001 C CNN
F 3 "~" H 10725 950 50  0001 C CNN
	1    10725 950 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pad M9
U 1 1 637AD756
P 10600 950
F 0 "M9" H 10600 1050 50  0001 C CNN
F 1 "Mounting_Pad" H 10600 875 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10600 950 50  0001 C CNN
F 3 "~" H 10600 950 50  0001 C CNN
	1    10600 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 1100 10600 1175
Wire Wire Line
	10725 1100 10725 1175
Connection ~ 10850 1175
Wire Wire Line
	10850 1175 10975 1175
Wire Wire Line
	10600 1175 10725 1175
Connection ~ 10725 1175
Wire Wire Line
	10725 1175 10850 1175
$Comp
L RetroPanel:SD35VC0_Front_Panel J1
U 1 1 62825997
P 9250 4125
F 0 "J1" H 9200 5425 50  0000 L CNN
F 1 "Front Panel" H 9350 5425 50  0000 L CNN
F 2 "RetroPanel:SD35VC0_PinHeader_1x30_P2.54mm_Horizontal" H 9250 4125 50  0001 C CNN
F 3 "~" H 9250 4125 50  0001 C CNN
	1    9250 4125
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2925 9050 2925
Wire Wire Line
	8900 2925 8900 3000
$Comp
L power:GND #PWR0101
U 1 1 6282785A
P 8900 3000
F 0 "#PWR0101" H 8900 2750 50  0001 C CNN
F 1 "GND" H 8905 2827 50  0000 C CNN
F 2 "" H 8900 3000 50  0001 C CNN
F 3 "" H 8900 3000 50  0001 C CNN
	1    8900 3000
	1    0    0    -1  
$EndComp
NoConn ~ 9050 5825
$EndSCHEMATC
