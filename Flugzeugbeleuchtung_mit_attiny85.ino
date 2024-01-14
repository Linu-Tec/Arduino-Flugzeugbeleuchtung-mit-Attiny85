int taxi = 2,
    TakeoffLanding = 3,
    Runwayturnoff = 4,
    Strobe = 0,
    Beacon = 1;

int ledPins[3] = {2, 3, 4};

int flashTimeouts[6] = {50, 50, 50, 400, 50, 400};
int flashBehaviour[2][6] = {{0, 0, 0, 0, 1, 0}, {1, 0, 1, 0, 0, 0}};
int flashPosition = 0;
long flashTimer = 0;

unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  pinMode(taxi, OUTPUT);
  pinMode(TakeoffLanding, OUTPUT);
  pinMode(Runwayturnoff, OUTPUT);
  pinMode(Strobe, OUTPUT);
  pinMode(Beacon, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  LEDan();
}

void LEDan(){
  digitalWrite(taxi, HIGH);
  digitalWrite(TakeoffLanding, HIGH);
  digitalWrite(Runwayturnoff, HIGH);
}

void LEDaus(){
  digitalWrite(taxi, LOW);
  digitalWrite(TakeoffLanding, LOW);
  digitalWrite(Runwayturnoff, LOW);
}

void blinken(){
  digitalWrite(Beacon, flashBehaviour[0][flashPosition]);
  digitalWrite(Strobe, flashBehaviour[1][flashPosition]);
  if(flashTimer + flashTimeouts[flashPosition] < millis()) {
    flashPosition++;
    flashTimer = millis();
    if (flashPosition > 5) flashPosition = 0;
  }
}

void loop() {
  blinken();
}
