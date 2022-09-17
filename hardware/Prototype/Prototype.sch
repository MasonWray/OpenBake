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
L Modules:Adafruit_24_TFT U?
U 1 1 63260F31
P 3350 2650
F 0 "U?" H 3325 2715 50  0000 C CNN
F 1 "Adafruit_24_TFT" H 3325 2624 50  0000 C CNN
F 2 "" H 3350 2600 50  0001 C CNN
F 3 "" H 3350 2600 50  0001 C CNN
	1    3350 2650
	1    0    0    -1  
$EndComp
$Comp
L Modules:Adafruit_ItsyBitsy_M0 U?
U 1 1 63261DFE
P 5950 3300
F 0 "U?" H 5950 3465 50  0000 C CNN
F 1 "Adafruit_ItsyBitsy_M0" H 5950 3374 50  0000 C CNN
F 2 "" H 5950 3350 50  0001 C CNN
F 3 "" H 5950 3350 50  0001 C CNN
	1    5950 3300
	1    0    0    -1  
$EndComp
$Comp
L Modules:Adafruit_MAX31855 U?
U 1 1 63262A86
P 8050 3700
F 0 "U?" H 8428 3396 50  0000 L CNN
F 1 "Adafruit_MAX31855" H 8428 3305 50  0000 L CNN
F 2 "" H 8050 3750 50  0001 C CNN
F 3 "" H 8050 3750 50  0001 C CNN
	1    8050 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6326403D
P 4300 4600
F 0 "#PWR?" H 4300 4450 50  0001 C CNN
F 1 "+3.3V" H 4315 4773 50  0000 C CNN
F 2 "" H 4300 4600 50  0001 C CNN
F 3 "" H 4300 4600 50  0001 C CNN
	1    4300 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 63264721
P 3950 4800
F 0 "#PWR?" H 3950 4550 50  0001 C CNN
F 1 "GND" H 3955 4627 50  0000 C CNN
F 2 "" H 3950 4800 50  0001 C CNN
F 3 "" H 3950 4800 50  0001 C CNN
	1    3950 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4750 3950 4750
Wire Wire Line
	3950 4750 3950 4800
Wire Wire Line
	3850 4650 4300 4650
$Comp
L power:+3.3V #PWR?
U 1 1 63266DB3
P 6450 4550
F 0 "#PWR?" H 6450 4400 50  0001 C CNN
F 1 "+3.3V" H 6465 4723 50  0000 C CNN
F 2 "" H 6450 4550 50  0001 C CNN
F 3 "" H 6450 4550 50  0001 C CNN
	1    6450 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6326720F
P 5500 4700
F 0 "#PWR?" H 5500 4450 50  0001 C CNN
F 1 "GND" H 5505 4527 50  0000 C CNN
F 2 "" H 5500 4700 50  0001 C CNN
F 3 "" H 5500 4700 50  0001 C CNN
	1    5500 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4600 6450 4600
Wire Wire Line
	6450 4600 6450 4550
$Comp
L power:+3.3V #PWR?
U 1 1 632681A5
P 7850 3750
F 0 "#PWR?" H 7850 3600 50  0001 C CNN
F 1 "+3.3V" H 7865 3923 50  0000 C CNN
F 2 "" H 7850 3750 50  0001 C CNN
F 3 "" H 7850 3750 50  0001 C CNN
	1    7850 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 63268929
P 7400 4050
F 0 "#PWR?" H 7400 3800 50  0001 C CNN
F 1 "GND" H 7405 3877 50  0000 C CNN
F 2 "" H 7400 4050 50  0001 C CNN
F 3 "" H 7400 4050 50  0001 C CNN
	1    7400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4650 4300 4600
Text GLabel 6350 3700 2    50   Input ~ 0
SCK
Text GLabel 6350 3600 2    50   Input ~ 0
MOSI
Text GLabel 6350 3500 2    50   Input ~ 0
MISO
Text GLabel 3900 4450 2    50   Input ~ 0
SCK
Text GLabel 3900 4250 2    50   Input ~ 0
MOSI
Text GLabel 3900 4350 2    50   Input ~ 0
MISO
Text GLabel 7900 4100 0    50   Input ~ 0
TC_DO
Text GLabel 7900 4200 0    50   Input ~ 0
TC_CS
Text GLabel 7900 4300 0    50   Input ~ 0
TC_CLK
Wire Wire Line
	7900 4100 7950 4100
Wire Wire Line
	7950 4200 7900 4200
Wire Wire Line
	7900 4300 7950 4300
Wire Wire Line
	7950 4000 7400 4000
Wire Wire Line
	7400 4000 7400 4050
Wire Wire Line
	7950 3800 7850 3800
Wire Wire Line
	7850 3800 7850 3750
Text GLabel 6350 3400 2    50   Input ~ 0
TC_DO
Text GLabel 5550 3900 0    50   Input ~ 0
TC_CS
Text GLabel 5550 4400 0    50   Input ~ 0
TC_CLK
Text GLabel 3900 4150 2    50   Input ~ 0
TFT_CS
Text GLabel 3900 4050 2    50   Input ~ 0
TFT_DC
Text GLabel 3900 3750 2    50   Input ~ 0
Y+
Text GLabel 3900 3650 2    50   Input ~ 0
X+
Text GLabel 3900 3550 2    50   Input ~ 0
Y-
Text GLabel 3900 3450 2    50   Input ~ 0
X-
Text GLabel 5550 4100 0    50   Input ~ 0
TFT_CS
Text GLabel 5550 4000 0    50   Input ~ 0
TFT_DC
Text GLabel 6350 3800 2    50   Input ~ 0
Y+
Text GLabel 6350 4000 2    50   Input ~ 0
X-
Text GLabel 5550 4300 0    50   Input ~ 0
Y-
Text GLabel 5550 4200 0    50   Input ~ 0
X+
Wire Wire Line
	6300 3400 6350 3400
Wire Wire Line
	6350 3500 6300 3500
Wire Wire Line
	6300 3600 6350 3600
Wire Wire Line
	6350 3700 6300 3700
Wire Wire Line
	6300 3800 6350 3800
Wire Wire Line
	6350 4000 6300 4000
Wire Wire Line
	5550 4400 5600 4400
Wire Wire Line
	5600 4300 5550 4300
Wire Wire Line
	5550 4200 5600 4200
Wire Wire Line
	5600 4100 5550 4100
Wire Wire Line
	5550 4000 5600 4000
Wire Wire Line
	5600 3900 5550 3900
Wire Wire Line
	5500 4700 5500 4600
Wire Wire Line
	5500 4600 5600 4600
Wire Wire Line
	3900 4450 3850 4450
Wire Wire Line
	3850 4350 3900 4350
Wire Wire Line
	3900 4250 3850 4250
Wire Wire Line
	3850 4150 3900 4150
Wire Wire Line
	3900 4050 3850 4050
Wire Wire Line
	3850 3750 3900 3750
Wire Wire Line
	3900 3650 3850 3650
Wire Wire Line
	3850 3550 3900 3550
Wire Wire Line
	3900 3450 3850 3450
$EndSCHEMATC
