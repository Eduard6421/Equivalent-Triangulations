#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<edge.h>

class triangle
{
public:
    edge e1,e2,e3;
    triangle();
    triangle(edge a,edge b,edge c);
    static bool common_edge(triangle t1,triangle t2);
    static bool test_flip(triangle &t1,triangle &t2);
    virtual ~triangle();
    static void ended();

protected:

private:


};

#endif // TRIANGLE_H
