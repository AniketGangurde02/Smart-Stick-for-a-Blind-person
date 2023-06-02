#define TRIGGER_PIN 2  // Ultrasonic sensor trigger pin
#define ECHO_PIN 3     // Ultrasonic sensor echo pin
#define BUZZER_PIN 4   // Buzzer pin

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  long duration, distance;
  
  // Send ultrasonic pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Measure echo response time
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Output distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Beep the buzzer based on distance
  if (distance <= 30) {
    // If object is within 100cm, beep continuously at a faster rate
    for (int i = 0; i < 5; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }
  } else if (distance > 30 && distance <= 40) {
    // If object is within 100-200cm, beep at a slower rate
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  } else {
    // If object is further than 200cm, no beep
    digitalWrite(BUZZER_PIN, LOW);
  }
}
