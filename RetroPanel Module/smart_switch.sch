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
P 7475 4175
F 0 "J14" H 7555 4217 50  0000 L CNN
F 1 "PWR_OK" H 7555 4126 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7475 4175 50  0001 C CNN
F 3 "~" H 7475 4175 50  0001 C CNN
	1    7475 4175
	1    0    0    -1  
$EndComp
Text Notes 7575 4350 0    50   ~ 0
(Grey)
$Comp
L Connector_Generic:Conn_01x01 J15
U 1 1 63656D65
P 7475 4825
F 0 "J15" H 7555 4867 50  0000 L CNN
F 1 "COMMON" H 7555 4776 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7475 4825 50  0001 C CNN
F 3 "~" H 7475 4825 50  0001 C CNN
	1    7475 4825
	1    0    0    -1  
$EndComp
Text Notes 7575 5000 0    50   ~ 0
(BLACK)
Text Notes 7575 3650 0    50   ~ 0
(Green)
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 636587F1
P 7475 2875
F 0 "J12" H 7555 2917 50  0000 L CNN
F 1 "+5VSB" H 7555 2826 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7475 2875 50  0001 C CNN
F 3 "~" H 7475 2875 50  0001 C CNN
	1    7475 2875
	1    0    0    -1  
$EndComp
Text Notes 7575 3050 0    50   ~ 0
(Grey)
$Comp
L Timer:NE555P U2
U 1 1 63659578
P 5675 3475
F 0 "U2" H 5375 3825 50  0000 C CNN
F 1 "NE555P" H 5675 3450 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 6325 3075 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ne555.pdf" H 6525 3075 50  0001 C CNN
	1    5675 3475
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 6365E9A2
P 7200 4900
F 0 "#PWR0118" H 7200 4650 50  0001 C CNN
F 1 "GND" H 7205 4727 50  0000 C CNN
F 2 "" H 7200 4900 50  0001 C CNN
F 3 "" H 7200 4900 50  0001 C CNN
	1    7200 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4900 7200 4825
Wire Wire Line
	7200 4825 7275 4825
Wire Wire Line
	4975 2875 4975 3675
Wire Wire Line
	5675 3075 5675 2875
$Comp
L Device:C_Small C?
U 1 1 636700F3
P 4850 3050
AR Path="/635DDED3/636700F3" Ref="C?"  Part="1" 
AR Path="/63655027/636700F3" Ref="C6"  Part="1" 
F 0 "C6" H 4942 3096 50  0000 L CNN
F 1 "100nF" H 4942 3005 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4850 3050 50  0001 C CNN
F 3 "~" H 4850 3050 50  0001 C CNN
	1    4850 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4850 2875 4850 2950
Wire Wire Line
	4850 3150 4850 3475
$Comp
L Device:R_Small R?
U 1 1 636747F5
P 4475 4000
AR Path="/636747F5" Ref="R?"  Part="1" 
AR Path="/63655027/636747F5" Ref="R18"  Part="1" 
F 0 "R18" H 4525 3950 50  0000 L CNN
F 1 "33k" H 4525 4025 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4475 4000 50  0001 C CNN
F 3 "~" H 4475 4000 50  0001 C CNN
	1    4475 4000
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 63675D72
P 5675 3875
F 0 "#PWR0119" H 5675 3625 50  0001 C CNN
F 1 "GND" H 5680 3702 50  0000 C CNN
F 2 "" H 5675 3875 50  0001 C CNN
F 3 "" H 5675 3875 50  0001 C CNN
	1    5675 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	4475 3900 4475 2875
Wire Wire Line
	4475 4100 4475 4175
Wire Wire Line
	6250 4175 6250 3675
Wire Wire Line
	6250 3675 6175 3675
Connection ~ 4475 4175
Wire Wire Line
	4475 4175 4475 4350
Wire Wire Line
	5175 3275 5100 3275
Wire Wire Line
	5100 3275 5100 4175
Connection ~ 5675 2875
Wire Wire Line
	5100 4175 6250 4175
Connection ~ 6250 4175
$Comp
L Device:C_Small C?
U 1 1 6367F100
P 6775 4175
AR Path="/635DDED3/6367F100" Ref="C?"  Part="1" 
AR Path="/63655027/6367F100" Ref="C8"  Part="1" 
F 0 "C8" V 6975 4125 50  0000 L CNN
F 1 "1000nF" V 6900 4050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 6775 4175 50  0001 C CNN
F 3 "~" H 6775 4175 50  0001 C CNN
	1    6775 4175
	0    1    -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6368CB1B
