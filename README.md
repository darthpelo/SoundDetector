# SoundDetector
Ispired by Robotix lesson on [youtube](https://youtu.be/jrK9pda1TiY).

Developed using [platformio](http://platformio.org).

## 🤖 Schema
![schema](https://github.com/darthpelo/SoundDetector/blob/master/lib/Fritzing/sketch_bb.png)

## 🤓 Code

The main logic is in the `main.cpp` file.

The setup (libraries, variables, pins etc)

```swift
#include <Arduino.h>
#include <Helper.h>

int micPin = A0;
int alertPin = 11;
int micValue0 = 0;
int micValue1 = 0;

int led0 = 3;
int led1 = 5;
int led2 = 7;

Helper helper;

void setup() {
  pinMode(alertPin, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(micPin, INPUT);
  Serial.begin(9600);
}

```

Some useful functions to compare values

```swift
bool mayor(int value) {
  return helper.diff() > value;
}

bool equal(int value) {
  return helper.diff() == value;
}

void high(int arg[]) {
  for( unsigned int a = 0; a < sizeof(arg)/sizeof(arg[0]); a = a + 1 ) {
    digitalWrite(arg[a], HIGH);
  }
}

void low(int arg[]) {
  for( unsigned int a = 0; a < sizeof(arg)/sizeof(arg[0]); a = a + 1 ) {
    digitalWrite(arg[a], LOW);
  }
}
```

The loop where we compare two sound samples from the microphone to decide the volume level and how many LEDs turn on/off

```swift
void loop() {
  micValue0 = analogRead(micPin);
  delay(1);
  micValue1 = analogRead(micPin);

  helper.setValues(micValue0, micValue1);

  if (equal(1)) {
    int leds[] = {led0};
    high(leds);
    delay(100);
  } else {
    int leds[] = {led0};
    low(leds);
  }

  if (equal(2)) {
    int leds[] = {led0, led1};
    high(leds);
    delay(100);
  } else {
    int leds[] = {led0, led1};
    low(leds);
  }

  if (equal(3)) {
    int leds[] = {led0, led1, led2};
    high(leds);
    delay(100);
  } else {
    int leds[] = {led0, led1, led2};
    low(leds);
  }

  if (mayor(3)) {
    int leds[] = {led0, led1, led2, alertPin};
    high(leds);
    delay(100);
  } else {
    int leds[] = {led0, led1, led2, alertPin};
    low(leds);
  }
}
```

Inside the folder `/lib/Helper` a simple Helper class.

## 📹 Demo
[Video](https://vimeo.com/209011151)
