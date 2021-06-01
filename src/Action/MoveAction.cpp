#include "../../include/Action/MoveAction.h"
#include <iostream>
#include <random>
#include <map>
#include "../../include/Entity/Humanoid.h"
MoveAction::MoveAction(Humanoid& target, int distance):
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
        _target.move(_endPos);
}

void MoveAction::random(const Field& field  ){
    //std::cout<<"Random move YOLO\n";

    int randFuncId = rand()%8;
    auto res = _rmove[randFuncId];
    
    Cell temp = (this->*res)(field);
    
    _endPos = temp;
    
}

void MoveAction::getCloserTo(const Cell& destination, unsigned nbSteps){
    Cell position = _target.getPos();
    int xIncc = 0, yIncc = 0;

    for(unsigned i = 0; i < nbSteps; i++){
        int dx = destination.getX() - (position.getX()+xIncc);
        int dy = destination.getY() - (position.getY()+yIncc);

        if(dx > 0)
            xIncc++;
        if(dx < 0)
            xIncc--;
        if(dy > 0)
            yIncc++;
        if(dy < 0)
            yIncc--;
    }
    _endPos = Cell(position.getX() + xIncc, position.getY() + yIncc);
}

Cell MoveAction::Up(const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX();
    int newy = _target.getPos().getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = Cell(newx,newy);
    return t;
}
Cell MoveAction::Down(const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX();
    int newy = _target.getPos().getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::Left( const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX()-_distance;
    int newy = _target.getPos().getY();

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::Right(const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX()+_distance;
    int newy = _target.getPos().getY();

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::UpLeft(const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX()-_distance;
    int newy = _target.getPos().getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::UpRight(const Field& field){
    Cell t = _target.getPos();
    int newx = _target.getPos().getX()+_distance;
    int newy = _target.getPos().getY()+_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::DownLeft(const Field& field){
    Cell t = _target.getPos();    
    int newx = _target.getPos().getX()-_distance;
    int newy = _target.getPos().getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t =  Cell(newx,newy);
    return t;
}
Cell MoveAction::DownRight(const Field& field){
    Cell t = _target.getPos();    
    int newx = _target.getPos().getX()+_distance;
    int newy = _target.getPos().getY()-_distance;

    if(newx > 0 && newy >0 && newx < field.getWidth() && newy < field.getHeight())
        t = Cell(newx,newy);
    return t;
}


