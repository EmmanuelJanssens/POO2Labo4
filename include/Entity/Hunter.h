#include "../../include/Entity/Humanoid.h"
#include "../view/BuffyView.h"

class Hunter : public Humanoid{
public:
    void render(BuffyView& view) const override;
};