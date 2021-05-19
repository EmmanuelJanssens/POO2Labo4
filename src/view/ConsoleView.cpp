//
// Created by Rosalie Chhen on 17.05.2021.
//

#include "../../include/view/ConsoleView.h"
#include <iostream>

using namespace std;

ConsoleView::ConsoleView(const Field *f) : _field(f){}

void ConsoleView::display(const Humanoid &human) const {
    SetConsoleTextAttribute(hConsole, _HUMAN_COLOR);
    cout << _HUMAN_SYMBOL;
}

void ConsoleView::display(const Hunter &hunter) const {

}

void ConsoleView::display(const Vampire &vampire) const {
    SetConsoleTextAttribute(hConsole, _VAMPIRE_COLOR);
    cout << _VAMPIRE_SYMBOL;
}

void ConsoleView::display(const Field &field) const {

}

void ConsoleView::displayBorders(const Field& field) const {

}
