/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: owner
 *
 * Created on January 4, 2018, 7:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "SpiceSocket.h"
#include "ServerProcess.h"
#include "ProcessSpiceCommands.h"




/*
 * 
 */
int main(int argc, char** argv) {
    printf("INFO: Server startup.\n");

    int clientFd = 0;
    int listenFd = 0;

    listenFd = ListenFd();
    while (1) { // main accept() loop

        struct sockaddr_storage clientaddr;
        socklen_t addrsize;
        printf("INFO: Server waiting for client connection.\n");
        clientFd = accept(listenFd, (struct sockaddr *) &clientaddr, &addrsize);
        if (clientFd == -1) {
            perror("accept");
            continue;
        }
        if (!fork()) { // this is the child process
            close(listenFd); // child doesn't need the listener

            ServerProcess(clientFd);

            close(clientFd);
            printf("INFO: Server child process exiting.\n");
            exit(EXIT_SUCCESS);
        }
        printf("INFO: Server closing clientFd.\n");
        close(clientFd); // parent doesn't need this
    }

    printf("INFO: Server shutting down.\n");

   return (EXIT_SUCCESS);
}

