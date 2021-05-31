#include "../../include/Entity/Humanoid.h"
#include "../view/BuffyView.h"

class Hunter : public Humanoid{
public:

    Hunter(const Cell& pos);

    void render(const BuffyView& view) const override;
    void setAction(Field& field) override;
};