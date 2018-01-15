/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ProcessSpiceCommands.h"

char * ProcessSpiceCommands(char* ibuf) {

   printf("INFO: ProcessSpiceCommands received ibuf = %s\n", ibuf);

   char * obuf = "ProcessSpiceCommands";

   char* token = strtok(ibuf, DELIMITER);
   int command = 1;


   while (token != NULL) {

      printf("INFO: ProcessSpiceCommands received token = %s\n", token);

      if (command == 1) {
         printf("INFO: ProcessSpiceCommands received command = %s\n", token);
         SpiceCommands[NumCmds] = strdup(token);
         NumCmds++;
         command = 0;
         printf("DEBUG: End of command processing\n");

      } else {
         int ninputs = atoi(token);
         printf("INFO: ProcessSpiceCommands received number inputs = %d\n", ninputs);
         for (int i = 0; i < ninputs; i++) {
            token = strtok(NULL, DELIMITER);
            printf("INFO: ProcessSpiceCommands received input type = %s\n", token);
         }
         token = strtok(NULL, DELIMITER);
         int noutputs = atoi(token);
         printf("INFO: ProcessSpiceCommands received number outputs = %d\n", noutputs);
         for (int i = 0; i < noutputs; i++) {
            token = strtok(NULL, DELIMITER);
            printf("INFO: ProcessSpiceCommands received output type = %s\n", token);
         }
         command = 1;
      }

      token = strtok(NULL, DELIMITER);
      printf("INFO: ProcessSpiceCommands received token = %s\n", token);

   }

   return obuf;
}