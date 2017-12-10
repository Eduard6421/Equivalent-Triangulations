#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<point.h>

class triangle
{
    public:
        triangle(const point &a,const point &b,const point &c);
        virtual ~triangle();

    protected:

    private:
        point p1,p2,p3;
};

#endif // TRIANGLE_H
