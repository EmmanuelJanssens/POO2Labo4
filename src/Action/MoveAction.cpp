#include "../../include/Action/MoveAction.h"
#include <iostream>
#include <random>

MoveAction::MoveAction(Cell& targetPos, int distance):
    _targetPos(targetPos),
    _distance(distance),
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
    _targetPos.setCoord(_endPos);
}

void MoveAction::random(Field& field  ){
    std::cout<<"Random move YOLO\n";

    int randFuncId = rand()%8;
    auto res = _rmove[randFuncId];
    
    Cell temp = (this->*res)();

    if(isInBoundsBeforeMove(field,temp))
        _endPos = temp;
}

bool MoveAction::isInBoundsBeforeMove(Field& f, const Cell &pos){

    if(pos.getX() < 0)
        return false;
    if(pos.getY() < 0)
        return false;
    if(pos.getX() > f.getWidth())
        return false;
    if(pos.getY() > f.getHeight())
        return false;    
    return true;
}
Cell MoveAction::Up(){
    return Cell(_targetPos.getX(),_targetPos.getY()+_distance);
}
Cell MoveAction::Down(){
    return Cell(_targetPos.getX(),_targetPos.getY()-_distance);
}
Cell MoveAction::Left(){
    return Cell(_targetPos.getX()-_distance,_targetPos.getY());
}
Cell MoveAction::Right(){
    return Cell(_targetPos.getX()+_distance,_targetPos.getY());
}
Cell MoveAction::UpLeft(){
    return Cell(_targetPos.getX()-_distance,_targetPos.getY()+_distance);
}
Cell MoveAction::UpRight(){
    return Cell(_targetPos.getX()+_distance,_targetPos.getY()+_distance);
}
Cell MoveAction::DownLeft(){
    return Cell(_targetPos.getX()-_distance,_targetPos.getY()-_distance);
}
Cell MoveAction::DownRight(){
    return Cell(_targetPos.getX()+_distance,_targetPos.getY()+_distance);
}
