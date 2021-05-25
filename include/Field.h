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


    std::vector<Cell*> _row;
    //list of cells of the game
    std::vector<std::vector<Cell*>> _grid;

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

    void cleanCells();

    int getWidth() const;

    int getHeight() const;    

    // TODO change param int to unsigned
    Cell* getCellAt(int i, int j) const;

};

#endif //FIELD_H