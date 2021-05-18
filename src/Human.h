//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_HUMAN_H
#define POO2LABO4_HUMAN_H

#include "Humanoid.h"

#include <windows.h>
#include <iostream>

class Human : public Humanoid{


private:
    static const unsigned _COLOR_GUI = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;

public:

    std::ostream& toStream(std::ostream& os) const override {

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, _COLOR_GUI);

        return os << "h";
    }
};

#endif //POO2LABO4_HUMAN_H
