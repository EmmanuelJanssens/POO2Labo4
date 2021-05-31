#include "MoveAction.h"

class KillAction : public Action{
private:
    Humanoid* _target;

    //position to be acheived
    Cell* _endPos;
    Humanoid* _victim;
public:
    KillAction(Humanoid* targetPos, Humanoid* victim);
    void execute(Field& field) const override;
    void setEndPos(Cell* to);

};