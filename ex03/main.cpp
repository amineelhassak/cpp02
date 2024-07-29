#include "Point.hpp"

int main()
{
     Point a(0.0, 0.0);
    Point b(5.0, 0.0);
    Point c(0.0, 5.0);

    // Point à vérifier (à l'intérieur)
    Point p1(2.0, 2.0);
    // Point à vérifier (à l'extrieur)
    Point p2(5.0, 5.0);
    std::cout<< bsp(a,b,c,p2) << "\n";
}