#ifndef POO2LABO4_VAMPIRIZEACTION_H
#define POO2LABO4_VAMPIRIZEACTION_H

#include "Action.h"
class VampirizeAction : public Action{
private:
    Human* _victim;
public:
    VampirizeAction(Human* victim);
    void execute(Field& field) const override;
};


#endif //POO2LABO4_VAMPIRIZEACTION_H
