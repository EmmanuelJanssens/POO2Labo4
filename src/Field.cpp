#include "../include/Field.h"

#include <iostream>


Field::Field(unsigned w, unsigned h)
    :_turn(0),_w(w),_h(h){}

Field::~Field(){
    for(Humanoid* h : _humanoids){
        if(h != nullptr)
            delete h;
        h = nullptr;
    }
}
size_t Field::nextTurn(){
    
    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it!= _humanoids.end(); it++){
        (*it)->setAction(*this);
    }


    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++){
        (*it)->executeAction(*this);
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


 Humanoid* Field::getHumanoidAt(const Cell& pos) const {

    auto it = find_if(_humanoids.begin(), _humanoids.end(), [pos](Humanoid* h) {
        return h->getPos() == pos;
    });
    return it != _humanoids.end() ? *it : nullptr;
}

unsigned Field::getWidth() const{
    return _w;
}

unsigned Field::getHeight() const{
    return _h;
}


void Field::addHumanoid(Humanoid *h) {
    if(h != nullptr){
        _humanoids.push_back(h);
    }
}

size_t Field::getTurn() const {
    return _turn;
}

void Field::resetField() {
    _turn = 0;
    for(Humanoid* h : _humanoids){
        delete h;
    }
    _humanoids.clear();
}
