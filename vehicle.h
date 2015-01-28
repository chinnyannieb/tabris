#ifndef VEHICLE_H
#define VEHICLE_H

#include "Arduino.h"

#define MAX_SPEED 255

class Vehicle {
public:
    virtual void forward(uint8_t speed) = 0;

    virtual void backward(uint8_t speed) = 0;

    virtual void turnLeft(unsigned int degrees) = 0;

    virtual void turnRight(unsigned int degrees) = 0;

    virtual void stop() = 0;

    unsigned long getDelayForDegrees(unsigned int degrees);
};

//Motor driver with two ports
class VehicleWithTwoDrivers : public Vehicle {
public:
    VehicleWithTwoDrivers(uint8_t AIA, uint8_t AIB, uint8_t BIA, uint8_t BIB);

    void forward(uint8_t speed);

    void backward(uint8_t speed);

    void turnLeft(unsigned int degrees);

    void turnRight(unsigned int degrees);

    void stop();

private:
    const uint8_t AIA;
    const uint8_t AIB;
    const uint8_t BIA;
    const uint8_t BIB;

    void portAForward(uint8_t speed);

    void portBForward(uint8_t speed);

    void portABackwards(uint8_t speed);

    void portBBackwards(uint8_t speed);
};

#endif