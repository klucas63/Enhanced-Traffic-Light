#include <Arduino.h>
#include "config.h"
#include "walk.h"

Walk::Walk() {

};

Walk::~Walk() {

};

void Walk::ChangeWalk(int grn, int red) {
    switch (walkLightState)
    {
    case ST_WALKRED:
        digitalWrite(red,HIGH);
        digitalWrite(grn,LOW);
        break;
    
    case ST_REDFLASH:
        digitalWrite(red,!digitalRead(red));
        digitalWrite(grn,LOW);
        break;

    case ST_WALKGREEN:
        digitalWrite(red,LOW);
        digitalWrite(grn,HIGH);
        break;

    default:
        break;
    }
};