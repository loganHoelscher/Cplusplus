#ifndef H_CircleType
#define H_CircleType
#include <iostream>
#include "pointType.h"

using namespace std;

class circleType: protected pointType
{
private:
    double pi = 3.1416;
    int radius;
    double area;
    double circumference;
public:
    void circlePrint();
    void setRadius(int);
    int getRadius();
    double getArea();
    double getCircumference();
};

#endif

