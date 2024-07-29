#include  "Point.hpp"

Point::Point() : x(0),y(0)  {
}

Point::Point(float x,float y): x(x),y(y)    {
}

Point::Point(const Point &point){
    *this = point;
}

Point &Point::operator=(const Point& point) {
    return ((void)point, *this);
}

const Fixed &Point::getX() const    {
    return (this->x);
}

const Fixed & Point::getY() const   {
    return (this->y);
}

Point::~Point() {
}
