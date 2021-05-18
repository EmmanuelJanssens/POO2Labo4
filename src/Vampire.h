//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_VAMPIRE_H
#define POO2LABO4_VAMPIRE_H

#include <windows.h>
#include <iostream>

#include "Humanoid.h"

class Vampire : public Humanoid{

private:
    static const unsigned _COLOR_GUI = FOREGROUND_BLUE;

public:
    std::ostream& toStream(std::ostream& os) const override{

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, _COLOR_GUI);

        return os << "V";
    }
};

#endif //POO2LABO4_VAMPIRE_H
