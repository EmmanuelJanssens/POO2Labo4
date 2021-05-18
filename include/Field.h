#ifndef FIELD_H
#define FIELD_H

#include <list>

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
};

#endif //FIELD_H