/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "printEt.h"

void printEt(ConstSpiceDouble et) {
   SpiceChar utc[23];
   et2utc_c(et, "C", 3, 23, utc);

   printf("UTC       = %s     \n", utc);
   printf("ET        = %20.10f \n", et);
}

