/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   printStateDiff.h
 * Author: owner
 *
 * Created on November 2, 2018, 4:09 PM
 */

#ifndef PRINTSTATEDIFF_H
#define PRINTSTATEDIFF_H

#include "SpiceUsr.h"

#ifdef __cplusplus
extern "C" {
#endif

   void printStateDiff(ConstSpiceChar* target, ConstSpiceChar* frame, ConstSpiceChar* observer,
           ConstSpiceDouble et1, ConstSpiceDouble et2,
           SpiceDouble* state1, SpiceDouble* state2);


#ifdef __cplusplus
}
#endif

#endif /* PRINTSTATEDIFF_H */

