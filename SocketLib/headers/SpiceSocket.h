/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpiceSocket.h
 * Author: owner
 *
 * Created on January 7, 2018, 5:57 PM
 */

#ifndef SPICESOCKET_H
#define SPICESOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>

#define HOSTNAME "localhost"
#define PORT 8080
#define PORTNUMBER "8080"
#define BACKLOG 1
#define BSIZE 10240

#define FURNSH_ID 1

typedef struct {
   int id;
   char data[BSIZE - sizeof (int)];
} SpiceId;

#ifdef __cplusplus
extern "C" {
#endif

   int ListenFd();

   int RecvFd();

   int SocketFd(struct addrinfo **addrinfoResult);

#ifdef __cplusplus
}
#endif

#endif /* SERVERCLIENT_H */

