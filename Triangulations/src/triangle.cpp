#include "triangle.h"
#include<stdio.h>
#include<iostream>
triangle::triangle()
{
    //ctor
}

triangle::~triangle()
{
    //dtor
}

triangle::triangle(edge a,edge b,edge c)
{
    e1 = a;
    e2 = b;
    e3 = c;

}

bool triangle :: common_edge(triangle t1,triangle t2)           //Test if two triangles have a common edge
{
    if(t1.e1 == t2.e1 || t1.e1 == t2.e2 || t1.e1 == t2.e3)
        return true;

    if(t1.e2 == t2.e1 || t1.e2 == t2.e2 || t1.e2 == t2.e3)
        return true;

    if(t1.e3 == t2.e1 || t1.e3 == t2.e2 || t1.e3 == t2.e3)
        return true;


    return false;

}

bool triangle :: test_flip(triangle &t1,triangle &t2)
{
    point a,b,c,d;
    edge vekt1[3];
    edge vekt2[3];

    int orientation;
    int ad_x,ad_y;
    int bd_x,bd_y;
    int cd_x,cd_y;
    int c31,c32,c33;

    double det;

    int i,j;


    vekt1[0] = t1.e1;
    vekt1[1] = t1.e2;
    vekt1[2] = t1.e3;

    vekt2[0] = t2.e1;
    vekt2[1] = t2.e2;
    vekt2[2] = t2.e3;


    for(i = 0 ; i<3; ++i)
        for(j = 0 ; j < 3 ; ++j)
            if(vekt1[i] == vekt2[j])
                goto found;
found:
    a = vekt1[i].start;                // AB is the common edge of the triangles
    b = vekt1[i].end;
    c = vekt1[(i+1)%3].end;            //C is in triangle T1 but not in T2
    d = vekt2[(j+1)%3].end;            //D is in triangle T2 but not in T1

    /*std::cout<<a.x<<' '<<a.y<<'\n';
    std::cout<<b.x<<' '<<b.y<<'\n';
    std::cout<<c.x<<' '<<c.y<<'\n';
    std::cout<<d.x<<' '<<d.y<<'\n';
    */


    orientation = point::orientation(a,b,c);



    ad_x = a.x - d.x;
    ad_y = a.y - d.y;

    bd_x = b.x - d.x;
    bd_y = b.y - d.y;

    cd_x = c.x - d.x;
    cd_y = c.y - d.y;

    c31 = ad_x*ad_x + ad_y*ad_y;
    c32 = bd_x*bd_x + bd_y*bd_y;
    c33 = cd_x*cd_x + cd_y*cd_y;


    det = ad_x*bd_y*c33+bd_x*cd_y*c31+cd_x*ad_y*c32;
    det -= (c31*bd_y*cd_x+c32*cd_y*ad_x+c33*ad_y*bd_x);

    /*std::cout<<orientation<<'\n';
    std::cout<<det;
    */
    if(orientation > 0)
    {
        if(det > 0)
        {
            t1.e1.start = a;
            t1.e1.end   = c;
            t1.e2.start = c;
            t1.e2.end   = d;
            t1.e3.start = d;
            t1.e3.end   = a;

            t2.e1.start = b;
            t2.e1.end   = c;
            t2.e2.start = c;
            t2.e2.end   = d;
            t2.e3.start = d;
            t2.e3.end   = b;
            return 1;
        }

    }
    else
    {
        if(det < 0 )
        {
            t1.e1.start = a;
            t1.e1.end   = c;
            t1.e2.start = c;
            t1.e2.end   = d;
            t1.e3.start = d;
            t1.e3.end   = a;

            t2.e1.start = b;
            t2.e1.end   = c;
            t2.e2.start = c;
            t2.e2.end   = d;
            t2.e3.start = d;
            t2.e3.end   = b;
            return 1;

        }


    }

    return 0;




}
