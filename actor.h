#ifndef ACTOR_H
#define ACTOR_H
#include "shapes.h"


class Actor{
    private:
    float speed_x;
    float speed_y;
    shapes::Shape* collision;
    Point speed_vector;

    public:
    Actor(shapes::Shape* collision, int speed_x, int speed_y);
    Point getPos();

    void step();
    void onBorderHit(bool hit_x, bool hit_y);
    
};

#endif