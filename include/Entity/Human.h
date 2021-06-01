#ifndef POO2LABO4_HUMAN_H
#define POO2LABO4_HUMAN_H

#include "Humanoid.h"
#include "../view/BuffyView.h"

/**
 * @brief Represents a simple human that moves randomly accross the field
 * 
 * @file Human.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class Human : public Humanoid{

public:

    /**
     * @brief Construct a new Human object
     * 
     * @param pos initial position of the human
     */
    Human(const Cell& pos);

    /**
     * @brief display on a displayer
     * 
     * @param view view on wich it should be displayed
     */
    void render(const BuffyView& view) const override;

    /**
     * @brief Set the Action object
     * 
     * @param field current context
     */
    void setAction(Field& field) override;

    /**
     * @brief Get the freshly converted human into a vampire
     * 
     * @return Vampire* 
     */
    Vampire* getVampirized();

    /**
     * @brief Destroy the Human object
     * 
     */
    ~Human() = default;
};


#endif //POO2LABO4_HUMAN_H
