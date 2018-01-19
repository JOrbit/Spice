/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SpiceSocket.h"

int Receive(int clientFd, char* ibuf) {
   int nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL);
   printf("INFO: Receive recv returned nbytes = %d\n", nbytes);
   printf("INFO: Receive recv returned ibuf = %s\n", ibuf);
   return nbytes;
}