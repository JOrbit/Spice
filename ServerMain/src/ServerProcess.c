/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServerProcess.h"
#include "SpiceSocket.h"
#include "ProcessSpiceCommands.h"
#include "ProcessSpiceCommand.h"

void ClearBuf(int nybtes, char* ibuf);

void ServerProcess(int clientFd) {
   int NumCmds = 0;
   char* SpiceCommands[NUMCMDS] = {0};


   char ibuf[BSIZE] = {0};
   char obuf[BSIZE] = {0};
   int nbytes;

   nbytes = Receive(clientFd, ibuf);
   NumCmds = ProcessSpiceCommands(ibuf, SpiceCommands);
   sprintf(obuf, "ServerProcess ProcessSpiceCommands called.");
   Send(clientFd, obuf);
   ClearBuf(nbytes, ibuf);
   ClearBuf(strlen(obuf), obuf);

   while ((nbytes = Receive(clientFd, ibuf))) {
      char* token = strtok(ibuf, DELIMITER);
      printf("INFO: ServerProcess received token = %s\n", token);
      int found = 0;
      printf("DEBUG: ServerProcess NumCmds = %d\n", NumCmds);
      for (int i = 0; i < NumCmds; i++) {
         printf("DEBUG: ServerProcess SpiceCommands[%d] = %s\n",
                 i, SpiceCommands[i]);

         if (strcmp(token, SpiceCommands[i]) == 0) {
            printf("INFO: ServerProcess found spice command %s\n", SpiceCommands[i]);
            found = 1;
            ProcessSpiceCommand(token, i, obuf);
            Send(clientFd, obuf);
            ClearBuf(nbytes, ibuf);
            ClearBuf(strlen(obuf), obuf);
         }
      }
      if (found == 0) {
         printf("WARNING: SpiceCommand %s not found!\n", token);
      }

   }
}

void ClearBuf(int nbytes, char* ibuf) {
   for (int i = 0; i < nbytes; i++) {
      ibuf[i] = 0;
   }
}
