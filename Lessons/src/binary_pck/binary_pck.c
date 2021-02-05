/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

/*
Standard CSPICE User Include File
 */
#include "SpiceUsr.h"

/*
Local Parameters
 */

#define METAKR "./data/binary_pck/mrotat.tm"

int binary_pck(void) {
    /*
    Local Variables
     */
    SpiceChar * timstr;

    SpiceDouble dist;
    SpiceDouble et;
    SpiceDouble imoonv [3];
    SpiceDouble lat;
    SpiceDouble lon;
    SpiceDouble ltime;
    SpiceDouble mmoonv [3];
    SpiceDouble msub [3];
    SpiceDouble pmoonv [3];
    SpiceDouble psub [3];
    SpiceDouble r;
    SpiceDouble sep;
    SpiceDouble srfvec [3];
    SpiceDouble trgepc;


    /*
    Load the kernels this program requires.
     */
    furnsh_c(METAKR);

    /*
    Convert our UTC string to seconds past J2000 TDB.
     */
    timstr = "2007 JAN 1 00:00:00";
    str2et_c(timstr, &et);

    /*
    Look up the apparent position of the Earth relative
    to the Moon's center in the IAU_MOON frame at ET.
     */
    spkpos_c("earth", et, "iau_moon",
            "lt+s", "moon", imoonv, &ltime);

    /*
    Express the Earth direction in terms of longitude
    and latitude in the IAU_MOON frame.
     */
    reclat_c(imoonv, &r, &lon, &lat);

    printf("\n"
            "Moon-Earth direction using low accuracy\n"
            "PCK and IAU_MOON frame:\n"
            "Earth lon (deg):        %15.6f\n"
            "Earth lat (deg):        %15.6f\n"
            "\n",
            lon * dpr_c(),
            lat * dpr_c());

    /*
    Look up the apparent position of the Earth relative
    to the Moon's center in the MOON_ME frame at ET.
     */
    spkpos_c("earth", et, "moon_me",
            "lt+s", "moon", mmoonv, &ltime);

    /*
    Express the Earth direction in terms of longitude
    and latitude in the MOON_ME frame.
     */
    reclat_c(mmoonv, &r, &lon, &lat);

    printf("Moon-Earth direction using high accuracy\n"
            "PCK and MOON_ME frame:\n"
            "Earth lon (deg):        %15.6f\n"
            "Earth lat (deg):        %15.6f\n"
            "\n",
            lon * dpr_c(),
            lat * dpr_c());

    /*
    Find the angular separation of the Earth position
    vectors in degrees.
     */
    sep = dpr_c() * vsep_c(imoonv, mmoonv);

    printf("For IAU_MOON vs MOON_ME frames:\n");
    printf("Moon-Earth vector separation angle (deg):     "
            "%15.6f\n\n", sep);

    /*
    Look up the apparent position of the Earth relative
    to the Moon's center in the MOON_PA frame at ET.
     */
    spkpos_c("earth", et, "moon_pa",
            "lt+s", "moon", pmoonv, &ltime);

    /*
    Express the Earth direction in terms of longitude
    and latitude in the MOON_PA frame.
     */
    reclat_c(pmoonv, &r, &lon, &lat);

    printf("Moon-Earth direction using high accuracy\n"
            "PCK and MOON_PA frame:\n"
            "Earth lon (deg):        %15.6f\n"
            "Earth lat (deg):        %15.6f\n"
            "\n",
            lon * dpr_c(),
            lat * dpr_c());

    /*
    Find the angular separation of the Earth position
    vectors in degrees.
     */
    sep = dpr_c() * vsep_c(pmoonv, mmoonv);

    printf("For MOON_PA vs MOON_ME frames:\n");
    printf("Moon-Earth vector separation angle (deg):     "
            "%15.6f\n\n", sep);

    /*
    Find the apparent sub-Earth point on the Moon at ET using the
    MOON_ME frame.
     */
    subpnt_c("near point: ellipsoid",
            "moon", et, "moon_me", "lt+s",
            "earth", msub, &trgepc, srfvec);

    /*
    Display the sub-point in latitudinal coordinates.
     */
    reclat_c(msub, &r, &lon, &lat);

    printf("Sub-Earth point on Moon using high accuracy\n"
            "PCK and MOON_ME frame:\n"
            "Sub-Earth lon (deg):   %15.6f\n"
            "Sub-Earth lat (deg):   %15.6f\n\n",
            lon * dpr_c(),
            lat * dpr_c());

    /*
    Find the apparent sub-Earth point on the Moon at ET using the
    MOON_PA frame.
     */
    subpnt_c("near point: ellipsoid",
            "moon", et, "moon_pa", "lt+s",
            "earth", psub, &trgepc, srfvec);

    /*
    Display the sub-point in latitudinal coordinates.
     */
    reclat_c(psub, &r, &lon, &lat);

    printf("Sub-Earth point on Moon using high accuracy\n"
            "PCK and MOON_PA frame:\n"
            "Sub-Earth lon (deg):   %15.6f\n"
            "Sub-Earth lat (deg):   %15.6f\n\n",
            lon * dpr_c(),
            lat * dpr_c());

    /*
    Find the distance between the sub-Earth points
    in km.
     */
    dist = vdist_c(msub, psub);

    printf("Distance between sub-Earth points (km): "
            "%15.6f\n", dist);

    return ( 0);
}

