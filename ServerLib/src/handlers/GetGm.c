/*
https://naif.jpl.nasa.gov/pub/naif/toolkit_docs/C/info/mostused.html#M
 
Computing and Propagating Orbital Elements
APIs:

    conics_c - determines the state of an orbiting body from a set orbital elements.
    oscelt_c - determines the set of orbital elements corresponding to the state of a body. 

Brief Example:

   The following example computes the set of orbital elements for the
   state of the Mars Express spacecraft at a given time:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SpiceUsr.h"

#include "GetGm.h"

void GetGm(char* msg, char* results) {

   SpiceInt n;
   SpiceDouble gm;
   SpiceDouble et;

   /*
    *  load kernels: LSK, MEX trajectory SPK, and gravity PCK 
    */
   const char* delimiters = ",";
   char* token = strtok(msg, delimiters);

   printf("INFO: GetGmEt received token = %s\n", token);
   printf("INFO: GetGmEt calling furnsh_c using token\n");
   furnsh_c(token);

   /*
    *  retrieve GM for object
    */
   token = strtok(NULL, delimiters);
   printf("INFO: GetGmEt received token = %s\n", token);
   printf("INFO: GetGmEt calling bodvrd_c using token\n");
   bodvrd_c(token, "GM", 1, &n, &gm);
   printf("INFO: GetGmEt GM = %f\n", gm);
   sprintf(results, "%f,", gm);

}