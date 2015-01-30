#include "control.h"

Control::Control(uint8_t rx, uint8_t tx, Robot *robot) : robot(robot) {
    controlPort = new SoftwareSerial(rx, tx);
}

void Control::changeMode() {
    if (controlPort->available()) {
        String command = controlPort->readString();
        if (command.equals("MANUAL")) {
            robot->manual();
            robot->stop();
        } else if (command.equals("AUTO")) {
            robot->autonom();
        }
    }
}

void Control::run() {
    changeMode();
    if (robot->isAutonomus()) {
        robot->moveForward();
        controlPort->print("Distance: ");
        controlPort->println(robot->getDistance());
    }
}
