EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RetroPanel (Front)"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "3.5\" Front panel"
$EndDescr
$Comp
L RetroPanel:Front_Panel J1
U 1 1 62825997
P 9250 4125
F 0 "J1" H 9200 5325 50  0000 L CNN
F 1 "Front Panel" H 9200 5250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x26_P2.54mm_Horizontal" H 9250 4125 50  0001 C CNN
F 3 "~" H 9250 4125 50  0001 C CNN
	1    9250 4125
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 6282785A
P 8975 5700
F 0 "#PWR0101" H 8975 5450 50  0001 C CNN
F 1 "GND" H 8980 5527 50  0000 C CNN
F 2 "" H 8975 5700 50  0001 C CNN
F 3 "" H 8975 5700 50  0001 C CNN
	1    8975 5700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 62828DC5
P 8975 3050
F 0 "#PWR0102" H 8975 2900 50  0001 C CNN
F 1 "VCC" H 8990 3223 50  0000 C CNN
F 2 "" H 8975 3050 50  0001 C CNN
F 3 "" H 8975 3050 50  0001 C CNN
	1    8975 3050
	1    0    0    -1  
$EndComp
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
P 4225 4225
F 0 "SW1" H 4225 4510 50  0000 C CNN
F 1 "TURBO" H 4225 4419 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 4225 4225 50  0001 C CNN
F 3 "~" H 4225 4225 50  0001 C CNN
	1    4225 4225
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW1
U 2 1 62E3C504
P 4225 4875
F 0 "SW1" H 4225 5160 50  0000 C CNN
F 1 "TURBO" H 4225 5069 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 4225 4875 50  0001 C CNN
F 3 "~" H 4225 4875 50  0001 C CNN
	2    4225 4875
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 1 1 62E3F52F
P 1725 4225
F 0 "SW2" H 1725 4510 50  0000 C CNN
F 1 "POWER" H 1725 4419 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 1725 4225 50  0001 C CNN
F 3 "~" H 1725 4225 50  0001 C CNN
	1    1725 4225
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW2
U 2 1 62E3FA35
P 1725 4875
F 0 "SW2" H 1725 5160 50  0000 C CNN
F 1 "POWER" H 1725 5069 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 1725 4875 50  0001 C CNN
F 3 "~" H 1725 4875 50  0001 C CNN
	2    1725 4875
	1    0    0    -1  
$EndComp
Text GLabel 1375 4225 0    50   Output ~ 0
SW_PWR1
NoConn ~ 1925 4125
Wire Wire Line
	1925 4975 2000 4975
NoConn ~ 1925 4775
Text GLabel 3950 4225 0    50   Output ~ 0
SW_TURBO1
Wire Wire Line
	3950 4225 4025 4225
NoConn ~ 4425 4125
NoConn ~ 4025 4875
NoConn ~ 4425 4775
Wire Wire Line
	1375 4225 1450 4225
Wire Wire Line
	1450 4225 1450 4875
Wire Wire Line
	1450 4875 1525 4875
Connection ~ 1450 4225
Wire Wire Line
	1450 4225 1525 4225
Wire Wire Line
	2000 4975 2000 4325
Wire Wire Line
	2000 4325 1925 4325
Text GLabel 2075 4975 2    50   Output ~ 0
SW_PWR2
Wire Wire Line
	2000 4975 2075 4975
Connection ~ 2000 4975
Text Notes 875  5550 0    50   ~ 0
This is only suitable for use with ATX to AT conversions,\nthe switch needs to be a 6pin latching type. AT power\nsupplies use high voltage here, so please don't kill\nyourself.
Wire Wire Line
	4425 4975 4500 4975
Wire Wire Line
	4500 4975 4500 4325
Wire Wire Line
	4500 4325 4425 4325
Text GLabel 4575 4975 2    50   Output ~ 0
SW_TURBO2
Wire Wire Line
	4500 4975 4575 4975
Connection ~ 4500 4975
Text Notes 3400 5400 0    50   ~ 0
Latching 6pin turbo switch, with LED indicator\n(if required).
$Comp
L Switch:SW_DPDT_x2 SW3
U 1 1 6359A1EF
P 1725 6150
F 0 "SW3" H 1725 6435 50  0000 C CNN
F 1 "RESET" H 1725 6344 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 1725 6150 50  0001 C CNN
F 3 "~" H 1725 6150 50  0001 C CNN
	1    1725 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW3
U 2 1 6359A1F5
P 1725 6800
F 0 "SW3" H 1725 7085 50  0000 C CNN
F 1 "RESET" H 1725 6994 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 1725 6800 50  0001 C CNN
F 3 "~" H 1725 6800 50  0001 C CNN
	2    1725 6800
	1    0    0    -1  
$EndComp
Text GLabel 1375 6150 0    50   Output ~ 0
SW_RESET1
NoConn ~ 1925 6050
Wire Wire Line
	1925 6900 2000 6900
NoConn ~ 1925 6700
Wire Wire Line
	1375 6150 1450 6150
Wire Wire Line
	1450 6150 1450 6800
