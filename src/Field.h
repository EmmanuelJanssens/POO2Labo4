//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_FIELD_H
#define POO2LABO4_FIELD_H

#include "Humanoid.h"
#include "Human.h"
#include "Vampire.h"
#include "Cell.h"

#include <list>

class Field {

private:
    std::list<Humanoid*> _humanoids;
    unsigned _size;
    std::list<Cell*> _cells;
public:
    Field(unsigned size, unsigned nbHumans, unsigned nbVampires);
    std::list<Humanoid*> getHumanoids() const;
    unsigned getSize() const;
    std::list<Cell*> getCells() const;
};


#endif //POO2LABO4_FIELD_H
