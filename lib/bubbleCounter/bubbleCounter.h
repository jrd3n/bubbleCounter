#ifndef bubbleCounter_h
#define bubbleCounter_h

#include <Arduino.h>

class bubbleCounter
{
public:
  bubbleCounter(int pinNo);
  void run();
  unsigned int count = 0;

private:
  bool previousBubbleState;
  int bubblePin;
  int threshold;
};

// the #include statment and code go here...

#endif