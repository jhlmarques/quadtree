#ifndef SHAPES_H
#define SHAPES_H
#include "point.h"

namespace shapes{

class Shape{
    public:
    Point pos;

    public:
    Shape(int x, int y);
    virtual bool intersects(Shape& p) = 0;
    virtual bool contains(Point& p) = 0;
};

class Rectangle : public Shape{
    private:
    int width;
    int height;

    public:
    Rectangle(int x, int y, int width, int height) : 
        Shape(x, y), 
        width(width), 
        height(height){}

    virtual bool intersects(Shape& range);
    virtual bool contains(Point& p);

};

}

#endif