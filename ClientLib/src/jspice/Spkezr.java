/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jspice;

import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class Spkezr {

   private static final Logger LOG = Logger.getLogger(Spkezr.class.getName());
   private static final String COMMAND = "SPKEZR";
   //
   // Inputs
   //
   private String target = null;
   private double et = Double.NaN;
   private String refFrame = null;
   private String abcorr = null;
   private String observer = null;
   //
   // Outputs
   //
   private String status = null;
   private double[] stateVectors = null;
   private double lt = Double.NaN;

   private Spkezr() {
   }

   public Spkezr(String targ, double et, String ref, String abcorr,
           String obs) {
      this.target = targ;
      this.et = et;
      this.refFrame = ref;
      this.abcorr = abcorr;
      this.observer = obs;
      this.stateVectors = new double[6];
   }

   public String getTarget() {
      return target;
   }

   public double getEt() {
      return et;
   }

   public String getRefFrame() {
      return refFrame;
   }

   public String getAbcorr() {
      return abcorr;
   }

   public String getObserver() {
      return observer;
   }

   public String getStatus() {
      return status;
   }

   public double[] getStateVectors() {
      return stateVectors;
   }

   public double getLt() {
      return lt;
   }

   @Override
   public String toString() {
      String s = Spkezr.COMMAND;
      s = s + GetSocket.DELIMITER;
      s = s + this.target;
      s = s + GetSocket.DELIMITER;
      s = s + this.et;
      s = s + GetSocket.DELIMITER;
      s = s + this.refFrame;
      s = s + GetSocket.DELIMITER;
      s = s + this.abcorr;
      s = s + GetSocket.DELIMITER;
      s = s + this.observer;
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
      StringTokenizer st = new StringTokenizer(this.status,
              GetSocket.DELIMITER);
      for (int i = 0; i < this.stateVectors.length; i++) {
         this.stateVectors[i] = Double.parseDouble(st.nextToken());
      }
      this.lt = Double.parseDouble(st.nextToken());
      return this.status;
   }

   public static void main(String[] args) {
      String target = "EARTH";
      double et = 0.0;
      String refFrame = "J2000";
      String abcorr = "NONE";
      String observer = "SUN";
      Spkezr spkzer = new Spkezr(target, et, refFrame, abcorr, observer);
      LOG.log(Level.INFO, "spkzer.toString = " + spkzer.toString());
   }
}
