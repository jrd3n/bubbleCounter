#include <Arduino.h>
#include <bubbleCounter.h>

unsigned long endTimeSerial = 0;

// unsigned long previousMillis = 0;
bubbleCounter bubble(A3); // choose the pin number

void serialRun(int interval) // function that write to the serial with a delay , with out using the delay funtion
{
    if (endTimeSerial < millis())
    {

        String Line = "Count = " + String(bubble.count);

        Serial.println(Line);

        endTimeSerial = millis() + interval;

        Line = "";
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);

}

void loop()
{
    // put your main code here, to run repeatedly:
    bubble.run(); // for the counter to work this needs to be in the loop
    serialRun(200);

    // int noOfBubbles = bubble.count;
    
}