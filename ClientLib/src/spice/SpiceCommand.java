/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spice;

import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author owner
 */
public class SpiceCommand {

   private static final Logger LOG = Logger.getLogger(SpiceCommand.class.getName());

   public static final String INT = "INT";
   public static final String DOUBLE = "DOUBLE";
   public static final String CHAR = "CHAR";

   private String name;
   private List<String> inputs;
   private List<String> outputs;

   public SpiceCommand() {
   }

   public String getName() {
      return name;
   }

   public void setName(String name) {
      this.name = name;
   }

   public List<String> getInputs() {
      return inputs;
   }

   public void setInputs(List<String> inputs) {
      this.inputs = inputs;
   }

   public List<String> getOutputs() {
      return outputs;
   }

   public void setOutputs(List<String> outputs) {
      this.outputs = outputs;
   }

   public String toString() 
   {
      String s = this.name + SpiceConstants.DELIMITER;

      s += this.inputs.size() + SpiceConstants.DELIMITER;
      for (String si : this.inputs) {
         s += si + SpiceConstants.DELIMITER;
      }
    
      s += this.outputs.size() + SpiceConstants.DELIMITER;
      for (String so : this.outputs) {
         s += so + SpiceConstants.DELIMITER;
      }
      
      LOG.log(Level.INFO, "toString = " + s);
              
      return s;
   }

}
