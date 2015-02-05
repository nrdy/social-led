int lightPin[2] = {0, A0};              // list of lights corresponding with status and time arrays, 0 space reserved for error state in all arrays because of Spark function
int lightStatus[2];                     // track whether lights should be on or not
int lightTime[2];                       // track when light turns on up to time limit

// Global constants:
const int amtPins = 2;                  // amount of Pins +1 because '0' in array is reserved for error-state in Spark function
const int ms = 20;                      // define blink rate in milliseconds
const int hld = 500;                    // define time to hold lights in place each cycle in milliseconds
const int secs = 600;                 // define time to continue flashing lights after being triggered in seconds


int lightemup(String i) {
    int j = i.toInt();
    if (j == 0) {                       // returned by toInt() if the string could not be changed to an integer
        return -1;                      // NUMBERS!
    } else {
        lightStatus[j] = 1;             // set light to be on
        lightTime[j] = millis();        // store when the light came on, WARNING: millis() resets every 50 earth days, may cause problems.  If necessary, alter code or try on different planets.
        return 0;
    };
}

void setup() {
    Spark.function("light", lightemup); // pass the array index for the LED you wish to trigger, check out http://docs.spark.io/api/#introduction-calling-a-function if you don't know what this is.
    for (int x =1; x<= amtPins; x++) {
        pinMode(lightPin[x], OUTPUT);   // set pin for LEDs to output
    };
}

void loop() {
<<<<<<< HEAD
    for (int i =0; i < 255; i +=15)     // 'flicker-in effect': define 1st voltage variable, perform loop until greater than or equal to 255, increment by 15 each run
    {
        for (int x =1; x <= amtPins; x++) {         // do this for each defined pin
            if (lightStatus[x] == 1 && (millis()-lightTime[x]) <= (1000*secs)) {        // only light if the light has been triggered by 'lightemup' within the 'secs' time
                analogWrite(lightPin[x], i);        // write 1st voltage to LED 1
                delay(ms);                          // pause for 'ms' milliseconds
            } else if (lightStatus[x] == 1 && (millis()-lightTime[x]) > (1000*secs)) {  // if time 'secs' has passed, unset the light so it doesn't go off again until the light is triggered again
                lightStatus[x] = 0;
            };
        };
    };
    delay(hld);                         // defined wait
    for (int i =255; i >= 0; i-=15) {    // 'flicker-out effect': define 1st voltage variable for LED 1, perform loop until less than or equal to zero, decrement by 15 each run
        for (int x =1; x <= amtPins; x++) {
            if (lightStatus[x] == 1) {
                analogWrite(lightPin[x], i);        // write 1st voltage to LED 1
                delay(ms);                          // pause for 'ms' milliseconds
            };
        };
    };
    delay(hld);                         // hold the lights where they are for set time
}
=======
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
>>>>>>> origin/master
