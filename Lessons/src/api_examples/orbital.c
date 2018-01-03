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

#include "SpiceUsr.h"

orbital() {

    SpiceInt n;
    SpiceDouble gm;
    SpiceDouble et;
    SpiceDouble state[6];
    SpiceDouble lt;
    SpiceDouble elts[8];

    /*
       load kernels: LSK, MEX trajectory SPK, and gravity PCK 
     */
    furnsh_c("../kernels/pub/naif/MEX/kernels/lsk/former_versions/naif0008.tls");
    furnsh_c("../kernels/pub/naif/MEX/kernels/spk/ORMM__050901000000_00165.BSP");
    furnsh_c("../kernels/pub/naif/MEX/kernels/pck/DE403-MASSES.TPC");

    /*
       retrieve GM for Mars 
     */
    bodvrd_c("MARS", "GM", 1, &n, &gm);

    /*
       convert UTC to ET 
     */
    str2et_c("2005 SEP 02 04:50:45", &et);
    printf("UTC       = %s     \n", "2005 SEP 02 04:50:45");
    printf("ET        = %20.6f \n", et);

    /*
       compute state of MEX at given UTC 
     */
    spkezr_c("MEX", et, "MARSIAU", "NONE", "MARS",
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