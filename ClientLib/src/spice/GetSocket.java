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

   private static final Logger LOG = Logger.getLogger(GetSocket.class.getName());

   private static final String ServerName = "localhost";
   private static final int Port = 8080;
   private static Socket socket = null;

   public static Socket getSocket() {
      if (GetSocket.socket == null) {
         String msg = "Connecting to " + GetSocket.ServerName + " on port " + GetSocket.Port;
         LOG.log(Level.INFO, msg);

         try {
            socket = new Socket(GetSocket.ServerName, GetSocket.Port);
         } catch (IOException ex) {
            msg = "Server is not running!";
            LOG.log(Level.SEVERE, msg);
         }

      }
      return (GetSocket.socket);
   }

   public static void closeSocket() {
      if (GetSocket.socket != null) {
         try {
            GetSocket.socket.close();
         } catch (IOException ex) {
            String msg = "Server is not running!";
            LOG.log(Level.SEVERE, msg);
         }
         GetSocket.socket = null;
      }
   }

}
