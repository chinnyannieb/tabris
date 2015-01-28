#include "Arduino.h"
#include "ultrasonic.h"
#include "TimerOne.h"
#include "vehicle.h"

#define NORMAL_SPEED 128
#define MIN_DISTANCE 45

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
    vehicle->forward(NORMAL_SPEED);
    if (distance <= MIN_DISTANCE) {
        vehicle->backward(NORMAL_SPEED/2);
        vehicle->turnLeft(45);
    }
}