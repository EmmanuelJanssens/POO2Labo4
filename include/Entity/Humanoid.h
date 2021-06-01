#ifndef HUMANOID_H
#define HUMANOID_H
#include "../Cell.h"
#include "../Action/Action.h"
#include "../view/Displayable.h"
class Field;
class Humanoid : public Displayable{
    
    bool _isAlive = true;

    Cell _position;

    Action* _action;
    public:
    
    Humanoid(const Cell& pos);

    /**
     * Set the action to be executed
     * @param field context in wich the action will be executed
     * */
    virtual void setAction(Field& field) = 0;

    void cleanAndSetAction(Action* action);


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

    Cell getPos() const;

    void move (const Cell& pos);

    virtual void render(const BuffyView& view) const = 0;

    void dies();

    virtual ~Humanoid();
};

#endif //HUMANOID_H