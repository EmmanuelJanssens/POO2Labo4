#include "../../include/Action/VampirizeAction.h"
#include "../../include/Entity/Human.h"
#include "../../include/Entity/Vampire.h"
#include "../../include/Entity/Humanoid.h"
#include "../../include/Field.h"


VampirizeAction::VampirizeAction(Human *victim) : _victim(victim){}

void VampirizeAction::execute(Field &field) const {
    if(_victim != nullptr){
        Vampire* v = _victim->getVampirized();
        if(v != nullptr){
            field.addHumanoid(v);
        }
    }
}
