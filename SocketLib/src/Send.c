/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SpiceSocket.h"

void Send(int clientFd, char* message) {
   int length = strlen(message);
   printf("INFO: Send message = %s\n", message);
   printf("INFO: Send message length = %d\n", length);
   send(clientFd, message, length, MSG_NOSIGNAL);
}

