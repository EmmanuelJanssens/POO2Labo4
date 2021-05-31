#include "../../include/Entity/Humanoid.h"

#include "../../include/Action/KillAction.h"

KillAction::KillAction(Humanoid *targetPos, Humanoid *victim)
        : _target(targetPos),  _victim(victim) {}

void KillAction::execute(Field &field) const {
    //_victim->dies(); // Ligne qui bug
    _target->move(field, _endPos);
    std::cout << "KillAction::execute" << std::endl;
}

void KillAction::setEndPos(Cell* to) {
    _endPos = to;
}



