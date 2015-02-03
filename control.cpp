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
    } else if (controlPort->available()) {
        int command = controlPort->read();
        manualDrive(command);
    }
}

void Control::manualDrive(int command) {
    if (command == 'f') {
        stepForward();
    } else if (command == 'b') {
        stepBackwards();
    } else if (command == 'l') {
        robot->getVehicle()->turnLeft(45);
    } else if (command == 'r') {
        robot->getVehicle()->turnRight(45);
    }
}

void Control::stepBackwards() {
    robot->getVehicle()->backward(255);
    delayAndStop(300);
}

void Control::stepForward() {
    robot->getVehicle()->forward(255);
    delayAndStop(300);
}

void Control::delayAndStop(unsigned long delayInterval) {
    delay(delayInterval);
    robot->stop();
}
