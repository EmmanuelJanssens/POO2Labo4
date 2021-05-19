#ifndef CELL_H
#define CELL_H

#include <algorithm>
#include <list>
#include <iostream>


class Humanoid;

class Cell{
    protected:
    //x position
    int _x;

    //y position
    int _y;

    std::list<Humanoid*> _entitiesOnCell;

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
    Cell(int x, int y);

    Cell(int x, int y, Humanoid* h);

    /**
     * Set the coordinates
     * @param x x coordinates
     * @param y y coordinates
     * */

    void setCoord(int x, int y);
    
    /**
     * Set the coordinates
     * @param c cell to copy coordinates from
     * */
    void setCoord(const Cell& c);


    int getX() const;
    int getY() const;

    void removeEntity(Humanoid* h);
    void removeAll();
    
    void setEntity(Humanoid* h);
    bool hasEntity();

    Cell& operator=(const Cell& c);

    friend std::ostream& operator<<(std::ostream& op, const Cell& c);
};



#endif //CELL_H