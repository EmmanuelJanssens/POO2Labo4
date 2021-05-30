#include "../../include/view/ConsoleView.h"
#include "../../include/Entity/Humanoid.h"
#include "../../include/Entity/Human.h"
#include "../../include/Entity/Vampire.h"


#include <iostream>
#include <string>


using namespace std;

ConsoleView::ConsoleView() {}

void ConsoleView::display(const Human &human) const {
    SetConsoleTextAttribute(hConsole, _HUMAN_COLOR);
    cout << _HUMAN_SYMBOL;
}

void ConsoleView::display(const Hunter &hunter) const {
    SetConsoleTextAttribute(hConsole, _HUNTER_COLOR);
    cout << _HUNTER_SYMBOL;
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
                // on display le dernier de la liste sur une cellule
                // Par liaison dynamique, va appeler le render() de Human, Vampire ou Hunter
                // qui va appeler la bonne surcharge de display dans la classe ConsoleView
                (cellToDisplay->getEntitiesOnCell().back())->render(*this);
                SetConsoleTextAttribute(hConsole, 15); // reset color console text
            } else {
                cout << _EMPTY_SYMBOL;
            }
        }
        cout << _VERTICAL_BORDER << "\n";
    }
    cout << _CORNER << horizontal_border << _CORNER << endl;

}


Command ConsoleView::processInput() const{
    char input;
    bool valid = false;
    Command command = DEFAULT;
    while(!valid){
        std::cout << "q)quit s)tatistics n)ext: ";
        input = (char) tolower(cin.get());
        if (input == '\n') {
            cout << "Enter key is pressed" << endl;
            command = NEXT;
            break;
        } else {

            switch(input) {
                case _QUIT_KEY:
                    valid = true;
                    command = QUIT;
                    break;
                case _STATISTICS_KEY:
                    valid = true;
                    command = STATISTICS;
                    break;
                case _NEXT_KEY_1:
                    valid = true;
                    command = NEXT;
                    break;
                default:
                    break;
            }
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return command;

}