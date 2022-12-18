#include <Arduino.h>
#include "config.h"
#include "traffic.h"

Traffic traffic;

void setup(){
  pinMode(GRNLGHT1PIN,OUTPUT);
  pinMode(YLWLGHT1PIN,OUTPUT);
  pinMode(REDLGHT1PIN,OUTPUT);
  pinMode(GRNLGHT2PIN,OUTPUT);
  pinMode(YLWLGHT2PIN,OUTPUT);
  pinMode(REDLGHT2PIN,OUTPUT);

  pinMode(REDXWLK1PIN,OUTPUT);
  pinMode(GRNXWLK1PIN,OUTPUT);
  pinMode(REDXWLK2PIN,OUTPUT);
  pinMode(GRNXWLK1PIN,OUTPUT);

  Serial.begin(115200);

  Serial.println(F("Boot"));
}

void loop() {
  traffic.CycleLights();
}