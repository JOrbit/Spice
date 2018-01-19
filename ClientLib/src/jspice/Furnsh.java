/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jspice;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class Furnsh {

   private static final Logger LOG = Logger.getLogger(Furnsh.class.getName());
   private static final String COMMAND = "FURNSH";

   private String fileName = null;
   private String data = null;
   private String status = null;

   private Furnsh() {
   }

   public Furnsh(String fileName) {
      this.fileName = fileName;
   }

   public String getFileName() {
      return fileName;
   }

   public void setFileName(String fileName) {
      this.fileName = fileName;
   }

   @Override
   public String toString() {
      String s = Furnsh.COMMAND;
      s = s + GetSocket.DELIMITER;
      s = s + this.getFileName();
      s = s + GetSocket.DELIMITER;
      return s;
   }

   private byte[] toBytes() {
      return this.toString().getBytes();
   }

   public String process() {
      LOG.log(Level.INFO, "process() called state = " + this.toString());
      GetSocket.sendReceive(this.toBytes());
      this.status = GetSocket.receiveToString();
      return this.status;

   }

}
