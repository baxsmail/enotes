### Creech Scheduling
* what if you have LOTS of cores 
	* you can run a thread with context switching ( # cores >> processes , cores ~ threads )
	* "Scheduling" becomes load balance
	* RAM 1600MHz * 1.6GBPS = 0.256 GB/s
	* might have saved some energy by using many cores since we don't need to save/load freq.
	* who is most parallel? Give that guy the most cores

### e.g.
* get a processor with 16 cores run process and each process can have 4 threads

* Round 0: give each process 1 core
	* P1 500 instr. / 1000 cycles
	* P2 400 instr. / 1000 cycles
	* P3 300 instr. / 1000 cycles
	* P4 200 instr. / 1000 cycles

* Round 1: equal share
	* Threads&P1 { 500,500,500,500 } 2000 total and 500 avg.
	* Threads&P2 { 100,100,100,100 } 400 total and 100 avg.
	* Threads&P3 { 100,200,100,200 } 600 total and 150 avg.
	* Threads&P4 { 600,600,600,600 } 2400 total and 100 avg.

* Result 1
	* N speed up 
	* No speed up at all
	* N/2 speed up
	* 3N speed up

* one scheduling method
	* 3N + N + N/2 = 15 ( sum up of tasks )

### Virtual Memory

* early systems: mem-management by hand
* Atlas System : " Sinlge level store "
* Translation step says 1 of 3 things
	1. dat is in mem [ i can have it ]
	2. data is on disk [ Os has to get i & put it into mem. ]
	3. invalid reference
* what if one want an event larger address space
	* 32 bit space / 64 bit space
	* 20 bit page number and 12 bit page offset
	* linear table has 1M entries each of which is ~ 4 bytes
