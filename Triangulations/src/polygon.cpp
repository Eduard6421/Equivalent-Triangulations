#include "polygon.h"
#include <algorithm>
polygon::polygon(std::vector<point> temp)
{
    for(int i = 0; i < (int)temp.size(); i++)
        vertices.push_back(temp[i]);
}


void polygon:: triangulate()
{
    std::sort(vertices.begin(), vertices.end());
}

polygon::~polygon()
{
    //dtor
}
