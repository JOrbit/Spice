/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import spice.GetSocket;

/**
 *
 * @author owner
 */
public class ClientMain {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      int nbytes = 1024;
      byte[] ibytes = new byte[nbytes];
      String msg;
      Logger logger = Logger.getLogger("ClientMain");

      try {

         msg = "Connected to server: " + GetSocket.getSocket().getRemoteSocketAddress();
         logger.log(Level.INFO, msg);
         msg = "Server = " + GetSocket.getSocket().toString();
         logger.log(Level.INFO, msg);

         InputStream inFromServer = GetSocket.getSocket().getInputStream();
         DataInputStream in = new DataInputStream(inFromServer);
         OutputStream outToServer = GetSocket.getSocket().getOutputStream();
         DataOutputStream out = new DataOutputStream(outToServer);

         for (int i = 0; i < 10; i++) {

            String omsg = "Requst #" + (i + 1);
            byte[] obytes = omsg.getBytes();
            out.write(obytes, 0, obytes.length);
            msg = "Sent to server -> " + omsg;
            logger.log(Level.INFO, msg);

            nbytes = in.read(ibytes, 0, ibytes.length);
            msg = "Read nbytes = " + nbytes;
            logger.log(Level.INFO, msg);
            String imsg = new String(ibytes, 0, nbytes);
            imsg = imsg + "\n";
            msg = "Received message -> " + imsg;
            logger.log(Level.INFO, msg);

         }

         GetSocket.getSocket().close();
      } catch (IOException ex) {
         msg = "Server is not running.";
         logger.log(Level.SEVERE, msg);
      }
   }
}
