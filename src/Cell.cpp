#include <typeinfo>
#include "../include/Cell.h"
#include "../include/Entity/Humanoid.h"
std::ostream& operator<<(std::ostream& os, const Cell& c){
    /* // DEBUG
    std::string type = " ";
    for(Humanoid* h : c._entitiesOnCell){
        if(typeid(*h) == typeid(Humanoid))
            type = "h";
        else
            type = "0";
    }
    os<<"("<<c._x<<","<<c._y<<") "<<type<<" ";
    */
    return os;
}

Cell::Cell():_x(0),_y(0){}
Cell::Cell(const Cell& c){
    setCoord(c);
}
Cell::Cell(int x, int y){
    setCoord(x,y);
}
Cell::Cell(int x, int y, Humanoid* h):_x(x),_y(y){
    setEntity(h);
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

void Cell::removeAll(){
    for(Humanoid* h: _entitiesOnCell){
        _entitiesOnCell.remove(h);
    }
}
void Cell::removeEntity(Humanoid* toRemove){
    if(_entitiesOnCell.empty())
        return;
    for(Humanoid* h: _entitiesOnCell){
        if(h == toRemove){
            _entitiesOnCell.remove(h);
            break;
        }
    }
}
void Cell::setEntity(Humanoid* h){
    if(h != nullptr)
        _entitiesOnCell.push_back(h);
}
bool Cell::hasEntity() const{
    return !_entitiesOnCell.empty();
}
Cell& Cell::operator=(const Cell& c){

    this->setCoord(c);

    return *this;
}

const std::list<Humanoid *> &Cell::getEntitiesOnCell() const {
    return _entitiesOnCell;
}
