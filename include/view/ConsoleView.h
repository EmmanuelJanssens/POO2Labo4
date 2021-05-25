#ifndef POO2LABO4_CONSOLEVIEW_H
#define POO2LABO4_CONSOLEVIEW_H

#include "../Field.h"
#include "BuffyView.h"

#include <windows.h>
#include <iostream>

class ConsoleView : public BuffyView{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    static const unsigned _VAMPIRE_COLOR = FOREGROUND_BLUE;
    static const unsigned _HUMAN_COLOR = 13;//FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;

    static const char _VAMPIRE_SYMBOL = 'V';
    static const char _HUMAN_SYMBOL = 'h';
    static const char _EMPTY_SYMBOL = ' ';

    static const char _VERTICAL_BORDER = '|';
    static const char _HORIZONTAL_BORDER = '-';
    static const char _CORNER = '+';

    static const char _QUIT_KEY = 'q';
    static const char _STATISTICS_KEY = 's';
    static const char _NEXT_KEY_1 = 'n';
    static const char _NEXT_KEY = '\n';


public:
    explicit ConsoleView();

    void display(const Human& human) const override;
    void display(const Hunter& hunter) const override;
    void display(const Vampire& vampire) const override;
    void display(const Field& field) override;
    Command processInput() const override;
};


#endif //POO2LABO4_CONSOLEVIEW_H
