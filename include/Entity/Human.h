#ifndef POO2LABO4_HUMAN_H
#define POO2LABO4_HUMAN_H

#include "Humanoid.h"
#include "../view/BuffyView.h"

class Human : public Humanoid{
public:
    void render(BuffyView& view) const override;
};


#endif //POO2LABO4_HUMAN_H
