//
// Created by Rosalie Chhen on 19.05.2021.
//

#include "../include/BuffyController.h"

BuffyController::BuffyController(){}

void BuffyController::start(BuffyView &view) {
    Field f(15,15);
    view.display(f);
}


