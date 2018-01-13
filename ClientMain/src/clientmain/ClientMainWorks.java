/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.util.logging.Level;
import java.util.logging.Logger;
import spice.GetEt;
import spice.GetSocket;
import spice.LoadSpiceData;

/**
 *
 * @author owner
 */
public class ClientMainWorks {

   private static final Logger LOG = Logger.getLogger(ClientMainWorks.class.getName());

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      String lskFile = "D:/naif/Kernels/MEX/lsk/naif0008.tls";
      String utc = "2005 SEP 02 04:50:45";
      
      String msg = "ClientMainWorks loading LskFile = " + lskFile;
      LOG.log(Level.INFO, msg);
      LoadSpiceData.LoadLskFile(lskFile);

      msg = "ClientMainWorksg calling getEt with UTC = " + utc;
      LOG.log(Level.INFO, msg);
      double et = GetEt.getEt("2005 SEP 02 04:50:45");
      msg = "ClientMainWorks got et = " + Double.toString(et);
      LOG.log(Level.INFO, msg);
      
      GetSocket.closeSocket();

   }
}
