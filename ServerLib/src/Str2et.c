/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ProcessSpiceCommands.h"
#include "Str2et.h"
#include "SpiceUsr.h"

void Str2et(char* token, char* obuf) {

   printf("INFO: Str2et token = %s\n", token);
   token = strtok(NULL, DELIMITER);
   printf("INFO: Str2et received utc = %s\n", token);
   SpiceDouble et;
   str2et_c(token, &et);
   printf("INFO: Str2et str2et_c returned ephemeris time = %f \n", et);
   sprintf(obuf, "%f", et);
   printf("INFO: Str2et obuf = %s\n", obuf);
   printf("INFO: Str2et strlen(obuf) = %d\n", strlen(obuf));
  
}