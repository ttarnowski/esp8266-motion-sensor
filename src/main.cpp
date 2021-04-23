#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(D2, OUTPUT);
  delay(5000);
}

// no mov -> mov
unsigned long t1;

// mov -> no mov
unsigned long t2;

int prevState = LOW;

void loop() {
  int currentState = digitalRead(D1);

  if (currentState != prevState) {
    if (currentState == HIGH) {
      Serial.println("movement detected");
      digitalWrite(D2, HIGH);
      t2 = millis();
      Serial.print("no mov -> mov time:");
      Serial.println(millis() - t1);
    } else {
      Serial.println("no movement detected");
      digitalWrite(D2, LOW);
      Serial.print("mov -> no mov time:");
      Serial.println(millis() - t2);
      t1 = millis();
    }
  }

  prevState = currentState;
}