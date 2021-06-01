#include "../../include/Field.h"
#include "../../include/Entity/Vampire.h"
#include "../../include/Action/MoveAction.h" // TO ERASE
#include "../../include/Action/KillAction.h"
#include "../../include/Entity/Human.h"
#include "../../include/Action/VampirizeAction.h"
#include "../../include/Field.h"
#include "../../include/view/BuffyView.h"

Vampire::Vampire(const Cell& pos):Humanoid(pos){
}

void Vampire::render(const BuffyView &view) const {
    view.display(*this);
}

void Vampire::setAction(Field &field) {

    Humanoid* humanFound = field.getClosestHumanoidTo<Human>(*this);
    //Humanoid* humanFound = field.getClosestHumanoidTo<Human>(*this);
    if(humanFound != nullptr){
        // kill
        // If the human is close enough (1 cell or 0 cell away from the vampire), the vampire kills him
        if(humanFound->getPos().distanceTo(getPos()) <= 1){
            int randKillVampirize = rand()%2;
            if(randKillVampirize == 0){
                KillAction *action = new KillAction(humanFound);
                Humanoid::cleanAndSetAction(action);
            } else if(randKillVampirize == 1){
                VampirizeAction *action = new VampirizeAction(static_cast<Human*>(humanFound));
                Humanoid::cleanAndSetAction(action);
            }

        } else {
        // Move in the direction of the human
            MoveAction *action = new MoveAction(*this, 1);
            action->getCloserTo(humanFound->getPos(), 1);
            Humanoid::cleanAndSetAction(action);
        }
    } else {
        // If there is no more humans, no action is set to vampires (don't move)
        Humanoid::cleanAndSetAction(nullptr);
    }

}
