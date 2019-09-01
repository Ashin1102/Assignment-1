#include <Arduino.h>

uint8_t led_Pin = 6;     // Led pin
uint8_t button_Pin = 2;  //Push Buttton to get the frequency
float P_pin = A0;        // Potentiometer pin
float setTime;           // set time for the frequency
float Value = 0;         // Flag store the potentiometer reading
float setFrequency = 0;  //Flag to store the value coming from the sensor
bool ButtonState = HIGH; // store the state of button
void ISR_Button();
uint8_t buttonState;
uint8_t readButton;
uint32_t debounceDelay_ms = 100;   // time taken to debounce in millisecond
uint32_t currentMillis = millis(); // store how long the microcontroller isrunning
uint32_t previousMillis = 0;       // will store last time LED
uint8_t lastButtonState = 0;       // variable used to store the previous button state
uint8_t lastDebounceTime;          // variable used to store the initial state of button

void setup()
{

    pinMode(led_Pin, OUTPUT);          // ledPin as an OUTPUT:
    pinMode(button_Pin, INPUT_PULLUP); // push button as an INPUT:

    attachInterrupt(digitalPinToInterrupt(button_Pin), ISR_Button, FALLING); // Interrupt to return the value of frequency of Blinking LED

    Serial.begin(9600);
}

void loop()
{

    Value = analogRead(P_pin);                   // read the value from the sensor:
    setFrequency = (map(Value, 0, 1024, 0, 50)); // map analog input from potentiometer to  0-50Hz
    setTime = (1 / setFrequency) * 1000;         // converting frequency to timeperiod in seconds

    for (previousMillis = millis(); (currentMillis - previousMillis) <= (setTime / 2);)

    {
        currentMillis = millis();
        digitalWrite(led_Pin, HIGH); // LED ON
    }
    for (previousMillis = millis(); (currentMillis - previousMillis) <= (setTime / 2);)

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
   if (readButton = !lastButtonState) // check the button is in previous state or not
    {
        lastDebounceTime = millis(); // store the current time into the variable
    }

    if ((millis() - lastDebounceTime) > debounceDelay_ms)
    {
       
    lastButtonState = readButton; // save the reading. Next time through the loop,
}