#include "Field.h"
#include "Entity/Humanoid.h"
#include "Entity/Hunter.h"
#include "Entity/Vampire.h"
#include "Entity/Human.h"


/**
 * @brief This file contains generic method definition of Field
 *
 * @file FieldGenericMethod.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 */

/**
 * @brief Compute the closest humanoid from another given in argument
 *
 * @param predator the humanoid from where to look from
 * @return Humanoid* the pointer to the closest humanoid
 * */
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

