/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.util.logging.Level;
import java.util.logging.Logger;
import jspice.Bodvrd;
import jspice.Furnsh;
import jspice.GetSocket;
import jspice.Spkezr;
import jspice.Str2et;

/**
 *
 * @author owner
 */
public class ClientMain {

   private static final Logger LOG = Logger.getLogger(ClientMain.class.getName());

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      
      LOG.setLevel(Level.SEVERE);

      String earthSunTm = "D:/naif/Kernels/EarthSun.tm";
      Furnsh furnshEarthSunTm = new Furnsh(earthSunTm);
      furnshEarthSunTm.process();

      int year = 1017;
      String utc = null;
      for (int i = 0; i < 1; i++) {
         utc = new String(Integer.toString(year));
         utc = utc + " SEP 02 04:50:45";
         year++;
         Str2et str2etUtc = new Str2et(utc);
         str2etUtc.process();
         LOG.log(Level.INFO, "str2etUtc.getEt() = " + str2etUtc.getEt());
         LOG.log(Level.INFO, "runs = " + (i + 1));
      }

      Bodvrd bodvrd = new Bodvrd("EARTH");
      bodvrd.process();
      LOG.log(Level.INFO, "bodvrd.getGm() = " + bodvrd.getGm());

      String target = "EARTH";
      double det = 86400.0;
      double et = 0.0;
      String refFrame = "J2000";
      String abcorr = "NONE";
      String observer = "SUN";
      for (int i = 0; i < (365 * 24); i++) {
         Spkezr spkezr = new Spkezr(target, et, refFrame, abcorr, observer);
         spkezr.process();
         for (int j = 0; j < spkezr.getStateVectors().length; j++) {
            LOG.log(Level.INFO, "stageVectors[" + j + "] = "
                    + spkezr.getStateVectors()[j]);
         }
         LOG.log(Level.INFO, "lt = " + spkezr.getLt());
         et += det;
      }

      GetSocket.closeSocket();
   }
}
