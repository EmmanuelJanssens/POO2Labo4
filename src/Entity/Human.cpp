//
// Created by Rosalie Chhen on 19.05.2021.
//

#include "../../include/Entity/Human.h"
#include "../../include/Action/MoveAction.h"
Human::Human(const Cell& pos):Humanoid(pos){
}

void Human::render(const BuffyView &view) const {
    view.display(*this);
}


void Human::setAction(Field& field){
    MoveAction *action = new MoveAction(*this,1);
    action->random(field);
    Humanoid::cleanAndSetAction(action);
}