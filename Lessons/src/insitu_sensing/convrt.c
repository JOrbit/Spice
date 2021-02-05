#include <stdio.h>
#include "SpiceUsr.h"

int convrt() {
    SpiceChar * mkfile;
    SpiceChar * utc;
    SpiceDouble et;

    mkfile = "./data/insitu_sensing/convrt.tm";
    utc = "2004-06-11T19:32:00";
    str2et_c(utc, &et);

    printf("UTC       = %s     \n", utc);
    printf("ET        = %20.6f \n", et);

    return ( 0);
}

