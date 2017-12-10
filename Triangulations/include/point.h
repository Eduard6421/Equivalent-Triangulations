#ifndef POINT_H
#define POINT_H


class point
{
    private:
        double x, y;

    public:
        point();
        point(const point &tmp);
        point(double a,double b);
        virtual ~point();
        friend class Poylgon;



    static double dist(point a, point b);
    static double area(point a, point b, point c);
    static bool on_segment(point a,point b,point c);
    static int orientation(point a,point b,point c);
    static bool intersects(point a,point b,point c,point d);

    bool isInTriangle(point a, point b, point c);

    bool operator <(const point& a);
    bool operator ==(const point& a);
    point& operator = (const point &a);


};
#endif // POINT_H
