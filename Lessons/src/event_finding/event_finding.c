/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string.h>
#include <stdio.h>
#include "SpiceUsr.h"

/*
PROGRAM VIEWPR
 
Find and display the window of times when the MEX
spacecraft is above a specified elevation limit in the
topocentric reference frame of DSN station DSS-14.
 */

int event_finding() {
    /*
    Local constants
     */

    /*
    The  meta-kernel:
     */
#define METAKR          "./data/event_finding/viewpr.tm"

    /*
    Maximum number of intervals in any window:
     */
#define MAXIVL          1000

    /*
    Maximum result window size:
     */
#define MAXWIN          ( 2 * MAXIVL )

    /*
    Format string for time output:
     */
#define TDBFMT          "YYYY MON DD HR:MN:SC.### (TDB) ::TDB"

    /*
    String lengths and other bounds:
     */
#define LNSIZE          201
#define TIMLEN          51

    /*
    Local variables
     */

    /*
    Confinement window used to store interval to be searched:
     */
    SPICEDOUBLE_CELL(cnfine, MAXWIN);

    /*
    Window to hold sets of times when
    target is above the elevation limit:
     */
    SPICEDOUBLE_CELL(riswin, MAXWIN);

    SpiceChar * abcorr;
    SpiceChar * coord;
    SpiceChar * crdsys;
    SpiceChar * obsfrm;
    SpiceChar * relate;
    SpiceChar * srfpt;
    SpiceChar * start;
    SpiceChar * stop;
    SpiceChar * target;
    SpiceChar timstr [ TIMLEN ];

    SpiceDouble adjust;
    SpiceDouble elvlim;
    SpiceDouble etbeg;
    SpiceDouble etend;
    SpiceDouble intbeg;
    SpiceDouble intend;
    SpiceDouble revlim;

    /*
    stepsz is the step size, measured in seconds, used to search
    for times bracketing a state transition.
     */
    SpiceDouble stepsz;

    SpiceInt i;
    SpiceInt winsiz;


    /*
    Load the meta-kernel.
     */
    furnsh_c(METAKR);

    /*
    Assign the inputs for our search.
 
    Since we're interested in the apparent location of the
    target, we use light time and stellar aberration
    corrections. We use the "converged Newtonian" form
    of the light time correction because this choice may
    increase the accuracy of the occultation times we'll
    compute using gfoclt_c.
     */
    srfpt = "DSS-14";
    obsfrm = "DSS-14_TOPO";
    target = "MEX";
    abcorr = "CN+S";
    start = "2004 MAY 2 TDB";
    stop = "2004 MAY 6 TDB";
    elvlim = 6.0;

    /*
    The elevation limit above has units of degrees; we convert
    this value to radians for computation using SPICE routines.
    We'll store the equivalent value in radians in REVLIM.
     */
    revlim = rpd_c() * elvlim;

    /*
    Since SPICE doesn't directly support the AZ/EL coordinate
    system, we use the equivalent constraint
 
       latitude > REVLIM
 
    in the latitudinal coordinate system, where the reference
    frame is topocentric and is centered at the viewing location.
     */
    crdsys = "LATITUDINAL";
    coord = "LATITUDE";
    relate = ">";

    /*
    The adjustment value only applies to absolute extrema
    searches; simply give it an initial value of zero
    for this inequality search.
     */
    adjust = 0.0;

    /*
    STEPSZ is the step size, measured in seconds, used to search
    for times bracketing a state transition. Since we don't expect
    any events of interest to be shorter than five minutes, and
    since the separation between events is well over 5 minutes,
    we'll use this value as our step size. Units are seconds.
     */
    stepsz = 300.0;

    /*
    Display a banner for the output report:
     */
    printf("\n%s\n\n",
            "Inputs for target visibility search:");

    printf("   Target                       = %s\n", target);
    printf("   Observation surface location = %s\n", srfpt);
    printf("   Observer's reference frame   = %s\n", obsfrm);
    printf("   Elevation limit (degrees)    = %f\n", elvlim);
    printf("   Aberration correction        = %s\n", abcorr);
    printf("   Step size (seconds)          = %f\n", stepsz);

    /*
    Convert the start and stop times to ET.
     */
    str2et_c(start, &etbeg);
    str2et_c(stop, &etend);

    /*
    Display the search interval start and stop times
    using the format shown below.
 
       2004 MAY 06 20:15:00.000 (TDB)
 
     */
    timout_c(etbeg, TDBFMT, TIMLEN, timstr);
    printf("   Start time                   = %s\n", timstr);

    timout_c(etend, TDBFMT, TIMLEN, timstr);
    printf("   Stop time                    = %s\n", timstr);

    printf("\n");

    /*
    Initialize the "confinement" window with the interval
    over which we'll conduct the search.
     */
    wninsd_c(etbeg, etend, &cnfine);

    /*
    In the call below, the maximum number of window
    intervals gfposc_c can store internally is set to MAXIVL.
 
    Now search for the time period, within our confinement
    window, during which the apparent target has elevation
    at least equal to the elevation limit.
     */
    gfposc_c(target, obsfrm, abcorr, srfpt,
            crdsys, coord, relate, revlim,
            adjust, stepsz, MAXIVL, &cnfine, &riswin);

    /*
    The function wncard_c returns the number of intervals
    in a SPICE window.
     */
    winsiz = wncard_c(&riswin);

    if (winsiz == 0) {
        printf("No events were found.\n");
    } else {
        /*
        Display the visibility time periods.
         */
        printf("Visibility times of %s as seen from %s:"
                "\n\n",
                target, srfpt);

        for (i = 0; i < winsiz; i++) {
            /*
            Fetch the start and stop times of the Ith interval
            from the search result window riswin.
             */
            wnfetd_c(&riswin, i, &intbeg, &intend);

            /*
            Convert the rise time to a TDB calendar string.
             */
            timout_c(intbeg, TDBFMT, TIMLEN, timstr);

            /*
            Write the string to standard output.
             */
            if (i == 0) {
                printf("Visibility or window start time:  %s\n",
                        timstr);
            } else {
                printf("Visibility start time:            %s\n",
                        timstr);
            }

            /*
            Convert the set time to a TDB calendar string.
             */
            timout_c(intend, TDBFMT, TIMLEN, timstr);

            /*
            Write the string to standard output.
             */
            if (i == winsiz - 1) {
                printf("Visibility or window stop time:   %s\n",
                        timstr);
            } else {
                printf("Visibility stop time:             %s\n",
                        timstr);
            }

            printf("\n");
        }
    }

    return ( 0);
}
