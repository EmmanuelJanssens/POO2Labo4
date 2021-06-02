#include "../../include/Entity/Humanoid.h"
#include "../../include/Action/KillAction.h"

KillAction::KillAction(Humanoid *victim)
        : _victim(victim) {}

void KillAction::execute(Field &) const {
    if(_victim != nullptr){
        _victim->dies();
    }
}




