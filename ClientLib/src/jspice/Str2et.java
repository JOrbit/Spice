/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jspice;

import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class Str2et {
    private static final Logger LOG = Logger.getLogger(Str2et.class.getName());
   private static final String COMMAND = "STR2ET";

   private String utc = null;

   private Str2et() {
   }

   public Str2et(String fileName) {
      this.utc = fileName;
   }

   public String getUtc() {
      return utc;
   }

   public void setUtc(String utc) {
      this.utc = utc;
   }

   @Override
   public String toString() {
      String s = Str2et.COMMAND;
      s = s + SpiceConstants.DELIMITER;
      s = s + this.getUtc();
      s = s + SpiceConstants.DELIMITER;
      return s;
   }
   
   public byte[] toBytes() {
      return this.toString().getBytes();
   }

}
