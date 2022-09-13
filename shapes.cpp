#include "shapes.h"

shapes::Shape::Shape(int x, int y){
    this->pos = Point(x, y);
}

bool shapes::Rectangle::intersects(Shape& range){
    shapes::Rectangle& _range = dynamic_cast<Rectangle&>(range);

    return !(_range.pos.x + _range.width/2 < pos.x - width / 2|| \
            _range.pos.x  - _range.width/2 > pos.x + width / 2|| \
            _range.pos.y + _range.height/2 < pos.y - height / 2|| \
            _range.pos.y - _range.height/2 > pos.y + height / 2);    
}

bool shapes::Rectangle::contains(Point& p){
    return (p.x >= pos.x - width / 2  \
            && p.x <= pos.x + width / 2 \
            && p.y >= pos.y - height /2  \
            && p.y <= pos.y + height / 2);    
}