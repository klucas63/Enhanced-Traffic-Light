#ifndef TIMERS_H
#define TIMERS_H

class Timers {
private:
    unsigned long red_ms;
    unsigned long ylw_ms;
    unsigned long grn_ms;
    unsigned long lastCheckGrn_ms;
    unsigned long lastCheckYlw_ms;
    unsigned long lastCheckRed_ms;
    unsigned long lastCheckWalkRed_ms;

public:
    Timers();
    ~Timers();

    bool TimeToChangeGrn();
    bool TimeToChangeYlw();
    bool TimeToChangeRed();
    bool TimeToFlashWalk();
};
#endif