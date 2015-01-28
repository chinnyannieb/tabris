#include "Arduino.h"
#include "ultrasonic.h"
#include "TimerOne.h"
#include "vehicle.h"

Ultrasonic *ultrasonic;
Vehicle *vehicle;
float distance = INFINITY_DISTANCE;

void updateDistance() {
    distance = ultrasonic->measureDistance();
}

void setup() {
    ultrasonic = new Ultrasonic(12, 13);
    vehicle = new VehicleWithTwoDrivers(3, 5, 6, 9);
    Timer1.initialize(MEASUREMENT_INTERVALS);
    Timer1.attachInterrupt(updateDistance);
}

void loop() {
    vehicle->forward(255);
    if (distance < 25) {
        vehicle->backward(200);
        delay(100);
        vehicle->turnLeft(45);
    }
}