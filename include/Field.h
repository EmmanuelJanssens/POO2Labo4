#ifndef FIELD_H
#define FIELD_H

#include <list>
#include <vector>
#include "Cell.h"

/**class predeclarations**/
class Humanoid;
class Human;
class Vampire;
class Hunter;

/**
 * @brief Main field on wich entities will move and behave
 * 
 * @file Field.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 */
class Field{

    //current turn id
    size_t _turn;

    //field width
    const unsigned _w;

    //field height
    const unsigned _h;

    //list of humanoids/entities present in the scene
    std::list<Humanoid*> _humanoids;

    public:

    /**
     * Constructor
     * */
    Field(unsigned w, unsigned h);

    ~Field();
    /**
     * Handles a turn
     * @return next turn identifier
     * */
    size_t nextTurn();

    /**
     * @brief return current  turns
     * 
     * @return size_t 
     */
    size_t getTurn() const;

    /**
     * @brief Get the field width
     * 
     * @return int 
     */
    int getWidth() const;



    /**
     * @brief Get Field height
     * 
     * @return int 
     */
    int getHeight() const;    

    /**
     * @brief Get the Humanoid At a certain position
     * 
     * @param pos 
     * @return Humanoid* 
     */
     Humanoid* getHumanoidAt(const Cell& pos) const;

    /**
     * @brief Add an entity onto the field
     * 
     * @param h 
     */
     void addHumanoid(Humanoid* h);



    // Retourne l'humain le plus proche
    Human* getClosestHuman(const Vampire& predator) const;

    // Retourne l'humain le plus proche
    Vampire* getClosestVampire(const Hunter& predator) const;

    void initHumanoids(const std::list<Humanoid*>& humanoids);

    template<typename T>
    Humanoid* getClosestHumanoidTo(const Humanoid &predator) const;

    void resetField();

};

#endif //FIELD_H