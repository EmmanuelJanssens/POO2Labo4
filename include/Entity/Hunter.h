#ifndef HUNTER_H
#define HUNTER_H
#include "../../include/Entity/Humanoid.h"

/**
 * @brief Represent a hunter
 * 
 * @file Hunter.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 * 
 */
class Hunter : public Humanoid{
public:

    /**
     * @brief Construct a new Hunter object
     * 
     * @param pos initial position
     */
    Hunter(const Cell& pos);

    /**
     * @brief Displays on to a renderer
     * 
     * @param view view to be displayed on
     */
    void render(const BuffyView& view) const override;

    /**
     * @brief Set the Action object
     * 
     * @param field field where the action will be executed
     */
    void setAction(Field& field) override;

    /**
     * @brief destructor
     * */
    ~Hunter() = default;
};

#endif //HUNTER_H