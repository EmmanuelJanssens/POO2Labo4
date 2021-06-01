#include "MoveAction.h"

class KillAction : public Action{
private:

    Humanoid* _victim;
public:
    KillAction(Humanoid* victim);
    void execute(Field& field) const override;

};