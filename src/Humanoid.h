//
// Created by Rosalie Chhen on 17.05.2021.
//

#ifndef POO2LABO4_HUMANOID_H
#define POO2LABO4_HUMANOID_H

#include <iostream>

class Humanoid{

    friend std::ostream& operator<<(std::ostream& os, const Humanoid& h) {
        return h.toStream(os);
    }

public:

    virtual std::ostream& toStream(std::ostream& os) const = 0;
};

#endif //POO2LABO4_HUMANOID_H
