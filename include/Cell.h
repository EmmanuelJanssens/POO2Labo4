#ifndef CELL_H
#define CELL_H

#include <algorithm>
#include <list>
#include <iostream>


/**
 * @brief Represents coordinates onto a 2D plane
 * 
 * @file Cell.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class Cell{

    //x position
    int _x;

    //y position
    int _y;

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

    /**
     * @brief get X position
     * 
     * @return int 
     */
    int getX() const;

    /**
     * @brief get Y position
     * 
     * @return int 
     */
    int getY() const;

    /**
     * @brief Affectation operator
     * 
     * @param c 
     * @return Cell& 
     */
    Cell& operator=(const Cell& c);

    /**
     * @brief equal comparator operator
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    bool operator==(const Cell& c);
    
    /**
     * @brief Display a cell (mainly for debug purposes)
     * 
     * @param op 
     * @param c 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& op, const Cell& c);

    /**
     * @brief  Returns distance between two cells, with cells as units
     * 
     * @param c 
     * @return int 
     */
    int distanceTo(const Cell& c) const;
};



#endif //CELL_H