#include "../../include/Entity/Humanoid.h"
#include "../../include/Field.h"
#include "../../include/Action/MoveAction.h"



Humanoid::Humanoid(const Cell& pos):_position(pos){
}

void Humanoid::cleanAndSetAction(Action* action){
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
    return _isAlive;
}

Cell Humanoid::getPos(){
    return _position;
}

void Humanoid::move(const Cell& pos){
    _position = pos;
}

void Humanoid::dies() {
    _isAlive = false;
}
