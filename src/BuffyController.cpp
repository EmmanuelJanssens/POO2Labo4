#include <iomanip>
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

    // Create field
    Field f(FIELD_WIDTH,FIELD_HEIGHT);

    // Init humanoids on random places on field
    initHumanoids(f);

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
                statistics();
                std::cout << "STATISTIC" << std::endl; // debug
                break;
            case NEXT:
                f.nextTurn();
                std::cout << "NEXT" << std::endl; // debug
                break;
            default:
                break;
        }
    }
}

void BuffyController::statistics()  {
    Field simulation(FIELD_WIDTH, FIELD_HEIGHT);
    Hunter toCheckVampires(Cell(0,0));
    Vampire toCheckHumans(Cell(0,0));

    unsigned nbBuffySuccess = 0;

    for(unsigned i = 0; i < NB_SIMULAITONS; i++){
        simulation.resetField();
        initHumanoids(simulation);

        while(simulation.getClosestVampire(toCheckVampires) != nullptr){
            simulation.nextTurn();
        }

        if(simulation.getClosestHuman(toCheckHumans) != nullptr){
            nbBuffySuccess++;
        }
    }

    double percentBuffySuccess = ((double) nbBuffySuccess * 100) / NB_SIMULAITONS;
    std::cout << "nbBuffySuccess : " << nbBuffySuccess << std::endl;

    std::cout << "Pourcentage de succes de Buffy : " << percentBuffySuccess << "%" << std::endl;
}

void BuffyController::initHumanoids(Field& field) {
    for(unsigned i = 0; i < NB_HUMANS; i++){
        field.addHumanoid(new Human(randomPos(field.getWidth(),field.getHeight())));
    }

    for(unsigned i = 0; i < NB_VAMPIRES; i++){
        field.addHumanoid(new Vampire(randomPos(field.getWidth(),field.getHeight())));
    }

    field.addHumanoid(new Hunter(randomPos(field.getWidth(),field.getHeight())));
}


