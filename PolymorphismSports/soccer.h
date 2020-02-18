// soccer class

#ifndef H_Soccer
#define H_Soccer
#include "athlete.h"
#include <string>

using namespace std;

class soccer : public athlete   //deriving class from athlete
{
public:
    string scorePoints()    //unique scorePoints
    {
        return " I score points by kicking the ball into the net";
    }
    
    string move()   //unique move
    {
        return " I move by running around the field with my legs";
    }
    
};

#endif
