#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

/*
Define the maximum length for any string, 80
characters plus one null terminator.
 */
#define STRLEN 256

int xtic() {

    /* Declare the needed variables: */

    SpiceDouble et;
    SpiceDouble et1;
    SpiceDouble et2;

    SpiceBoolean ok;

    SpiceChar error [STRLEN];
    SpiceChar pictr [STRLEN];
    SpiceChar timstr[STRLEN];

    /*
    Assign the META variable to the name of the meta-kernel
    that contains the LSK kernel and create an arbitrary
    time string.
     */
    SpiceChar * CALSTR =
            "Mar 15, 2003 12:34:56.789 AM PST";

    SpiceChar * META =
            "./data/other_stuff/xtic.tm";

    SpiceChar * AMBIGSTR =
            "Mar 15, 79 12:34:56";


    /* Load the meta-kernel. */

    furnsh_c(META);
    printf("Original time string     : %s\n", CALSTR);

    /*
    Convert the time string to the number of ephemeris
    seconds past the J2000 epoch. This is the most common
    internal time representation used by the CSPICE
    system; CSPICE refers to this as ephemeris time (ET).
     */
    str2et_c(CALSTR, &et);
    printf("Corresponding ET         : %20.6f\n", et);


    /*
    Make a picture of an output format. Describe a Unix-like
    time string then send the picture and the 'et' value through
    timout_c to format and convert the ET representation of the
    time string into the form described in timout_c. The
    '::UTC-7' token indicates the time zone for the 'timstr'
    output - PDT. 'PDT' is part of the output, but not a time
    system token.
     */
    timout_c(et,
            "Wkd Mon DD HR:MN:SC PDT YYYY ::UTC-7",
            STRLEN,
            timstr);
    printf("Time in string format 1  : %s\n", timstr);


    /*
    Create another picture, this time combine a calendar,
    2 digit year , with Julian Day format.
     */
    timout_c(et,
            "Wkd Mon DD HR:MN ::UTC-7 YR (JULIAND.##### JDUTC)",
            STRLEN,
            timstr);
    printf("Time in string format 2  : %s\n", timstr);


    /*
    Why create a picture by hand when CSPICE can do it for you?
    Input a string to tpictr_c with the format of interest.
    'ok' returns a boolean indicating whether an error
    occurred while parsing the picture string, if so,
    an error diagnostic message returns in 'error'. In this
    example, no need exists to check the error flag since
    the picture string is known as correct..
     */
    tpictr_c("12:34:56.789 P.M. PDT January 1, 2006",
            STRLEN,
            STRLEN,
            pictr,
            &ok,
            error);

    /*
    Confirm the tpictr_c call succeeded. Report the error string
    if not.
     */
    if (!ok) {
        printf("\nError in TPICTR call:\n");
        printf("%s\n", error);
        exit(1);
    }

    timout_c(et, pictr, STRLEN, timstr);
    printf("Time in string format 3  : %s\n", timstr);


    /*
    Two digit year representations often cause problems due to
    the ambiguity of the century. The routine tsetyr_c gives the
    user the ability to set a default range for 2 digit year
    representation. SPICE uses 1969AD as the default start
    year so the numbers inclusive of 69 to 99 represent years
    1969AD to 1999AD, the numbers inclusive of 00 to 68 represent
    years 2000AD to 2068AD.
 
    The defined time string AMBIGSTR contains a two-digit
    year. Since the SPICE base year is 1969, the time
    subsystem interprets the string as 1979.
     */
    str2et_c(AMBIGSTR, &et1);


    /*
    Set 1980 as the base year causes CSPICE to interpret the time
    string's "79" as 2079.
     */
    tsetyr_c(1980);
    str2et_c(AMBIGSTR, &et2);


    /*
    Calculate the number of years between the two ET
    representations, ~100.
     */
    printf("Years between evaluations: %20.6f\n",
            (et2 - et1) / jyear_c());


    return (0);
}
