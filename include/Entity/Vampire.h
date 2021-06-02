#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Humanoid.h"


/**
 * @brief Represents a Vampire
 * 
 * @file Vampire.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class Vampire : public Humanoid{
public:

    /**
     * @brief Construct a new Vampire object
     * 
     * @param pos 
     */
    Vampire(const Cell& pos);

    /**
     * @brief Renders on to displayer
     * 
     * @param view view oni which to display
     */
    void render(const BuffyView& view) const override;

    /**
     * @brief Set the Action to be performed
     * 
     * @param field field on which the action will be performed
     */
    void setAction(Field& field) override;

    /**
     * @brief destructor
     * */
    ~Vampire() = default;
};

#endif