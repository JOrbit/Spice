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

#include "printEt.h"
#include "printState.h"
#include "printEltsX.h"
#include "printStateDiff.h"



#define GM "GM"

SpiceDouble findMinEt(ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        SpiceDouble et1, SpiceDouble et2);

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
      strcpy(frame, "ECLIPJ2000"); //"ECLIPJ2000"; //"J2000";
      strcpy(target, "EARTH");
   }

   printf("Observer = %s\n", observer);
   printf("Frame    = %s\n", frame);
   printf("Target   = %s\n", target);

   ConstSpiceChar* lskFile = "D:/naif/Kernels/Generic/lsk/naif0011.tls";
   ConstSpiceChar* spkFile1 = "D:/naif/Kernels/Generic/spk/planets/de431_part-1.bsp";
   ConstSpiceChar* spkFile2 = "D:/naif/Kernels/Generic/spk/planets/de431_part-2.bsp";
   ConstSpiceChar* pckFile = "D:/naif/Kernels/Generic/pck/gm_de431.tpc";

   SpiceInt igm;
   SpiceDouble gm;

   SpiceDouble et1;
   SpiceDouble z1;
   SpiceDouble et2;
   SpiceDouble z2;

   SpiceChar utc[23];



   /*
      load kernels: LSK, Solar system SPK, and gravity PCK 
    */
   printf("Load data.\n");

   furnsh_c(lskFile);
   furnsh_c(spkFile1);
   furnsh_c(spkFile2);
   furnsh_c(pckFile);

   /*
      retrieve GM for SUN 
    */
   bodvrd_c(observer, GM, 1, &igm, &gm);

   /*
      convert UTC to ET 
    */

   double state[NSTATES];
   double lt;

   str2et_c("2018 JAN 01 12:00:00", &et1);

   printf("Target %s State Variables %s Reference Frame.\n", target, frame);
   printf("UTC                        Z(km)\n");

   for (int i = 0; i < 366; i++) {

      spkezr_c(target, et1, frame, "NONE", observer,
              state, &lt);
      z1 = state[2];

      et2utc_c(et1, "C", 3, 23, utc);

      printf("%s                        %20.2f\n", utc, state[2]);

      if (i > 0) {

         if ((fabs(z1) + fabs(z2)) > fabs(z1 + z2)) {

            SpiceDouble minEt = findMinEt(target, frame, observer, et1, et2);

            spkezr_c(target, minEt, frame, "NONE", observer,
                    state, &lt);

            et2utc_c(minEt, "C", 3, 23, utc);
            printf("Minimum Z(km) date and value.\n");
            printf("%s         %20.2f\n", utc, state[2]);

         }


         et2 = et1;
         z2 = z1;
         et1 = et1 + spd_c();

      }
   }

   return (EXIT_SUCCESS);
}

SpiceDouble findMinEt(ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        SpiceDouble et1, SpiceDouble et2) {
   SpiceDouble minEt = (et1 + et2) / 2.0;
   SpiceDouble diff = 1.0;


   while (diff > 0.001) {

      SpiceDouble z1;
      SpiceDouble state1[NSTATES];
      SpiceDouble minZ;
      SpiceDouble minState[NSTATES];
      SpiceDouble z2;
      SpiceDouble state2[NSTATES];
      SpiceDouble lt;

      minEt = (et1 + et2) / 2.0;

      spkezr_c(target, et1, frame, "NONE", observer,
              state1, &lt);
      z1 = state1[2];

      spkezr_c(target, minEt, frame, "NONE", observer,
              minState, &lt);
      minZ = minState[2];

      spkezr_c(target, et2, frame, "NONE", observer,
              state2, &lt);
      z2 = state2[2];

      if (z1 > 0 && z2 < 0) {
         if (minZ < 0) {
            et2 = minEt;
         } else {
            et1 = minEt;
         }
      } else if (z1 < 0 && z2 > 0) {
         if (minZ < 0) {
            et1 = minEt;
         } else {
            et2 = minEt;
         }
      } else {
         printf("SEVERE ERROR: z1 and z2 are the same sign.\n");
         exit(-1);
      }

      diff = fabs(minZ);

      /* FOR DEBUGGING
      printf("END DO LOOP: \n");
      printf("z1, minZ, z2 = %10.2f, %10.2f, %10.2f\n", z1, minZ, z2);
      printf("et1, minEt, et2 = %10.2f, %10.2f, %10.2f\n", et1, minEt, et2);
      printf("diff = %10.5f\n", diff);
       */
   }

   return minEt;
}

