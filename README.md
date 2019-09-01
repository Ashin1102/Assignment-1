# Assignment-1

Student Assessment Cover Sheet^
WelTec
Wellington Institute of Technology

4 WelTec, Private Bag 39814, Lower Hutt 5045, New Zealand ()) 0800 935 832^0 http://www.weltec.ac.nz

Legal Surname or Family Name(s) (^) Legal First or Given Name(s)
KEEZHUTTU ALEX (^) ASHIN
Preferred Name(s) WelTec Student ID
ASHIN K ALEX (^) 21 9 1 0 5 6
Assessment Title 7 Due Date
Assignment 0- Flicker Fusion Treshold 01/09/
(Please enter your Assessment Title and Due Date)
Office Use Only
(Please enter the name of the School your Programme belongs to) Engineering
Programme C,
HV4530 Eng.Dip in Mechatronics
(Please enter your Programme code eg HVXXXX)
MG7013 EMBEDDED SYSTEMS
(Please enter your Course code eg IDXXXX)
Frank Beinersdorf
(^) Received on behalf of the School (date stamp)
(Please enter your Tutor's name)
Declaration: (^) .it's Signaturc
This assessment is my own original work. I have acknowledged
contributions from other sources using the APA reference format.
This part of the Assessment Cover sheet is retained by the School as proof that your assessment was handed in.
Assessment Title
Assignment 0- Flicker Fusion Treshold
(Please enter your Assessment Title and Due Date)
Programme Code and Title
HV4530 Eng.Dip in Mechatronics
(Please enter your Programme code eg HVXXXX)
Course Code and Title (and cti!
MG7013 EMBEDDED SYSTEMS
(Please enter your Course code eg IDXXXX)
_J
Due Date
01/09/
Office Use Only
First fiarn:.
Ashin Keezhuttu Alex
Preferred Name(s)
Received on behalf of the School (date stamp)
WelTec Student ID
(^1) 1 9 ri Q 51 61
du(1,1-4 ,t nt
otO
Flicker
Fusion
Threshold

September 1
2019
CONTENTS

    INTRODUCTION............................................................................................
    OBJECTIVE.....................................................................................................
    COMPONENTS USED....................................................................................
    CIRCUIT DIAGRAM........................................................................................
    FLOW CHART.................................................................................................
    METHODOLOGY............................................................................................
    HARDWARE....................................................................................................
    PROGRAM......................................................................................................
    PROBLEMS FACED.........................................................................................
    RESULT............................................................................................................
    CONCLUSION.................................................................................................

INTRODUCTION............................................................................................

The flicker fusion threshold can be defined as the frequency at which an intermittent light

stimulus appears to be completely steady to the average human observer. Flicker fusion
threshold is related to persistence of vision.
OBJECTIVE.....................................................................................................

 Design a circuit diagram with the components provided.

 Write the code in Visual Studio Code for the Teensy 3.2 microcontroller with respect
to the designed circuit.

 Upload the program to Teensy 3.2 micro controller.

 Adjust the potentiometer to change Frequency of the LED blinking.

 Use the interrupt button to display the current blinking frequency on the serial
monitor.

COMPONENTS USED....................................................................................

 Teensy 3.2 development Board

 A computer installed with Visual Studio code

 LED

 Resistor

 Potentiometer – 10 kOhm

 Jumper Wires

 Push-button

 Bread Board
Circuit Design
FLOW CHART.................................................................................................
METHODOLOGY............................................................................................

 Write the program in visual studio code as described in the project requirement.
 Design the hardware on the breadboard with respect to the written code
 Replay the delay function with Millis/ Micros to create a delay.
 Use an external interrupt button for the debouncing time and design the code
accordingly.
 Connect a potentiometer to vary the frequency.
 A resistor must be used to protect the LED.
 An external button must be used to display set frequency.

HARDWARE....................................................................................................
PROGRAM......................................................................................................

#include <Arduino.h>

uint8_t led_Pin = 6 ; // Led pin
uint8_t button_Pin = 2 ; //Push Buttton to get the frequency
float P_pin = A0; // Potentiometer pin
float setTime; // set time for the frequency
float Value = 0 ; // Flag store the potentiometer reading
float setFrequency = 0 ; //Flag to store the value coming from the sensor
bool ButtonState = HIGH; // store the state of button
void ISR_Button();
uint8_t buttonState;
uint8_t readButton;
uint32_t debounceDelay_ms = 100 ; // time taken to debounce in millisecond
uint32_t currentMillis = millis(); // store how long the microcontroller
isrunning
uint32_t previousMillis = 0 ; // will store last time LED
uint8_t lastButtonState = 0 ; // variable used to store the previous
button state

uint8_t lastDebounceTime; // variable used to store the initial state
of button

void setup()
{

pinMode(led_Pin, OUTPUT); // ledPin as an OUTPUT:
pinMode(button_Pin, INPUT_PULLUP); // push button as an INPUT:

attachInterrupt(digitalPinToInterrupt(button_Pin), ISR_Button, FALLING);
// Interrupt to return the value of frequency of Blinking LED

Serial.begin( 9600 );
}

void loop()
{

Value = analogRead(P_pin); // read the value from the
sensor:
setFrequency = (map(Value, 0 , 1024 , 0 , 50 )); // map analog input from
potentiometer to 0-50Hz
setTime = ( 1 / setFrequency) * 1000 ; // converting frequency to
timeperiod in seconds

for (previousMillis = millis(); (currentMillis - previousMillis) <=
(setTime / 2 );)

{
currentMillis = millis();
digitalWrite(led_Pin, HIGH); // LED ON
}
for (previousMillis = millis(); (currentMillis - previousMillis) <=
(setTime / 2 );)

{
currentMillis = millis();

digitalWrite(led_Pin, LOW);
}

if(ButtonState == true){
ButtonState = false;
Serial.println("SetFrequency"); // print the command
Serial.println(setFrequency);// to print the value of variable
}
}

void ISR_Button() // This funcion executes when button has been pressed
{

ButtonState = true;
if (readButton = !lastButtonState) // check the Current state of button
{
lastDebounceTime = millis(); // Update current time into the variable
}

if ((millis() - lastDebounceTime) > debounceDelay_ms)
{

lastButtonState = readButton; // save the reading.
}
PROBLEMS FACED.........................................................................................

 Initial i have faced some trouble with programing in visual studio code as I am not
familiar with visual studio code and its programing.
 With helps of the class tutorials, some research and friends I have done with the
programing.
 At the initial stage the potentiometer was not working, later an error in the
connection was rectified.
 Then I found my interrupt button was not working as my serial monitor is printing the
code continuously. Later with the help of my tutor I have fixed the issue, as my code
was found messy.
 After fixing the button issue .with a button press the serial monitor start printing
multiple frequencies. It was later rectified, as it was due to some error in the
denouncing code.

RESULT............................................................................................................
YouTube Video: https://www.youtube.com/watch?v=iVX1rxkabvk&feature=youtu.be
CONCLUSION.................................................................................................

The Assignment: flicker fusion Threshold, has been completed successfully and by connecting
the teens 3. 2 board to the computer frequency of the flickering LED is displayed on the serial

monitor of the version studio code, which is used for the coding .The duty cycle has been

observed on the oscilloscope. The circuit diagram is designed using EasyEda online.
