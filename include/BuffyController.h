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

    static const unsigned FIELD_WIDTH = 50;
    static const unsigned FIELD_HEIGHT = 50;

    static const unsigned NB_HUMANS = 20;
    static const unsigned NB_VAMPIRES = 10;

    static const unsigned NB_SIMULATIONS = 10000;

    /**
     * @brief Instanciate and put randomly humanoids on field
     *
     * @param field
     * */
    void initHumanoids(Field& field);

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

    /**
     * @brief Compute the success statistics of Buffy against Vampires
     * */
    void statistics();
};


#endif //POO2LABO4_BUFFYCONTROLLER_H
