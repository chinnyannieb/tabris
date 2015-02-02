#include "control.h"

Control::Control(uint8_t rx, uint8_t tx, Robot *robot) : robot(robot) {
    controlPort = new SoftwareSerial(rx, tx);
    controlPort->begin(9600);
}

void Control::changeMode() {
    if (controlPort->available()) {
        int command = controlPort->read();
        if (command == 'm') {
            robot->manual();
            robot->stop();
            controlPort->println("MANUAL-OK");
        } else if (command == 'a') {
            robot->autonom();
            controlPort->println("AUTO-OK");
        }
    }
}

void Control::run() {
    changeMode();
    if (robot->isAutonomus()) {
        robot->moveForward();
    }
}
