#define SENSOR_PIN       A0
#define LED_PIN           8
#define BUZZER_PIN        9
#define SMOKE_THRESHOLD  550

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smoke Detector Ready!");
}

void loop() {
  int val = analogRead(SENSOR_PIN);
  Serial.print("Sensor: ");
  Serial.print(val);

  if (val > SMOKE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    Serial.println(" → SMOKE DETECTED!");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println(" → Clear");
  }

  delay(300);
}