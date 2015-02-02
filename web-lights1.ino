int funcState;
int lastFuncState;
const int ledPin = D0;

int lightemup(String command) {           // Lights on for IFTTT!
  digitalWrite(ledPin, HIGH);
  funcState = 1;
}

void setup() {
  Spark.function("light", lightemup);   // IFTTT can use this to light the light
  pinMode(ledPin, OUTPUT);
}

void loop() {
    static unsigned char ledState = LOW;
    static unsigned long ledCameOn = 0;
// If the LED has been on for at least 10 seconds then turn it off.
    if(ledState == HIGH) {
        if(millis()-ledCameOn > 10000) {
            digitalWrite(ledPin,LOW);
            ledState = LOW;
        }
    }
// If the button's state has changed, then turn the LED on IF it is not on already.
    if(funcState != lastFuncState) {
        lastFuncState = funcState;
        if((funcState == 1) && (ledState == LOW)) {
            digitalWrite(ledPin, HIGH);
            ledState = HIGH;
            ledCameOn = millis();
            }
        }
}
