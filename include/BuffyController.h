#ifndef POO2LABO4_BUFFYCONTROLLER_H
#define POO2LABO4_BUFFYCONTROLLER_H

#include "Field.h"
#include "view/BuffyView.h"
#include "view/ConsoleView.h"

class BuffyView;

/**
 * @brief Main application controller
 * 
 * @file BuffyController.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class BuffyController {

public:

    /**
     * @brief Construct a new Buffy Controller object
     * 
     */
    BuffyController();

    /**
     * @brief start the application
     * 
     * @param view 
     */
    void start(BuffyView& view);
};


#endif //POO2LABO4_BUFFYCONTROLLER_H
