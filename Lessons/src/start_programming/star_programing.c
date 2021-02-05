/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "SpiceUsr.h"

int start_programming() {
    ConstSpiceChar * versn;

    versn = tkvrsn_c("TOOLKIT");

    printf("Toolkit version %s\n", versn);

    return (0);
}

