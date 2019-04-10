/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

#include "printEt.h"
#include "printState.h"

void printState(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* state) {
   printf("State of %s in frame %s from observer %s as of:\n",
           target, frame, observer);
   printEt(et);
   printf("Target %s State Variables %s Reference Frame.\n", target, frame);
   printf(" X(km)           = %20.10f\n", state[0]);
   printf(" Y(km)           = %20.10f\n", state[1]);
   printf(" Z(km)           = %20.10f\n", state[2]);
   printf("VX(km/s)         = %20.10f\n", state[3]);
   printf("VY(km/s)         = %20.10f\n", state[4]);
   printf("VZ(km/s)         = %20.10f\n", state[5]);
}
