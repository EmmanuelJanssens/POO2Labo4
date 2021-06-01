
#ifndef POO2LABO4_DISPLAYABLE_H
#define POO2LABO4_DISPLAYABLE_H
class BuffyView;

/**
 * @brief All classes that inherit this must implement a render function
 * @file Displayable.h
 * @author Chhen Rosalie
 * @author Janssens Emmanuel
 */
class Displayable{
public:
    /**
     * @brief render onto a displayer
     * 
     * @param view 
     */
    virtual void render(const BuffyView& view) const = 0;};

#endif //POO2LABO4_DISPLAYABLE_H
