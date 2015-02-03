#ifndef CONTROL_H
#define CONTROL_H

#include "Arduino.h"
#include "robot.h"

class Control {

public:
    Control(uint8_t rx, uint8_t tx, Robot *robot);

    void changeMode();

    void run();

private:
    SoftwareSerial *controlPort;
    Robot *robot;

    void manualDrive(int command);

    void stepForward();

    void stepBackwards();

    void delayAndStop(unsigned long delayInterval);
};

#endif