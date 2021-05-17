#include "../../include/Action/MoveAction.h"
#include <iostream>
#include <random>

MoveAction::MoveAction(Cell& targetPos):
    _targetPos(targetPos){
        
}

void MoveAction::execute(Field& field){
    _targetPos.setCoord(_endPos);
}

void MoveAction::random(Field& field, size_t Radius ){
    std::cout<<"Random move YOLO\n";

    int r = rand()%100+1;
    int r2 = rand()%100+1;
    _endPos = Cell(r,r2);
}
