#include "../include/Field.h"
#include "../include/Entity/Humanoid.h"
#include "../include/Entity/Hunter.h"
#include "../include/Entity/Vampire.h"
#include "../include/Entity/Human.h"

#include <iostream>

Field::Field(int w, int h)
    :_turn(0),_w(w),_h(h){
    //put entities on random positions
   /* for(Humanoid* entity: _humanoids){
        int rand_i = rand()%h;
        int rand_j = rand()%w;
    }
*/
    unsigned nbHumans = 5;
    unsigned nbVampires = 3;
    for(unsigned i = 0; i < nbHumans; i++){
        _humanoids.push_back(new Human(/*Set random pos*/));
    }
    for(unsigned i = 0; i < nbVampires; i++){
        _humanoids.push_back(new Vampire(/*Set random pos*/));
    }
    _humanoids.push_back(new Hunter(/*Set random pos*/));

}

Field::~Field(){
    for(Humanoid* h : _humanoids){
        if(h != nullptr)
            delete h;
        h = nullptr;
    }
}
size_t Field::nextTurn(){
    
    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it!= _humanoids.end(); it++){
        //std::cout<<"Entity Current pos "<<(*it)->getPos()<<std::endl;
        (*it)->setAction(*this);
    }

    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++){
        (*it)->executeAction(*this);
       //std::cout<<"Entity Current pos (After Move) "<<(*it)->getPos()<<std::endl;
    }

    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ){
        //std::cout<<(*it)->getPos()<<"x ";
        if( !(*it)->isAlive()){
            Humanoid* toDelete = *it;
            it = _humanoids.erase(it);
            //_grid[toDelete->getPos()->getX()][toDelete->getPos()->getY()]->removeEntity(*it);
            // effacer de la case aussi
            delete toDelete;
        }
        else{
            ++it;
        }
    }

    return _turn++;
}



int Field::getWidth() const{
    return _w;
}

int Field::getHeight() const{
    return _h;
}

/*std::list<Humanoid *> Field::getAround(Humanoid *predator) {

    int util[] = {-1, 0, 1};
    Cell* center = predator->getPos();
    std::list<Humanoid *> results;

    for(int u : util){
        for(int v : util){
            int xToCheck = center->getX() + u;
            int yToCheck = center->getY() + v;
            // pad depasser les bords et pas soi-meme
            if(xToCheck >= 0 && xToCheck < _w && yToCheck >= 0 && yToCheck < _h && !(u == 0 && v == 0)) {
                std::list<Humanoid *> humanoidsToCheck = getCellAt(xToCheck, yToCheck)->getEntitiesOnCell();
                for(Humanoid* h : humanoidsToCheck){
                    results.push_back(h);
                }
            }
        }
    }

    return results;
}


template<typename T>
Humanoid *Field::getClosestTo(Humanoid* predator)  {
    Humanoid* closestFound = nullptr;

    int minimalDistance = std::numeric_limits<int>:: max();

    for(Humanoid* h : _humanoids){
        if(dynamic_cast<T*>(h)){
            int newDistance = predator->getPos()->distanceTo(h->getPos());
            if(newDistance < minimalDistance){
                minimalDistance = newDistance;
                closestFound = h;
            }
        }
    }

    return closestFound;
}
*/