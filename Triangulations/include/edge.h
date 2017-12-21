#ifndef EDGE_H
#define EDGE_H
#include "point.h"

class edge
{
public:
    point start,end;
    edge();
    edge(point a,point b);
    point get_start();
    point get_end();
    virtual ~edge();

    bool operator == (const edge &other);

protected:

private:



};

#endif // EDGE_H
