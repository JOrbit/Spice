#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

/*
Define the maximum length for any string, 80
characters plus one null terminator.
 */
#define STRLEN 256

void doerr();

int errsyst() {

    /*  Declare the needed variables: */

    SpiceChar errcon[STRLEN];
    SpiceBoolean doloop = SPICETRUE;

    /*
    Check into the error subsystem to create a traceback
    showing the call tree. A chkout_c must balance every
    chkin_c.
     */
    chkin_c("ERRSYSC");

    /*
    Before we start, what's the initial (default)
    error state? erract_c both sets the state and
    reports the state.
     */
    erract_c("GET", STRLEN, errcon);
    printf("Default error state: %s\n", errcon);


    /*
    Now start an input loop so we can try different
    settings for error response.
     */

   
    do {

        /* Again use ERRACT to retrieve the current error mode. */
        erract_c("GET", STRLEN, errcon);
        printf("Current error state: %s\n", errcon);


        /*
        Okay, input one of the response settings strings
        then set the error subsystem response to that value.
         */
        prompt_c("Set error condition (DEFAULT, REPORT, "
                "ABORT, RETURN, IGNORE): ",
                STRLEN,
                errcon);
        erract_c("SET", STRLEN, errcon);

        /* Cause an error signal. */
        /* TODO: doerr(); */


        /*
        Check for an error signal via a call to FAILED.
        At this point we see an important difference
        between the error mode's response to an error
        signal.
         */
        if (!failed_c()) {
            puts("No error signal noted.");
        } else {
            puts("Error signal noted.");
        }

    } while (doloop);


    /*
    Check out of the error subsystem tho' we'll
    never hit this call.
     */
    chkout_c("ERRSYSC");

    return (0);
}

/* This subroutine initiates a SPICE error signal. */

void doerr() {

    /* Check into the error subsystem as before. */

    chkin_c("DOERR");

    /*
    Let's signal an error. The string passed by setmsg_c
    is the long error message. You may place markers in the
    long message string then later substitute other data
    items for those markers.
     */
    setmsg_c("A truly horrendous event occurred "
            "during execution of this program. "
            "Data added to long error message string: "
            "A double #, an int #, and a string #.");

    /*
    Now substitute other data into the long message string.
    Note the substitutions work on the first found marker.
     */
    errdp_c("#", 186282.397);
    errint_c("#", 666);
    errch_c("#", "A STRING");


    /*
    SIGERR causes the error signal with the string passed
    from SETMSG. Set the error flag in the SPICE error
    subsystem and execute the proper error response.
     */
    sigerr_c("OOPS(SOMETHINGBAD)");

    chkout_c("DOERR");

}


