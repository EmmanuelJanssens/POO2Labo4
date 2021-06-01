#include "MoveAction.h"

/**
 * @brief Kills an humanoid
 * 
 * @file KillAction.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class KillAction : public Action{
private:

    //victim to be killed
    Humanoid* _victim;
public:

    /**
     * @brief Construct a new Kill Action object
     * 
     * @param victim victim to be killed
     */
    KillAction(Humanoid* victim);

    /**
     * @brief executes the action
     * 
     * @param field 
     */
    void execute(Field& field) const override;

};