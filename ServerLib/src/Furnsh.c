/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>

#include "ProcessSpiceCommands.h"
#include "Furnsh.h"
#include "SpiceUsr.h"

void Furnsh(char* token, char* obuf) {

   printf("INFO: Furnsh token = %s\n", token);
   token = strtok(NULL, DELIMITER);
   printf("INFO: Furnsh file name  = %s\n", token);
   furnsh_c(token);
   sprintf(obuf, "furnsh_c called with file name = %s\n", token);

}