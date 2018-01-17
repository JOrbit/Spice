/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServerProcess.h"
#include "SpiceSocket.h"
#include "GetEt.h"
#include "LoadSpiceData.h"
#include "ProcessSpiceCommands.h"
#include "ProcessSpiceCommand.h"

void ServerProcess(int clientFd) {
   int NumCmds = 0;
   char* SpiceCommands[NUMCMDS] = {0};


   char ibuf[BSIZE] = {0};
   char obuf[BSIZE] = {0};
   int nbytes;

   nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL);
   printf("INFO: ServerProcess received nbytes = %d\n", nbytes);
   printf("INFO: ServerProcess received message. %s\n", ibuf);
   NumCmds = ProcessSpiceCommands(ibuf, SpiceCommands);
   printf("INFO: ServerProcess called ProcessSpiceCommands\n");
   printf("DEBUG: ServerProcess NumCmds = %d\n", NumCmds);
   sprintf(obuf, "ServerProcess ProcessSpiceCommands called.");
   printf("INFO: ServerProcess strlen(obuf) = %d\n", strlen(obuf));
   send(clientFd, obuf, strlen(obuf), MSG_NOSIGNAL);

   while ((nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL))) {
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
            printf("INFO: strlen(obuf) = %d\n", strlen(obuf));
            send(clientFd, obuf, strlen(obuf), MSG_NOSIGNAL);
         }
      }
      if (found == 0) {
         printf("WARNING: SpiceCommand %s not found!\n", token);
      }

   }

}
