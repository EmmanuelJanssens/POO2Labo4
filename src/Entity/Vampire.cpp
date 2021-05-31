#include "../../include/Entity/Vampire.h"
#include "../../include/Action/MoveAction.h" // TO ERASE
#include "../../include/Action/KillAction.h"


void Vampire::render(BuffyView &view) const {
    view.display(*this);
}

void Vampire::setAction(Field &field) {

    // Si un Human est à côté :
    bool foundHumanToAttack = false;
    std::list<Humanoid *> humanoidsAround = field.getAround(this);
    if(!humanoidsAround.empty()){
        for(Humanoid* h : humanoidsAround){
            Human* humanToAttack = dynamic_cast<Human*>(h);
            if(humanToAttack != nullptr){
                foundHumanToAttack = true;
                KillAction *action = new KillAction(this, humanToAttack);
                action->setEndPos(humanToAttack->getPos());
                std::cout << "VAMPIRE:: KILL ACTION CREATED" <<std::endl;
                Humanoid::cleanAndSetAction(action);
            }
        }
    }

    // Sinon bouge en direction d'un Human
    bool foundHumanToHunt = false;
    //Human* humanToHunt = (Human*) field.getClosestTo<Human>(this);
    if(!foundHumanToAttack){
        //if(humanToHunt != nullptr){
            foundHumanToHunt = true;
            MoveAction *action = new MoveAction(this,1);
            action->random(field);
            Humanoid::cleanAndSetAction(action);
        //}
    }


}
