/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spice;

import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class GetSocket {

   private static String ServerName = "localhost";
   private static int Port = 8080;
   private static Socket socket = null;

   public static Socket getSocket() {
      if (GetSocket.socket == null) {
         Logger logger = Logger.getLogger("GetSocket");
         String msg = "Connecting to " + GetSocket.ServerName + " on port " + GetSocket.Port;
         logger.log(Level.INFO, msg);

         try {
            socket = new Socket(GetSocket.ServerName, GetSocket.Port);
         } catch (IOException ex) {
            msg = "Server is not running!";
            logger.log(Level.SEVERE, msg);
         }

      }
      return (GetSocket.socket);
   }

}
