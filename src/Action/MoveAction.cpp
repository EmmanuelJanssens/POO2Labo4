#include <map>

#include "../../include/Action/MoveAction.h"
#include "../../include/Entity/Humanoid.h"
#include "../../include/Field.h"

MoveAction::MoveAction(Humanoid& target, int distance):
    _target(target),
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

void MoveAction::execute(Field& ) const {
        _target.move(_endPos);
}

void MoveAction::random(const Field& field  ){
    //std::cout<<"Random move YOLO\n";

    int randFuncId = rand()%8;
    auto res = _rmove[randFuncId];
    
    (this->*res)(field);
    
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

bool MoveAction::isInBounds(const Field& field, const Cell& c){
    return (c.getX() > 0 && c.getY() >0 && c.getX() < static_cast<int>((field.getWidth())) && c.getY() < static_cast<int>(field.getHeight()));
}
void MoveAction::setEndPos(const Field& field, const Cell& c){
    if(isInBounds(field,c))
        _endPos = c;
}

void MoveAction::Up(const Field& field){

    Cell new_p = Cell(
         _target.getPos().getX(),
         _target.getPos().getY()+_distance
    );
    setEndPos(field,new_p);
}
void MoveAction::Down(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX(),
        _target.getPos().getY()-_distance
    );
    setEndPos(field,new_p);
}
void MoveAction::Left( const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()-_distance,
        _target.getPos().getY()
    );
    setEndPos(field,new_p);
}
void MoveAction::Right(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()+_distance,
        _target.getPos().getY()
    );
    setEndPos(field,new_p);
}
void MoveAction::UpLeft(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()-_distance,
        _target.getPos().getY()+_distance
    );
    setEndPos(field,new_p);
}
void MoveAction::UpRight(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()+_distance,
        _target.getPos().getY()+_distance
    );
    setEndPos(field,new_p);

}
void MoveAction::DownLeft(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()-_distance,
        _target.getPos().getY()-_distance
    );
    setEndPos(field,new_p);

}
void MoveAction::DownRight(const Field& field){
    Cell new_p = Cell(
        _target.getPos().getX()+_distance,
        _target.getPos().getY()+_distance
    );
    setEndPos(field,new_p);
}


