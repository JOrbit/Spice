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


#define GM "GM"

#define NSTATES 6

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

   SpiceDouble lt;

   SpiceDouble state[NSTATES];

   SpiceDouble AU2KM = 149597870.691;
   SpiceDouble KM2AU = 1.0 / AU2KM;

   SpiceChar* fileName = (char *) malloc(sizeof (target) + sizeof (frame) +
           sizeof (observer) + 64);
   strcpy(fileName, target);
   strcat(fileName, frame);
   strcat(fileName, observer);
   strcat(fileName, "XyzR.txt");
   printf("fileName = %s\n", fileName);

   FILE* file = fopen(fileName, "w");
   if (!file) {
      printf("SEVERE ERROR: fopen failed for file %s\n", fileName);
      exit(-1);
   }


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

   SpiceDouble et;
   printf("j2000_c() = %f\n", j2000_c());
   utc2et_c("2000-01-01T12:00:00", &et);
   printf("et = %f\n", et);
   printf("spd_c() = %f\n", spd_c());
   
   SpiceDouble radius = 0;
   printf("UTC                          X(AU)                     Y(AU)                  Z(AU)              R{AU)\n");
   for (int i = 0; i < 1000; i++) {
       spkezr_c(target, et, frame, "NONE", observer, state, &lt);
      et2utc_c(et, "C", 3, 23, utc);
     
      radius = sqrt(state[0] * state[0] +
              state[1] * state[1] +
              state[2] * state[2]);
      printf("%s %20.10f %20.10f %20.10f %20.10f\n",
              utc,
              state[0] * KM2AU,
              state[1] * KM2AU,
              state[2] * KM2AU,
              radius * KM2AU);
     fprintf(file, "%20.10f %20.10f %20.10f %20.10f %20.10f\n", 
              et, state[0], state[1], state[2], radius);

     et += spd_c();
      
      
   }
   
   fclose(file);
}
