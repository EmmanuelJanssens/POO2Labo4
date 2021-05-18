#ifndef HUMANOID_H
#define HUMANOID_H
#include "../Cell.h"
#include "../Action/Action.h"
class Field;
class Humanoid{
    
    bool _isAlive;

    Cell _position;

    Action* _action;
    public:


    /**
     * Set the action to be executed
     * @param field context in wich the action will be executed
     * */
    void setAction(Field& field);

    /**
     * Execute the previously set action
     * @param field context in wich the action will be executed
     * */
    void executeAction(Field& field);


    /**
     * Wether the current entity exists 
     * @return true if the entity exists
     * @return false if the entity does not exists
     * */
    bool isAlive();

    Cell getPos();
};

#endif //HUMANOID_H