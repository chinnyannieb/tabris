#include "ultrasonic.h"
#include "Arduino.h"

Ultrasonic::Ultrasonic(uint8_t echoPin, uint8_t triggerPin) : echoPin(echoPin), triggerPin(triggerPin) {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Ultrasonic::measureDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long echoDuration = pulseIn(echoPin, HIGH);
    return this->getDistanceFromDuration(echoDuration);
}

float Ultrasonic::getDistanceFromDuration(long echoDuration) {
    float distance = echoDuration / 29 / 2;
    if (distance > INFINITY_DISTANCE) {
        distance = INFINITY_DISTANCE;
    }

    return distance;
}
