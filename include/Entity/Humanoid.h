#ifndef HUMANOID_H
#define HUMANOID_H
#include "../Cell.h"
#include "../Action/Action.h"
#include "../view/Displayable.h"

/**
 * @brief Predeclaration of the field
 * 
 */
class Field;

/**
 * @brief Abstract Humanoid class, base class of all displayable entities
 * 
 * @file Humanoid.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 */
class Humanoid : public Displayable{
    
    //vitals
    bool _isAlive = true;

    //current position in the field
    Cell _position;

    //Action to be performed
    Action* _action;

    public:

    /**
     * @brief Construct a new Humanoid object
     * 
     * @param pos initial position
     */
    Humanoid(const Cell& pos);

    /**
     * Set the action to be executed
     * @param field context in wich the action will be executed
     * */
    virtual void setAction(Field& field) = 0;

    /**
     * @brief Set a new action safely
     * 
     * @param action 
     */
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

    /**
     * @brief Get the Current position 
     * 
     * @return Cell position
     */
    Cell getPos() const;
    
    /**
     * @brief update the current position
     * 
     * @param pos new position
     */
    void move (const Cell& pos);

    /**
     * @brief render onto a displayer
     * 
     * @param view 
     */
    virtual void render(const BuffyView& view) const = 0;

    /**
     * @brief dies sets _isAlive to false
     * 
     */
    void dies();

    /**
     * @brief Destroy the Humanoid object
     * 
     */
    virtual ~Humanoid();
};

#endif //HUMANOID_H