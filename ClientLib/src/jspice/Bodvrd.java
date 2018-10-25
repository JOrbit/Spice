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
public class Bodvrd {

   private static final Logger LOG = Logger.getLogger(Bodvrd.class.getName());
   private static final String COMMAND = "BODVRD";

   private String bodym = null;
   private static String bodyProperty = "GM"; // TODO more properties
   private String status = null;

   private double gm = Double.NaN;

   private Bodvrd() {
   }

   public Bodvrd(String bodynm) {
      Bodvrd.LOG.setLevel(LogLevel.LEVEL);
      this.bodym = bodynm;
   }

   public String getBodym() {
      return bodym;
   }

   public String getStatus() {
      return status;
   }

   public double getGm() {
      return gm;
   }

   @Override
   public String toString() {
      String s = Bodvrd.COMMAND;
      s = s + GetSocket.DELIMITER;
      s = s + this.getBodym();
      s = s + GetSocket.DELIMITER;
      return s;
   }

   private byte[] toBytes() {
      return this.toString().getBytes();
   }

   public String process() {
      LOG.log(Level.INFO, "process() sends = " + this.toString());
      GetSocket.sendReceive(this.toBytes());
      this.status = GetSocket.receiveToString();
      LOG.log(Level.INFO, "process() received = " + this.status);
      this.gm = Double.parseDouble(this.status);
      return this.status;
   }

   public static void main(String[] args) {
      Bodvrd bodvcd = new Bodvrd("MARS");
      LOG.log(Level.INFO, "bodvcd = " + bodvcd.toString());

   }
}
