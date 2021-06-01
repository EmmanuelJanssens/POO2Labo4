#ifndef FIELD_H
#define FIELD_H

#include <list>
#include <vector>
#include "Cell.h"


class Humanoid;
class Human;
class Vampire;
class Hunter;
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

    size_t getTurn() const;


    int getWidth() const;

    int getHeight() const;    

     Humanoid* getHumanoidAt(const Cell& pos) const;

     void addHumanoid(Humanoid* h);

    // Retourne les humanoids à distance 1 du prédateur (tous ceux juste autour)
    //std::list<Humanoid *> getAround(Humanoid* predator);

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