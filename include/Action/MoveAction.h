#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "Action.h"
#include "../Cell.h"
#include <vector>


/**
 * @brief Implements simple movement for a Humanoid
 *              - Random movement
 *              - Approaching movement
 * 
 * @file MoveAction.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class MoveAction : public Action{


    //target to move
    Humanoid& _target;

    //position to reach
    Cell _endPos;

    //distance to be travelled
    int _distance;


    //
    typedef Cell(MoveAction::*RandomMove)(const Field& field);

    //array of possible moves
    RandomMove _rmove[8];


    /**
     *       ^
     *     \ | /
     *    <- x ->
     *     / | \
     *       v
     * */

    /**
     * @brief Move up
     * 
     * @param field 
     * @return Cell 
     */
    Cell Up(const Field& field);

    /**
     * @brief Move down
     * 
     * @param field 
     * @return Cell 
     */
    Cell Down(const Field& field);

    /**
     * @brief Move Left
     * 
     * @param field 
     * @return Cell 
     */
    Cell Left(const Field& field);

    /**
     * @brief Move Right
     * 
     * @param field 
     * @return Cell 
     */
    Cell Right(const Field& field);

    /**
     * @brief Move Up-Right
     * 
     * @param field 
     * @return Cell 
     */
    Cell UpRight(const Field& field);

    /**
     * @brief Move Down-right
     * 
     * @param field 
     * @return Cell 
     */
    Cell DownRight(const Field& field);

    /**
     * @brief Move Up-left
     * 
     * @param field 
     * @return Cell 
     */
    Cell UpLeft(const Field& field);

    /**
     * @brief Move Down Left
     * 
     * @param field 
     * @return Cell 
     */
    Cell DownLeft(const Field& field);



    public:

    /**
     * @brief Constructor
     *
     * @param targetPos the target to be modified
     * */
    MoveAction(Humanoid& targetPos, int distance);
    
    /**
     * @brief Movement's own action
     *
     * @param field in what context we should move
     * */
    void execute(Field& field) const override;

    /**
     * @brief Calculate a random movement in the current context
     *
     * @param field current context
     * @param radius to wich extent we can move
     * */
    void random(const Field& field );

    /**
     * @brief Calculate a movement which get the moving target closer to
     * a position, the movement has nbSteps as distance
     * 
     * @param destination The position to get closer to
     * @param nbSteps 
     */
    void getCloserTo(const Cell& destination, unsigned nbSteps);


};

#endif //MOVEACTION_H