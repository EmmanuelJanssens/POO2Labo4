#ifndef ACTION_H
#define ACTION_H

#include "../Field.h"

/**
 * @brief Action interface
 * 
 * @file Action.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * */
class Action{
    public:

    /**
     * Abstract method, each class that extends this class must have this function
     * implemented
     * 
     * @param field current field on wich the action will be executed
     * */
    virtual void execute(Field& field) const = 0;


    /**
     * @brief Destroy the Action object
     * 
     */
    virtual ~Action() = default;
};
#endif //ACTION_H