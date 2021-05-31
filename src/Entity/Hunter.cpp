#include "../../include/Entity/Hunter.h"
#include "../../include/Action/MoveAction.h" // TO ERASE

Hunter::Hunter(const Cell& pos):Humanoid(pos){
}
void Hunter::render(const BuffyView &view) const {
    view.display(*this);
}

void Hunter::setAction(Field &field) {
    MoveAction *action = new MoveAction(*this,2);
    action->random(field);
    Humanoid::cleanAndSetAction(action);
}
