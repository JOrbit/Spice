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

#include "GetEt.h"

void GetEt(char* msg, char* results) {

   SpiceInt n;
   SpiceDouble et;

   char* rmsg;

   /*
    *  load kernels: LSK, MEX trajectory SPK, and gravity PCK 
    */
   const char* delimiters = ",";
   char* token = strtok(msg, delimiters);

   
   
   printf("INFO: GetEt received token = %s\n", token);
   printf("INFO: GetEt calling str2et_c using token\n");
   str2et_c(token, &et);
   printf("ET        = %20.6f \n", et);
   
   sprintf(results, "%f,", et);
   
}