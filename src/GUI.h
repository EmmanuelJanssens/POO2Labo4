//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_GUI_H
#define POO2LABO4_GUI_H

#include "Field.h"

class GUI {

    const Field* _field;

public:
    explicit GUI(const Field *f);
    void display() const;
};


#endif //POO2LABO4_GUI_H
