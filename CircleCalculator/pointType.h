// Class pointType

#ifndef H_PointType
#define H_PointType
using namespace std;

class pointType
{
protected:
    int xpoint;
    int ypoint;
public:
    void print();
    void setxpoint(int);
    void setypoint(int);
    int getxpoint();
    int getypoint();
    
};

#endif
