#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <point.h>
#include <edge.h>
#include<triangle.h>

using namespace std;

const int NMAX = 1000;

vector<triangle> t1;
int n;


ifstream in("data.in");
ofstream out("data.out");


void read_data()
{
    int x1,y1;
    int x2,y2;
    int i,j;
    edge e1,e2,e3;

    in>>n;

    for(i = 0 ; i < n ; ++i)
    {
        in>>x1>>y1>>x2>>y2;
        edge e1(point(x1,y1),point(x2,y2));
        in>>x1>>y1>>x2>>y2;
        edge e2(point(x1,y1),point(x2,y2));
        in>>x1>>y1>>x2>>y2;
        edge e3(point(x1,y1),point(x2,y2));

        triangle temp(e1,e2,e3);
        t1.push_back(temp);
    }




}
/*
int sum;
void solve()        // in solve o sa intre doar muchiile diferite de la inkeput
{
    int i,j;
    while(!solved)
    {
        solved = 1;

        for(i = 0 ; i < n ; ++i)
        {
            if(!checked[i])
            {
                solved = 0;
                break;
            }
        }

        if(!solved)
        {





        }


    }


}
*/


void print_triangulation()
{
    int i;
    for(i = 0 ; i < n ; ++i)
    {
        out<<t1[i].e1.start.x<<' '<<t1[i].e1.start.y<<' '<<t1[i].e1.end.x<<' '<<t1[i].e1.end.y<<'\n';
        out<<t1[i].e2.start.x<<' '<<t1[i].e2.start.y<<' '<<t1[i].e2.end.x<<' '<<t1[i].e2.end.y<<'\n';
        out<<t1[i].e3.start.x<<' '<<t1[i].e3.start.y<<' '<<t1[i].e3.end.x<<' '<<t1[i].e3.end.y<<'\n';

        out<<'\n';
    }


}

bool common_edge(int i,int j)
{
    if(i == j)
        return false;
    else
        return triangle::common_edge(t1[i],t1[j]);

}

bool test_flip(int i,int j)
{
    triangle::test_flip(t1[i],t1[j]);
}


void delauney()
{
    int i,j;
    bool flipped = true;

    while(flipped)
    {
        flipped = false;
        for(i = 0 ; i < n ; ++i)
            for(j = 0 ; j < n ; ++j)
                if(common_edge(i,j))
                {
                    if(test_flip(i,j))
                        flipped = true;

                }
    }
}

int main()
{
    read_data();
    delauney();
    print_triangulation();

}
