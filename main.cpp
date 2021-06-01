#include <time.h>
#include <iostream>
#include "include/Field.h"
#include "include/Entity/Humanoid.h"
#include "include/Action/MoveAction.h"
#include "include/BuffyController.h"


using namespace std;


int main(int , char* []){
    srand (time(NULL));

    BuffyController bc;
    bc.start(*new ConsoleView());

    return EXIT_SUCCESS;
}