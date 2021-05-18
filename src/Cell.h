//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_CELL_H
#define POO2LABO4_CELL_H

#include "Humanoid.h"

#include <list>

class Cell {

private:
    unsigned _x;
    unsigned _y;
    std::list<Humanoid*> _humanoids;
public:
    Cell(unsigned x, unsigned y);
    void addHumanoid(Humanoid* h);

};


#endif //POO2LABO4_CELL_H
