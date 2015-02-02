#ifndef ROBOT_H
#define ROBOT_H

#include "Arduino.h"
#include "ultrasonic.h"
#include "TimerOne.h"
#include "vehicle.h"
#include "math.h"
#include "SoftwareSerial.h"

class Robot {
public:
    Robot(Ultrasonic *rangesensor, Vehicle *vehicle);

    void moveForward();

    void updateDistance();

    void stop();

    bool isAutonomus();

    void manual();

    void autonom();

    float getDistance();
private:
    Ultrasonic *rangesensor;
    Vehicle *vehicle;
    float currentDistance;
    bool autonomus;
};

#endif