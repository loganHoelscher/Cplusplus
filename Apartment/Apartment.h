//Class Apartment

#ifndef H_Apartment
#define H_Apartment
using namespace std;

class Apartment
{
private:
    int rooms;
    int rent;
    int sqfeet;
    double pricePerFoot;
public:
    void print();
    void printAgain();
    void check();
    void setRooms(int);
    void setRent(int);
    void setSqfeet(int);
    int getRooms();
    int getRent();
    int getSqfeet();
};

#endif
