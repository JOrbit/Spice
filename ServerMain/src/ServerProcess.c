/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServerProcess.h"
#include "SpiceSocket.h"
#include "ProcessSpiceCommand.h"

void ServerProcess(int clientFd) {
   char ibuf[BSIZE] = {0};
   char obuf[BSIZE] = {0};
   int nbytes;

   while ((nbytes = Receive(clientFd, ibuf))) {
      char* token = strtok(ibuf, DELIMITER);
      printf("INFO: ServerProcess received token = %s\n", token);
      ProcessSpiceCommand(token, obuf);
      Send(clientFd, obuf, strlen(obuf), ibuf);
   }
}
