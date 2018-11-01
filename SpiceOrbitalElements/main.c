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

void printDateTime(ConstSpiceDouble et);

void printState(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* state);
void printOrbitalElements(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* elts);


#define GM "GM"
ConstSpiceInt NSTATES = 6;

/*
 * 
 */
int main(int argc, char** argv) {

   printf("SpiceOrbitalElements\n");

   ConstSpiceChar* lskFile = "D:/naif/Kernels/Generic/lsk/naif0011.tls";
   ConstSpiceChar* spkFile = "D:/naif/Kernels/Generic/spk/planets/de432s.bsp";
   ConstSpiceChar* pckFile = "D:/naif/Kernels/Generic/pck/gm_de431.tpc";

   ConstSpiceChar* observer = "SUN";
   ConstSpiceChar* frame = "J2000";
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
   SpiceDouble diff[NSTATES];

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
   str2et_c("2001 SEP 22 23:05:00", &et2);

   /*
      compute state of Target at given UTC 
    */
   spkezr_c(target, et1, frame, "NONE", observer,
           state1, &lt);
   printState(et1, target, frame, observer, state1);
   oscelt_c(state1, et1, gm, elts1);
   printOrbitalElements(et1, target, frame, observer, elts1);



   spkezr_c(target, et2, frame, "NONE", observer,
           state2, &lt);
   printState(et2, target, frame, observer, state2);
   oscelt_c(state2, et2, gm, elts2);
   printOrbitalElements(et2, target, frame, observer, elts2);

   vsubg_c(state2, state1, NSTATES, diff);
   printf("Perturbation in x, dx/dt = %e %e\n", diff[0], diff[3]);
   printf("                y, dy/dt = %e %e\n", diff[1], diff[4]);
   printf("                z, dz/dt = %e %e\n", diff[2], diff[5]);

   conics_c(elts1, et2, pstate);
   vsubg_c(pstate, state1, NSTATES, diff);
   printState(et2, target, frame, observer, pstate);
   printf("Perturbation in x, dx/dt = %e %e\n", diff[0], diff[3]);
   printf("                y, dy/dt = %e %e\n", diff[1], diff[4]);
   printf("                z, dz/dt = %e %e\n", diff[2], diff[5]);

   return (EXIT_SUCCESS);
}

void printDateTime(ConstSpiceDouble et) {
   SpiceChar utc[23];
   et2utc_c(et, "C", 3, 23, utc);

   printf("UTC       = %s     \n", utc);
   printf("ET        = %20.10f \n", et);
}

void printState(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* state) {
   printf("State of %s in frame %s from observer %s as of:\n",
           target, frame, observer);
   printDateTime(et);
   printf("Target %s State Variables %s Reference Frame.\n", target, frame);
   printf(" X(km)           = %20.10f\n", state[0]);
   printf(" Y(km)           = %20.10f\n", state[1]);
   printf(" Z(km)           = %20.10f\n", state[2]);
   printf("VX(km/s)         = %20.10f\n", state[3]);
   printf("VY(km/s)         = %20.10f\n", state[4]);
   printf("VZ(km/s)         = %20.10f\n", state[5]);
}

void printOrbitalElements(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* elts) {
   printf("Orbital Elements of %s in frame %s from observer %s as of:\n",
           target, frame, observer);
   printDateTime(et);
   printf("Perifocal distance              rp(km)            = %20.10f\n", elts[0]);
   printf("Eccentricity                    ecc               = %20.10f\n", elts[1]);
   printf("Inclination                     inc(rad)          = %20.10f\n", elts[2]);
   printf("Longitude of the ascending node lnode(rad)        = %20.10f\n", elts[3]);
   printf("Argument of periapsis           argp(rad)         = %20.10f\n", elts[4]);
   printf("Mean anomaly at epoch           m0(rad)           = %20.10f\n", elts[5]);
   printf("Epoch                           t0(s)             = %20.10f\n", elts[6]);
   printf("Gravitational parameter         mu(km3/s2)        = %20.10f\n", elts[7]);
}