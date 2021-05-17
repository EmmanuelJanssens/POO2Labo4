#include "../include/Field.h"
#include "../include/Entity/Humanoid.h"

Field::Field(int w, int h)
    :_turn(0){
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());
    _humanoids.push_back(new Humanoid());

}
int Field::nextTurn(){
    
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