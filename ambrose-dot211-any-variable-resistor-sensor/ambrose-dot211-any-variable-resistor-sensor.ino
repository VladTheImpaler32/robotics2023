#include <Arduino.h>  // only needed for https://platformio.org/

void setup(){  
  // 8:0-255   10: 0-1023,  12 : 0-4095, 16 : 0-65535
  //analogReadResolution(10);   // 10 default Range 0-1023
  Serial.begin(115200);
  
}

void loop() {

  Serial.println("Resolution 10, Max = 1023, Analog Read A0: " + String(analogRead(A0)) );
  delay(1000);    // wait a bit
                  
}
