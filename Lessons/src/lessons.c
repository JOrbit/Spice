/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

lessons() {

    printf("LESSON: start_programming\n");
    start_programming();

    printf("LESSON: binary_pck\n");
    binary_pck();

    printf("LESSON: event_finding\n");
    event_finding();

    /* 
     * insitu_sensing
     */

    printf("LESSON: insitu_sensing\n");
    convrt();
    getsta();
    sclket();
    scvel();
    soldir();
    sscpnt();

    /*
     * other_stuff
     */

    printf("LESSON: other_stuff\n");
    kpool();
    kervar();
    printf("CALL: coord()\n");
    coord();
    printf("CALL: xtic()\n");
    xtic();
    /*
    printf("CALL: errsyst()\n");
    errsyst();
 
    printf("CALL: aderr()\n");
    aderr();
     */
    printf("CALL: win()\n");
    win();
    /*
    printf("CALL: tkvstr()\n");
    tkvstr();
     */
    printf("CALL: sccalc()\n");
    sccalc();

    return (EXIT_SUCCESS);
}