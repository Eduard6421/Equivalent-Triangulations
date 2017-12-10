#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

ifstream f("data.in");

class point{
    friend class Polygon;
    double x, y;
    public:
        point();
        point(double a, double b){
            x = a;
            y = b;
        }

        static double dist(point a, point b){
            return sqrt( pow((a.x - b.x), 2) + pow((a.y - b.y), 2) );
        }

        static double area(point a, point b, point c){
            double d1 = dist(a, b);
            double d2 = dist(b, c);
            double d3 = dist(c, a);
            double sPerimeter = (d1 + d2 + d3) / 2;

            return sqrt(sPerimeter*(sPerimeter - d1) * (sPerimeter - d2) * (sPerimeter - d3));
        }

        bool isInTriangle(point a, point b, point c){ // check using areas with Heron`s Formula
            double totalArea = area(a, b, c);
            double a1 = area(*this, a, b);
            double a2 = area(*this, b, c);
            double a3 = area(*this, a, c);

            return (abs(totalArea - (a1 + a2 + a3)) < 0.02);
        }

        bool operator<(const point& a){
            if(x == a.x)
                return y < a.y;
            return x < a.x;
        }
        bool operator==(const point& a){
            return (x == a.x) && (y == a.y);
        }
};

class Polygon{
    vector<point> vertices;
    public:
        Polygon(){}
        Polygon(vector<point> temp){
            for(int i = 0; i < (int)temp.size(); i++)
                vertices.push_back(temp[i]);
        }
        void triangulate(){
            sort(vertices.begin(), vertices.end());

        }
};

int main()
{
    int n;
    f >> n;
    vector<point> vertice;

    for(int i = 0; i < n; i++){
        double a, b;
        f >> a >> b;
        point x(a, b);
        vertice.push_back(x);
    }

    Polygon P(vertice);
    P.triangulate();

    return 0;
}
