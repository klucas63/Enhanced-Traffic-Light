#ifndef TRAFFIC_H
#define TRAFFIC_H
#include "config.h"
#include "walk.h"
#include "timers.h"

class Traffic {
private:
    TRAFFICSTATES trafficLightState1 = ST_RED;
    TRAFFICSTATES trafficLightState2 = ST_GREEN;

public:
    Timers timers1;
    Timers timers2;
    Walk walk1;
    Walk walk2;

    Traffic();
    ~Traffic();

    void CycleLights();
    void ChangeLights(TRAFFICSTATES, int, int, int);
};
#endif