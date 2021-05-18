//
// Created by Rosalie Chhen on 17.05.2021.
//

#include "Field.h"

Field::Field(unsigned size, unsigned nbHumans, unsigned nbVampires) : _size(size){
    for(unsigned i = 0; i < nbHumans; i++){
        _humanoids.push_back(new Human);
    }

    for(unsigned i = 0; i < nbVampires; i++){
        _humanoids.push_back(new Vampire);
    }
}

std::list<Humanoid*> Field::getHumanoids() const{
    return _humanoids;
}

unsigned Field::getSize() const{
    return _size;
}

std::list<Cell*> Field::getCells() const{
    return _cells;
}
