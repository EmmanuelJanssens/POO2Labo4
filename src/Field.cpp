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

    unsigned nbHumans = 5;
    unsigned nbVampires = 3;
    for(unsigned i = 0; i < nbHumans; i++){
        _humanoids.push_back(new Human(randomPos(w,h)));
    }
    for(unsigned i = 0; i < nbVampires; i++){
        _humanoids.push_back(new Vampire(randomPos(w,h)));
    }
    _humanoids.push_back(new Hunter(randomPos(w,h)));
    */
}

void Field::initHumanoids(const std::list<Humanoid *>& humanoids) {
    _humanoids = humanoids;
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


 Humanoid* Field::getHumanoidAt(const Cell& pos) const {

    auto it = find_if(_humanoids.begin(), _humanoids.end(), [pos](Humanoid* h) {
        return h->getPos() == pos;
    });
    return it != _humanoids.end() ? *it : nullptr;
}
int Field::getWidth() const{
    return _w;
}

int Field::getHeight() const{
    return _h;
}

Human *Field::getClosestHuman(const Vampire &predator) const {
    Human* found = nullptr;
    int minimalDistance = std::numeric_limits<int>:: max();

    for(Humanoid* h : _humanoids){
        if(dynamic_cast<Human*>(h)){
            int newDistance = predator.getPos().distanceTo(h->getPos());
            if(newDistance < minimalDistance){
                minimalDistance = newDistance;
                found = (Human*)h;
            }
        }
    }

    return found;
}

Vampire *Field::getClosestVampire(const Hunter &predator) const {
    Vampire* found = nullptr;
    int minimalDistance = std::numeric_limits<int>:: max();

    for(Humanoid* h : _humanoids){
        if(dynamic_cast<Vampire*>(h)){
            int newDistance = predator.getPos().distanceTo(h->getPos());
            if(newDistance < minimalDistance){
                minimalDistance = newDistance;
                found = (Vampire*)h;
            }
        }
    }

    return found;
}

void Field::addHumanoid(Humanoid *h) {
    if(h != nullptr){
        _humanoids.push_back(h);
    }
}

size_t Field::getTurn() const {
    return _turn;
}
