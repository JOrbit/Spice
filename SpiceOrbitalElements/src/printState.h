/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   printState.h
 * Author: owner
 *
 * Created on November 1, 2018, 6:04 PM
 */

#include "SpiceUsr.h"

#ifndef PRINTSTATE_H
#define PRINTSTATE_H


#ifdef __cplusplus
extern "C" {
#endif

   static ConstSpiceInt NSTATES = 6;

   void printState(ConstSpiceDouble et,
           ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
           ConstSpiceDouble* state);


#ifdef __cplusplus
}
#endif

#endif /* PRINTSTATE_H */

