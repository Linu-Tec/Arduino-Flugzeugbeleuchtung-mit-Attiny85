// https://starthardware.org/flugzeugbeleuchtung-mit-arduino/

//  0    ,   1   ,  2  ,         3          ,      4
// Strobe, Beacon, Taxi, Takeoff und Landing, Runway turn off
int ledPins[5] = {0, 1, 2, 3, 4};
int buttonPin = 14;   // entspricht dem Analog In 0 (A0)

int beleuchtungsZustaende[8][5] = {
  {0, 0, 0, 0, 0},  // state 0 Grounded
  {0, 1, 1, 1, 1},  // state 1 Taxi
  {1, 1, 1, 1, 0},  // state 2 Takeoff
  {1, 1, 0, 1, 0},  // state 3 Climbing
  {1, 1, 0, 0, 0},  // state 4 In Flight
  {1, 1, 0, 1, 0},  // state 5 Landing
  {0, 1, 1, 1, 1},  // state 6 Taxi
  {0, 1, 1, 0, 1}   // state 7 Grounded
};

int flashTimeouts[6] = {50, 50, 50, 400, 50, 400};
int flashBehaviour[2][6] = {{0, 0, 0, 0, 1, 0}, {1, 0, 1, 0, 0, 0}};
int flashPosition = 0;
long flashTimer = 0;
int myState = 0;

unsigned long previousMillis = 0;
const long interval = 10000;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}


void zeigeBeleuchtung() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], beleuchtungsZustaende[myState][i]);
  }
  if (beleuchtungsZustaende[myState][0] == 1) {
    digitalWrite(ledPins[0], flashBehaviour[1][flashPosition]);
    if (flashTimer + flashTimeouts[flashPosition] < millis()) {
      flashPosition++;
      flashTimer = millis();
      if (flashPosition > 5) flashPosition = 0;
    }
  }
  if (beleuchtungsZustaende[myState][1] == 1) {
    digitalWrite(ledPins[1], flashBehaviour[0][flashPosition]);
    if (flashTimer + flashTimeouts[flashPosition] < millis()) {
      flashPosition++;
      flashTimer = millis();
      if (flashPosition > 5) flashPosition = 0;
    }
  }
}


void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    
    myState++;
    flashTimer = millis();
    flashPosition = 0;
    if (myState >= 8) myState = 0;
  }
  zeigeBeleuchtung();
  delay(10);
}
