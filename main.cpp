#include <iostream>
#include "include/Field.h"
#include "include/Entity/Humanoid.h"
#include "include/Action/MoveAction.h"

using namespace std;


int main(int argc, char* argv[]){

    Field f(10,10);

    cout<<f.nextTurn()<<endl;
    cout<<f.nextTurn()<<endl;
    return EXIT_SUCCESS;
}