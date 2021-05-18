//
// Created by Rosalie Chhen on 17.05.2021.
//

#include "GUI.h"
#include <iostream>

using namespace std;

GUI::GUI(const Field *f) : _field(f){}

void GUI::display() const{
    // Display square borders
    for(unsigned i = 0; i < _field->getSize(); i++){

    }

    // Display humanoids
    for(Humanoid* h : _field->getHumanoids()){
        cout << *h;
    }
}