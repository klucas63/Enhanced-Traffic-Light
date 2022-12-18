#ifndef WALK_H
#define WALK_H

class Walk {
private:

public:
    Walk();
    ~Walk();

    WALKSTATES walkLightState = ST_WALKRED;

    void ChangeWalk(int grn, int red);
};
#endif