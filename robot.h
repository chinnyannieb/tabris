#ifndef ROBOT_H
#define ROBOT_H

#include "Arduino.h"
#include "ultrasonic.h"
#include "TimerOne.h"
#include "vehicle.h"
#include "math.h"

class Robot {
public:
    Robot(Ultrasonic *rangesensor, Vehicle *vehicle);

    void moveForward();

    void updateDistance();

private:
    Ultrasonic *rangesensor;
    Vehicle *vehicle;
    float currentDistance;
};

#endif