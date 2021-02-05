#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

int sccalc() {

    /*
    All the functions have the same calling sequence:
 
       VALUE = function_name();
       some_procedure( function_name() );
       printf ( "%19.12f\n", function_name() );
 
    First a simple example using the seconds per day
    constant...
     */
    printf("Number of (S)econds (P)er (D)ay         : %19.12f\n",
            spd_c());

    /*
    ...then show the value of degrees per radian, 180/Pi...
     */
    printf("Number of (D)egrees (P)er (R)adian      : %19.16f\n",
            dpr_c());

    /*
    ...and the inverse, radians per degree, Pi/180.
    It is obvious dpr_c() equals 1.0/rpd_c(), or more simply
    dpr_c() * rpd_c() equals 1.0.
     */
    printf("Number of (R)adians (P)er (D)egree      : %19.16f\n",
            rpd_c());

    /*
    What's the value for the astrophysicist's favorite
    physical constant (in a vacuum)?
     */
    printf("Speed of light in KM per second         : %19.12f\n",
            clight_c());

    /*
    How long (in Julian days) from the J2000 epoch to the
    J2100 epoch?
     */
    printf("Number of days between epochs J2000  \n");
    printf("  and J2100                             : %19.12f\n",
            j2100_c() - j2000_c());

    /*
    Redo the calculation returning seconds...
     */
    printf("Number of seconds between epochs\n");
    printf("  J2000 and J2100                       : %19.5f\n",
            spd_c() * (j2100_c() - j2000_c()));

    /*
    ...then tropical years.
     */
    printf("Number of tropical years between\n");
    printf("  epochs J2000 and J2100                : %19.12f\n",
            (spd_c() / tyear_c()) * (j2100_c() - j2000_c()));

    /*
    Finally, how can I convert a radian value to degrees.
     */
    printf("Number of degrees in Pi/2 radians of arc: %19.16f\n",
            halfpi_c() * dpr_c());

    /*
    and degrees to radians.
     */
    printf("Number of radians in 250 degrees of arc : %19.16f\n",
            250. * rpd_c());

    return (0);
}

