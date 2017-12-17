#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <point.h>
#include <polygon.h>
#include <triangle.h>

using namespace std;

vector< pair<int,int> > edges;
vector<point> v;

ifstream in("data.in");
ofstream out("data.out");


int main()
{

    int n;
    int x,y;

    in>>n;

    for(int i = 0 ; i < n ; ++i)
    {
        in>>x>>y;
        v.push_back(point(x,y));
    }

    for(int i = 0 ; i < n ; ++i)
    {
        out<<v[i].get_x()<<' '<<v[i].get_y()<<'\n';

    }

    out<<point::intersect(v[0],v[1],v[2],v[3]);




    return 0;
}
