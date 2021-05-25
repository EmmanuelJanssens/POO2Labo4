//
// Created by Rosalie Chhen on 17.05.2021.
//

#include "../../include/view/ConsoleView.h"
#include "../../include/Entity/Humanoid.h"
#include "../../include/Entity/Human.h"
#include "../../include/Entity/Vampire.h"


#include <iostream>


using namespace std;

ConsoleView::ConsoleView() {}

void ConsoleView::display(const Human &human) const {
    SetConsoleTextAttribute(hConsole, _HUMAN_COLOR);
    cout << _HUMAN_SYMBOL;
}

void ConsoleView::display(const Hunter &hunter) const {

}

void ConsoleView::display(const Vampire &vampire) const {
    SetConsoleTextAttribute(hConsole, _VAMPIRE_COLOR);
    cout << _VAMPIRE_SYMBOL;
}

void ConsoleView::display(const Field &field)  {

    SetConsoleTextAttribute(hConsole, 15); // set color console text

    string horizontal_border(field.getWidth(), _HORIZONTAL_BORDER);
    cout << _CORNER << horizontal_border << _CORNER << endl;

    // Draw vampires, humans and Buffy
    for(unsigned iLine = 0; iLine < field.getHeight(); iLine++){
        cout << _VERTICAL_BORDER;
        for(unsigned iCol = 0; iCol < field.getWidth(); iCol++){
            Cell* cellToDisplay = field.getCellAt(iLine, iCol);
            //cout << "(" << cellToDisplay->getX() << "," << cellToDisplay->getY() << ")"; // DEBUG, TO ERASE
            if(cellToDisplay->hasEntity()){
                //display(*cellToDisplay->getEntitiesOnCell().back());
                (cellToDisplay->getEntitiesOnCell().back())->render(*this); // on display le dernier de la liste sur une cellule
                SetConsoleTextAttribute(hConsole, 15); // reset color console text
            } else {
                cout << _EMPTY_SYMBOL;
            }
        }
        cout << _VERTICAL_BORDER << "\n";
    }
    cout << _CORNER << horizontal_border << _CORNER << endl;

}
