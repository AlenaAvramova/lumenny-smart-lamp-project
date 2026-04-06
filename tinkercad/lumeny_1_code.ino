const int pirPin = 13;
const int ledPin = 3;
const int ldrPin = A0;

unsigned long lastMotionTime = 0;
bool isOn = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int motion = digitalRead(pirPin);
  int light = analogRead(ldrPin);

  if (motion == HIGH && light < 500) {
    digitalWrite(ledPin, HIGH);
    lastMotionTime = millis();
    isOn = true;
  }
  if (isOn && millis () - lastMotionTime >= 8000) {
    digitalWrite(ledPin, LOW);
    isOn = false;
  }
}