#ifndef MATRIXSERVER_CUBETEST_H
#define MATRIXSERVER_CUBETEST_H

#include <CubeApplication.h>
#include "Joystick.h"
#include <vector>
#include <Mpu6050.h>
#include <string>
#include<iostream>
#include <ctime>
#include "Color2.h"

class CubeTest : public CubeApplication{
public:
    CubeTest();
    bool loop();
private:
    class Particle;
    class Drop;
    Mpu6050 Imu;
    Color actColors;
    std::vector<Color> allTheColors;
    std::vector<Color> allTheColorsRandom;
    std::vector<Joystick *> joysticks;
    std::vector<std::string> screenNames;

};

#endif //MATRIXSERVER_CUBETEST_H
