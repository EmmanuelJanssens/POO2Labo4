#include <iostream>
#include "include/Field.h"
#include "include/Entity/Humanoid.h"
#include "include/Action/MoveAction.h"

using namespace std;


int main(int argc, char* argv[]){
    srand (time(NULL));

    Field f(10,10);

    cout<<"\n\n\nplay\n\n\n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout<<*f.getCellAt(j,i);
        }
        cout<<endl;
    }

    f.nextTurn();
    cout<<"\n\n\nplay\n\n\n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout<<*f.getCellAt(j,i);
        }
        cout<<endl;
    }
    return EXIT_SUCCESS;
}