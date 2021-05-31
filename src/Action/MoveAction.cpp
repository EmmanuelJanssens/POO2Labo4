#include "../../include/Action/MoveAction.h"
#include <iostream>
#include <random>
#include <map>
#include "../../include/Entity/Humanoid.h"
MoveAction::MoveAction(Humanoid* target, int distance):
    _distance(distance),
    _target(target),
    _rmove{
        &MoveAction::Up, 
        &MoveAction::Down,
        &MoveAction::Left, 
        &MoveAction::Right, 
        &MoveAction::UpLeft, 
        &MoveAction::UpRight,
        &MoveAction::DownLeft,
        &MoveAction::DownRight
    }{
     
}

void MoveAction::execute(Field& field) const {
    _target->move(field,_endPos);
}

void MoveAction::random(Field& field  ){
    //std::cout<<"Random move YOLO\n";

    int randFuncId = rand()%8;
    auto res = _rmove[randFuncId];
    
    Cell *temp = (this->*res)(field);
    
    _endPos = temp;
    
}

void MoveAction::getCloserTo(Field &field) {

}

Cell* MoveAction::Up(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX();
    int newy = _target->getPos()->getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::Down(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX();
    int newy = _target->getPos()->getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::Left(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX()-_distance;
    int newy = _target->getPos()->getY();

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::Right(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX()+_distance;
    int newy = _target->getPos()->getY();

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::UpLeft(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX()-_distance;
    int newy = _target->getPos()->getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::UpRight(Field& field){
    Cell* t = _target->getPos();
    int newx = _target->getPos()->getX()+_distance;
    int newy = _target->getPos()->getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::DownLeft(Field& field){
    Cell* t = _target->getPos();    
    int newx = _target->getPos()->getX()-_distance;
    int newy = _target->getPos()->getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}
Cell* MoveAction::DownRight(Field& field){
    Cell* t = _target->getPos();    
    int newx = _target->getPos()->getX()+_distance;
    int newy = _target->getPos()->getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = field.getCellAt(newx,newy);
    return t;
}


