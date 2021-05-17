#include "../include/Cell.h"


Cell::Cell():_x(0),_y(0){}
Cell::Cell(const Cell& c){
    setCoord(c);
}
Cell::Cell(size_t x, size_t y){
    setCoord(x,y);
}

void Cell::setCoord(size_t x, size_t y){
    _x = x;
    _y = y;
}

void Cell::setCoord(const Cell& c){

    _x = c._x;
    _y = c._y;
}