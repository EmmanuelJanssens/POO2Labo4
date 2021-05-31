#ifndef POO2LABO4_HUMAN_H
#define POO2LABO4_HUMAN_H

#include "Humanoid.h"
#include "../view/BuffyView.h"

class Human : public Humanoid{
public:

    Human(const Cell& pos);

    void render(const BuffyView& view) const override;
    void setAction(Field& field) override;
};


#endif //POO2LABO4_HUMAN_H
