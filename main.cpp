#include <iostream>
#include "include/Field.h"
#include "include/Entity/Humanoid.h"
#include "include/Action/MoveAction.h"

using namespace std;


int main(int argc, char* argv[]){
    srand (time(NULL));

    Field f(10,10);

    cout<<"Start turn \n"<<f.nextTurn()<<endl;
    cout<<"Start turn \n"<<f.nextTurn()<<endl;
    return EXIT_SUCCESS;
}