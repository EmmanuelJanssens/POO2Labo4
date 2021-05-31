#include "../../include/Entity/Hunter.h"
#include "../../include/Action/MoveAction.h" // TO ERASE

void Hunter::render(BuffyView &view) const {
    view.display(*this);
}

void Hunter::setAction(Field &field) {
    MoveAction *action = new MoveAction(*this,2);
    action->random(field);
    Humanoid::cleanAndSetAction(action);
}
