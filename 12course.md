## Proj 6 and MIDTERM REVIEW 

### MIDTERM
* Midterm 
	* open questions, better to draw some graphs

* Topics
	1. IPC
	2. context switching
	3. contexts: processes, thread, fibres
	4. synchronization
	5. Virt. Mem.:w!
	6. interrupts, reentrance
	7. time + how to manage it ( less hardware )
	8. cache coherence
	9. multiprocessors
	10. toolchains, crosscompiling ( least importance )
* Should talk with hardware issue

### Proj 6

* Proj 6 lasts for 2 weeks

* details
	* c0
	* c1 
		* flash_led : GPIO 0x3f2xxxx
		* flash_led_diffio random like 0x02xxxxx
	* our task
		* turn on virtual memory 
		* map 0x02xxxxx to 0x3f2xxxx
	* e.g.
		* VA : | VPN | offset |
		* Page Table maintain a map from VPN to PFN
		* PA : | PFN | offset |
		* ARM can help to do this
			* give HW a pointer of a 2^12 table
			* last 2-bit trick
				* 0x00 : invalid
				* 0x01 : mapping to another page table
				* 0x10 : valid direct addr.
				* 0x11 : reserved, not implemented
		* your design
			* simply turning on the TLB and page translation
			* 0x000 cache & data
			* 0x002 blink 
				* goto 0x3f2 page
			* 0x400 timer clock
			* 0x3f2 GPIOs
