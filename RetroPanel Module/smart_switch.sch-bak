EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "3.5\" RetroPanel Module (Smart Switch)"
Date ""
Rev "A"
Comp ""
Comment1 ""
Comment2 "latching switch is installed on the front and then wired to the ATX to AT cables."
Comment3 "to shut down when one of its outputs have been shorted. If the circuit is not needed, a"
Comment4 "Circuit for using standard ATX-case with ATX to AT-kits, the circuit allows the PSU "
$EndDescr
$Comp
L Connector_Generic:Conn_01x01 J14
U 1 1 636561A7
P 7250 4200
F 0 "J14" H 7330 4242 50  0000 L CNN
F 1 "PWR_OK" H 7330 4151 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7250 4200 50  0001 C CNN
F 3 "~" H 7250 4200 50  0001 C CNN
	1    7250 4200
	1    0    0    -1  
$EndComp
Text Notes 7350 4375 0    50   ~ 0
(Grey)
$Comp
L Connector_Generic:Conn_01x01 J15
U 1 1 63656D65
P 7250 4850
F 0 "J15" H 7330 4892 50  0000 L CNN
F 1 "COMMON" H 7330 4801 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7250 4850 50  0001 C CNN
F 3 "~" H 7250 4850 50  0001 C CNN
	1    7250 4850
	1    0    0    -1  
$EndComp
Text Notes 7350 5025 0    50   ~ 0
(BLACK)
Text Notes 7350 3675 0    50   ~ 0
(Green)
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 636587F1
P 7250 2900
F 0 "J12" H 7330 2942 50  0000 L CNN
F 1 "+5VSB" H 7330 2851 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7250 2900 50  0001 C CNN
F 3 "~" H 7250 2900 50  0001 C CNN
	1    7250 2900
	1    0    0    -1  
$EndComp
Text Notes 7350 3075 0    50   ~ 0
(Grey)
$Comp
L Timer:NE555P U2
U 1 1 63659578
P 5450 3500
F 0 "U2" H 5150 3850 50  0000 C CNN
F 1 "NE555P" H 5450 3475 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 6100 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ne555.pdf" H 6300 3100 50  0001 C CNN
	1    5450 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 6365E9A2
P 6975 4925
F 0 "#PWR0118" H 6975 4675 50  0001 C CNN
F 1 "GND" H 6980 4752 50  0000 C CNN
F 2 "" H 6975 4925 50  0001 C CNN
F 3 "" H 6975 4925 50  0001 C CNN
	1    6975 4925
	1    0    0    -1  
$EndComp
Wire Wire Line
	6975 4925 6975 4850
Wire Wire Line
	6975 4850 7050 4850
Wire Wire Line
	4750 2900 4750 3700
Wire Wire Line
	5450 3100 5450 2900
$Comp
L Device:C_Small C?
U 1 1 636700F3
P 4625 3075
AR Path="/635DDED3/636700F3" Ref="C?"  Part="1" 
AR Path="/63655027/636700F3" Ref="C6"  Part="1" 
F 0 "C6" H 4717 3121 50  0000 L CNN
F 1 "100nF" H 4717 3030 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4625 3075 50  0001 C CNN
F 3 "~" H 4625 3075 50  0001 C CNN
	1    4625 3075
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4625 2900 4625 2975
Wire Wire Line
	4625 3175 4625 3500
$Comp
L Device:R_Small R?
U 1 1 636747F5
P 4250 4025
AR Path="/636747F5" Ref="R?"  Part="1" 
AR Path="/63655027/636747F5" Ref="R18"  Part="1" 
F 0 "R18" H 4300 3975 50  0000 L CNN
F 1 "33k" H 4300 4050 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4250 4025 50  0001 C CNN
F 3 "~" H 4250 4025 50  0001 C CNN
	1    4250 4025
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 63675D72
P 5450 3900
F 0 "#PWR0119" H 5450 3650 50  0001 C CNN
F 1 "GND" H 5455 3727 50  0000 C CNN
F 2 "" H 5450 3900 50  0001 C CNN
F 3 "" H 5450 3900 50  0001 C CNN
	1    5450 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3925 4250 2900
Wire Wire Line
	4250 4125 4250 4200
Wire Wire Line
	6025 4200 6025 3700
Wire Wire Line
	6025 3700 5950 3700
Connection ~ 4250 4200
Wire Wire Line
	4250 4200 4250 4375
Wire Wire Line
	4950 3300 4875 3300
Wire Wire Line
	4875 3300 4875 4200
Connection ~ 5450 2900
Wire Wire Line
	4875 4200 6025 4200
