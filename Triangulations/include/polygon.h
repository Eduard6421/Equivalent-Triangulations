#include<point.h>
#include<vector>
#ifndef POLYGON_H
#define POLYGON_H


class polygon
{
public:
    polygon( std::vector <point> temp);
    virtual ~polygon();
    void triangulate();

private:
    std::vector<point> vertices;
};

#endif // POLYGON_H
