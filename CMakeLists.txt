# Set a variable for commands below
set(PROJECT_NAME robot)

# Define your project and language
project(${PROJECT_NAME} C CXX)

set(${PROJECT_NAME}_BOARD uno)

# Define the source code
set(${PROJECT_NAME}_SRCS ultrasonic.cpp vehicle.cpp entrypoint.cpp robot.cpp TimerOne.cpp control.cpp)

# Define the port for uploading code to the Arduino
set(${PROJECT_NAME}_PORT /dev/ttyACM0)

link_directories(${ARDUINO_SDK}/SoftwareSerial/)
# Command to generate code arduino firmware (.hex file)
generate_arduino_firmware(${PROJECT_NAME})