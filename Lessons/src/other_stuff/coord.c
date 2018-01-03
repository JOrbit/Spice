#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

/* Define the length of the time string, 32
characters plus 1 for the null terminator.
 */
#define LENOUT 33

int coord() {

    /*
    Type the variables.
     */
    SpiceInt dim;

    /*
    Define the inertial and non inertial frame names.
     */
    SpiceChar inrfrm [] = "J2000";
    SpiceChar nonfrm [] = "IAU_EARTH";
    /* 
     * SpiceChar timstr [LENOUT];
     */
    SpiceChar timstr [] = "Feb 3 2002 TDB";
    
    SpiceDouble et;
    SpiceDouble range;
    SpiceDouble ra;
    SpiceDouble dec;
    SpiceDouble lat;
    SpiceDouble colat;
    SpiceDouble lon;
    SpiceDouble ltime;
    SpiceDouble flat;
    SpiceDouble rad [3];
    SpiceDouble pos [3];

    /*
    Load the needed kernels using a furnsh_c call on the
    meta kernel.
     */
    furnsh_c("./data/other_stuff/coord.tm");


    /*
    Prompt the user for a time string. Convert the
    time string to ephemeris time J2000 (ET).
     */

    /*
     * See initialization
     * prompt_c("Time of interest: ", LENOUT, timstr);
     */
    str2et_c(timstr, &et);

    /*
    Access the kernel pool data for the triaxial radii of the
    Earth, 'rad[0]' holds the equatorial radius, 'rad[2]'
    the polar radius.
     */
    bodvrd_c("Earth", "RADII", 3, &dim, rad);

    /*
    Calculate the flattening factor for the Earth.
 
             equatorial_radius - polar_radius
    flat =   ________________________________
 
                   equatorial_radius
     */

    flat = (rad[0] - rad[2]) / rad[0];

    /*
    Make the spkpos_c call to determine the apparent position of
    the Moon w.r.t. to the Earth at 'et' in the inertial frame.
     */
    spkpos_c("MOON", et, inrfrm, "LT+S", "EARTH", pos, &ltime);


    /*
    Show the current frame and time.
     */
    printf(" Time : %s\n", timstr);
    printf("  Inertial Frame: %s\n", inrfrm);

    /*
    First convert the position vector
    X = pos[0], Y = pos[1], Z = pos[2], to RA/DEC.
     */
    recrad_c(pos, &range, &ra, &dec);
    printf("   Range/Ra/Dec\n");
    printf("    Range: %20.6f\n", range);
    printf("    RA   : %20.6f\n", ra * dpr_c());
    printf("    DEC  : %20.6f\n", dec * dpr_c());

    /*
    ...latitudinal coordinates...
     */
    reclat_c(pos, &range, &lon, &lat);
    printf("   Latitudinal\n");
    printf("    Rad  : %20.6f\n", range);
    printf("    Lon  : %20.6f\n", lon * dpr_c());
    printf("    Lat  : %20.6f\n", lat * dpr_c());

    /*
    ...spherical coordinates use the colatitude,
    the angle from the Z axis.
     */
    recsph_c(pos, &range, &colat, &lon);
    printf("   Spherical\n");
    printf("    Rad  : %20.6f\n", range);
    printf("    Lon  : %20.6f\n", lon * dpr_c());
    printf("    Colat: %20.6f\n", colat * dpr_c());


    /*
    Make the spkpos_c call to determine the apparent position of
    the Moon w.r.t. to the Earth at 'et' in the non-inertial,
    body fixed, frame.
     */
    spkpos_c("MOON", et, nonfrm, "LT+S", "EARTH", pos, &ltime);

    puts(" ");
    printf("  Non-inertial Frame: %s\n", nonfrm);

    /*
    ...latitudinal coordinates...
     */
    reclat_c(pos, &range, &lon, &lat);
    printf("   Latitudinal\n");
    printf("    Rad  : %20.6f\n", range);
    printf("    Lon  : %20.6f\n", lon * dpr_c());
    printf("    Lat  : %20.6f\n", lat * dpr_c());

    /*
    ...spherical coordinates...
     */
    recsph_c(pos, &range, &colat, &lon);
    printf("   Spherical\n");
    printf("    Rad  : %20.6f\n", range);
    printf("    Lon  : %20.6f\n", lon * dpr_c());
    printf("    Colat: %20.6f\n", colat * dpr_c());

    /*
    ...finally, convert the position to geodetic coordinates.
     */
    recgeo_c(pos, rad[0], flat, &lon, &lat, &range);
    printf("   Geodetic\n");
    printf("    Rad  : %20.6f\n", range);
    printf("    Lon  : %20.6f\n", lon * dpr_c());
    printf("    Lat  : %20.6f\n", lat * dpr_c());
    puts(" ");


    return (0);
}
