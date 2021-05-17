#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "Action.h"
#include "../Cell.h"
class Humanoid;
class MoveAction : public Action{

    //Entity to move

    Cell& _targetPos;
    Cell _endPos;

    public:

    /**
     * Constructor
     * @param targetPos the target to be modified
     * */
    MoveAction(Cell& targetPos);

    /**
     * Movement's own action
     * @param field in what context we should move
     * */
    void execute(Field& field) override;

    /**
     * Calculate a random movement in the current context
     * @param field current context
     * @param radius to wich extent we can move
     * */
    void random(Field& field, size_t radius);
    
};

#endif //MOVEACTION_H