/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>

#include "ProcessSpiceCommand.h"
#include "Furnsh.h"
#include "Str2et.h"
#include "Bodvrd.h"
#include "Spkezr.h"

void ProcessSpiceCommand(char* token, char* obuf) {

   printf("INFO: ProcessSpiceCommand token = %s\n", token);
   printf("DEBUG: ProcessSpiceCommand strcmp(token,BODVRD) = %d\n", strcmp(token, "BODVRD"));
   
   if (strcmp(token, "FURNSH") == 0) {
      Furnsh(token, obuf);
   } else if (strcmp(token, "STR2ET") == 0) {
      Str2et(token, obuf);
   } else if (strcmp(token, "BODVRD") == 0) {
      Bodvrd(token, obuf);
   } else if (strcmp(token, "SPKEZR") == 0) {
      Spkezr(token, obuf);
   } else {
      sprintf(obuf, "INFO: ProcessSpiceCommand received UNKNOWN COMMAND = %s\n", token);
   } 
  
}