#ifndef FIELD_H
#define FIELD_H

#include <list>

class Humanoid;
class Field{

    //current turn id
    int _turn;

    //list of humanoids/entities present in the scene
    std::list<Humanoid*> _humanoids;

    public:

    /**
     * Constructor
     * */
    Field(int w, int h);

    /**
     * Handles a turn
     * @return next turn identifier
     * */
    int nextTurn();
};

#endif //FIELD_H