/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessSpiceCommands.h
 * Author: owner
 *
 * Created on January 9, 2018, 7:17 PM
 */

#ifndef PROCESSSPICECOMMANDS_H
#define PROCESSSPICECOMMANDS_H


#define NUMCMDS 4096
#define DELIMITER ","

#ifdef __cplusplus
extern "C" {
#endif


int ProcessSpiceCommands(char*, char** );

#ifdef __cplusplus
}
#endif

#endif /* PROCESSSPICECOMMANDS_H */

