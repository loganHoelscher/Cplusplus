//**********************************************************
// Circle Area and Circumference Calculator
// Logan Hoelscher
// 9/13/2018
// 
// This program asks the user to enter an x coordinate
// and a y coordinate and sets that input as the center of the 
// circle. The user is then prompted to give the radius of the
// circle. This information is then used to calculate the area
// and the circumference of the circle.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Input: The user intputs 3 total integers- and x coordinate
// a y coordinate, and a radius for the circle.
//
// Output: The program processes the input and spits out the
// current position of the circle's center, the radius of the
// circle, then finally the area and circumference of the
// circle.
//**********************************************************

#include <iostream>
#include <cmath>
#include "pointType.h"
#include "circleType.h"

using namespace std;


int main()
{
	pointType p;
	circleType c;
	
	p.getxpoint();
	p.getypoint();
	p.print();
	
	c.getRadius();
	c.getArea();
	c.getCircumference();
	c.circlePrint();
}
//***********************************************************
//       This code is for the pointType implementation


//function to display the values of the x & y coordinates
void pointType::print()
{
	cout << "The x coordinate is: " << xpoint << endl;
	cout << "The y coordinate is: " << ypoint << endl;
	
	cout << "The center of your circle is located at: ";
	cout << "(" << xpoint << ", " << ypoint << ")" << endl << endl;
	
}

// set x coordinate
void pointType::setxpoint(int x)
{
	xpoint = x;
}

// set y coordinate
void pointType::setypoint(int y)
{
	ypoint = y;
}

//get x coordinate
int pointType::getxpoint()
{
	cout << "Enter the x coordinate: " << endl;
	cin >> xpoint;
	return xpoint;
}

//get y coordinate
int pointType::getypoint()
{
	cout << "Enter the y coordinate: " << endl;
	cin >> ypoint;
	return ypoint;
}

//****************************************************************
//          This code is for the circleType implementation



//print function to display the values stored in the circle variables
void circleType::circlePrint()
{
	cout << "The radius of your circle is: " << radius << endl;
	cout << "Given this information, I can find the area and circumference of your circle!" << endl << endl;
	
	cout << "Area = " << area << endl;
	cout << "Circumference = " << circumference << endl;
}


//set radius value to r
void circleType::setRadius(int r)
{
	radius = r;
}

//get the value of the radius from the user
int circleType::getRadius()
{
	cout << "Enter the radius of the circle: " << endl;
	cin >> radius;
	return radius;
}

// function to execute the formula for the area of a circle
double circleType::getArea()
{
	area = pi * pow(radius, 2);
	return area;
}

// function to execute the formula for the circumference of a circle
double circleType::getCircumference()
{
	circumference = 2 * pi * radius;
	return circumference;
}











