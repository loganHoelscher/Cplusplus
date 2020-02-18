/***************************************** 
* Logan Hoelscher
* September 2018
* 
* This program is a tool for students looking
* to rent an apartment. It calculates and 
* compares the price per square foot of 
* on campus apartments and off campus
* apartments. It also displays the number
* of rooms and whether or not the apartment
* is pet friendly
*****************************************/


#include <iostream>
#include <string>
#include "Apartment.h"
using namespace std;

int main()
{
    Apartment onCampus;
    Apartment offCampus;
    
    onCampus.getRooms();
    onCampus.getRent();
    onCampus.getSqfeet();
    onCampus.print();
    
    cout << endl << "Now enter the information for your off campus apartment!" << endl<< endl;
    
    offCampus.getRooms();
    offCampus.getRent();
    offCampus.getSqfeet();
    offCampus.printAgain();
	onCampus.check();
	
	
}

void Apartment::print()
{
    cout << "The amount of rooms in your apartment: " << rooms << endl;
    cout << "The monthly rent for your apartment: $" << rent << endl;
    cout << "The square footage of your apartment: " << sqfeet << endl;
    
    pricePerFoot = sqfeet/rent;
    cout << "The cost per square foot of your apartment: $" << pricePerFoot << endl;
    
    cout << endl << "Pets are not allowed here :( " << endl;
    cout << endl << "Also, there's no washer and dryer so I hope you got some quarters mate " << endl;
}
    
void Apartment::printAgain()
    {
        cout << "The amount of rooms in your apartment: " << rooms << endl;
        cout << "The monthly rent for your apartment: $" << rent << endl;
        sqfeet += 150;
        cout << "The square footage of your apartment: " << sqfeet << endl;
        
        pricePerFoot = sqfeet/rent;
        cout << "The cost per square foot of your apartment is: $" << pricePerFoot << endl;
        
        cout << endl << "Your pets are allowed here :)" << endl;
        cout << endl << "Each unit is equipped with a washer and dryer" << endl;
		
        
    }

void Apartment::setRooms(int r)
    {
        rent = r;
    }
void Apartment::setRent(int mr)
    {
        rent = mr;
    }
void Apartment::setSqfeet(int sf)
    {
        sqfeet = sf;
    }

int Apartment::getRooms()
    {
        cout << "How many rooms would you like? " << endl;
        cin >> rooms;
        return rooms;
    }
    
int Apartment::getRent()
    {
        cout << "Please enter your desired rent per month: " << endl;
        cin >> rent;
        return rent;
    }
    
int Apartment::getSqfeet()
    {
        cout << "Enter your desired square footage: " << endl;
        cin >> sqfeet;
        return sqfeet;
    }
	void Apartment::check()
	{
		Apartment onCampus;
		Apartment offCampus;
		
		if(onCampus.rooms = offCampus.rooms)
		{
			cout << "* Both apartments have the same number of rooms! *" << endl;
		}
		
		if(onCampus.rent = offCampus.rent)
		{
			cout << "* Both apartents have the same rent per month! *" << endl;
		}
		
		if(onCampus.sqfeet = offCampus.sqfeet)
		{
			cout << "* Both apartments have the same square feet! * " << endl;
		}
		
	}









