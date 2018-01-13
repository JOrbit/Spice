/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientmain;

import java.net.Socket;
import java.util.logging.Logger;
import spice.GetSocket;
import spice.SpiceCommands;

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
      
      byte[] send = SpiceCommands.toBytes();
      byte[] received = GetSocket.sendReceive(socket, send);
      
      GetSocket.closeSocket();
   }
}
