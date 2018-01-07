/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SpiceUsr.h"

#include "LoadSpiceData.h"

void LoadSpiceData(char* msg, char* results) {
   const char* delimiters = ",";
   char* token = strtok(msg, delimiters);

   /*
    *  Load Spice Data
    */
   printf("INFO: LoadSpiceData received token = %s\n", token);
   printf("INFO: LoadSpiceData calling furnsh_c token\n");
   furnsh_c(token);

}