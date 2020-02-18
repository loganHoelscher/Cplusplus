//*****************************************************
// Polymorphism Sports
// Logan Hoelscher
// September 21, 2018
//
// The purpose of this program is to practice
// polymorphism and object oriented programming.
// The two virtual functions scorePoints and move are
// initially left undefined, which allows them to be used
// in multiple ways depending on the specific sport. 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Input: There is no input from the user for this 
// program.
//
// Output: The output of this program is the specific
// sport, the way you score points in that sport, and the
// way you move around in that sport.
//*****************************************************

#include <iostream>
#include "athlete.h"
#include "soccer.h"
#include "football.h"
using namespace std;


int main()
{
	soccer s;	//class soccer object
	football f;	//class footbal object
	
	athlete *a1 = &s;	//assign athlete pointer to s object address
	athlete *a2 = &f;	// assign athlete pointer to f object address
	
	a1->setSport("Soccer");	//set name of sport
	a2->setSport("Football");
	
	s.print();	//call print function and display string values
	cout << s.scorePoints() << endl;
	cout << s.move() << endl << endl;
	
	f.print();	//call print function and display string values
	cout << f.scorePoints() << endl;
	cout << f.move() << endl;
	
	
}

// defining the setSport function
void athlete::setSport(string sprt)
	{ sport = sprt; }

// providing the template in which the sport name will
// be displayed to the user
void athlete::print() const
{
	cout << " I am a " << sport << " player," << endl;
}

// return the string in the sport variable
string athlete::getSport()const
	{ return sport; }

// returning the string defined in scorePoints()
string athlete::scorePoints()
	{ return ""; }

// returning the string defined in move()
string athlete::move()
	{ return ""; }

// defining the string in athlete constructor
athlete::athlete(string sprt)
	{ setSport(sprt); }
