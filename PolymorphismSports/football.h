// football class

#ifndef H_Football
#define H_Football
#include "athlete.h"
#include <string>

using namespace std;


class football : public athlete //deriving class from athlete
{
public:
    string scorePoints()    //unique scorePoints
    {
        return " I score points by getting a touchdown";
    }
    
    string move()   //unique move
    {
        return " I move by running and tackling other players";
    }
};

#endif
