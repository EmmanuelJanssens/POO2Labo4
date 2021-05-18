//
// Created by Rosalie Chhen on 17.05.2021.
//

#include "Cell.h"

Cell::Cell(unsigned x, unsigned y) : _x(x), _y(y){

}

void Cell::addHumanoid(Humanoid* h){
    _humanoids.push_back(h);
}