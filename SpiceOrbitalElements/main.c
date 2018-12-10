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
#include <string.h>
#include <math.h>

#include "SpiceUsr.h"
#include "SpiceZmc.h"

#include "printEt.h"
#include "printState.h"
#include "printEltsX.h"
#include "printStateDiff.h"

SpiceDouble calcMeanAnomaly(SpiceDouble radsPerPeriod, SpiceDouble epoch
        , SpiceDouble emar, SpiceDouble et);

SpiceDouble calcTrueAnomaly(SpiceDouble eccentricity, SpiceDouble meanAnomaly);


#define GM "GM"

/*
 * 
 */
int main(int argc, char** argv) {

   SpiceChar observer[20];
   SpiceChar frame[20];
   SpiceChar target[20];

   printf("SpiceOrbitalElements main.c \n");

   if (argc == 4) {
      strcpy(observer, argv[1]);
      strcpy(frame, argv[2]);
      strcpy(target, argv[3]);
   } else {
      strcpy(observer, "SUN");
      strcpy(frame, "J2000"); //"ECLIPJ2000"; //"J2000";
      strcpy(target, "EARTH");
   }

   printf("Observer = %s\n", observer);
   printf("Frame    = %s\n", frame);
   printf("Target   = %s\n", target);

   ConstSpiceChar* lskFile = "D:/naif/Kernels/Generic/lsk/naif0011.tls";
   ConstSpiceChar* spkFile1 = "D:/naif/Kernels/Generic/spk/planets/de431_part-1.bsp";
   ConstSpiceChar* spkFile2 = "D:/naif/Kernels/Generic/spk/planets/de431_part-2.bsp";
   ConstSpiceChar* pckFile1 = "D:/naif/Kernels/Generic/pck/gm_de431.tpc";
   ConstSpiceChar* pckFile2 = "D:/naif/Kernels/Generic/pck/pck00010.tpc";

   SpiceInt igm;
   SpiceDouble gm;

   SpiceChar utc[23];

   SpiceDouble state[NSTATES];
   SpiceDouble lt;

   SpiceDouble elts[SPICE_OSCLTX_NELTS];


   /*
       load kernels: LSK, Solar system SPK, and gravity PCK 
    */
   printf("Load data.\n");

   furnsh_c(lskFile);
   furnsh_c(spkFile1);
   furnsh_c(spkFile2);
   furnsh_c(pckFile1);
   furnsh_c(pckFile2);

   /*
      retrieve GM for SUN 
    */
   bodvrd_c(observer, GM, 1, &igm, &gm);

   printf("Target %s State Variables %s Reference Frame.\n", target, frame);

   spkezr_c(target, J2000, frame, "NONE", observer, state, &lt);
   printState(J2000, target, frame, observer, state);
   oscltx_c(state, J2000, gm, elts);
   printEltsX(J2000, target, frame, observer, elts);

   SpiceDouble P = elts[10];
   SpiceDouble emar = elts[5];
   SpiceDouble eecc = elts[1];

   SpiceDouble radsPerPeriod = M_TWOPI / P;
   printf("radsPerPeriod = %20.10f\n", radsPerPeriod);
   SpiceDouble et = J2000 + spd_c();
   for (int i = 0; i < 366; i++) {
      printf("UTC                    mar               cmar                 diff\n");
      SpiceDouble cmar = calcMeanAnomaly(radsPerPeriod, J2000, emar, et);
      spkezr_c(target, et, frame, "NONE", observer, state, &lt);
      //   printState(J2000, target, frame, observer, state);
      oscltx_c(state, et, gm, elts);
      //   printEltsX(J2000, target, frame, observer, elts);
      SpiceDouble mar = elts[5];
      SpiceDouble ta = elts[8];
      et2utc_c(et, "C", 3, 23, utc);
      printf("%s %20.10f %20.10f %20.10f\n", utc, mar, cmar, (cmar - mar));
      SpiceDouble cta = calcTrueAnomaly(eecc, cmar);
      printf("%s %20.10f %20.10f %20.10f\n", utc, ta, cta, (cta - ta));

      et += spd_c();
   }

}

SpiceDouble calcMeanAnomaly(SpiceDouble radsPerPeriod, SpiceDouble epoch
        , SpiceDouble emar, SpiceDouble et) {
   SpiceDouble cmar = 0;
   cmar = (radsPerPeriod * (et - epoch)) + emar;
   return cmar;
}

SpiceDouble calcTrueAnomaly(SpiceDouble eccentricity, SpiceDouble meanAnomaly) {
   SpiceDouble cta = 0;
   SpiceDouble e = eccentricity;
   SpiceDouble M = meanAnomaly;

   cta = M;
   cta += ((2 * e - (0.25 * e * e * e)) * sin(M));
   cta += ((1.25 * e * e * sin(2.0 * M)));
   cta += ((13.0 * e * e * e * sin(3.0 * M)) / 12.0);

   return cta;
}
