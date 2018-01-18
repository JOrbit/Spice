/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jspice;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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

   public static final int BSIZE = 10240;

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

   public static byte[] sendReceive(Socket socket, byte[] send, byte[] receive) {
      byte[] received = null;
      try {
         InputStream inFromServer = null;
         inFromServer = GetSocket.getSocket().getInputStream();
         DataInputStream in = new DataInputStream(inFromServer);
         OutputStream outToServer = GetSocket.getSocket().getOutputStream();
         DataOutputStream out = new DataOutputStream(outToServer);

         out.write(send, 0, send.length);

         int nbytes = in.read(receive, 0, receive.length);
         LOG.log(Level.INFO, "in.read nbytes = " + nbytes);
         received = new byte[nbytes];
         LOG.log(Level.INFO, "received.length = " + received.length);
         System.arraycopy(receive, 0, received, 0, nbytes);
         LOG.log(Level.INFO, "received.length = " + received.length);

      } catch (IOException ex) {
         Logger.getLogger(GetSocket.class.getName()).log(Level.SEVERE, null, ex);
      }

      return received;
   }

}
