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

void printDateTime(ConstSpiceChar* utc, ConstSpiceDouble et);

void printState(ConstSpiceChar* frame, ConstSpiceChar* target,
        ConstSpiceDouble * state);
void printOrbitalElements(ConstSpiceChar* target, ConstSpiceDouble* elts);


#define GM "GM"
ConstSpiceInt NSTATES = 6;
ConstSpiceInt NELTS = 8;
ConstSpiceInt NUTC = 5;

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

   ConstSpiceChar * utc[] = {
      "2000 JAN 01 12:00:00",
      "2000 APR 01 12:00:00",
      "2000 JUL 01 12:00:00",
      "2000 OCT 01 12:00:00",
      "2001 JAN 01 12:00:00",
   };
 
   SpiceInt n;
   SpiceDouble gm;
   SpiceDouble et[NUTC];
   SpiceDouble oet[NUTC - 1];
   SpiceDouble state[NUTC][NSTATES];
   SpiceDouble ostate[NUTC - 1][NSTATES];
   SpiceDouble lt[NUTC];
   SpiceDouble olt[NUTC - 1];
   SpiceDouble elts[NUTC][NELTS];
   SpiceDouble pelts[NUTC - 1][NELTS];

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
   bodvrd_c(observer, GM, 1, &n, &gm);

   /*
      convert UTC to ET 
    */

   for (int i = 0; i < NUTC; i++) {

      str2et_c(utc[i], &et[i]);
      printDateTime(utc[i], et[i]);


      /*
         compute state of Target at given UTC 
       */
      spkezr_c(target, et[i], frame, "NONE", observer,
              state[i], &lt[i]);

      printState(frame, target, state[i]);

      /*
             compute orbital elements 
       */
      oscelt_c(state[i], et[i], gm, elts[i]);
      printOrbitalElements(target, elts[i]);

   }


   return (EXIT_SUCCESS);
}

void printDateTime(ConstSpiceChar* utc, ConstSpiceDouble et) {
   printf("UTC       = %s     \n", utc);
   printf("ET        = %20.10f \n", et);
}

void printState(ConstSpiceChar* frame, ConstSpiceChar* target,
        ConstSpiceDouble* state) {
   printf("Target %s State Variables %s Reference Frame.\n", target, frame);
   printf(" X(km)           = %20.10f\n", state[0]);
   printf(" Y(km)           = %20.10f\n", state[1]);
   printf(" Z(km)           = %20.10f\n", state[2]);
   printf("VX(km/s)         = %20.10f\n", state[3]);
   printf("VY(km/s)         = %20.10f\n", state[4]);
   printf("VZ(km/s)         = %20.10f\n", state[5]);
}

void printOrbitalElements(ConstSpiceChar* target, ConstSpiceDouble* elts) {
   printf("Target %s Orbital Elements.\n", target);
   printf("Perifocal distance              rp(km)            = %20.10f\n", elts[0]);
   printf("Eccentricity                    ecc               = %20.10f\n", elts[1]);
   printf("Inclination                     inc(rad)          = %20.10f\n", elts[2]);
   printf("Longitude of the ascending node lnode(rad)        = %20.10f\n", elts[3]);
   printf("Argument of periapsis           argp(rad)         = %20.10f\n", elts[4]);
   printf("Mean anomaly at epoch           m0(rad)           = %20.10f\n", elts[5]);
   printf("Epoch                           t0(s)             = %20.10f\n", elts[6]);
   printf("Gravitational parameter         mu(km3/s2)        = %20.10f\n", elts[7]);
}