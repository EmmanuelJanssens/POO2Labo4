#include "../include/Cell.h"

#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Cell& c){
     // DEBUG
    os<<"("<<c._x<<","<<c._y<<")";
    return os;
}

Cell::Cell():_x(0),_y(0){}
Cell::Cell(const Cell& c){
    setCoord(c);
}
Cell::Cell(int x, int y){
    setCoord(x,y);
}
void Cell::setCoord(int x, int y){
    _x = x;
    _y = y;
}

void Cell::setCoord(const Cell& c){

    _x = c._x;
    _y = c._y;
}
int Cell::getX()const{
    return _x;
}
int Cell::getY()const{
    return _y;
}

Cell& Cell::operator=(const Cell& c){

    this->setCoord(c);

    return *this;
}
bool Cell::operator==(const Cell& c){
    return _x == c._x && _y == c._y;
}
int Cell::distanceTo(const Cell& c) const{
    return std::max(std::abs(c._x - _x), std::abs(c._y - _y));
}
