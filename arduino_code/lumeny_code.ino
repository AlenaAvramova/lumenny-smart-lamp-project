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
/*int threshold = 500; // ще го нагласим

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightValue = analogRead(ldrPin);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | Motion: ");
  Serial.println(motion);

  // Условие: движение + тъмно
  if (motion == HIGH && lightValue < threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}*/