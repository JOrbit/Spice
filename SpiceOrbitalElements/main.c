/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: owner
 *
 * Created on October 28, 2018, 1:39 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "SpiceUsr.h"

#include "printEt.h"
#include "printState.h"
#include "printEltsX.h"
#include "printStateDiff.h"



#define GM "GM"

/*
 * 
 */
int main(int argc, char** argv) {


   printf("SpiceOrbitalElements\n");

   ConstSpiceChar* lskFile = "D:/naif/Kernels/Generic/lsk/naif0011.tls";
   ConstSpiceChar* spkFile = "D:/naif/Kernels/Generic/spk/planets/de432s.bsp";
   ConstSpiceChar* pckFile = "D:/naif/Kernels/Generic/pck/gm_de431.tpc";

   ConstSpiceChar* observer = "SUN";
   ConstSpiceChar* frame = "ECLIPJ2000"; //"J2000";
   ConstSpiceChar* target = "EARTH";


   SpiceInt igm;
   SpiceDouble gm;
   SpiceDouble et1;
   SpiceDouble et2;
   SpiceDouble state1[NSTATES];
   SpiceDouble state2[NSTATES];
   SpiceDouble lt;
   SpiceDouble elts1[SPICE_OSCLTX_NELTS];
   SpiceDouble elts2[SPICE_OSCLTX_NELTS];
   SpiceDouble pstate[NSTATES];

   /*
      load kernels: LSK, Solar system SPK, and gravity PCK 
    */
   printf("Load data.\n");

   furnsh_c(lskFile);
   furnsh_c(spkFile);
   furnsh_c(pckFile);

   /*
      retrieve GM for SUN 
    */
   bodvrd_c(observer, GM, 1, &igm, &gm);

   /*
      convert UTC to ET 
    */

   str2et_c("2000 JAN 01 12:00:00", &et1);



   for (int i = 0; i < 20; i++) {
      //
      // Retrieve state of Target at given ET
      //
      spkezr_c(target, et1, frame, "NONE", observer,
              state1, &lt);
      printState(et1, target, frame, observer, state1);
      oscltx_c(state1, et1, gm, elts1);
      printEltsX(et1, target, frame, observer, elts1);
      //
      // Retrieve state of Target at and ET + the orbital period 
      // from the previous target
      //
      et2 = et1 + elts1[10];
      spkezr_c(target, et2, frame, "NONE", observer,
              state2, &lt);
      printState(et2, target, frame, observer, state2);
      //
      // Calculate a state from a previous one
      //
      printf("Perturb state1 to pstate using oscltx_x and find diff.\n");
      oscltx_c(state2, et2, gm, elts2);
      printEltsX(et2, target, frame, observer, elts2);
      conics_c(elts1, et2, pstate);
      printStateDiff(target, frame, observer,
              et1, et2,
              state1, pstate);

      et1 = et2;


   }

   return (EXIT_SUCCESS);
}