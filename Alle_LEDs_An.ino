int taxi = 2,
    TakeoffLanding = 3,
    Runwayturnoff = 4,
    Strobe = 0,
    Beacon = 1;


void setup() {
  pinMode(taxi, OUTPUT);
  pinMode(TakeoffLanding, OUTPUT);
  pinMode(Runwayturnoff, OUTPUT);
  pinMode(Strobe, OUTPUT);
  pinMode(Beacon, OUTPUT);

  digitalWrite(taxi, HIGH);
  digitalWrite(TakeoffLanding, HIGH);
  digitalWrite(Runwayturnoff, HIGH);
  digitalWrite(Strobe, HIGH);
  digitalWrite(Beacon, HIGH);
}

void loop() {
  
}
