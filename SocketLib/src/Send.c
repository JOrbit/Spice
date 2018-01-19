/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SpiceSocket.h"

void Send(int clientFd, char* obuf, int nbytes, char* ibuf) {
   int length = strlen(obuf);
   printf("INFO: Send obuf = %s\n", obuf);
   printf("INFO: Send obuf length = %d\n", length);
   send(clientFd, obuf, length, MSG_NOSIGNAL);
   printf("INFO: Send clearing obuf.\n");
   for (int i = 0; i < length; i++) {
      obuf[i] = 0;
   }
      printf("INFO: Send clearing ibuf.\n");

   for (int i = 0; i < nbytes; i++) {
      ibuf[i] = 0;
   }
}

