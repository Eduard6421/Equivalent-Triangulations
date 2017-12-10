#include "point.h"
#include<math.h>
#include<stdlib.h>
point::point(double a, double b)
{
    x = a;
    y = b;
}

point::~point()
{
    //dtor
}

double point::dist(point a, point b)
{
    return sqrt( pow((a.x - b.x), 2) + pow((a.y - b.y), 2) );
}

double point::area(point a, point b, point c)
{
    double d1 = point::dist(a, b);
    double d2 = point::dist(b, c);
    double d3 = point::dist(c, a);
    double sPerimeter = (d1 + d2 + d3) / 2;

    return sqrt(sPerimeter*(sPerimeter - d1) * (sPerimeter - d2) * (sPerimeter - d3));
}

bool point::isInTriangle(point a, point b, point c)  // check using areas with Heron`s Formula
{
    double totalArea = point::area(a, b, c);
    double a1 = point::area(*this, a, b);
    double a2 = point::area(*this, b, c);
    double a3 = point::area(*this, a, c);

    return (abs(totalArea - (a1 + a2 + a3)) < 0.000005);
}

bool point::operator<(const point& a)
{
    if(x == a.x)
        return y < a.y;
    return x < a.x;
}

bool point::operator==(const point& a)
{
    return (x == a.x) && (y == a.y);
}




