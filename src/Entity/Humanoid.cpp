#include "../../include/Entity/Humanoid.h"
#include "../../include/Field.h"
#include "../../include/Action/MoveAction.h"


void Humanoid::setAction(Field& field){
    MoveAction *action = new MoveAction(this,2);
    action->random(field);

    if(_action != nullptr){
        delete _action;
        _action = nullptr;
    }

    _action = action;
}

void Humanoid::executeAction(Field& field){
    if(_action!=nullptr){
        _action->execute(field);
    }
}

bool Humanoid::isAlive(){
    return true;
}

Cell* Humanoid::getPos(){
    return _position;
}

void Humanoid::setPosition(Field& f,Cell* pos){
    _position = pos;
    f.getCellAt(_position->getX(), _position->getY())->setEntity(this);

}
void Humanoid::move(Field& f,Cell* pos){
    f.getCellAt(_position->getX(), _position->getY())->removeEntity(this);
    setPosition(f,pos);
}