#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "Action.h"
#include "../Cell.h"
#include <vector>
class MoveAction : public Action{

    Humanoid* _target;

    //position to be acheived
    Cell* _endPos;

    //distance to be travelled
    int _distance;

    typedef Cell*(MoveAction::*RandomMove)(Field& field);
    RandomMove _rmove[8];


    /**
     *       ^
     *     \ | /
     *    <- x ->
     *     / | \
     *       v
     * */
    Cell* Up(Field& field);
    Cell* Down(Field& field);
    Cell* Left(Field& field);
    Cell* Right(Field& field);
    Cell* UpRight(Field& field);
    Cell* DownRight(Field& field);
    Cell* UpLeft(Field& field);
    Cell* DownLeft(Field& field);
    


    public:

    /**
     * Constructor
     * @param targetPos the target to be modified
     * */
    MoveAction(Humanoid* targetPos, int distance);
    
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