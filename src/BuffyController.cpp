#include "../include/BuffyController.h"
#include "../include/Entity/Hunter.h"
#include "../include/Entity/Vampire.h"
#include "../include/Entity/Human.h"

#include <iomanip>

Cell randomPos(unsigned w, unsigned h);

BuffyController::BuffyController(){}


Cell randomPos(unsigned w, unsigned h){
    unsigned rand_i = rand()%h;
    unsigned rand_j = rand()%w;

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
                break;
            case STATISTICS:
                statistics();
                break;
            case NEXT:
                f.nextTurn();
                break;
            default:
                break;
        }
    }
}

void BuffyController::statistics()  {
    Field simulation(FIELD_WIDTH, FIELD_HEIGHT);

    Hunter toCheckClosestHumanoid(Cell(0,0));

    unsigned nbBuffySuccess = 0;

    for(unsigned i = 0; i < NB_SIMULATIONS; i++){
        simulation.resetField();
        initHumanoids(simulation);

        while(simulation.getClosestHumanoidTo<Vampire>(toCheckClosestHumanoid) != nullptr){
            simulation.nextTurn();
        }

        if(simulation.getClosestHumanoidTo<Human>(toCheckClosestHumanoid) != nullptr){
            nbBuffySuccess++;
        }
    }

    double percentBuffySuccess = (static_cast<double> (nbBuffySuccess) * 100) / NB_SIMULATIONS;

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


