#include "../../include/Entity/Human.h"
#include "../../include/Entity/Vampire.h"
#include "../../include/Action/MoveAction.h"
#include "../../include/view/BuffyView.h"
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

Vampire *Human::getVampirized() {
    dies();
    return new Vampire(getPos());
}
