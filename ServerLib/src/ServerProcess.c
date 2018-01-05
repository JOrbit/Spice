/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServerClient.h"

void ServerProcess(int clientFd) {
   char ibuf[BSIZE] = {0};
   char obuf[BSIZE] = {0};
   SpiceId spiceId;
   int nbytes;
   char* header = "Acknowledge message. ";
   int hdrlen = strlen(header);
   while ((nbytes = recv(clientFd, ibuf, BSIZE, MSG_WAITALL))) {
      printf("SERVER: Received nbytes = %d\n", nbytes);
      printf("SERVER: Received message. %s\n", ibuf);

      spiceId = (SpiceId) ibuf;

      printf("INFO: ServerProcess spiceId.id = %i\n", spiceId.id);
      printf("INFO: ServerProcess spiceId.data = %s\n", spiceId.data);

      //
      // TODO: Call Spice function.
      // Return results or error messages.
      //        
   }

   printf("SERVER: Received nbytes = %d\n", nbytes);

}