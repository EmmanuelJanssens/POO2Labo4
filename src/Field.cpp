#include "../include/Field.h"
#include "../include/Entity/Humanoid.h"
#include <iostream>

Field::Field(int w, int h)
    :_turn(0),_w(w),_h(h){
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());

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
        std::cout<<"Entity Current pos "<<(*it)->getPos()<<std::endl;
        (*it)->setAction(*this);
    }

    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++){
        (*it)->executeAction(*this);
        std::cout<<"Entity Current pos (After Move) "<<(*it)->getPos()<<std::endl;
    }

    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ){
        if( !(*it)->isAlive()){
            Humanoid* toDelete = *it;
            it = _humanoids.erase(it);
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