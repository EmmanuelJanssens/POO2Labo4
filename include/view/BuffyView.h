#ifndef POO2LABO4_BUFFYVIEW_H
#define POO2LABO4_BUFFYVIEW_H


#include "../Entity/Humanoid.h"
#include "../Entity/Vampire.h"
#include "../Entity/Hunter.h"

class BuffyView {

public:

    virtual void display(const Humanoid& human) const = 0;
    virtual void display(const Hunter& hunter) const = 0;
    virtual void display(const Vampire& vampire) const = 0;
    virtual void display(const Field& field) const = 0;

};


#endif //POO2LABO4_BUFFYVIEW_H