Wire Wire Line
	1450 6800 1525 6800
Connection ~ 1450 6150
Wire Wire Line
	1450 6150 1525 6150
Wire Wire Line
	2000 6900 2000 6250
Wire Wire Line
	2000 6250 1925 6250
Text GLabel 2075 6900 2    50   Output ~ 0
SW_RESET2
Wire Wire Line
	2000 6900 2075 6900
Connection ~ 2000 6900
Text Notes 875  7175 0    50   ~ 0
Momentary reset switch, most newer ATX cases\ndon't include one - so one was therefore needed.
Text GLabel 2775 4700 3    50   Output ~ 0
LED_PWR2
Text GLabel 2775 4400 1    50   Input ~ 0
LED_PWR1
$Comp
L Device:LED D1
U 1 1 635B6CCE
P 2775 4550
F 0 "D1" V 2814 4432 50  0000 R CNN
F 1 "POWER" V 2723 4432 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 2775 4550 50  0001 C CNN
F 3 "~" H 2775 4550 50  0001 C CNN
	1    2775 4550
	0    -1   -1   0   
$EndComp
Text GLabel 5275 4700 3    50   Output ~ 0
LED_TURBO2
Text GLabel 5275 4400 1    50   Input ~ 0
LED_TURBO1
$Comp
L Device:LED D2
U 1 1 635C68A8
P 5275 4550
F 0 "D2" V 5314 4432 50  0000 R CNN
F 1 "TURBO" V 5223 4432 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 5275 4550 50  0001 C CNN
F 3 "~" H 5275 4550 50  0001 C CNN
	1    5275 4550
	0    -1   -1   0   
$EndComp
$Comp
L RetroPanel:3641AH U1
U 1 1 635D0ECA
P 6300 2075
F 0 "U1" H 6300 2742 50  0000 C CNN
F 1 "3641AH" H 6300 2651 50  0000 C CNN
F 2 "RetroPanel:3641AH" H 6300 1475 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/CA56-12CGKWA(Ver.9A).pdf" H 5870 2105 50  0001 C CNN
	1    6300 2075
	1    0    0    -1  
$EndComp
Text Label 5175 1775 2    50   ~ 0
7S_A
Text Label 5175 1875 2    50   ~ 0
7S_B
Text Label 5175 1975 2    50   ~ 0
7S_C
Text Label 5175 2075 2    50   ~ 0
7S_D
Text Label 5175 2175 2    50   ~ 0
7S_E
Text Label 5175 2275 2    50   ~ 0
7S_F
Text Label 5175 2375 2    50   ~ 0
7S_G
Text Label 5175 2475 2    50   ~ 0
7S_DP
Text Label 7425 2175 0    50   ~ 0
7S_D1
Text Label 7425 2275 0    50   ~ 0
7S_D2
Text Label 7425 2375 0    50   ~ 0
7S_D3
Text Label 7425 2475 0    50   ~ 0
7S_D4
Wire Wire Line
	5200 1775 4900 1775
Wire Wire Line
	5200 1875 4900 1875
Wire Wire Line
	5200 1975 4900 1975
Wire Wire Line
	5200 2075 4900 2075
Wire Wire Line
	5200 2175 4900 2175
Wire Wire Line
	5200 2275 4900 2275
Wire Wire Line
	5200 2375 4900 2375
Wire Wire Line
	5200 2475 4900 2475
Wire Wire Line
	7700 2175 7400 2175
Wire Wire Line
	7700 2275 7400 2275
Wire Wire Line
	7700 2375 7400 2375
Wire Wire Line
	7700 2475 7400 2475
Entry Wire Line
	4800 1875 4900 1775
Entry Wire Line
	4800 1975 4900 1875
Entry Wire Line
	4800 2075 4900 1975
Entry Wire Line
	4800 2175 4900 2075
Entry Wire Line
	4800 2275 4900 2175
Entry Wire Line
	4800 2375 4900 2275
Entry Wire Line
	4800 2475 4900 2375
Entry Wire Line
	4800 2575 4900 2475
Entry Wire Line
	7700 2475 7800 2575
Entry Wire Line
	7700 2375 7800 2475
Entry Wire Line
	7700 2275 7800 2375
Entry Wire Line
	7700 2175 7800 2275
Wire Bus Line
	4800 2775 7800 2775
Wire Wire Line
	9050 5625 8975 5625
Wire Wire Line
	8975 3050 8975 3125
Wire Wire Line
	8975 3125 9050 3125
Wire Wire Line
	8975 5625 8975 5700
