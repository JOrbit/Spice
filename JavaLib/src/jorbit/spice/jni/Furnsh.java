/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jorbit.spice.jni;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class Furnsh {

   public static native void cFurnsh(String kernel);

   private static final Logger logger = Logger.getLogger(Furnsh.class.getName());

   static {
      logger.log(Level.INFO, "java.library.path = "
              + System.getProperty("java.library.path"));
      System.loadLibrary("libJinSpic");
   }

   public static void main(String[] args) {
      String kernel = "TODO";
      Furnsh fo = new Furnsh();
      fo.cFurnsh(kernel);

   }
}
