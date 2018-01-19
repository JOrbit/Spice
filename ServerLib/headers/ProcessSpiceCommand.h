/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessSpiceCommand.h
 * Author: owner
 *
 * Created on January 16, 2018, 6:17 PM
 */

#ifndef PROCESSSPICECOMMAND_H
#define PROCESSSPICECOMMAND_H

#define DELIMITER ","

#ifdef __cplusplus
extern "C" {
#endif


   void ProcessSpiceCommand(char* token, char* obuf);

#ifdef __cplusplus
}
#endif

#endif /* PROCESSSPICECOMMAND_H */

