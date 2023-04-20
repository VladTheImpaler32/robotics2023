#include <AccelStepper.h>

// ULN2003 Motor Driver Pins
#define M11 16
#define M12 5
#define M13 4
#define M14 0
#define sensor1 14
#define M21 12
#define M22 13
#define M23 15
#define M24 3
#define sensor2 1

//init stepper
//AccelStepper stepper1(AccelStepper::FULL4WIRE, M14, M12, M13, M11);
//AccelStepper stepper2(AccelStepper::FULL4WIRE, M24, M22, M23, M21);
AccelStepper stepper[2] = {
  AccelStepper(AccelStepper::FULL4WIRE, M14, M12, M13, M11),
  AccelStepper(AccelStepper::FULL4WIRE, M24, M22, M23, M21),
};

//setup variables
int sensorVal[2];
char serialInput;
char letters[40] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '?', '!', ' '};
int sensor[2] = {sensor1, sensor2};

void setup() {
  Serial.begin(115200);
  WiFiSetup();

  for (int i=0; i<sizeof(sensor); i++){
    pinMode(sensor[i], INPUT);
    
    stepper[i].setMaxSpeed(1000);
    stepper[i].setAcceleration(1000);
  
    sensorVal[i] = digitalRead(sensor[i]);
    calibrate();
  }
}

void loop() {
  WiFiLoop();
}

void goTo(char input) {
  for (int j=0; j<sizeof(stepper); j++){
    for (int i=0; i<39; i++){
      if (input == letters[i]){
        Serial.println(String(letters[i]) + " At position " + String(i*102));
        stepper[j].moveTo(i*51);
        while (stepper[j].currentPosition() % 2048 != i*51){
          yield();
          stepper[j].setSpeed(500);
          stepper[j].runSpeed();
        }
      }
    }
  }
}

void calibrate() {
  for (int i=0; i<sizeof(stepper); i++){
    sensorVal[i] = digitalRead(sensor[i]);
    Serial.println("Calibrating...");
    stepper[i].move(4096);
    while (sensorVal[i] == HIGH){
      yield();
      stepper[i].run();
      sensorVal[i] = digitalRead(sensor[i]);
      if (stepper[i].distanceToGo() == 0){
        stepper[i].move(4096);
      }
    }
    stepper[i].setCurrentPosition(0);
    Serial.println("Done Calibrating");
    return;
  }
}
