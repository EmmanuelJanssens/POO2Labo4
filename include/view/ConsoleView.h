//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_CONSOLEVIEW_H
#define POO2LABO4_CONSOLEVIEW_H

#include "../Field.h"
#include "BuffyView.h"

#include <windows.h>
#include <iostream>

class ConsoleView : public BuffyView{

    const Field* _field; // TODO pas besoin peut-être

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    static const unsigned _VAMPIRE_COLOR = FOREGROUND_BLUE;
    static const unsigned _HUMAN_COLOR = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;

    static const char _VAMPIRE_SYMBOL = 'V';
    static const char _HUMAN_SYMBOL = 'h';
    static const char _EMPTY_SYMBOL = ' ';

public:
    explicit ConsoleView(const Field *f);

    void display(const Humanoid& human) const;
    void display(const Hunter& hunter) const;
    void display(const Vampire& vampire) const;
    void display(const Field& field) const;
    void displayBorders(const Field& field)const;
};


#endif //POO2LABO4_CONSOLEVIEW_H
