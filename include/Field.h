#ifndef FIELD_H
#define FIELD_H

#include <list>
#include <vector>
#include "Cell.h"

class Humanoid;
class Field{

    //current turn id
    size_t _turn;

    //field width
    int _w;

    //field height
    int _h;

    //list of humanoids/entities present in the scene
    std::list<Humanoid*> _humanoids;

    public:

    /**
     * Constructor
     * */
    Field(int w, int h);

    ~Field();
    /**
     * Handles a turn
     * @return next turn identifier
     * */
    size_t nextTurn();


    int getWidth() const;

    int getHeight() const;    

     Humanoid* getHumanoidAt(const Cell& pos) const;

    // Retourne les humanoids à distance 1 du prédateur (tous ceux juste autour)
    //std::list<Humanoid *> getAround(Humanoid* predator);

    // Retourne l'humain le plus proche
    // cette methode peut être const
    //template <typename T>
    //Humanoid* getClosestTo(Humanoid* predator) ;


};

#endif //FIELD_H