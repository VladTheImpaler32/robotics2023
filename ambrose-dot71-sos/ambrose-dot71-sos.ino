int sos[] = {1,1,1,2,2,2,1,1,1};
void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  for (int i=0; i<sizeof(sos)/sizeof(sos[0]); i++){
      digitalWrite(LED_BUILTIN, LOW);
      delay(sos[i]*500);
      digitalWrite(LED_BUILTIN, HIGH);           
      delay(sos[i]*250);
  }
    delay(5000);
}

    // make the LED flash an SOS then wait 5 seconds and repeat
    // Who can do it in as few lines as possible!!
    // each command on it's own line
