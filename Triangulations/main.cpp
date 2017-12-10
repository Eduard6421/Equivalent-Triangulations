#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include<point.h>
#include<polygon.h>
using namespace std;

ifstream f("data.in");


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
