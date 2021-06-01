//#include "../../include/Entity/Human.h"
#include "../view/BuffyView.h"
#include "../Field.h"
#include "Humanoid.h"

class Vampire : public Humanoid{
public:
    Vampire(const Cell& pos);

    void render(const BuffyView& view) const override;
    void setAction(Field& field) override;
};