/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jspice;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class SpiceCommands {

   private static final Logger LOG = Logger.getLogger(SpiceCommands.class.getName());

   private static List<SpiceCommand> commands = null;

   private SpiceCommands() {
   }

   public static List<SpiceCommand> getCommands() {
      if (commands == null) {

         commands = new ArrayList<SpiceCommand>();

         /*
   
           void furnsh_c ( ConstSpiceChar  * file ) 
 
           VARIABLE  I/O  DESCRIPTION 
            --------  ---  -------------------------------------------------- 
          file       I   Name of SPICE kernel file (text or binary). 
 
          */
         SpiceCommand sc = new SpiceCommand();
         sc.setName("FURNSH");
         List<String> inputs = new ArrayList<String>();
         String sv = new String(SpiceCommand.CHAR);
         inputs.add(sv);
         sc.setInputs(inputs);
         List<String> outputs = new ArrayList<String>();
         sc.setOutputs(outputs);
         commands.add(sc);

         /*
            void str2et_c ( ConstSpiceChar * str,
                            SpiceDouble    * et   )
   
            VARIABLE  I/O  DESCRIPTION
            --------  ---  --------------------------------------------------
            str        I   A string representing an epoch.
            et         O   The equivalent value in seconds past J2000, TDB.
          */
         sc = new SpiceCommand();
         sc.setName("STR2ET");
         inputs = new ArrayList<String>();
         sv = new String(SpiceCommand.CHAR);
         inputs.add(sv);
         sc.setInputs(inputs);
         outputs = new ArrayList<String>();
         sv = new String(SpiceCommand.CHAR);
         outputs.add(sv);
         sc.setOutputs(outputs);
         commands.add(sc);

         /*
   void bodvrd_c ( ConstSpiceChar   * bodynm,
                   ConstSpiceChar   * item,
                   SpiceInt           maxn,
                   SpiceInt         * dim,
                   SpiceDouble      * values ) 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodynm     I   Body name. 
   item       I   Item for which values are desired. ("RADII", 
                  "NUT_PREC_ANGLES", etc. ) 
   maxn       I   Maximum number of values that may be returned. 
   dim        O   Number of values returned. 
   values     O   Values. 
 
          */
         sc = new SpiceCommand();
         sc.setName("BODVRD");
         inputs = new ArrayList<String>();
         sv = new String(SpiceCommand.CHAR);
         inputs.add(sv);
         sv = new String(SpiceCommand.CHAR);
         inputs.add(sv);
         sv = new String(SpiceCommand.INT);
         inputs.add(sv);
         sc.setInputs(inputs);
         outputs = new ArrayList<String>();
         sv = new String(SpiceCommand.INT);
         outputs.add(sv);
         sv = new String(SpiceCommand.DOUBLE);
         outputs.add(sv);
         sc.setOutputs(outputs);
         commands.add(sc);

      }

      return commands;
   }

   public static byte[] toBytes() {
      byte[] bytes = null;

      List<SpiceCommand> commands = getCommands();

      String s = "";
      for (SpiceCommand sc : commands) {
         s += sc.toString();
      }

      LOG.log(Level.INFO, s);
      
      return s.getBytes();
   }

   public static void main(String[] args) 
   {
      SpiceCommands.toBytes();
   }
}
