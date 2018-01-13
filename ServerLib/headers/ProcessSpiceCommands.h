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


int NumCmds = 0;
#define NUMCMDS 4096
char SpiceCommands[NUMCMDS] = {0}; 
char SpiceInputs[NUMCMDS] = {0}; 
char SpiceOutputs[NUMCMDS] = {0}; 

#ifdef __cplusplus
extern "C" {
#endif


char * ProcessSpiceCommands(const char* ibuf);

#ifdef __cplusplus
}
#endif

#endif /* PROCESSSPICECOMMANDS_H */

