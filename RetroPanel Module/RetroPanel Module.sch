EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RetroPanel (Module)"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "3.5\" Module"
$EndDescr
$Comp
L mounting:Mounting_Pin M1
U 1 1 6359FE85
P 10825 625
F 0 "M1" H 10825 725 50  0001 C CNN
F 1 "Mounting_Pin" H 10825 550 50  0001 C CNN
F 2 "mounting:M3_pin" H 10825 625 50  0001 C CNN
F 3 "~" H 10825 625 50  0001 C CNN
	1    10825 625 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pin M2
U 1 1 6359FE86
P 10950 625
F 0 "M2" H 10950 725 50  0001 C CNN
F 1 "Mounting_Pin" H 10950 550 50  0001 C CNN
F 2 "mounting:M3_pin" H 10950 625 50  0001 C CNN
F 3 "~" H 10950 625 50  0001 C CNN
	1    10950 625 
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pin M3
U 1 1 6359FE87
P 11075 625
F 0 "M3" H 11075 725 50  0001 C CNN
F 1 "Mounting_Pin" H 11075 550 50  0001 C CNN
F 2 "mounting:M3_pin" H 11075 625 50  0001 C CNN
F 3 "~" H 11075 625 50  0001 C CNN
	1    11075 625 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 6282AADA
P 11075 1300
F 0 "#PWR0111" H 11075 1050 50  0001 C CNN
F 1 "GND" H 11080 1127 50  0000 C CNN
F 2 "" H 11075 1300 50  0001 C CNN
F 3 "" H 11075 1300 50  0001 C CNN
	1    11075 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10825 775  10825 850 
Wire Wire Line
	10950 775  10950 850 
Wire Wire Line
	10825 850  10950 850 
Wire Wire Line
	11075 775  11075 850 
Connection ~ 10950 850 
Wire Wire Line
	10950 850  11075 850 
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 6359FE89
P 10600 850
F 0 "#FLG0101" H 10600 925 50  0001 C CNN
F 1 "PWR_FLAG" V 10600 977 50  0001 L CNN
F 2 "" H 10600 850 50  0001 C CNN
F 3 "~" H 10600 850 50  0001 C CNN
	1    10600 850 
	0    -1   -1   0   
$EndComp
$Comp
L mounting:Mounting_Pad M5
U 1 1 637825FA
P 10950 1000
F 0 "M5" H 10950 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10950 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10950 1000 50  0001 C CNN
F 3 "~" H 10950 1000 50  0001 C CNN
	1    10950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	11075 850  11075 1225
Connection ~ 11075 1225
Wire Wire Line
	11075 1225 11075 1300
$Comp
L mounting:Mounting_Pad M8
U 1 1 6359FE8B
P 10825 1000
F 0 "M8" H 10825 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10825 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10825 1000 50  0001 C CNN
F 3 "~" H 10825 1000 50  0001 C CNN
	1    10825 1000
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pad M7
U 1 1 6359FE8C
P 10700 1000
F 0 "M7" H 10700 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10700 925 50  0001 C CNN
F 2 "RetroPanel:B.Pad_pin" H 10700 1000 50  0001 C CNN
F 3 "~" H 10700 1000 50  0001 C CNN
	1    10700 1000
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pad M6
U 1 1 637928C6
P 10575 1000
F 0 "M6" H 10575 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10575 925 50  0001 C CNN
F 2 "RetroPanel:B.Pad_pin" H 10575 1000 50  0001 C CNN
F 3 "~" H 10575 1000 50  0001 C CNN
	1    10575 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 1150 10950 1225
Connection ~ 10950 1225
Wire Wire Line
	10950 1225 11075 1225
Wire Wire Line
	10825 1150 10825 1225
Connection ~ 10825 1225
Wire Wire Line
	10825 1225 10950 1225
Wire Wire Line
	10700 1150 10700 1225
Connection ~ 10700 1225
Wire Wire Line
	10700 1225 10825 1225
$Comp
L mounting:Mounting_Pad M10
U 1 1 637AD750
P 10450 1000
F 0 "M10" H 10450 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10450 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10450 1000 50  0001 C CNN
F 3 "~" H 10450 1000 50  0001 C CNN
	1    10450 1000
	1    0    0    -1  
$EndComp
$Comp
L mounting:Mounting_Pad M9
U 1 1 6359FE8F
P 10325 1000
F 0 "M9" H 10325 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10325 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10325 1000 50  0001 C CNN
F 3 "~" H 10325 1000 50  0001 C CNN
	1    10325 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10325 1150 10325 1225
