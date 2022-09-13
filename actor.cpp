#include "actor.h"
#include "point.h"
#include <cstdlib>

Actor::Actor(shapes::Shape* collision, int speed_x, int speed_y){
    this->collision = collision;
    speed_vector = Point(speed_x, speed_y);
}

void Actor::step(){
    collision->pos += speed_vector;
}

void Actor::onBorderHit(bool hit_x, bool hit_y){
    if(hit_x){
        speed_vector.x = speed_vector.x * -1;
    }
    if(hit_y){
        speed_vector.y = speed_vector.y * -1;
    }
}


Point Actor::getPos(){
    return collision->pos;
}