P 4475 4450
AR Path="/6368CB1B" Ref="R?"  Part="1" 
AR Path="/63655027/6368CB1B" Ref="R19"  Part="1" 
F 0 "R19" H 4525 4400 50  0000 L CNN
F 1 "27k" H 4525 4475 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4475 4450 50  0001 C CNN
F 3 "~" H 4475 4450 50  0001 C CNN
	1    4475 4450
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 6368DC14
P 6500 4900
F 0 "#PWR0120" H 6500 4650 50  0001 C CNN
F 1 "GND" H 6505 4727 50  0000 C CNN
F 2 "" H 6500 4900 50  0001 C CNN
F 3 "" H 6500 4900 50  0001 C CNN
	1    6500 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C7
U 1 1 6368FB24
P 6500 4800
F 0 "C7" H 6588 4846 50  0000 L CNN
F 1 "4.7uF" H 6588 4755 50  0000 L CNN
F 2 "RetroPanel:CP_Radial_D4.0mm_P2.00mm_Custom" H 6500 4800 50  0001 C CNN
F 3 "~" H 6500 4800 50  0001 C CNN
	1    6500 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6368FE63
P 6500 4450
AR Path="/6368FE63" Ref="R?"  Part="1" 
AR Path="/63655027/6368FE63" Ref="R20"  Part="1" 
F 0 "R20" H 6550 4400 50  0000 L CNN
F 1 "220k" H 6550 4475 50  0000 L CNN
F 2 "resistor:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6500 4450 50  0001 C CNN
F 3 "~" H 6500 4450 50  0001 C CNN
	1    6500 4450
	1    0    0    1   
$EndComp
Wire Wire Line
	6500 3275 6500 4350
Wire Wire Line
	6500 4550 6500 4625
Wire Wire Line
	6500 4625 6500 4700
Connection ~ 6500 4625
$Comp
L power:GND #PWR0121
U 1 1 63699D4C
P 4475 4900
F 0 "#PWR0121" H 4475 4650 50  0001 C CNN
F 1 "GND" H 4480 4727 50  0000 C CNN
F 2 "" H 4475 4900 50  0001 C CNN
F 3 "" H 4475 4900 50  0001 C CNN
	1    4475 4900
	1    0    0    -1  
$EndComp
Text GLabel 6175 4525 0    50   Input ~ 0
SW_PWR1
Text GLabel 6175 4625 0    50   Input ~ 0
SW_PWR2
Wire Wire Line
	6250 4175 6250 4525
Wire Wire Line
	6175 4525 6250 4525
Text Label 7250 2875 2    50   ~ 0
+5VSB
Wire Wire Line
	4475 4550 4475 4900
Wire Wire Line
	6250 4175 6675 4175
Wire Wire Line
	6175 4625 6500 4625
Wire Wire Line
	6175 3275 6500 3275
Text Label 7250 3475 2    50   ~ 0
PWR_ON
Text Label 7250 4175 2    50   ~ 0
PWR_OK
Wire Wire Line
	6875 4175 7275 4175
Wire Wire Line
	6175 3475 7275 3475
Wire Wire Line
	5675 2875 7275 2875
Connection ~ 4850 2875
Connection ~ 4975 2875
Wire Wire Line
	4975 2875 5675 2875
Wire Wire Line
	4850 2875 4975 2875
Wire Wire Line
	4475 4175 5100 4175
Connection ~ 5100 4175
Wire Wire Line
	4850 3475 5175 3475
Wire Wire Line
	4975 3675 5175 3675
Wire Wire Line
	4475 2875 4850 2875
$Comp
L Connector_Generic:Conn_01x01 J13
U 1 1 6365793F
P 7475 3475
F 0 "J13" H 7555 3517 50  0000 L CNN
F 1 "PWR_ON" H 7555 3426 50  0000 L CNN
F 2 "RetroPanel:PSU_Wire" H 7475 3475 50  0001 C CNN
F 3 "~" H 7475 3475 50  0001 C CNN
	1    7475 3475
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 639556AC
P 5675 2875
F 0 "#FLG0101" H 5675 2950 50  0001 C CNN
F 1 "PWR_FLAG" H 5675 3048 50  0000 C CNN
F 2 "" H 5675 2875 50  0001 C CNN
F 3 "~" H 5675 2875 50  0001 C CNN
	1    5675 2875
	1    0    0    -1  
$EndComp
$EndSCHEMATC
