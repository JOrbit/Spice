/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   printEltsX.h
 * Author: owner
 *
 * Created on November 1, 2018, 6:28 PM
 */

#include "SpiceUsr.h"

#ifndef PRINTELTSX_H
#define PRINTELTSX_H

#ifdef __cplusplus
extern "C" {
#endif


void printEltsX(ConstSpiceDouble et,
        ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
        ConstSpiceDouble* elts);



#ifdef __cplusplus
}
#endif

#endif /* PRINTELTSX_H */

