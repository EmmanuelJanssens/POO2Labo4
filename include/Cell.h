#ifndef CELL_H
#define CELL_H

#include <algorithm>
#include <list>

class Cell{

    //x position
    size_t _x;

    //y position
    size_t _y;


    public:

    /**
     * Default constructor
     * */
    Cell();

    /**
     * Copy constructor
     * @param c cell to copy coordinates from
     * */
    Cell(const Cell& c);

    /**
     * Set individual coordinates
     * @param x x coordinates
     * @param y y coordinates
     * */
    Cell(size_t x, size_t y);

    /**
     * Set the coordinates
     * @param x x coordinates
     * @param y y coordinates
     * */

    void setCoord(size_t x, size_t y);
    
    /**
     * Set the coordinates
     * @param c cell to copy coordinates from
     * */
    void setCoord(const Cell& c);


    size_t getX();
    size_t getY();
};

#endif //CELL_H