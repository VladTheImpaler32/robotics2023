// refer to 
// https://www.arduino.cc/reference/en/#variables


// Global Variables
bool myBool01 = false;
int myInt01 = 0;
int myInt02 = 0;
long myLong01 = 23452345;
long myLong02 = 2;
float myFloat01 = 34.23;
char myChar01 = 'F';
char myChar02 = 'T';
char myChar03 = ' ';
String myString = "Fred";
int myArray01[] = {1,2,3,4,5};
int loopcount = -1;
struct myStruct01{
       String myName;
       int age;
  };
// many more types of variables including advanced arrays and structs

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  int myLocal = 5;
}

void loop() {
  // put your main code here, to run repeatedly:
  int myLocal = 99;
  myInt01 += 1;
  myInt02 += 1 + myInt01;
  myBool01 = !myBool01;
  myFloat01 = myFloat01 + myInt01;
  loopcount += 1;
  
  if (myBool01 == true) {
    myChar03 = myChar02;
  } else {
    myChar03 = myChar01;
  }
  
  if (myInt02 % 2 == 0) {
    myString = "Even";
  } else {
    myString = "Odd";
  }

  Serial.println("Counting myInt02: " + String(myInt02));
  Serial.println("Counting myInt01: " + String(myInt01));
  Serial.println("myBool01: " + String(myBool01) );
  Serial.println("myLong01: " + String(myLong01) );
  Serial.println("myFloat01 + myInt01 : " + String(myFloat01,3) );
  Serial.println("myChar01: Is the Bool T of F?: " + String(myChar03));
  Serial.println("myString: Is myInt02 Even or Odd?: " + myString );  
  Serial.println("Why doesn't myLocal = 5 when it equals: " + String(myLocal));
  Serial.println("Array: " + String(myArray01[loopcount]));
  Serial.println(String(loopcount));

  if (loopcount > 3){
    loopcount = -1;
  }
  
  Serial.println("------------------------------------");
  Serial.println();
  delay(2000);
}
