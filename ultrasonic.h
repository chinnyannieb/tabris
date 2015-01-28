#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

#define INFINITY_DISTANCE 250
#define MEASUREMENT_INTERVALS 100000

class Ultrasonic {
public:
    Ultrasonic(uint8_t echoPin, uint8_t triggerPin);

    float measureDistance();

private:
    uint8_t echoPin, triggerPin;

    float getDistanceFromDuration(long echoDuration);
};

#endif