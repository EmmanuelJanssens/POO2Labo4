#include "../../include/Entity/Humanoid.h"
#include "../view/BuffyView.h"

class Vampire : public Humanoid{
public:
    void render(BuffyView& view) const override;
};