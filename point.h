#ifndef POINT_H
#define POINT_H

struct Point{
    int x;
    int y;
    Point();
    Point(const Point& p1);
    Point(int _x, int _y) : x(_x), y(_y){};
    
    Point& operator +=(Point& p);
    Point& operator -=(Point& p);

};

#endif