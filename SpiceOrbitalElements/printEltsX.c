/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "printEt.h"
#include "printEltsX.h"
#include "r2d.h"

void printEltsX(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* elts) {
   printf("Orbital Elements of %s in frame %s from observer %s as of:\n",
           target, frame, observer);
   printEt(et);
   printf("Perifocal distance              rp(km)            = %20.10f\n", elts[0]);
   printf("Eccentricity                    ecc               = %20.10f\n", elts[1]);
   printf("Inclination                     inc(rad)          = %20.10f\n", elts[2]);
   printf("Inclination                     inc(deg)          = %20.10f\n", r2d(elts[2]));
   printf("Longitude of the ascending node lnode(rad)        = %20.10f\n", elts[3]);
   printf("Longitude of the ascending node lnode(deg)        = %20.10f\n", r2d(elts[3]));
   printf("Argument of periapsis           argp(rad)         = %20.10f\n", elts[4]);
   printf("Argument of periapsis           argp(deg)         = %20.10f\n", r2d(elts[4]));
   printf("Mean anomaly at epoch           m0(rad)           = %20.10f\n", elts[5]);
   printf("Mean anomaly at epoch           m0(deg)           = %20.10f\n", r2d(elts[5]));
   printf("Epoch                           t0(s)             = %20.10f\n", elts[6]);
   printf("Gravitational parameter         mu(km3/s2)        = %20.10f\n", elts[7]);
   printf("True anomaly at epoch           nu(rad)           = %20.10f\n", elts[8]);
   printf("True anomaly at epoch           nu(deg)           = %20.10f\n", r2d(elts[8]));
   printf("Semi-major axis                 A(km)             = %20.10f\n", elts[9]);
   printf("Orbital period                  TAU(s)            = %20.10f\n", elts[10]);
}