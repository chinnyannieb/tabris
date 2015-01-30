#include "Arduino.h"
#include "ultrasonic.h"
#include "vehicle.h"
#include "robot.h"
#include "control.h"

Robot *robot;
Control *control;

void updateDistance() {
    robot->updateDistance();
}

void setup() {
    Ultrasonic *ultrasonic = new Ultrasonic(12, 13);
    Vehicle *vehicle = new VehicleWithTwoDrivers(3, 5, 6, 9);
    robot = new Robot(ultrasonic, vehicle);
    control = new Control(7, 8, robot);

    Timer1.initialize(MEASUREMENT_INTERVALS);
    Timer1.attachInterrupt(updateDistance);
}

void loop() {
    control->run();
}