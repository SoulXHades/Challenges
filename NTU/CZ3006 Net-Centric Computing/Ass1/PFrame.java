/*===============================================================*
 *  File: PFrame.java                                            *
 *                                                               *
 *  The class for Frame objects. 					     *
 *  Used by SWP and SWE classes.	 			     *
 *  Uses the Packet class			     			     *
 *				                                         *
 *  Author: Professor SUN Chengzheng                             *
 *          School of Computer Engineering                       *
 *          Nanyang Technological University                     *
 *          Singapore 639798                                     *
 *===============================================================*/
public class PFrame {
/**************************************************************
		Class constants
**************************************************************/
   
   public static final int DATA = 0;
   public static final int ACK  = 1;
   public static final int NAK  = 2;
   public static final String[] KIND = {"DATA", 
						    "ACK", 
						    "NAK" };  

/**************************************************************
           Instance variables (all public for easy reference)
**************************************************************/
   
   public int kind = 0;
   public int ack = 0;
   public Packet info = new Packet();
   public int seq = 0; 

}//End of PFrame Class
