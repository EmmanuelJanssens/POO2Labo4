#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "Cell.h"
class Humanoid;
class BoardCell: public Cell{

    //represents the entities that are on the current cell
    std::list<Humanoid> _entitiesOnCell;
    
};

#endif //BOARDCELL_H