/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spice;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class GetEt {

   private static final Logger LOG = Logger.getLogger(GetEt.class.getName());

   static public double getEt(String utc) {
      double et = 0;

      int nbytes = 1024;
      byte[] ibytes = new byte[nbytes];
      String msg;

      try {

         msg = "Connected to server: " + GetSocket.getSocket().getRemoteSocketAddress();
         LOG.log(Level.INFO, msg);
         msg = "Server = " + GetSocket.getSocket().toString();
         LOG.log(Level.INFO, msg);

         InputStream inFromServer = GetSocket.getSocket().getInputStream();
         DataInputStream in = new DataInputStream(inFromServer);
         OutputStream outToServer = GetSocket.getSocket().getOutputStream();
         DataOutputStream out = new DataOutputStream(outToServer);

         byte[] obytes = utc.getBytes();
         out.write(obytes, 0, obytes.length);
         msg = "Sent to server -> " + utc;
         LOG.log(Level.INFO, msg);

         nbytes = in.read(ibytes, 0, ibytes.length);
         msg = "Read nbytes = " + nbytes;
         LOG.log(Level.INFO, msg);
         String imsg = new String(ibytes, 0, nbytes);
         imsg = imsg + "\n";
         msg = "Received message -> " + imsg;
         LOG.log(Level.INFO, msg);

      } catch (IOException ex) {
         msg = "Server is not running.";
         LOG.log(Level.SEVERE, msg);
      }

      return (et);
   }

}
