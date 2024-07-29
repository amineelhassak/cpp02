#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(float,float);
        Point(const Point &);
        const   Fixed &getX() const;
        const   Fixed &getY() const ;
        Point &operator=(const Point&);
        ~Point();
};
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif 