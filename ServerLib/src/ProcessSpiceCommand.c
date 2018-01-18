/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>

#include "ProcessSpiceCommand.h"
#include "Furnsh.h"
#include "Str2et.h"

void ProcessSpiceCommand(char* token, int ispc, char* obuf) {

   printf("INFO: ProcessSpiceCommand token = %s\n", token);
   printf("INFO: ProcessSpiceCommand ispc = %d\n", ispc);
   printf("INFO: ProcessSpiceCommand obuf = %s\n", obuf);
   if (strcmp(token, "FURNSH") == 0) {
      Furnsh(token, obuf);
   } else if (strcmp(token, "STR2ET") == 0) {
      Str2et(token, obuf);
   } else if (strcmp(token, "BODVRD") == 0) {
      sprintf(obuf, "INFO: ProcessSpiceCommand receive command BODVRD");
   } else {
      sprintf(obuf, "INFO: ProcessSpiceCommand received UNKNOWN COMMAND");
   }
   printf("INFO: ProcessSpiceCommand token = %s\n", token);
   printf("INFO: ProcessSpiceCommand ispc = %d\n", ispc);
   printf("INFO: ProcessSpiceCommand obuf = %s\n", obuf);

}