#include "Arduino.h"
#include "NesController.h"

NesController::NesController(int clock, int latch, int datin)
{
      clockPin = clock;
      latchPin = latch;
      datinPin = datin;

      pinMode(latchPin,OUTPUT);
      pinMode(clockPin,OUTPUT);
      pinMode(datinPin,INPUT);
      digitalWrite(latchPin,HIGH);
      digitalWrite(clockPin,HIGH);
      
      buttonsState = lastButtonsState = 0;
}

void NesController::update()
{

    //set old buttons to current buttons
    lastButtonsState = buttonsState;
    
    digitalWrite(latchPin,LOW);
    digitalWrite(clockPin,LOW);

    digitalWrite(latchPin,HIGH);
    delayMicroseconds(2);
    digitalWrite(latchPin,LOW);
    
    buttonsState = !digitalRead(datinPin);
    for (int i = 1; i <= 7; i++) {
        digitalWrite(clockPin,HIGH);
        delayMicroseconds(2);
        buttonsState = (buttonsState << 1) + !digitalRead(datinPin);
        delayMicroseconds(4);
        digitalWrite(clockPin,LOW);
    }
}
boolean NesController::isAnyButtonPressed() {
    return buttonsState > 0 && lastButtonsState == 0;
}
boolean NesController::isDown(int button)
{
    return buttonsState & button;
}
boolean NesController::isPressed(int button)
{
    return (buttonsState & button) && !(lastButtonsState & button);
}
boolean NesController::isReleased(int button)
{
    return !(buttonsState & button) && (lastButtonsState & button);
}