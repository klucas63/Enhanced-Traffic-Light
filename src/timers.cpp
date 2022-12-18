#include <Arduino.h>
#include "config.h"
#include "timers.h"

Timers::Timers() {

};

Timers::~Timers() {

};

bool Timers::TimeToChangeGrn() {
    bool bRetVal = false;
    unsigned long current_ms = millis();

    if (lastCheckGrn_ms == 0) {
        lastCheckGrn_ms = current_ms;
    }

    if ((current_ms > lastCheckGrn_ms + REDGRNCYCLE)) {
        bRetVal = true;
        lastCheckGrn_ms = 0;
    }

    return bRetVal;
};

bool Timers::TimeToChangeYlw() {
    bool bRetVal = false;
    unsigned long current_ms = millis();

    if (lastCheckYlw_ms == 0) {
        lastCheckYlw_ms = current_ms;
    }

    if ((current_ms > lastCheckYlw_ms + YELLOWCYCLE)) {
        bRetVal = true;
        lastCheckYlw_ms = 0;
    }

    return bRetVal;
};

bool Timers::TimeToChangeRed() {
    bool bRetVal = false;
    unsigned long current_ms = millis();

    if (lastCheckRed_ms == 0) {
        lastCheckRed_ms = current_ms;
    }

    if ((current_ms > lastCheckRed_ms + REDGRNCYCLE + YELLOWCYCLE)) {
        bRetVal = true;
        lastCheckRed_ms = 0;
    }

    return bRetVal;
};

bool Timers::TimeToFlashWalk() {
    bool bRetVal = false;
    unsigned long current_ms = millis();

    if (lastCheckWalkRed_ms == 0) {
        lastCheckWalkRed_ms = current_ms;
    }

    if ((current_ms > lastCheckWalkRed_ms + ST_DONTWALKFLASH)) {
        bRetVal = true;
        lastCheckWalkRed_ms = 0;
    }

    return bRetVal;
}