Wire Wire Line
	10325 1225 10450 1225
Wire Wire Line
	10450 1150 10450 1225
Connection ~ 10450 1225
Wire Wire Line
	10450 1225 10575 1225
Wire Wire Line
	10575 1150 10575 1225
Connection ~ 10575 1225
Wire Wire Line
	10575 1225 10700 1225
Connection ~ 11075 850 
Connection ~ 10825 850 
$Comp
L mounting:Mounting_Pad M4
U 1 1 635B1EEE
P 10200 1000
F 0 "M4" H 10200 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10200 925 50  0001 C CNN
F 2 "RetroPanel:B.Pad_pin" H 10200 1000 50  0001 C CNN
F 3 "~" H 10200 1000 50  0001 C CNN
	1    10200 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 1150 10200 1225
Wire Wire Line
	10325 1225 10200 1225
Connection ~ 10325 1225
$Comp
L mounting:Mounting_Pad M11
U 1 1 635B4DD6
P 10075 1000
F 0 "M11" H 10075 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 10075 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 10075 1000 50  0001 C CNN
F 3 "~" H 10075 1000 50  0001 C CNN
	1    10075 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10075 1150 10075 1225
Wire Wire Line
	10075 1225 10200 1225
Connection ~ 10200 1225
$Comp
L mounting:Mounting_Pad M12
U 1 1 635B6874
P 9950 1000
F 0 "M12" H 9950 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 9950 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 9950 1000 50  0001 C CNN
F 3 "~" H 9950 1000 50  0001 C CNN
	1    9950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 1150 9950 1225
Wire Wire Line
	9950 1225 10075 1225
Connection ~ 10075 1225
$Comp
L mounting:Mounting_Pad M13
U 1 1 635B7F85
P 9825 1000
F 0 "M13" H 9825 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 9825 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 9825 1000 50  0001 C CNN
F 3 "~" H 9825 1000 50  0001 C CNN
	1    9825 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9825 1150 9825 1225
Wire Wire Line
	9825 1225 9950 1225
Connection ~ 9950 1225
$Comp
L RetroPanel:Front_Panel J1
U 1 1 62825997
P 9250 4125
F 0 "J1" H 9200 5325 50  0000 L CNN
F 1 "Front Panel" H 9200 5250 50  0000 L CNN
F 2 "RetroPanel:Module_Panel" H 9250 4125 50  0001 C CNN
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
Text GLabel 8975 5025 0    50   Input ~ 0
SW_EXTRA1
Text GLabel 8975 5125 0    50   Input ~ 0
SW_EXTRA2
Wire Wire Line
	8975 5025 9050 5025
Wire Wire Line
	8975 5125 9050 5125
$Comp
L mounting:Mounting_Pad M14
U 1 1 635E064A
P 9700 1000
F 0 "M14" H 9700 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 9700 925 50  0001 C CNN
F 2 "RetroPanel:B.Pad_pin" H 9700 1000 50  0001 C CNN
F 3 "~" H 9700 1000 50  0001 C CNN
	1    9700 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 1150 9700 1225
Wire Wire Line
	9700 1225 9825 1225
Connection ~ 9825 1225
$Comp
L mounting:Mounting_Pad M15
U 1 1 635E5F23
P 9575 1000
F 0 "M15" H 9575 1100 50  0001 C CNN
F 1 "Mounting_Pad" H 9575 925 50  0001 C CNN
F 2 "RetroPanel:Pad_pin" H 9575 1000 50  0001 C CNN
F 3 "~" H 9575 1000 50  0001 C CNN
	1    9575 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9575 1150 9575 1225
Wire Wire Line
	9575 1225 9700 1225
Connection ~ 9700 1225
$Comp
L mounting:Mounting_Pin M16
U 1 1 635F4633
P 10700 625
F 0 "M16" H 10700 725 50  0001 C CNN
F 1 "Mounting_Pin" H 10700 550 50  0001 C CNN
F 2 "mounting:M3_pin" H 10700 625 50  0001 C CNN
F 3 "~" H 10700 625 50  0001 C CNN
	1    10700 625 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 775  10700 850 
Wire Wire Line
	10700 850  10825 850 
Connection ~ 10700 850 
Wire Wire Line
	10600 850  10700 850 
$EndSCHEMATC
