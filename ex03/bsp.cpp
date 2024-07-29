#include "Point.hpp"

float area_(float xa,float xb,float xc,float ya,float yb,float yc)
{
    return abs((xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb) ) / 2);
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
    float ax = a.getX().getRawBits() / (1 << a.getX().getFractionalBits());
    float ay = a.getY().getRawBits() / (1 << a.getX().getFractionalBits());
    float bx = b.getX().getRawBits() / (1 << a.getX().getFractionalBits());
    float by = b.getY().getRawBits() / (1 << a.getX().getFractionalBits());
    float cx = c.getX().getRawBits() / (1 << a.getX().getFractionalBits());
    float cy = c.getY().getRawBits() / (1 << a.getX().getFractionalBits());
    float px = point.getX().getRawBits() / (1 << a.getX().getFractionalBits());
    float py = point.getY().getRawBits() / (1 << a.getX().getFractionalBits());

    return (area_(ax, bx, cx, ay, by, cy) == ( area_(px, bx, cx, py, by, cy) + area_(ax, px, cx, ay, py, cy) + area_(ax, bx, px, ay, by, py)));
}