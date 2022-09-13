#include "point.h"

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(const Point& p1){
        x = p1.x;
        y = p1.y;
}

Point& Point::operator +=(Point& p){
    x = x + p.x;
    y = y + p.y;
    Point _p = Point(x + p.x, y + p.y);
    return _p;
}

Point& Point::operator -=(Point& p){
    x = x - p.x;
    y = y - p.y;
    Point _p = Point(x - p.x, y - p.y);
    return _p;
}