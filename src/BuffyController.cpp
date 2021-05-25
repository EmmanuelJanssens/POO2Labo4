#include "../include/BuffyController.h"

BuffyController::BuffyController(){}

void BuffyController::start(BuffyView &view) {
    Field f(15,15);

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
                std::cout << "NEXT" << std::endl; // debug
                break;
            default:
                break;
        }
    }
}


