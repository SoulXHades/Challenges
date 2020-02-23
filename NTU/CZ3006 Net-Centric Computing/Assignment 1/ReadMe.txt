THE SIMULATED COMMUNICATION SYSTEM(provided)
The simulated communication system consists of the following two major components:

1.Network Simulator
This component simulates the physical transmission media which connects two communicating virtual machines. 
The component may be set to operate in one of the four different quality levels of service:
	o Level 0: an error-free transmission media.oLevel 1: a transmission media which may lose frames.
	o Level 2: a transmission media which may damage frames (i.e., generating checksum-errors).
	o Level 3: a transmission media which may lose and damage frames.


2.Virtual MachineThis component simulates a communicating virtual machine. 
Internally, it is divided into two sub-components:

(1) Sliding Window ProtocolThis component implements the sliding window protocol (i.e., the data link layer). 
In this simulated system, this component cannot work alone, and must interact with the Sliding Window Environment component 
(to be described next) in order to fetch/deliver packets from/to the upper network layer, 
and to fetch/deliver frames from/to the lower physical layer.

(2) Sliding Window EnvironmentThis component provides the environment in which the sliding window protocol component is working. 
Basically, this componentimplements the following interfaces:
	o The  interface  between  the  data  link  layer  and  the  network  layer.  
	This  interface consists of three procedures:
		- to_network_layer(), to deliver a packet to the network layer.
		- from_network_layer(), to fetch a packet from the network layer.
	o The  interface  between  the  data  link  layer  and  the  physical  layer.  
	This  interface consists of two procedures:
		- to_physical_layer(),to deliver a frame to the physical layer.
		- from_physical_layer(), to fetch a frame from the physical layer.

	In addition, this component is responsible for interacting with the Network Simulator to transmit/receive frames 
	to/from the underlying transmission media.

	o The  interface  between  the  data  link  layer  and  the  underlying  event  queue.  
	This interface consists of the following procedures:
		- wait_for_event(): to wait for the arrival of an event.
		- generate_acktimeout_event():to   generate   an   acknowledgement timeout event.
		- generate_timeout_event(int  seqnr):  to  generate  a  timeout  event for an outstanding frame with the sequence number seqnr. 

	Note: When a  timeout  event  is  being  handled  by  the  sliding  window  protocol,  
	the protocol   variable oldest_framewill   be   automatically   set   to   the sequence number corresponding to the current 
	timeout event.It  should  be  pointed  out  that  the  Network  Simulator  component  is  running  in  one process,  
	and  the  Virtual  Machine  component  (including  both  the  Sliding  Window Protocol  and  the  Sliding  Window  Environment)  
	is  running  in  another  process.  To simulate  the  communication  between  two  virtual  machines,  
	two  Virtual  Machine processes must be executed.


YOUR TASK
Both  the  Network  Simulator  and  Sliding  Window  Environment  components  have  been implemented and supplied. 
Your task is to implement the Sliding Window Protocol component (i.e.,  the  data  link-layer)  of  the  simulated  communication  system.  
This  component  must implement all the features in the sliding window protocol specified in Fig.3-19 of Section 3.4 of the text book
(provided together with this Lab Manual on NTULearn), including:

1.Full-duplex data communication.
2.In-order delivery of packets to the network-layer.
3.Selective repeatretransmission strategy.
4.Synchronization with the network-layer by granting credits.
5.Negative acknowledgement.
6.Separate acknowledgment when the reverse traffic is light or none.

Your implementation must be able to withstand quality level 3 of the Network Simulator component.


TESTING AND RUNNING THE SYSTEM
To  run  your  code  in  the  simulated  communicated  system,  you  should  first  compile  your  java code by typing:

javac SWP.java

Then the following steps should be followed to run the system:

1.start the Network Simulator (NetSim) component in one window by typing:
	java NetSim n,   where nis the quality level and may take a value 0, 1, 2, or 3. 
2.start  the  first  Virtural  Machine  (VMach)  component  in  another  separate  window  by typing:
	java VMach 1, where 1 is the identifier of this VMach. 
3.start  the  second  Virtural  Machine  (VMach) component in the  third separate  window by typing:
	java VMach 2, where 2is the identifier of this VMach. 

To  terminate  the  whole  system  at  the  end  or  middle  of  the  execution,  
you  may  simply  type control-c in anyone of the three windows.

After   each   run   of   the   system,   two   output   text   files ─ receive_file_1.txt and receive_file_2.txt ─ will  
be  automatically  generated,  with receive_file_1.txtbeing generated    by    VMach   1   
and   containing   the   texts   received   from   VMach   2,   and receive_file_2.txt being  generated  by  
VMach  2  and  containing  the  texts  received  from VMach   1.   If   the   sliding   window   protocol   is   correctly   implemented,   
the   contents   in receive_file_1.txtshould   be   the   same   as send_file_2.txt,   
and   the   contents   in receive_file_2.txtshould  be  the  same  as send_file_1.txt. 
Both send_file_1.txtand send_file_2.txthave been provided(see APPENDICES of this manual).


GENERAL SUGGESTIONS
1.Read this document and the supplied source files carefully.
2.Read and fully understand the sliding windowprotocol in Fig.3-18. and relevant sections (particularly Section3.4.) of the textbook.
3.While testing your sliding window protocol implementation, first test it while NetSim is running at quality level 0, 
then at quality levels 1, 2,and 3, one by one.


APPENDICES
The following files have been provided:

1.Source files:Two java source files are provided:
	o SWP.java:The skeleton of the Sliding Window Protocol component. Note: this is the only provided java source file that you can change. 
	You may add new java classes in orderto fully implement the sliding window protocol.
	o PFrame.java:The frame class source file. 
	Note: this java source file is provided for your reference in implementing sliding window protocol, 
	but you should not change anything inthis file.
2.Class filesA number of java class files are provided, which implement the Network Simulator component 
and the Sliding Window Environment component:oNetSim.class: the main class of the Network Simulator component.
	o Forwarder.class: an auxiliary thread class of the NetSim component.
	o VMach.class:the main class of the Virtual Machine component.
	o SWE.class:the major class of the Sliding Window Environment component.
	o FrameHanlder.class: an auxiliary thread class of the SWE component.
	o NetworkSender.class: an auxiliary thread class of the SWE component.
	o NetworkReceiver.class: an auxiliary thread class of the SWE component.
	o EventQueue.class: an auxiliary class of the SWE component.
	o Packet.class: an auxiliary class of the SWE component.
	o PacketQueue.class: an auxiliary class of the SWE component.
	o PEvent.class: an auxiliary class of the SWE component.
	o PFrame.class: an auxiliary class of the SWE component.
	o PFrameMsg.class: an auxiliary class of the SWEcomponent.
3.Testing text filesTwo text files are provided for testing purpose. 
They are used by the Sliding Window Environment component to generate a sequence of packets to be sent 
to the other communicating machines:
	o send_file_1.txt: the file is used by VMach 1 to generate a sequence of (text) packets to VMach 2.
	o send_file_2.txt: the file is used by VMach 2 to generate a sequence of (text) packets to VMach 1.

You do not need to change these two input files. But if you wish, you are free to modify 
the contents of these two files to suit your special needs of testing. 

You should download all the above files (packaged in ass1.zip) from the course siteof NTULearn) 
into your local PC in any directory of your choice. Then, you should update the ``classpath'' 
environment variable of your system (Windows or Unix/Linux) to include the path to the directory containing the downloaded files.