#include "Field.h"
#include "GUI.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    Field f(3,4);

    GUI gui(&f);

    gui.display();

    return EXIT_SUCCESS;
}