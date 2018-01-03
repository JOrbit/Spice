#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SpiceUsr.h"

#define UTCLEN       32

void tostan(SpiceChar * alias);

int tkvstr() {

    /*
    Define the few variables needed for data input
    and output.
     */

    SpiceChar funits [UTCLEN];
    SpiceChar tunits [UTCLEN];
    SpiceChar fromstr[UTCLEN];
    SpiceDouble fvalue;
    SpiceDouble tvalue;

    /*
    Define the tkvrsn_c return value.
     */
    ConstSpiceChar * vers;

    /*
    Display the Toolkit version string with a
    tkvrsn_c call.
     */
    vers = tkvrsn_c("TOOLKIT");
    printf("\nConvert demo program compiled against "
            "CSPICE Toolkit %s\n\n", vers);

    /*
    The user first inputs the name of a unit of measure.
    Send the name through TOSTAN for de-aliasing.
     */
    prompt_c("From Units : ", UTCLEN, funits);
    tostan(funits);

    /*
    Input a double precision value to express in a new
    unit format.
     */
    prompt_c("From Value : ", UTCLEN, fromstr);
    prsdp_c(fromstr, &fvalue);

    /*
    Now the user inputs the name of the output units.
    Again we send the units name through TOSTAN for
    de-aliasing.
     */
    prompt_c("To Units   : ", UTCLEN, tunits);
    tostan(tunits);

    convrt_c(fvalue, funits, tunits, &tvalue);
    printf("%12f.6 %s\n", tvalue, tunits);

    return(0);
}

void tostan(SpiceChar * alias) {

    /*
    As a convenience, let's alias a few common terms
    to their appropriate counterpart. Use eqstr_c
    to compare strings. The comparison ignores
    letter case and trailing/leading spaces.
     */

    if (eqstr_c(alias, "meter")) {

        /*
        First, a 'meter' by any other name is a
        'METER' and smells as sweet ...
         */
        strcpy(alias, "METERS");

    } else if (eqstr_c(alias, "klicks") ||
            eqstr_c(alias, "kilometers") ||
            eqstr_c(alias, "kilometer")) {

        /*
        ... 'klicks' and 'KILOMETERS' and
        'KILOMETER' identifies 'KM'....
         */
        strcpy(alias, "KM");

    } else if (eqstr_c(alias, "secs")) {

        /*
        ... 'secs' to 'SECONDS'.
         */
        strcpy(alias, "SECONDS");

    } else if (eqstr_c(alias, "miles")) {

        /*
        ... and finally 'miles' to 'STATUTE_MILES'.
        Normal people think in statute miles.
        Only sailors think in nautical miles - one
        minute of arc at the equator.
         */
        strcpy(alias, "STATUTE_MILES");
    }
}