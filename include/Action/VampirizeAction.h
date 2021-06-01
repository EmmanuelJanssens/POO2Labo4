#ifndef POO2LABO4_VAMPIRIZEACTION_H
#define POO2LABO4_VAMPIRIZEACTION_H

#include "Action.h"

/**
 * @brief Perform the action to transform a human into a vampire
 * 
 * @file VampirizeAction.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class VampirizeAction : public Action{

    //victim to transform
    Human* _victim;
    
public:

    /**
     * @brief Construct a new Vampirize Action object
     * 
     * @param victim 
     */
    VampirizeAction(Human* victim);

    /**
     * @brief Execute the vampirization action
     * 
     * @param field 
     */
    void execute(Field& field) const override;
};


#endif //POO2LABO4_VAMPIRIZEACTION_H
