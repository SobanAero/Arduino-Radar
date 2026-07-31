#include <Servo.h>

Servo radarServo;

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 10;

long duration;
int distance;

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 400;
  }

  return duration * 0.034 / 2;
}

void setup() {

  Serial.begin(9600);

  radarServo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  for (int angle = 0; angle <= 180; angle++) {

    radarServo.write(angle);
    delay(20);

    distance = getDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

  for (int angle = 180; angle >= 0; angle--) {

    radarServo.write(angle);
    delay(20);

    distance = getDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}