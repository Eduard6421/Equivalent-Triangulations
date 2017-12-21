#include "point.h"
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

point::point()
{

}

point::point(const point &tmp)
{
    x = tmp.x;
    y = tmp.y;

}

point::point(double a, double b)
{
    x = a;
    y = b;
}

point::~point()
{
    //dtor
}

double point::get_x()
{
    return this->x;
}
double point::get_y()
{
    return this->y;
}

double point::determinant(point a,point b,point c)
{
    double d1,d2,d3,d4;
    double answer;

    d1 = a.x-c.x;
    d2 = a.y-c.y;
    d3 = b.x-c.x;
    d4 = b.y-c.y;

    answer = d1*d4  - d2*d3;

    return answer;
}


double point ::area(point a,point b,point c)
{
    double det = point::determinant(a,b,c);

    det = abs(det);

    return det/2;
}

int point ::orientation(point a,point b,point c)
{
    int det = point::determinant(a,b,c);

    if(det > 0 )
        return 1;
    if(det < 0 )
        return -1;
    else
        return 0;
}


bool point :: intersect(point a,point b,point c,point d)
{
    int o_123,o_124,o_341,o_342;

    o_123 = orientation(a,b,c);
    o_124 = orientation(a,b,d);
    o_341 = orientation(c,d,a);
    o_342 = orientation(c,d,b);

    if ((o_123 != o_124) && (o_341 != o_342))
        return true;

    if(o_123 == 0 && check_projections(a,b,c) )
        return 1;
    if(o_124 == 0 && check_projections(a,b,d) )
        return 1;
    if(o_341 == 0 && check_projections(c,d,a) )
        return 1;
    if(o_342 == 0 && check_projections(c,d,b) )
        return 1;

    return false;

}

bool point ::check_projections(point a,point b, point c)
{

    if(  (c.x <max(a.x,b.x) && c.x >min(a.x,b.x ))    &&     ( c.y <max(a.y,b.y) && c.y >min(a.y,b.y))    )  // obligatoriu mai mic!
        return 1;
    return 0;
}

bool point::operator<(const point& a)
{
    if(x == a.x)
        return y < a.y;
    return x < a.x;
}

bool point::operator==(const point& a)
{
    return ((x == a.x) && (y == a.y));
}

point& point::operator = (const point &a)
{
    x=a.x;
    y=a.y;
    return *this;
}





