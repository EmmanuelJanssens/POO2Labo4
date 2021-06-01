#ifndef POO2LABO4_BUFFYVIEW_H
#define POO2LABO4_BUFFYVIEW_H

#include "Command.h"

/**class predeclaration**/
class Humanoid;
class Hunter;
class Vampire;
class Human;
class Field;

/**
 * @brief Abstract displayer, all classes that inherit this one must implement all the member functions
 * 
 * @file BuffyView.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class BuffyView {

public:

    /**
     * @brief Display a human
     * 
     * @param human 
     */
    virtual void display(const Human& human) const = 0;

    /**
     * @brief Display a hunter
     * 
     * @param hunter 
     */
    virtual void display(const Hunter& hunter) const = 0;

    /**
     * @brief Display a vampire
     * 
     * @param vampire 
     */
    virtual void display(const Vampire& vampire) const = 0;

    /**
     * @brief Display the field
     * 
     * @param field 
     */
    virtual void display(const Field& field) const = 0;

    /**
     * @brief Process user input
     * 
     * @return Command 
     */
    virtual Command processInput() const = 0;

};


#endif //POO2LABO4_BUFFYVIEW_H
