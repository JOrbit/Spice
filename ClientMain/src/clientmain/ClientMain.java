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

      String lskFile = "D:/naif/Kernels/MEX/lsk/naif0008.tls";
      Furnsh furnshLsk = new Furnsh(lskFile);
      furnshLsk.process();

      int year = 1017;
      String utc = null;
      for (int i = 0; i < 1; i++) {
         utc = new String(Integer.toString(year));
         utc = utc + " SEP 02 04:50:45";
         year++;
         Str2et str2etUtc = new Str2et(utc);
         str2etUtc.process();
         LOG.log(Level.INFO, "bodvrd.getGm() = " + str2etUtc.getEt());
         LOG.log(Level.INFO, "runs = " + (i + 1));
      }

      String pckFile = "D:/naif/Kernels/MEX/pck/DE403-MASSES.TPC";
      Furnsh furnshPck = new Furnsh(pckFile);
      furnshPck.process();

      Bodvrd bodvrd = new Bodvrd("MARS");
      bodvrd.process();
      LOG.log(Level.INFO, "bodvrd.getGm() = " + bodvrd.getGm());

      String spkFile = "D:/naif/Kernels/MEX/spk/ORMM__050901000000_00165.BSP";
      Furnsh furnshSpk = new Furnsh(spkFile);
      furnshSpk.process();

      String target = "EARTH";
      double et = 0.0;
      String refFrame = "J2000";
      String abcorr = "NONE";
      String observer = "SUN";
      Spkezr spkezr = new Spkezr(target, et, refFrame, abcorr, observer);
      spkezr.process();
      for (int i = 0; i < spkezr.getStateVectors().length; i++) {
         LOG.log(Level.INFO, "stageVectors[" + i + "]"
                 + spkezr.getStateVectors()[i]);
      }
      LOG.log(Level.INFO, "lt = " + spkezr.getLt());

      GetSocket.closeSocket();
   }
}
