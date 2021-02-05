#include <stdio.h>
#include "SpiceUsr.h"

int sscpnt() {
    SpiceChar * mkfile;
    SpiceChar * utc;
    SpiceChar * sclk;
    SpiceChar * target;
    SpiceChar * frame;
    SpiceChar * corrtn;
    SpiceChar * observ;
    SpiceChar * method;
    SpiceChar * fromfr;
    SpiceChar * tofr;

    SpiceDouble et;
    SpiceDouble state [6];
    SpiceDouble sundir [3];
    SpiceDouble ltime;
    SpiceDouble spoint [3];
    SpiceDouble trgepc;
    SpiceDouble srfvec [3];
    SpiceDouble srad;
    SpiceDouble slon;
    SpiceDouble slat;
    SpiceDouble sbpdir [3];
    SpiceDouble m2imat [3][3];

    SpiceInt scid;


    mkfile = "./data/insitu_sensing/sscpnt.tm";
    furnsh_c(mkfile);

    utc = "2004-06-11T19:32:00";
    str2et_c(utc, &et);

    printf("UTC       = %s     \n", utc);
    printf("ET        = %20.6f \n", et);

    scid = -82;
    sclk = "1465674964.105";
    scs2e_c(scid, sclk, &et);

    printf("SCLK      = %s     \n", sclk);
    printf("ET        = %20.6f \n", et);

    target = "CASSINI";
    frame = "ECLIPJ2000";
    corrtn = "NONE";
    observ = "SUN";

    spkezr_c(target, et, frame, corrtn, observ, state, &ltime);

    printf(" X        = %20.6f\n", state[0]);
    printf(" Y        = %20.6f\n", state[1]);
    printf(" Z        = %20.6f\n", state[2]);
    printf("VX        = %20.6f\n", state[3]);
    printf("VY        = %20.6f\n", state[4]);
    printf("VZ        = %20.6f\n", state[5]);

    target = "SUN";
    frame = "CASSINI_INMS";
    corrtn = "LT+S";
    observ = "CASSINI";

    spkpos_c(target, et, frame, corrtn, observ, sundir, &ltime);
    vhat_c(sundir, sundir);

    printf("SUNDIR(X) = %20.6f\n", sundir[0]);
    printf("SUNDIR(Y) = %20.6f\n", sundir[1]);
    printf("SUNDIR(Z) = %20.6f\n", sundir[2]);

    method = "NEAR POINT: ELLIPSOID";
    target = "PHOEBE";
    frame = "IAU_PHOEBE";
    corrtn = "NONE";
    observ = "CASSINI";

    subpnt_c(method, target, et, frame, corrtn, observ,
            spoint, &trgepc, srfvec);

    reclat_c(spoint, &srad, &slon, &slat);

    fromfr = "IAU_PHOEBE";
    tofr = "CASSINI_INMS";

    pxform_c(fromfr, tofr, et, m2imat);

    mxv_c(m2imat, srfvec, sbpdir);
    vhat_c(sbpdir, sbpdir);

    printf("LON       = %20.6f\n", slon * dpr_c());
    printf("LAT       = %20.6f\n", slat * dpr_c());
    printf("SBPDIR(X) = %20.6f\n", sbpdir[0]);
    printf("SBPDIR(Y) = %20.6f\n", sbpdir[1]);
    printf("SBPDIR(Z) = %20.6f\n", sbpdir[2]);

    return ( 0);
}
