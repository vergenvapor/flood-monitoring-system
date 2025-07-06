// Flood Monitoring System Simulation
#define TRIG_PIN 9
#define ECHO_PIN 8
#define ALERT_LED 7

// Simulated water level threshold in cm (lower distance = higher water)
#define FLOOD_LEVEL_THRESHOLD 15.0

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ALERT_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Flood Monitoring System Started...");
}

void loop() {
  float distance = measureDistance();

  Serial.print("Water Level Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < FLOOD_LEVEL_THRESHOLD) {
    Serial.println("⚠️ ALERT: Water level too high!");
    digitalWrite(ALERT_LED, HIGH);
    sendToCloud(distance);  // Simulate sending data to cloud
  } else {
    digitalWrite(ALERT_LED, LOW);
  }

  delay(2000);  // Wait for 2 seconds before next reading
}

// Function to measure distance using HC-SR04
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

// Simulated cloud function
void sendToCloud(float level) {
  // This would be an HTTP request in a real system.
  Serial.print("📡 Sending water level ");
  Serial.print(level);
  Serial.println(" cm to cloud...");
}
