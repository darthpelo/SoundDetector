#include <Arduino.h>

int micPin = A0;
int alertPin = 11;
int micValue0 = 0;
int micValue1 = 0;

int led0 = 3;
int led1 = 5;
int led2 = 7;

void setup() {
  pinMode(alertPin, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(micPin, INPUT);
  Serial.begin(9600);
}

int diff() {
  return micValue1-micValue0;
}

int invertDiff() {
  return micValue0-micValue1;
}

bool mayor(int value) {
  return diff() > value || invertDiff() > value;
}

bool equal(int value) {
  return diff() == value || invertDiff() == value;
}

void loop() {
  micValue0 = analogRead(micPin);
  Serial.println(micValue0);
  delay(1);
  micValue1 = analogRead(micPin);
  Serial.println(micValue1);

  if (equal(1)) {
    digitalWrite(led0, HIGH);
    delay(100);
  } else {
    digitalWrite(led0, LOW);
  }

  if (equal(2)) {
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    delay(100);
  } else {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
  }

  if (equal(3)) {
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(100);
  } else {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  if (mayor(3)) {
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(alertPin, HIGH);
    delay(100);
  } else {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(alertPin, LOW);
  }
}
