#include "../include/BuffyController.h"
#include "../include/Entity/Hunter.h"
#include "../include/Entity/Vampire.h"
#include "../include/Entity/Human.h"

BuffyController::BuffyController(){}


Cell randomPos(int w, int h){
    int rand_i = rand()%h;
    int rand_j = rand()%w;

    return Cell(rand_i,rand_j);
}

void BuffyController::start(BuffyView &view) {
    Field f(10,10);
    // Init entites
    unsigned nbHumans = 5;
    unsigned nbVampires = 3;
    std::list<Humanoid*> humanoidsToInit;
    for(unsigned i = 0; i < nbHumans; i++){
        humanoidsToInit.push_back(new Human(randomPos(f.getWidth(),f.getHeight())));
    }
    for(unsigned i = 0; i < nbVampires; i++){
        humanoidsToInit.push_back(new Vampire(randomPos(f.getWidth(),f.getHeight())));
    }
    humanoidsToInit.push_back(new Hunter(randomPos(f.getWidth(),f.getHeight())));

    f.initHumanoids(humanoidsToInit);

    bool running = true;

    while(running){

        view.display(f);
        Command inputUser = view.processInput();
        switch(inputUser){
            case QUIT:
                running = false;
                std::cout << "QUIT" << std::endl; // debug

                break;
            case STATISTICS:
                // call statistic method
                std::cout << "STATISTIC" << std::endl; // debug
                break;
            case NEXT:
                // Do the next simulation
                f.nextTurn();
                std::cout << "NEXT" << std::endl; // debug
                break;
            default:
                break;
        }
    }
}


