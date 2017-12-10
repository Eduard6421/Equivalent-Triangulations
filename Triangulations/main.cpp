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

    int i;

    in>>n;

    for(i = 0 ; i < n ; ++i)
    {
        int x,y;
        in>>x>>y;

        point temp(x,y);

        v.push_back(temp);
    }

    out<<point::intersects(v[0],v[1],v[2],v[3]);




    return 0;
}
