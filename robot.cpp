#include "robot.h"

Robot::Robot(Ultrasonic *rangesensor, Vehicle *vehicle) : rangesensor(rangesensor), vehicle(vehicle) {
    currentDistance = INFINITY_DISTANCE;
    autonomus = true;
}

void Robot::updateDistance() {
    currentDistance = rangesensor->measureDistance();
}

void Robot::moveForward() {
    vehicle->forward(255);
    if (currentDistance < 25) {
        vehicle->backward(200);
        delay(100);

        long turnLeftOrRight = random(0, 10);
        if (turnLeftOrRight <= 5) {
            vehicle->turnLeft(45);
        } else {
            vehicle->turnRight(45);
        }
    }
}

void Robot::stop() {
    vehicle->stop();
}

bool Robot::isAutonomus() {
    return autonomus;
}

void Robot::autonom() {
    autonomus = true;
}

void Robot::manual() {
    autonomus = false;
    stop();
}

float Robot::getDistance() {
    return currentDistance;
}
