/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "r2d.h"

ConstSpiceDouble r2d(SpiceDouble rad) {
   SpiceDouble deg = rad * 360.0 / (2.0 * PI);
   return deg;
}