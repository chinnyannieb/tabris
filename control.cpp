#include "control.h"

Control::Control(uint8_t rx, uint8_t tx, Robot *robot) : robot(robot) {
    controlPort = new SoftwareSerial(rx, tx);
    controlPort->begin(9600);
    controlPort->setTimeout(SERIAL_TIMEOUT);
}

void Control::changeMode(int command) {
    if (command == 'm') {
        robot->manual();
        robot->stop();
    } else if (command == 'a') {
        robot->autonom();
    }
}

void Control::run() {
    processCommands();
    if (robot->isAutonomus()) {
        robot->moveForward();
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

void Control::reactOnCommand(int command) {
    if (command == 'm' || command == 'a') {
        changeMode(command);
    } else if (!robot->isAutonomus() && (command == 'f' || command == 'b' || command == 'l' || command == 'r')) {
        manualDrive(command);
    }
    controlPort->println("OK");
}

void Control::processCommands() {
    while (controlPort->available() > 0) {
        reactOnCommand(controlPort->read());
    }
}