Connection ~ 6025 4200
$Comp
L Device:C_Small C?
U 1 1 6367F100
P 6550 4200
AR Path="/635DDED3/6367F100" Ref="C?"  Part="1" 
AR Path="/63655027/6367F100" Ref="C8"  Part="1" 
F 0 "C8" V 6750 4150 50  0000 L CNN
F 1 "1000nF" V 6675 4075 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 6550 4200 50  0001 C CNN
F 3 "~" H 6550 4200 50  0001 C CNN
	1    6550 4200
	0    1    -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6368CB1B
P 4250 4475
AR Path="/6368CB1B" Ref="R?"  Part="1" 
AR Path="/63655027/6368CB1B" Ref="R19"  Part="1" 
F 0 "R19" H 4300 4425 50  0000 L CNN
F 1 "27k" H 4300 4500 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4250 4475 50  0001 C CNN
F 3 "~" H 4250 4475 50  0001 C CNN
	1    4250 4475
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 6368DC14
P 6275 4925
F 0 "#PWR0120" H 6275 4675 50  0001 C CNN
F 1 "GND" H 6280 4752 50  0000 C CNN
F 2 "" H 6275 4925 50  0001 C CNN
F 3 "" H 6275 4925 50  0001 C CNN
	1    6275 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C7
U 1 1 6368FB24
P 6275 4825
F 0 "C7" H 6363 4871 50  0000 L CNN
F 1 "4.7uF" H 6363 4780 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 6275 4825 50  0001 C CNN
F 3 "~" H 6275 4825 50  0001 C CNN
	1    6275 4825
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6368FE63
P 6275 4475
AR Path="/6368FE63" Ref="R?"  Part="1" 
AR Path="/63655027/6368FE63" Ref="R20"  Part="1" 
F 0 "R20" H 6325 4425 50  0000 L CNN
F 1 "220k" H 6325 4500 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6275 4475 50  0001 C CNN
F 3 "~" H 6275 4475 50  0001 C CNN
	1    6275 4475
	1    0    0    1   
$EndComp
Wire Wire Line
	6275 3300 6275 4375
Wire Wire Line
	6275 4575 6275 4650
Wire Wire Line
	6275 4650 6275 4725
Connection ~ 6275 4650
$Comp
L power:GND #PWR0121
U 1 1 63699D4C
P 4250 4925
F 0 "#PWR0121" H 4250 4675 50  0001 C CNN
F 1 "GND" H 4255 4752 50  0000 C CNN
F 2 "" H 4250 4925 50  0001 C CNN
F 3 "" H 4250 4925 50  0001 C CNN
	1    4250 4925
	1    0    0    -1  
$EndComp
Text GLabel 5950 4550 0    50   Input ~ 0
SW_PWR1
Text GLabel 5950 4650 0    50   Input ~ 0
SW_PWR2
Wire Wire Line
	6025 4200 6025 4550
Wire Wire Line
	5950 4550 6025 4550
Text Label 7025 2900 2    50   ~ 0
+5VSB
Wire Wire Line
	4250 4575 4250 4925
Wire Wire Line
	6025 4200 6450 4200
Wire Wire Line
	5950 4650 6275 4650
Wire Wire Line
	5950 3300 6275 3300
Text Label 7025 3500 2    50   ~ 0
PWR_ON
Text Label 7025 4200 2    50   ~ 0
PWR_OK
Wire Wire Line
	6650 4200 7050 4200
Wire Wire Line
	5950 3500 7050 3500
Wire Wire Line
	5450 2900 7050 2900
Connection ~ 4625 2900
Connection ~ 4750 2900
Wire Wire Line
	4750 2900 5450 2900
Wire Wire Line
	4625 2900 4750 2900
Wire Wire Line
	4250 4200 4875 4200
Connection ~ 4875 4200
Wire Wire Line
	4625 3500 4950 3500
Wire Wire Line
	4750 3700 4950 3700
Wire Wire Line
	4250 2900 4625 2900
$Comp
L Connector_Generic:Conn_01x01 J13
U 1 1 6365793F
P 7250 3500
F 0 "J13" H 7330 3542 50  0000 L CNN
F 1 "PWR_ON" H 7330 3451 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7250 3500 50  0001 C CNN
F 3 "~" H 7250 3500 50  0001 C CNN
	1    7250 3500
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 639556AC
P 5450 2900
F 0 "#FLG0101" H 5450 2975 50  0001 C CNN
F 1 "PWR_FLAG" H 5450 3073 50  0000 C CNN
F 2 "" H 5450 2900 50  0001 C CNN
F 3 "~" H 5450 2900 50  0001 C CNN
	1    5450 2900
	1    0    0    -1  
$EndComp
Text Notes 7800 3225 0    50   ~ 0
Note that the colours assigned in the specification\nmight not actually match the cable that you have,\nin particular the cheap extensions and ATX to AT\ncable harnesses may have shuffled these around\ndepending on what they had on hand.
$EndSCHEMATC
