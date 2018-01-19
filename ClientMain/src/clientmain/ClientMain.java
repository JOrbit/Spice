/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.util.logging.Level;
import java.util.logging.Logger;
import jspice.Furnsh;
import jspice.GetSocket;
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
      LOG.log(Level.INFO, "Sending spice command = " + furnshLsk);
      String msg = furnshLsk.process();
      LOG.log(Level.INFO, "Received = " + msg);

      int year = 1017;
      String utc = null;
      for (int i = 0; i < 1000; i++) {
         utc = new String(Integer.toString(year));
         utc = utc + " SEP 02 04:50:45";
         LOG.log(Level.INFO, "utc = " + utc);
         year++;
         Str2et str2etUtc = new Str2et(utc);
         LOG.log(Level.INFO, "Sending spice command = " + str2etUtc);
         msg = str2etUtc.process();
         LOG.log(Level.INFO, "Received = " + msg);
         LOG.log(Level.INFO, "str2etUtc.getEt() = " + str2etUtc.getEt());

         LOG.log(Level.INFO, "runs = " + (i + 1));

      }

      GetSocket.closeSocket();
   }
}
