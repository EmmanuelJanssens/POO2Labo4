#ifndef POO2LABO4_BUFFYCONTROLLER_H
#define POO2LABO4_BUFFYCONTROLLER_H

#include "Field.h"
#include "view/BuffyView.h"
#include "view/ConsoleView.h"

class BuffyView;
class BuffyController {
private:

    static const unsigned FIELD_WIDTH = 30;
    static const unsigned FIELD_HEIGHT = 30;

    static const unsigned NB_HUMANS = 20;
    static const unsigned NB_VAMPIRES = 10;

    static const unsigned NB_SIMULAITONS = 10000;

public:

    BuffyController();
    void start(BuffyView& view);
    void initHumanoids(Field& field);
    void statistics();
};


#endif //POO2LABO4_BUFFYCONTROLLER_H
