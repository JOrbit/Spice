#include <stdio.h>
#include "SpiceUsr.h"

int sclket() {
    SpiceChar * mkfile;
    SpiceChar * utc;
    SpiceChar * sclk;

    SpiceDouble et;

    SpiceInt scid;


    mkfile = "./data/insitu_sensing/sclket.tm";
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


    return ( 0);
}
