5th Course  
========

### Processes , Threads, fiber

including

* Thread
	* Thread of control
	* Process stack - PC
	* register file contents
	* stack contents

* Process Image ( memory image )
	* all your code
	* data, dyn. data, stack, heap, etc.

### early systems

* distributed systems ( networks )
	* Q1:how to use this to speed up codes
	* Q2:how can run logically monohthic program on this system
	* A:cut it up into distinct pieces `+` use explicit message passing for inter-processing comunication

* server/client e.g.

```cpp
	/*
	 * server instance
	 */
	while(1){
		wait for packet
		read packet
		handle packet
		// distributed file system
		// perform vast calculation
		// use HW not local ( printer, net, ports, disks, tape )
		// data base request
		// google, Amazon, etc.
		send response
	}
	/*
	 * client instance
	 */

	get request( e.g. from user )
	package it up and send to server
	wait for response
	do something in response, if appropriate

```
* they try to give an illusion s.t. all mems. are one logical memory

* then they try : multiprocessor
	* like a tightly coupted distributed system
	* BUT with shared memory
	* Q1:how to use this to speed up codes
	* Q2:how can run logically monohthic program on this system
	* A: inter-process communication via overlaps in the memory images

* program e.g.

* A: get shared segment, write value into shared seg., signal B
* B: get shared segment, wait for signal from A, read values from shared shared seg.
	* this is much easier to program then explicit message passing

### processes and light-weighted processes( user-level threads )

* now the OS sees processes
	* mem image `+` a bunch of `*` PC/regs/stack ( one for each thread)


### project 3 stuffs

* mailbox
