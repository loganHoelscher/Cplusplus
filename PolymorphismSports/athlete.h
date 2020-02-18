// Class athlete

#ifndef H_Athlete
#define H_Athlete
#include <string>

using namespace std;

class athlete
{
public:
    void print() const;
    void setSport(string sprt);
    string getSport() const;
    virtual string scorePoints();
    virtual string move();
    athlete(string sprt = "");
    
protected:
    string sport;
    
    
};

#endif
