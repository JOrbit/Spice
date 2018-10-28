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
      load kernels: LSK, MEX trajectory SPK, and gravity PCK 
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
   printf("ET        = %20.6f \n", et);

   /*
      compute state of MEX at given UTC 
    */
   spkezr_c(target, et, frame, "NONE", observer,
           state, &lt);

   printf(" X        = %20.6f\n", state[0]);
   printf(" Y        = %20.6f\n", state[1]);
   printf(" Z        = %20.6f\n", state[2]);
   printf("VX        = %20.6f\n", state[3]);
   printf("VY        = %20.6f\n", state[4]);
   printf("VZ        = %20.6f\n", state[5]);

   /*
          compute orbital elements 
    */
   oscelt_c(state, et, gm, elts);

   printf("elts[0]   = %20.6f\n", elts[0]);
   printf("elts[1]        = %20.6f\n", elts[1]);
   printf("elts[2]        = %20.6f\n", elts[2]);
   printf("elts[3]        = %20.6f\n", elts[3]);
   printf("elts[4]        = %20.6f\n", elts[4]);
   printf("elts[5]        = %20.6f\n", elts[5]);
   printf("elts[6]        = %20.6f\n", elts[6]);
   printf("elts[7]        = %20.6f\n", elts[7]);


   return (EXIT_SUCCESS);
}

