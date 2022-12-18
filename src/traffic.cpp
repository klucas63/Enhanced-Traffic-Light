#include <Arduino.h>
#include "config.h"
#include "traffic.h"

Traffic::Traffic() {
    ChangeLights(trafficLightState1,REDLGHT1PIN,YLWLGHT1PIN,GRNLGHT1PIN);
    ChangeLights(trafficLightState2,REDLGHT2PIN,YLWLGHT2PIN,GRNLGHT2PIN);
    walk1.ChangeWalk(GRNXWLK1PIN,REDXWLK1PIN);
    walk2.ChangeWalk(GRNXWLK1PIN,REDXWLK1PIN);
};

Traffic::~Traffic() {

};

void ::Traffic::CycleLights() {
    if(trafficLightState1 == ST_RED && timers1.TimeToChangeRed()) {
        Serial.println("green1");
        trafficLightState1 = ST_GREEN;
        walk1.walkLightState = ST_WALKGREEN;
        ChangeLights(trafficLightState1,REDLGHT1PIN,YLWLGHT1PIN,GRNLGHT1PIN);
        walk1.ChangeWalk(GRNXWLK1PIN,REDXWLK1PIN);
    }
    if(trafficLightState2 == ST_RED && timers2.TimeToChangeRed()) {
        Serial.println("green2");
        trafficLightState2 = ST_GREEN;
        walk2.walkLightState = ST_WALKGREEN;
        ChangeLights(trafficLightState2,REDLGHT2PIN,YLWLGHT2PIN,GRNLGHT2PIN);
        walk2.ChangeWalk(GRNXWLK2PIN,REDXWLK2PIN);
    }
    if(trafficLightState1 == ST_YELLOW && timers1.TimeToChangeYlw()) {
        Serial.println("red1");
        trafficLightState1 = ST_RED;
        walk1.walkLightState = ST_WALKRED;
        ChangeLights(trafficLightState1,REDLGHT1PIN,YLWLGHT1PIN,GRNLGHT1PIN);
        walk1.ChangeWalk(GRNXWLK1PIN,REDXWLK1PIN);
    }
    if(trafficLightState2 == ST_YELLOW && timers2.TimeToChangeYlw()) {
        Serial.println("red2");
        trafficLightState2 = ST_RED;
        walk2.walkLightState = ST_WALKRED;
        ChangeLights(trafficLightState2,REDLGHT2PIN,YLWLGHT2PIN,GRNLGHT2PIN);
        walk2.ChangeWalk(GRNXWLK2PIN,REDXWLK2PIN);
    }
    if(trafficLightState1 == ST_GREEN && timers1.TimeToChangeGrn()) {
        Serial.println("yellow1");
        trafficLightState1 = ST_YELLOW;
        walk1.walkLightState = ST_REDFLASH;
        ChangeLights(trafficLightState1,REDLGHT1PIN,YLWLGHT1PIN,GRNLGHT1PIN);
    }
    if(trafficLightState2 == ST_GREEN && timers2.TimeToChangeGrn()) {
        Serial.println("yellow2");
        trafficLightState2 = ST_YELLOW;
        walk2.walkLightState = ST_REDFLASH;
        ChangeLights(trafficLightState2,REDLGHT2PIN,YLWLGHT2PIN,GRNLGHT2PIN);
    }

    if (walk1.walkLightState == ST_REDFLASH && timers2.TimeToFlashWalk()) {
        walk1.ChangeWalk(GRNXWLK1PIN,REDXWLK1PIN);
    } else if (walk2.walkLightState == ST_REDFLASH && timers2.TimeToFlashWalk()) {
        walk2.ChangeWalk(GRNXWLK2PIN,REDXWLK2PIN);
    }
};

void Traffic::ChangeLights(TRAFFICSTATES trafficState, int red, int ylw, int grn) {
  switch(trafficState) 
  {
    case ST_RED:
        digitalWrite(red,HIGH);
        digitalWrite(grn,LOW);
        digitalWrite(ylw,LOW);
        break;
    case ST_GREEN:
        digitalWrite(red,LOW);
        digitalWrite(grn,HIGH);
        digitalWrite(ylw,LOW);
        break;
    case ST_YELLOW:
        digitalWrite(red,LOW);
        digitalWrite(grn,LOW);
        digitalWrite(ylw,HIGH);
        break;
  }
};