Text GLabel 8975 3225 0    50   Input ~ 0
SW_PWR1
Text GLabel 8975 3325 0    50   Input ~ 0
SW_PWR2
Text GLabel 8975 3425 0    50   Output ~ 0
LED_PWR1
Text GLabel 8975 3525 0    50   Input ~ 0
LED_PWR2
Text GLabel 8975 5225 0    50   Input ~ 0
SW_TURBO1
Text GLabel 8975 5325 0    50   Input ~ 0
SW_TURBO2
Text GLabel 8975 5425 0    50   Output ~ 0
LED_TURBO1
Text GLabel 8975 5525 0    50   Input ~ 0
LED_TURBO2
Text GLabel 8975 3625 0    50   Input ~ 0
SW_RESET1
Text GLabel 8975 3725 0    50   Input ~ 0
SW_RESET2
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
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 63696E94
P 8975 3125
F 0 "#FLG0102" H 8975 3200 50  0001 C CNN
F 1 "PWR_FLAG" V 8975 3252 50  0001 L CNN
F 2 "" H 8975 3125 50  0001 C CNN
F 3 "~" H 8975 3125 50  0001 C CNN
	1    8975 3125
	0    -1   -1   0   
$EndComp
Entry Wire Line
	8200 4225 8100 4125
Entry Wire Line
	8200 4325 8100 4225
Entry Wire Line
	8200 4425 8100 4325
Entry Wire Line
	8200 4525 8100 4425
Entry Wire Line
	8200 4625 8100 4525
Entry Wire Line
	8200 4725 8100 4625
Entry Wire Line
	8200 4825 8100 4725
Entry Wire Line
	8200 4925 8100 4825
Entry Wire Line
	8200 3825 8100 3725
Entry Wire Line
	8200 3925 8100 3825
Entry Wire Line
	8200 4025 8100 3925
Entry Wire Line
	8200 4125 8100 4025
Connection ~ 8975 3125
Connection ~ 7800 2775
Wire Wire Line
	8975 3225 9050 3225
Wire Wire Line
	8975 3325 9050 3325
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
	8975 5425 9050 5425
Wire Wire Line
	8975 5525 9050 5525
Wire Wire Line
	8200 3825 9050 3825
Wire Bus Line
	8100 2775 7800 2775
Text Label 8225 3825 0    50   ~ 0
7S_D1
Text Label 8225 4925 0    50   ~ 0
7S_B
Text Label 8225 4425 0    50   ~ 0
7S_C
Text Label 8225 4225 0    50   ~ 0
7S_D
Text Label 8225 4525 0    50   ~ 0
7S_G
Text Label 8225 4325 0    50   ~ 0
7S_DP
Text Label 8225 4725 0    50   ~ 0
7S_D2
Text Label 8225 4825 0    50   ~ 0
7S_D3
Text Label 8225 4625 0    50   ~ 0
7S_D4
Wire Wire Line
	8200 3925 9050 3925
Wire Wire Line
	8200 4025 9050 4025
Wire Wire Line
	8200 4125 9050 4125
Wire Wire Line
	8200 4225 9050 4225
Wire Wire Line
	8200 4325 9050 4325
Wire Wire Line
	8200 4425 9050 4425
Wire Wire Line
	8200 4525 9050 4525
Wire Wire Line
	8200 4625 9050 4625
Wire Wire Line
	8200 4725 9050 4725
Wire Wire Line
	8200 4825 9050 4825
Wire Wire Line
	8200 4925 9050 4925
Text Label 8225 3925 0    50   ~ 0
7S_A
Text Label 8225 4025 0    50   ~ 0
7S_F
Text Label 8225 4125 0    50   ~ 0
7S_E
$Comp
L Switch:SW_DPDT_x2 SW4
U 1 1 6374F345
P 4225 6150
F 0 "SW4" H 4225 6435 50  0000 C CNN
F 1 "EXTRA" H 4225 6344 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 4225 6150 50  0001 C CNN
F 3 "~" H 4225 6150 50  0001 C CNN
	1    4225 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW4
U 2 1 6374F34B
P 4225 6800
F 0 "SW4" H 4225 7085 50  0000 C CNN
F 1 "EXTRA" H 4225 6994 50  0000 C CNN
F 2 "6pin_switch:dpdt_switch_black" H 4225 6800 50  0001 C CNN
F 3 "~" H 4225 6800 50  0001 C CNN
	2    4225 6800
	1    0    0    -1  
$EndComp
Text GLabel 3950 6150 0    50   Output ~ 0
SW_EXTRA1
Wire Wire Line
	3950 6150 4025 6150
NoConn ~ 4425 6050
NoConn ~ 4025 6800
NoConn ~ 4425 6700
Wire Wire Line
	4425 6900 4500 6900
Wire Wire Line
	4500 6900 4500 6250
Wire Wire Line
	4500 6250 4425 6250
Text GLabel 4575 6900 2    50   Output ~ 0
SW_EXTRA2
Wire Wire Line
	4500 6900 4575 6900
Connection ~ 4500 6900
Text Notes 3400 7175 0    50   ~ 0
An extra switch for future proofing (meaning\nI did not know what to do with it).
Text GLabel 8975 5025 0    50   Input ~ 0
SW_EXTRA1
Text GLabel 8975 5125 0    50   Input ~ 0
SW_EXTRA2
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
Wire Bus Line
	7800 2275 7800 2775
Wire Bus Line
	4800 1875 4800 2775
Wire Bus Line
	8100 2775 8100 4825
$EndSCHEMATC
