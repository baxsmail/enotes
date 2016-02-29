1st Course  
========

### in the ARM

BIG Counter ( MSB and LSB )

### in Q7 cortex

one system-wide( CPU-wide ) counter

0x4000 0000 - control reg
0x4000 001c - clock.lo (  real trigers update of )
0x4000 0020 - clock.hi

### what's it goal

* system-wide concept of "now"
* can have monotonically increasing second granularity clock
* can have high-resolution event timeout

### Timers

* in particcular, countdown timer
	* load it value
	* throws an interrupt when reaching 0
	* automatically reloads itself when it reaches 0

* one-system-wide controller each cor can recv interrupts format
	* via IRG
	* via FIQ
	* (none)

### p1 suggestion

* 0x4000 0040, 0044, 0048, 004C  control regs
* 0x4000 0034 set to enable timer ( PUT32 ), enable interrupt and git it a reload value
* 0x4000 0030 set bit 31 to clear timer interrupt 
* 0x4000 0030 but bit 30 reload timer with intterupting, i.e. watchdog
* 0x4000 0024 tells you which one/s get interrupt

### timer usage

* watchdog : catch erronous processes
* context switching
* DRAM
* monitor/screen refresh
* wt a specific amount of time

### timeout Q

* unix callout table
	* periodic functions, where kernel re-insert the event when it time-out
	* more complex data ( usually malloced struct )
	* priority levels
	* multiple queues
* some graph and e.g. related to project 1
* good for ??




