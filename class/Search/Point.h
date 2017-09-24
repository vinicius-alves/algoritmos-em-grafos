#include <iostream>

using namespace std;

#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        Point(unsigned int const &_x, unsigned int const &_y);
        unsigned int getX() const;
        unsigned int getY() const;

     private:
        unsigned int x;
        unsigned int y;
};
 
class Comparator
{
    public:
        unsigned int operator() (const Point& p1, const Point& p2);
};

#endif