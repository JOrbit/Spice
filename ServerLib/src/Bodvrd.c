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
#include <string.h>

#include "Bodvrd.h"
#include "ProcessSpiceCommand.h"
#include "SpiceUsr.h"

void Bodvrd(char* token, char* obuf) {

   token = strtok(NULL, DELIMITER);
   printf("INFO: Bodvrd received token  = %s\n", token);
   printf("INFO: Bodvrd calling bodvrd_c with bodynm = %s\n", token);
   SpiceInt n;
   SpiceDouble gm;
   bodvrd_c(token, "GM", 1, &n, &gm);
   printf("INFO: Bodvrd GM = %f\n", gm);
   sprintf(obuf, "%f", gm);

}