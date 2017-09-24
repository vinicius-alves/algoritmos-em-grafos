using namespace std;
#include "Point.h"

Point::Point(unsigned int const &_x, unsigned int const &_y){
      x = _x;
      y = _y;
}

unsigned int Point::getX() const { return x; }
unsigned int Point::getY() const { return y; }

 
unsigned int Comparator::operator() (const Point& p1, const Point& p2){
        return p1.getX() > p2.getX();
}

ostream & operator<<(ostream &os, const Point& p)
{
    return os << "(" << p.getX() << "," << p.getY() << ")" <<endl;
}