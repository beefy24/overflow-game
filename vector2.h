#include <iostream>
#include <limits>
#pragma once

using namespace std;

const short SHORT_INT_MIN = numeric_limits<short>::min();
const short SHORT_INT_MAX = numeric_limits<short>::max();

struct Vector2
{
    short x {};
    short y {};
    
    //inline - the call of this function will be replaced with the function's code.
    static inline Vector2 getRandomVector();
    static inline Vector2 getRandomVectorNearOverflow(short distanceMin, short distanceMax);
};

Vector2 Vector2::getRandomVector()
{
    int sign = (rand() % 2) ? 1 : -1;
    short randomX = (rand() % (SHORT_INT_MAX + 1)) * sign;

    sign = (rand() % 2) ? 1 : -1;
    short randomY = (rand() % (SHORT_INT_MAX + 1)) * sign;

    return {randomX, randomY};
}

Vector2 Vector2::getRandomVectorNearOverflow (short distanceMin, short distanceMax)
{
    Vector2 randomPosition = getRandomVector();

    int sign = (rand() % 2) ? 1 : -1;
    short randomDistance = ((rand() % (distanceMax-distanceMin+1)) + distanceMin) * (-sign);
    short newPositionXOrY = (SHORT_INT_MAX * sign) + randomDistance;

    sign = rand() % 2;
    if (sign) { randomPosition.x = newPositionXOrY; } else { randomPosition.y = newPositionXOrY; }

    return randomPosition;
}