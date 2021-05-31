#include "../../include/Entity/Human.h"
#include "../view/BuffyView.h"

class Vampire : public Humanoid{
public:
    void render(BuffyView& view) const override;
    void setAction(Field& field) override;
};