#include "triangle.h"

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

bool triangle :: common_edge(triangle t1,triangle t2)
{
    if(t1.e1 == t2.e1 || t1.e1 == t2.e2 || t1.e1 == t2.e3)
        return true;

    if(t1.e2 == t2.e1 || t1.e2 == t2.e2 || t1.e2 == t2.e3)
        return true;

    if(t1.e3 == t2.e1 || t1.e3 == t2.e2 || t1.e3 == t2.e3)
        return true;


    return false;

}

bool triangle :: test_flip(triangle t1,triangle t2)
{




}
