#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SpiceUsr.h"

/*
Define the max number of kernel variables
of concern for this examples.
 */
#define N_ITEMS   20

/*
Define the maximum length for any string, 80
characters plus one null terminator.
 */
#define STRLEN 81

int kervar() {

    /*
    Note, the pool routines return a boolean to 'found'
    signaling whether the requested variable name exists
    in the kernel pool. The code solutions do not check the
    boolean value since the solutions use variables known to
    exist. In general, code should always check the boolean
    value to ensure return of valid data.
     */

    /*
    As usual, type our variables...
     */
    SpiceInt i;
    SpiceInt j;
    SpiceInt dim;
    SpiceInt n_var;
    SpiceInt n_val;
    SpiceInt start;

    SpiceBoolean found;

    SpiceDouble dvars [N_ITEMS];

    SpiceChar cvals [N_ITEMS][STRLEN];
    SpiceChar cvars [N_ITEMS][STRLEN];
    SpiceChar type;
    SpiceChar tmplate[12];


    /*
    Load the example kernel containing the kernel variables.
    The kernels defined in KERNELS_TO_LOAD load into the
    kernel pool with this call.
     */
    furnsh_c("./data/other_stuff/kervar.tm");

    /*
    Initialize the start value. This values indicates
    index of the first element to return if a kernel
    variable is an array. start = 0 indicates return everything.
    start = 1 indicates return everything but the first element.
     */
    start = 0;


    /*
    Set the template for the variable names to find. Let's
    look for all variables containing  the string RING.
    Define this with the wildcard template '*RING*'. Note:
    the template '*RING' would match any variable name
    ending with the RING string.
     */
    strcpy(tmplate, "*RING*");

    /*
    We're ready to interrogate the kernel pool for the
    variables matching the template. gnpool_c tells us:
 
       1. Does the kernel pool contain any variables that
          match the template (value of found).
       2. If so, how many variables? (value of n_val)
       3. The variable names. (cvals, an array of strings)
     */

    gnpool_c(tmplate, start, N_ITEMS, STRLEN,
            &n_val, cvals, &found);

    if (found) {
        printf("Number variables matching template: %d\n", n_val);
    } else {
        puts("No kernel variables matched template");
        exit(0);
    }


    /*
    Okay, now we know something about the kernel pool
    variables of interest to us. Let's find out more...
     */
    for (i = 0; i < n_val; ++i) {

        /*
        Use dtpool_c to return the dimension and type,
        C (character) or N (numeric), of each pool
        variable name in the cvals array.
         */
        dtpool_c(cvals[i], &found, &dim, &type);
        printf("\n%s\n", cvals[i]);
        printf(" Number items: %d   Of type: %c\n\n", dim, type);

        /*
        Use the EQSTR routine to test character equality,
        'N' or 'C'.
         */
        if (type == 'N') {

            /*
            If 'type' equals "N", we found a numeric array.
            In this case any numeric array will be an array
            of double precision numbers ("doubles"). gdpool_c
            retrieves doubles from the kernel pool. 'dvars'
            contains the array of 'n_vars' values.
             */
            gdpool_c(cvals[i], start, N_ITEMS, &n_var,
                    dvars, &found);

            for (j = 0; j < n_var; ++j) {
                printf("  Numeric value: %20.6f\n", dvars[j]);
            }

        } else if (type == 'C') {

            /*
            If 'type' equals "C", we found a string array.
            gcpool_c retrieves string values from the
            kernel pool. cvars[i] contains the array of 'n_var'
            values.
             */
            gcpool_c(cvals[i], start, N_ITEMS,
                    STRLEN, &n_var, cvars, &found);

            for (j = 0; j < n_var; ++j) {
                printf("  String value: %s\n", cvars[j]);
            }

        }

    }

    puts(" ");

    /*
    Now look at the kernel variable EXAMPLE_TIMES. Extract this
    value as an array of doubles.
     */
    gdpool_c("EXAMPLE_TIMES", start, N_ITEMS, &n_var, dvars,
            &found);

    puts("EXAMPLE_TIMES");

    for (j = 0; j < n_var; ++j) {
        printf("  Time value:    %20.6f\n", dvars[j]);
    }

    return(0);
}
