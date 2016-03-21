### P5 issue

* core0 is int. by IRQ
* core1 is not using IRQ
* Int. Handler
	* saves status	
	* send MSG. to Kernel
	* jScheduling decision
	* restart state

### Virtual Mem. Hardware

* recap

* how to do this efficiently
	* HW/SW interaction/cooperation
		1. TLB
			1. If few segments, the process of segment translation can be really cheap( simple HW table )
			2. The page level translation however needs to keep track of millions of mappings
			3. How to make things faster
				1. cache
				2. pipeline
		2. bit of HW/OS interaction : who walks the page table
			1. OS
				* need TLB-miss interrupt
				* some way to insert mapping to TLB
			2. HW
				* would be nice ( e.g. MIPS )
			3. user application
		3. TLB-miss handler
		```nasm
			@ save state
			lw r1, <addr>
			@ if we should check validity of PTE
			mov r1, TLB
			@ restore state
		```
		4. make the constatnt case fast
			* speed up the TLB-miss by slowing down the PAGE FAULT
		5. HW can walk the page table
			* this requires the most cooperation ( HW completely dep. on OS )
			* also requres the simplest of page-table design
			* e.g. X86/ARM

* PA. RISC
	* inverted page table
		* entreis >= # physical pages in main memory
		* CRT( collision recitation table )

