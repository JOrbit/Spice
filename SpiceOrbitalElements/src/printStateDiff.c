/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>


#include "printStateDiff.h"
#include "printState.h"

void printStateDiff(ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble et1, ConstSpiceDouble et2,
        SpiceDouble* state1, SpiceDouble* state2) {

   SpiceDouble diff[NSTATES];

   printf("State difference of target %s.\n", target);

   printf("FROM:\n");
   printState(et1,
           target, frame, observer,
           state1);

   printf("TO:\n");
   printState(et2,
           target, frame, observer,
           state2);

   vsubg_c(state2, state1, NSTATES, diff);
   printf("Perturbation in x, dx/dt = %e %e\n", diff[0], diff[3]);
   printf("                y, dy/dt = %e %e\n", diff[1], diff[4]);
   printf("                z, dz/dt = %e %e\n", diff[2], diff[5]);

}
