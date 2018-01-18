/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import jspice.Furnsh;
import jspice.GetSocket;
import jspice.SpiceCommands;
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

      Socket socket = GetSocket.getSocket();
      byte[] receive = new byte[GetSocket.BSIZE];

      LOG.log(Level.INFO, "Sending list of spice commands");
      byte[] send = SpiceCommands.toBytes();
      byte[] received = GetSocket.sendReceive(socket, send, receive);
      String msg = new String(received, 0, received.length);
      LOG.log(Level.INFO, "Received = " + msg);

      String lskFile = "D:/naif/Kernels/MEX/lsk/naif0008.tls";
      Furnsh furnshLsk = new Furnsh(lskFile);
      LOG.log(Level.INFO, "Sending spice command = " + furnshLsk);
      send = furnshLsk.toBytes();
      received = GetSocket.sendReceive(socket, send, receive);
      msg = new String(received, 0, received.length);
      LOG.log(Level.INFO, "Received = " + msg);

      String utc = "2005 SEP 02 04:50:45";
      Str2et str2etUtc = new Str2et(utc);
      LOG.log(Level.INFO, "Sending spice command = " + str2etUtc);
      send = str2etUtc.toBytes();
      received = GetSocket.sendReceive(socket, send, receive);
      msg = new String(received, 0, received.length);
      LOG.log(Level.INFO, "Received = " + msg);
      double et = Double.parseDouble(msg);
      LOG.log(Level.INFO, "et = " + et);

      GetSocket.closeSocket();
   }
}
