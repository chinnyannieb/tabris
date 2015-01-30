#include "Arduino.h"
#include "ultrasonic.h"
#include "vehicle.h"
#include "robot.h"

Robot *robot;

void updateDistance() {
    robot->updateDistance();
}

void setup() {
    Ultrasonic *ultrasonic = new Ultrasonic(12, 13);
    Vehicle *vehicle = new VehicleWithTwoDrivers(3, 5, 6, 9);
    robot = new Robot(ultrasonic, vehicle);

    Timer1.initialize(MEASUREMENT_INTERVALS);
    Timer1.attachInterrupt(updateDistance);
}

void loop() {
    robot->moveForward();
}