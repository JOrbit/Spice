/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   r2d.h
 * Author: owner
 *
 * Created on November 1, 2018, 6:31 PM
 */

#ifndef R2D_H
#define R2D_H

#include "SpiceUsr.h"

#ifdef __cplusplus
extern "C" {
#endif

static ConstSpiceDouble PI = 3.14159265359;


SpiceDouble r2d(SpiceDouble rad);



#ifdef __cplusplus
}
#endif

#endif /* R2D_H */

