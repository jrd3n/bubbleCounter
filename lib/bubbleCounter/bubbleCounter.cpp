#include <Arduino.h>
#include <bubbleCounter.h>

bubbleCounter::bubbleCounter(int pinNo)
{
    pinMode(pinNo, INPUT); // sets the pin mode

    bubblePin = pinNo; // makes the pin No avalible later on

    unsigned int EndTime = millis() + 1000; // crates a varable so we can work out the threshold values for the light sensor

    int maxVal = 0;

    int minVal = 1028;

    // Serial.println("Starting the threshold analasis");

    while (millis() > EndTime)
    {
        int bubbleState = analogRead(bubblePin);

        maxVal = max(maxVal, bubbleState);

        minVal = min(minVal, bubbleState);
    }

    threshold = (maxVal + minVal) / 2;

    // Serial.println("ending the threshold analasis");
}

void bubbleCounter::run()
{
    //int debounceTime = 5;

    bool bubble;

    if (analogRead(bubblePin) > threshold)
    {
        bubble = true;

        //endTimeBubble = millis() + debounceTime;
    }

    else
    {
        bubble = false;
    }

    if (bubble != previousBubbleState)
    {
        if (bubble)
        {
            count++;
        }
    }

    previousBubbleState = bubble;
}