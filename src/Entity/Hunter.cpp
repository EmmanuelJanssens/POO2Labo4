#include "../../include/Entity/Hunter.h"
#include "../../include/Entity/Vampire.h"
#include "../../include/Action/MoveAction.h" // TO ERASE
#include "../../include/Action/KillAction.h"

Hunter::Hunter(const Cell& pos):Humanoid(pos){
}
void Hunter::render(const BuffyView &view) const {
    view.display(*this);
}

void Hunter::setAction(Field &field) {

    Vampire* vampireFound = field.getClosestVampire(*this);
    if(vampireFound != nullptr){

        // kill
        // If the vampire is close enough (1 cell or 0 cell away from Hunter), the hunter kills him
        if(vampireFound->getPos().distanceTo(getPos()) <= 1){
            KillAction *action = new KillAction(vampireFound); // ligne qui bug : terminate recursively
            Humanoid::cleanAndSetAction(action);
        } else {
            // Move in the direction of the vampire
            MoveAction *action = new MoveAction(*this, 1);
            action->getCloserTo(vampireFound->getPos(), 2);
            Humanoid::cleanAndSetAction(action);
        }
    } else {
        // If there is no more Vampires, Hunter moves randomly
        MoveAction *action = new MoveAction(*this,1);
        action->random(field);
        Humanoid::cleanAndSetAction(action);
    }
}

