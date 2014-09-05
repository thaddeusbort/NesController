#ifndef NesController_h
#define NesController_h

#include "Arduino.h"

const byte NES_A      = 0x80;
const byte NES_B      = 0x40;
const byte NES_SELECT = 0x20;
const byte NES_START  = 0x10;
const byte NES_UP     =  0x8;
const byte NES_DOWN   =  0x4;
const byte NES_LEFT   =  0x2;
const byte NES_RIGHT  =  0x1;

class NesController {
      public:
            int clockPin;// set the clock pin   RED
            int latchPin;// set the latch pin   ORANGE
            int datinPin;// set the data in pin YELLOW

            NesController(int clock, int latch, int datin);
            void update();
            boolean isAnyButtonPressed();
            boolean isDown(int button);
            boolean isPressed(int button);
            boolean isReleased(int button);
      
      private:
            byte buttonsState;
            byte lastButtonsState;
};

#endif