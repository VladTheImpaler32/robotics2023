
// Global Variables
int myCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  myCount += 1; 
  Serial.println("myCount: " + String(myCount) );
  Serial.println("LED is on when loop is even");
  for (int myLoop=0; myLoop <= myCount; myLoop++){
    if (myLoop % 5 == 0) {
      Serial.println();
    }
    if (myLoop % 2 == 0){
      Serial.print(myLoop);
      Serial.print(" is Even");
      digitalWrite(LED_BUILTIN, LOW);
    } else {
      Serial.print(myLoop);
      Serial.print(" is Odd");
      digitalWrite(LED_BUILTIN, HIGH); 
    }
    Serial.print(", ");  
  }
  Serial.println();
  Serial.println("-----------------------------" );
  Serial.println();
  delay(2000);

}
