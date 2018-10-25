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
   
   public static final String DELIMITER = ",";
   
   private static final String ServerName = "localhost";
   private static final int Port = 8080;
   private static Socket socket = null;

   public static final int BSIZE = 10240;

   private static int nSend = -1;
   private static byte[] send = new byte[BSIZE];
   private static int nReceive = -1;
   private static byte[] receive = new byte[BSIZE];

   private static Socket getSocket() {
      GetSocket.LOG.setLevel(LogLevel.LEVEL);
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

   public static byte[] getReceive() {
      return receive;
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
         GetSocket.nSend = -1;
         GetSocket.send = new byte[BSIZE];
         GetSocket.nReceive = -1;
         GetSocket.receive = new byte[BSIZE];
      }
   }

   private static void cleanBuffers(byte[] toSend) {
      if (GetSocket.nSend > 0) {
         for (int i = 0; i < GetSocket.nSend; i++) {
            GetSocket.send[i] = 0;
         }
      }
      GetSocket.nSend = toSend.length;
      for (int i = 0; i < GetSocket.nSend; i++) {
         GetSocket.send[i] = toSend[i];
      }

      if (GetSocket.nReceive > 0) {
         for (int i = 0; i < GetSocket.nReceive; i++) {
            GetSocket.receive[i] = 0;
         }
      }
   }

   public static void sendReceive(byte[] toSend) {
      cleanBuffers(toSend);
      try {
         InputStream inFromServer = null;
         inFromServer = GetSocket.getSocket().getInputStream();
         DataInputStream in = new DataInputStream(inFromServer);
         OutputStream outToServer = GetSocket.getSocket().getOutputStream();
         DataOutputStream out = new DataOutputStream(outToServer);

         out.write(GetSocket.send, 0, GetSocket.nSend);

         int nbytes = in.read(GetSocket.receive, 0, GetSocket.receive.length);
         LOG.log(Level.INFO, "in.read nbytes = " + nbytes);
         GetSocket.nReceive = nbytes;

      } catch (IOException ex) {
         Logger.getLogger(GetSocket.class.getName()).log(Level.SEVERE, null, ex);
      }

   }

   public static String receiveToString() {
      String receiveString = null;
      if (GetSocket.nReceive > 0) {
         receiveString = new String(GetSocket.receive, 0, GetSocket.nReceive);
         return receiveString;
      }
      return receiveString;
   }
}
