#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "Action.h"
#include "../Cell.h"
#include <vector>
class MoveAction : public Action{

    //position to be modified
    Cell& _targetPos;

    //position to be acheived
    Cell _endPos;

    //distance to be travelled
    int _distance;

    typedef Cell(MoveAction::*RandomMove)();
    RandomMove _rmove[8];


    /**
     *       ^
     *     \ | /
     *    <- x ->
     *     / | \
     *       v
     * */
    Cell Up();
    Cell Down();
    Cell Left();
    Cell Right();
    Cell UpRight();
    Cell DownRight();
    Cell UpLeft();
    Cell DownLeft();
    

    /**
     * Check if the current position is in bounds before moving
     * */
    bool isInBoundsBeforeMove(Field& f,const Cell& c);

    public:

    /**
     * Constructor
     * @param targetPos the target to be modified
     * */
    MoveAction(Cell& targetPos, int distance);
    
    /**
     * Movement's own action
     * @param field in what context we should move
     * */
    void execute(Field& field) const override;

    /**
     * Calculate a random movement in the current context
     * @param field current context
     * @param radius to wich extent we can move
     * */
    void random(Field& field );
    
};

#endif //MOVEACTION_H