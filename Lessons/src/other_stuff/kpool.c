#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

/*
Define the maximum length for any string, 80
characters plus one null terminator.
 */
#define LENOUT 81

int kpool() {

    /*  Declare the needed variables: */

    SpiceChar file [LENOUT];
    SpiceChar type [LENOUT];
    SpiceChar source [LENOUT];

    SpiceInt i;
    SpiceInt count;
    SpiceInt handle;

    SpiceBoolean found;


    /* Assign the path name of the meta kernel to META. */
    SpiceChar * META = "./data/other_stuff/kpool.tm";


    /*
    Load the meta kernel then use KTOTAL to interrogate the SPICE
    kernel subsystem for the total number of loaded kernel files.
     */
    furnsh_c(META);
    ktotal_c("ALL", &count);
    printf("Kernel count after load:        %d\n", count);


    /*
    Loop over the number of files; interrogate the SPICE system
    with kdata_c for the kernel names and the type. 'found' returns a
    boolean indicating whether any kernel files of the specified
    type were loaded by the kernel subsystem. This example ignores
    checking 'found' as kernels are known to be loaded.
     */
    for (i = 0L; i < count; i++) {
        kdata_c(i, "ALL", LENOUT, LENOUT, LENOUT,
                file, type, source, &handle, &found);
        printf("File   %s\n", file);
        printf("Type   %s\n", type);
        printf("Source %s\n", source);
        printf("\n");
    }


    /*
    Unload one kernel then check the count.
     */
    unload_c("kernels/spk/de405s.bsp");
    ktotal_c("ALL", &count);


    /*
    The subsystem should report one less kernel.
     */
    printf("Kernel count after one unload:  %d\n", count);


    /*
    Now unload the meta kernel. This action unloads all
    files listed in the meta kernel.
     */
    unload_c(META);


    /*
    Check the count. SPICE should return a count of zero.
     */
    ktotal_c("ALL", &count);
    printf("Kernel count after meta unload: %d\n", count);

    return(0);
}
