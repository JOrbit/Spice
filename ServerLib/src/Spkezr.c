/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ProcessSpiceCommand.h"
#include "Spkezr.h"
#include "SpiceUsr.h"

void Spkezr(char* token, char* obuf) {

   printf("INFO: Spkezr token = %s\n", token);
   ConstSpiceChar *targ = strtok(NULL, DELIMITER);
   SpiceDouble et;
   sscanf(strtok(NULL, DELIMITER), "%f", &et);
   ConstSpiceChar *ref = strtok(NULL, DELIMITER);
   ConstSpiceChar *abcorr = strtok(NULL, DELIMITER);
   ConstSpiceChar *obs = strtok(NULL, DELIMITER);
   printf("INFO: Spkezr received utc = %s\n", token);
   SpiceDouble lt;
   SpiceDouble state [6];
   printf("INFO: Spkezr spkezr_c(%s, %f, %s, %s, %s, state, &lt)\n", 
           targ, et, ref, abcorr, obs);
   spkezr_c(targ, et, ref, abcorr, obs, state, &lt);
   sprintf(obuf, "%f,%f,%f,%f,%f,%f,%f", state[0], state[1], state[2], 
           state[3], state[4], state[5], lt);
   printf("INFO: Spkezr obuf = %s\n", obuf);
   printf("INFO: Spkezr strlen(obuf) = %d\n", (int)strlen(obuf));

}