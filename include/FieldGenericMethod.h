
#include "Field.h"
#include "Entity/Humanoid.h"
#include "Entity/Hunter.h"
#include "Entity/Vampire.h"
#include "Entity/Human.h"

template<typename T>
Humanoid* Field::getClosestHumanoidTo(const Humanoid &predator) const {
    Humanoid* found = nullptr;
    int minimalDistance = std::numeric_limits<int>:: max();

    for(Humanoid* h : _humanoids){
        if(dynamic_cast<T*>(h)){
            int newDistance = predator.getPos().distanceTo(h->getPos());
            if(newDistance < minimalDistance){
                minimalDistance = newDistance;
                found = h;
            }
        }
    }

    return found;
}

