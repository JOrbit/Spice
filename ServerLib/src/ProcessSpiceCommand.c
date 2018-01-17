/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>

#include "ProcessSpiceCommand.h"

void ProcessSpiceCommand(char* token, int ispc, char* obuf) {

   printf("INFO: ProcessSpiceCommand token = %s\n", token);
   printf("INFO: ProcessSpiceCommand ispc = %d\n", ispc);
   printf("INFO: ProcessSpiceCommand obuf = %d\n", obuf);
   if (strcmp(token, "FURNSH") == 0) {
      sprintf(obuf, "ProcessPiced received command FURNSH");
   } else if (strcmp(token, "STR2ET") == 0) {
      sprintf(obuf, "ProcessPiced received command STR2ET");
   } else if (strcmp(token, "BODVRD") == 0) {
      sprintf(obuf, "ProcessPiced receive command BODVRD");
   } else {
      sprintf(obuf, "ProcessPiced received UNKNOWN COMMAND");
   }
   printf("INFO: ProcessSpiceCommand token = %s\n", token);
   printf("INFO: ProcessSpiceCommand ispc = %d\n", ispc);
   printf("INFO: ProcessSpiceCommand obuf = %d\n", obuf);

}