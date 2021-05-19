#include "../include/Field.h"
#include "../include/Entity/Humanoid.h"
#include <iostream>

Field::Field(int w, int h)
    :_turn(0),_w(w),_h(h),_row(w,nullptr),_grid(h,_row){
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


    std::cout<<" Initialize \n";
    //create empty grid
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            _grid.at(j).at(i) = new Cell(j,i);
            std::cout<< *_grid.at(j).at(i);
        }
        std::cout<<std::endl;
    }

    //put entities on random positions
    for(Humanoid* entity: _humanoids){

        int rand_i = rand()%h;
        int rand_j = rand()%w;
        entity->setPosition(*this,_grid.at(rand_i).at(rand_j));

    }

    std::cout<<" After init \n";

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){

            std::cout<< *_grid.at(j).at(i);
        }
        std::cout<<std::endl;
    }
}

Field::~Field(){
    for(Humanoid* h : _humanoids){
        if(h != nullptr)
            delete h;
        h = nullptr;
    }

    for(std::vector<Cell*> row: _grid){
        for(Cell* c: row){
            delete c;
        }
    }
}
size_t Field::nextTurn(){
    
    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it!= _humanoids.end(); it++){
        std::cout<<"Entity Current pos "<<*(*it)->getPos()<<std::endl;
        (*it)->setAction(*this);
    }

    for(std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++){
        (*it)->executeAction(*this);
        std::cout<<"Entity Current pos (After Move) "<<*(*it)->getPos()<<std::endl;
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


void Field::cleanCells(){
    for(std::vector<Cell*> row : _grid){
        for(Cell* c : row){
            c->removeAll();
        }
    }
}
int Field::getWidth() const{
    return _w;
}

int Field::getHeight() const{
    return _h;
}

Cell* Field::getCellAt(int i, int j){
    return _grid.at(i).at(j);
}
