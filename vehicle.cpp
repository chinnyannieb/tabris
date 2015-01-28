#include <stdint-gcc.h>
#include "vehicle.h"

VehicleWithTwoDrivers::VehicleWithTwoDrivers(uint8_t AIA, uint8_t AIB, uint8_t BIA, uint8_t BIB) : AIA(AIA), AIB(AIB),
                                                                                                   BIA(BIA), BIB(BIB) {
    pinMode(AIA, OUTPUT);
    pinMode(AIB, OUTPUT);
    pinMode(BIA, OUTPUT);
    pinMode(BIB, OUTPUT);
}

unsigned long Vehicle::getDelayForDegrees(unsigned int degrees) {
    return degrees * 25;
}

void VehicleWithTwoDrivers::forward(uint8_t speed) {
    portAForward(speed);
    portBForward(speed);
}

void VehicleWithTwoDrivers::backward(uint8_t speed) {
    portABackwards(speed);
    portBBackwards(speed);
}

void VehicleWithTwoDrivers::turnLeft(unsigned int degrees) {
    unsigned long delayTime = this->getDelayForDegrees(degrees);

    portAForward(MAX_SPEED);
    portBBackwards(MAX_SPEED);
    delay(delayTime);
    stop();
}

void VehicleWithTwoDrivers::turnRight(unsigned int degrees) {
    unsigned long delayTime = this->getDelayForDegrees(degrees);

    portABackwards(MAX_SPEED);
    portBForward(MAX_SPEED);
    delay(delayTime);
    stop();
}

void VehicleWithTwoDrivers::portAForward(uint8_t speed) {
    analogWrite(AIA, speed);
    analogWrite(AIB, 0);
}

void VehicleWithTwoDrivers::portBForward(uint8_t speed) {
    analogWrite(BIA, 0);
    analogWrite(BIB, speed);
}

void VehicleWithTwoDrivers::portABackwards(uint8_t speed) {
    analogWrite(AIA, 0);
    analogWrite(AIB, speed);
}

void VehicleWithTwoDrivers::portBBackwards(uint8_t speed) {
    analogWrite(BIA, speed);
    analogWrite(BIB, 0);
}

void VehicleWithTwoDrivers::stop() {
    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
}
