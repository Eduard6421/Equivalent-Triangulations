#ifndef POINT_H
#define POINT_H

class point
{
    private:

    public:

        double x, y;
        point();
        point(const point &tmp);
        point(double a,double b);
        virtual ~point();
        friend class edge;


    double get_x();
    double get_y();

    static double determinant(point a,point b,point c);      // find the determinant of |a,b,c|
    static double area(point a, point b, point c);           // find the area of triangle|a,b,c|
    static int orientation(point a,point b,point c);         // check orientation of (a,b) with c  : 1 - CCW / 0 - COL / -1 = CW
    static bool intersect(point a,point b,point c,point d);  // check if [a,b] intersects with [c,d]
    static bool check_projections(point a,point b, point c); // check if c is in [a,b] projection

    bool isInTriangle(point a, point b, point c);

    bool operator <(const point& a);
    bool operator ==(const point& a);
    bool operator !=(const point &a);
    point& operator = (const point &a);


};
#endif // POINT_H
