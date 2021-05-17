#include "../../include/Entity/Humanoid.h"
#include "../../include/Field.h"
#include "../../include/Action/MoveAction.h"


void Humanoid::setAction(Field& field){
    MoveAction *action = new MoveAction(_position);
    action->random(field,2);

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