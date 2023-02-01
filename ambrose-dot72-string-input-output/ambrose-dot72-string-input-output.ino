// Beginner C++ Programming String Input and Output
// You will need to open the Serial monitor and type the word "Hi" then click "send"

/*
* Note: The F() macro can move a pure string into flash instead of RAM
* That can be a seriaous help when you have used up all your RAM memory.
*
Serial.println(F(“Hello World”));
*
* Another commonly used and efficient output method is "printf":
*
int x = 40;
float y = 34.2745;
Serial.printf("Int is: %d and Float is %.2f \n", x, y);
*
* %.2f restrict a float number to just two digits after the decimal point in Arduino IDE.
*
* As you will see I use String() to wrap all outputs, not efficient but easy to get started.
*
*/



//Global Variables
String myIncoming = "";
int myLocation1 = 0;
int myLocation2 = 0;
int myLocation3 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // I don't typically use the following
   while (!Serial) {};   // waits for the serial monitor to be attached

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter something");
  while (Serial.available() == 0){} //waits until enter key pushed
  
  myIncoming = Serial.readString();
  Serial.println("You entered : " + String(myIncoming));

  // other string funcitons at 
  // https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
  myIncoming.toLowerCase(); 
  myLocation1 = myIncoming.indexOf("gman");
  myLocation2 = myIncoming.indexOf("gordon");
  myLocation3 = myIncoming.indexOf("barney");  
  
  if(myLocation1 >= 0){  // -1 means nothing found
     Serial.println("You entered gman at location: " + String(myLocation1));
  } else {
     Serial.println("You did not enter gman" );
  }

    if(myLocation2 >= 0){  // -1 means nothing found
     Serial.println("You entered gordon at location: " + String(myLocation2));
  } else {
     Serial.println("You did not enter gordon" );
  }

  if(myLocation3 >= 0){  // -1 means nothing found
     Serial.println("You entered barney at location: " + String(myLocation3));
  } else {
     Serial.println("You did not enter barney" );
  }
  myIncoming = "";
  Serial.println("----------------------------------");

  
}
