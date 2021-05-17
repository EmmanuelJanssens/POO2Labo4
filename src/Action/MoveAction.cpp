#include "../../include/Action/MoveAction.h"
#include <iostream>

MoveAction::MoveAction(Cell& targetPos):
    _targetPos(targetPos){
        
}

void MoveAction::execute(Field& field){
    _targetPos.setCoord(_endPos);
}

void MoveAction::random(Field& field, size_t Radius ){
    std::cout<<"Random move YOLO\n";
}
