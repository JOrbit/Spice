#include <stdio.h>
#include "SpiceUsr.h"
#include <stdlib.h>
#include <string.h>

#define MAXSIZ       8

/*
Define the maximum length for a UTC string, 25
characters plus one null terminator.
 */
#define UTCLEN       26

int win() {

    /*
    Define our variable types.
 
    Define the cells to use as windows.
    The windows can hold 8 data values i.e.
    four intervals.
     */

    SPICEDOUBLE_CELL(loswin, MAXSIZ);
    SPICEDOUBLE_CELL(phswin, MAXSIZ);
    SPICEDOUBLE_CELL(sched, MAXSIZ);

    SpiceInt i;
    SpiceInt small;
    SpiceInt large;

    SpiceChar utcstr[2][UTCLEN];

    /*
    Define sets of time intervals. For the purposes of this
    tutorial program, define time intervals representing
    an unobscured line of sight between a ground station
    and some  body.
     */
    SpiceChar los [MAXSIZ][UTCLEN] ={"Jan 1, 2003 22:15:02", "Jan 2, 2003  4:43:29",
        "Jan 4, 2003  9:55:30", "Jan 4, 2003 11:26:52",
        "Jan 5, 2003 11:09:17", "Jan 5, 2003 13:00:41",
        "Jan 6, 2003 00:08:13", "Jan 6, 2003  2:18:01"};

    /*
    A second set of intervals representing the times for which
    an acceptable phase angle exits between the ground station,
    the body and the Sun.
     */
    SpiceChar phase [MAXSIZ][UTCLEN] ={"Jan 2, 2003 00:03:30", "Jan 2, 2003 19:00:00",
        "Jan 3, 2003  8:00:00", "Jan 3, 2003  9:50:00",
        "Jan 5, 2003 12:00:00", "Jan 5, 2003 12:45:00",
        "Jan 6, 2003 00:30:00", "Jan 6, 2003 23:00:00"};

    SpiceDouble left;
    SpiceDouble right;
    SpiceDouble meas;
    SpiceDouble avg;
    SpiceDouble stddev;
    SpiceDouble los_et [MAXSIZ];
    SpiceDouble phs_et [MAXSIZ];


    /* Load our meta kernel for the leapseconds data. */
    furnsh_c("./data/other_stuff/win.tm");


    /*
    Windows consist of double precision values, convert the
    time tags defined in the LOS and PHASE arrays to
    double precision ET. Store the double values in the
    loswin and phswin arrays.
     */
    for (i = 0; i < MAXSIZ; ++i) {
        str2et_c(los[i], &los_et[i]);
        str2et_c(phase[i], &phs_et[i]);
    }

    /*
    Initialize the cells from the double precision arrays,
    then validate the cells as windows.
 
    Since we use 4 intervals, set the window to accept 8 (MAXSIZ)
    data values ( 4 * 2 = 8 ). Since we require no more than
    8 data values, assign a window size of 8.
     */

    memmove((SpiceDouble*) loswin.data,
            los_et,
            MAXSIZ * sizeof (SpiceDouble));

    memmove((SpiceDouble*) phswin.data,
            phs_et,
            MAXSIZ * sizeof (SpiceDouble));

    wnvald_c(MAXSIZ, MAXSIZ, &loswin);
    wnvald_c(MAXSIZ, MAXSIZ, &phswin);
    wnvald_c(MAXSIZ, MAXSIZ, &sched);


    /*
    The issue for consideration, at what times do line of
    sight events coincide with acceptable phase angles?
    Perform the set operation AND on loswin, phswin,
    place the results in the window 'sched'.
     */

    wnintd_c(&loswin, &phswin, &sched);

    puts(" ");
    printf("No. data values in sched           : %2d\n",
            (int) card_c(&sched));
    printf("Space available for values in sched: %2d\n",
            (int) size_c(&sched));

    /*
    Output the results. The number of intervals in 'sched'
    is half the number of data points (the cardinality).
    Use a call to card_c to retrieve the window's cardinality.
     */
    puts(" ");
    puts("Time intervals meeting defined criterion.");

    for (i = 0; i < card_c(&sched) / 2; ++i) {

        /*
        Extract from the derived 'sched' the values defining the
        time intervals, [small, large].
         */
        wnfetd_c(&sched, i, &left, &right);

        /*
        Convert the ET values to UTC for human comprehension.
         */
        et2utc_c(left, "C", 3, UTCLEN, utcstr[0]);
        et2utc_c(right, "C", 3, UTCLEN, utcstr[1]);

        /*
        Output the UTC string and the corresponding index
        for the interval.
         */
        printf("%2d  %s   %s\n", (int) i, utcstr[0], utcstr[1]);

    }

    puts(" ");
    puts("Summary of sched window");

    wnsumd_c(&sched, &meas, &avg, &stddev, &small, &large);

    /*
    Summarize the 'sched' window.
     */
    printf("o Total measure of sched    : %16.6f\n", meas);
    printf("o Average measure of sched  : %16.6f\n", avg);
    printf("o Standard deviation of\n ");
    printf("  the measures in sched     : %16.6f\n", stddev);


    /*
    The values for small and large refer to the indexes of the
    values in the window ('sched'). The shortest interval is
 
          [ SPICE_CELL_ELEM_D( &sched, small),
            SPICE_CELL_ELEM_D( &sched, small+1) ];
 
    the longest is
 
          [ SPICE_CELL_ELEM_D( &sched, large),
            SPICE_CELL_ELEM_D( &sched, large+1) ];
 
    Output the indexes for the shortest and longest
    intervals. As C bases an array index on 0, the interval
    index is half the array index.
     */
    printf("o Index of shortest interval: %2d\n", (int) small / 2);
    printf("o Index of longest interval : %2d\n", (int) large / 2);

    return (0);
}
