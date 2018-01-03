#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "SpiceUsr.h"

/*
Define the maximum length for any string, 80
characters plus one null terminator.
 */
#define STRLEN 81

int aderr() {


    /*  Declare the needed variables: */

    SpiceChar targ [STRLEN];

    /*
    Set a flag to start/stop and continue the
    inquiry loop.
     */
    SpiceBoolean doloop = SPICETRUE;

    SpiceDouble state[6];
    SpiceDouble ltime;


    /*
    The RETURN mode signals an error then returns to the
    caller. Just what we need. REPORT mode performs almost
    the same function as RETURN, however RETURN mode
    sets the return_c() value to TRUE and so the program does
    not execute those CSPICE routines that check the return_c()
    value. Consider REPORT mode useful for debugging.
     */
    erract_c("SET", STRLEN, "RETURN");

    /*
    Load the data we need for state evaluation.
     */
    furnsh_c("./data/other_stuff/aderr.tm");


    /*
    Start our input query loop to the user.
     */

    while (doloop) {

        /*
        For simplicity, we request only one input.
        The program calculates the state vector from
        Earth to the user specified target (TARG) in the
        J2000 frame, at ephemeris time zero, using
        aberration correction LT+S (light time plus
        stellar aberration).
         */
        prompt_c("Target: ", STRLEN, targ);

        if (eqstr_c(targ, "NONE")) {

            /*
            An exit condition. If the user inputs NONE
            for a target name, set the loop to stop...
             */
            doloop = SPICEFALSE;

        } else {

            /*
            ...otherwise evaluate the state between the Earth
            and the target.
             */
            spkezr_c(targ, 0., "J2000", "LT+S", "EARTH", state,
                    &ltime);

            /*
            What if the program can't perform the evaluation?
            Since we set the error subsystem to REPORT we know
            a failed spkezr_c call sets the failed_c flag to
            SPICETRUE then returns control to the calling routine.
            The CSPICE system also outputs an error message
            informing the user of the problem's cause.
 
            Examine the state of failed_c() to determine if we
            output a state vector or not.
             */

            if (!failed_c()) {
                printf("R : %20.6f %20.6f %20.6f\n",
                        state[0], state[1], state[2]);
                printf("V : %20.6f %20.6f %20.6f\n",
                        state[3], state[4], state[5]);
                printf("LT: %20.6f\n", ltime);
            } else {

                /*
                Problem. Something went wrong. Reset the error
                subsystem for another pass.
                 */
                reset_c();

            }

        }

    }

    return (0);
}
