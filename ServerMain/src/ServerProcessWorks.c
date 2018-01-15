/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServerProcess.h"
#include "SpiceSocket.h"
#include "GetEt.h"
#include "LoadSpiceData.h"

void ServerProcessWorks(int clientFd) {
   char ibuf[BSIZE] = {0};
   char obuf[BSIZE] = {0};
   int nbytes;

   while ((nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL))) {

      printf("INFO: ServerProcess received nbytes = %d\n", nbytes);
      printf("INFO: ServerProcess received message. %s\n", ibuf);

      LoadSpiceData(ibuf, obuf);

      send(clientFd, obuf, strlen(obuf), MSG_NOSIGNAL);
      
      printf("INFO: ServerProcess sent nbytes = %d\n", (int)strlen(obuf));
      printf("INFO: ServerProcess sent message = %s\n", obuf);
      
      for (int i = 0; i < nbytes; i++) {
         ibuf[i] = 0;
      }
      nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL);
      
      printf("INFO: ServerProcess received nbytes = %d\n", nbytes);
      printf("INFO: ServerProcess received message. %s\n", ibuf);

      GetEt(ibuf, obuf);

      send(clientFd, obuf, strlen(obuf), MSG_NOSIGNAL);

      printf("INFO: ServerProcess sent nbytes = %d\n", (int)strlen(obuf));
      printf("INFO: ServerProcess sent message = %s\n", obuf);
   }

   printf("SERVER: Received nbytes = %d\n", nbytes);

}