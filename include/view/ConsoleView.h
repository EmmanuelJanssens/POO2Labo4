#ifndef POO2LABO4_CONSOLEVIEW_H
#define POO2LABO4_CONSOLEVIEW_H

#include "../Field.h"
#include "BuffyView.h"

#include <windows.h>
#include <iostream>

/**
 * @brief Display in a windows console
 * 
 * @file ConsoleView.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class ConsoleView : public BuffyView{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    static const unsigned _VAMPIRE_COLOR = FOREGROUND_BLUE;
    static const unsigned _HUMAN_COLOR = 13;
    static const unsigned _HUNTER_COLOR = 6;

    static const char _VAMPIRE_SYMBOL = 'V';
    static const char _HUMAN_SYMBOL = 'h';
    static const char _HUNTER_SYMBOL = 'B';
    static const char _EMPTY_SYMBOL = ' ';

    static const char _VERTICAL_BORDER = '|';
    static const char _HORIZONTAL_BORDER = '-';
    static const char _CORNER = '+';

    static const char _QUIT_KEY = 'q';
    static const char _STATISTICS_KEY = 's';
    static const char _NEXT_KEY_1 = 'n';


public:

    /**
     * @brief Construct a new Console View object
     * 
     */
    explicit ConsoleView();

    /**
     * @brief prints a human on the console
     * 
     * @param human 
     */
    void display(const Human& human) const override;

    /**
     * @brief prints a hunter on the console
     * 
     * @param hunter 
     */
    void display(const Hunter& hunter) const override;

    /**
     * @brief print a vampier on the console
     * 
     * @param vampire 
     */
    void display(const Vampire& vampire) const override;

    /**
     * @brief print all the humanoids on the console as well as the outer bounds
     * 
     * @param field 
     */
    void display(const Field& field) const override;

    /**
     * @brief handle simple user input
     * 
     * @return Command 
     */
    Command processInput() const override;
};


#endif //POO2LABO4_CONSOLEVIEW_H
