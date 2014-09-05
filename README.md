NesController
=============

an arduino library that adds support for using an NES controller as an input device



## Usage

````
const int INPUT_NES_CONTROLLER_DATA     =  8;
const int OUTPUT_NES_CONTROLLER_LATCH   =  6;
const int OUTPUT_NES_CONTROLLER_CLOCK   =  7;
NesController nesController(OUTPUT_NES_CONTROLLER_CLOCK, OUTPUT_NES_CONTROLLER_LATCH, INPUT_NES_CONTROLLER_DATA);

void loop() {

  // check input controls
  nesController.update();

  // Listen for the Start button and then perform some action
  if(nesController.isPressed(NES_START)) {
    fireJelloCannon();
    Serial.println("Firing jello cannon");
  }
}
````
