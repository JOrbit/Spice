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

#define GM "GM"

/*
 * 
 */
int main(int argc, char** argv) {

   printf("SpiceOrbitalElements\n");

   printf("Load data.\n");

   SpiceInt n;
   SpiceDouble gm;
   SpiceDouble et;
   SpiceDouble state[6];
   SpiceDouble lt;
   SpiceDouble elts[8];

   ConstSpiceChar* strDate = "2000 JAN 01 12:00:00";
   ConstSpiceChar* observer = "SUN";
   ConstSpiceChar* frame = "J2000";
   ConstSpiceChar* target = "EARTH";

   /*
      load kernels: LSK, Solar system SPK, and gravity PCK 
    */
   furnsh_c("D:/naif/Kernels/Generic/lsk/naif0011.tls");
   furnsh_c("D:/naif/Kernels/Generic/spk/planets/de432s.bsp");
   furnsh_c("D:/naif/Kernels/Generic/pck/gm_de431.tpc");

   /*
      retrieve GM for SUN 
    */
   bodvrd_c(observer, GM, 1, &n, &gm);

   /*
      convert UTC to ET 
    */

   str2et_c(strDate, &et);
   
   printf("UTC       = %s     \n", strDate);
   printf("ET        = %20.10f \n", et);

   /*
      compute state of Target at given UTC 
    */
   spkezr_c(target, et, frame, "NONE", observer,
           state, &lt);
   
   printf("Target %s State Variables %s Reference Frame.\n", target, frame);
   printf(" X(km)           = %20.10f\n", state[0]);
   printf(" Y(km)           = %20.10f\n", state[1]);
   printf(" Z(km)           = %20.10f\n", state[2]);
   printf("VX(km/s)         = %20.10f\n", state[3]);
   printf("VY(km/s)         = %20.10f\n", state[4]);
   printf("VZ(km/s)         = %20.10f\n", state[5]);

   /*
          compute orbital elements 
    */
   oscelt_c(state, et, gm, elts);

   printf("Target %s Orbital Elements.\n", target);
   printf("Perifocal distance              rp(km)            = %20.10f\n", elts[0]);
   printf("Eccentricity                    ecc               = %20.10f\n", elts[1]);
   printf("Inclination                     inc(rad)          = %20.10f\n", elts[2]);
   printf("Longitude of the ascending node lnode(rad)        = %20.10f\n", elts[3]);
   printf("Argument of periapsis           argp(rad)         = %20.10f\n", elts[4]);
   printf("Mean anomaly at epoch           m0(rad)           = %20.10f\n", elts[5]);
   printf("Epoch                           t0(s)             = %20.10f\n", elts[6]);
   printf("Gravitational parameter         mu(km3/s2)        = %20.10f\n", elts[7]);


   return (EXIT_SUCCESS);
}

