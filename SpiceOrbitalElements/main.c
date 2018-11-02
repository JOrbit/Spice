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

   /*
      "2000 JAN 01 12:00:00",
      "2000 APR 01 12:00:00",
      "2000 JUL 01 12:00:00",
      "2000 OCT 01 12:00:00",
      "2001 JAN 01 12:00:00",
      "2000 OCT 01 12:00:00"
    */



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

   str2et_c("2000 SEP 22 17:27:00", &et1);
   //str2et_c("2001 SEP 22 23:05:00", &et2);

   /*
      compute state of Target at given UTC 
    */
   spkezr_c(target, et1, frame, "NONE", observer,
           state1, &lt);
   printState(et1, target, frame, observer, state1);
   oscltx_c(state1, et1, gm, elts1);
   printEltsX(et1, target, frame, observer, elts1);

   et2 = et1 + 5 * elts1[10];



   spkezr_c(target, et2, frame, "NONE", observer,
           state2, &lt);
   printState(et2, target, frame, observer, state2);

   oscltx_c(state2, et2, gm, elts2);
   printEltsX(et2, target, frame, observer, elts2);

   conics_c(elts1, et2, pstate);
   printStateDiff(target, frame, observer,
           et1, et2,
           state1, pstate);

   return (EXIT_SUCCESS);
}