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

point& point::operator = (const point &a)
{
    x=a.x;
    y=a.y;
    return *this;
}



int point:: orientation(point a,point b,point c)
{

    double slope_1;
    double slope_2;

    if(a.x == b.x && b.x == c.x)
        return 0;       //Colinear

    if(a.x!=b.x)
        slope_1 = (a.y-b.y) / (a.x-b.x);
    if(c.x!=b.x)
        slope_2 = (c.y-b.y) / (c.x-b.x);

    if(a.x==b.x)
    {
        if(c.x > a.x)
            return 1;
        else
            return 0;
    }

    if(b.x==c.x)
    {
        if(c.x > a.x)
        {
            if(c.y > b.y)
                return -1;
            else
                return 1;
        }
        else
        {
            if(c.y > b.y)
                return 1;
            else
                return -1;
        }
    }


    if(slope_1 < slope_2)
        return -1;          //Counter Clock-Wise

    if(slope_1 == slope_2)
        return 0;           //Colinear


    return 1;               //Clockwise
}


bool point::on_segment(point a,point b,point c)     // a,b = capetele segmentului nostru.
{

    if( abs(dist(a,b) - (dist(a,c)+dist(c,b))) < 0.002)
        return true;

    return false;



}


bool point::intersects(point a,point b,point c,point d)
{
    int orientation_1;
    int orientation_2;
    int orientation_3;
    int orientation_4;

    orientation_1 = point::orientation(a,b,c);
    orientation_2 = point::orientation(a,b,d);
    orientation_3 = point::orientation(c,d,a);
    orientation_4 = point::orientation(c,d,b);

    cout<<orientation_1<<' '<<orientation_2<<' '<<orientation_3<<' '<<orientation_4<<'\n';

    if(orientation_1 != orientation_2  && orientation_3 !=orientation_4)
        return true;


    if(orientation_1 == 0 && on_segment(a,c,b))
        return true;
    if(orientation_2 == 0 && on_segment(a,d,b))
        return true;
    if(orientation_3 == 0 && on_segment(c,a,d))
        return true;
    if(orientation_4 == 0 && on_segment(c,b,d))
        return true;


    return false;


}



