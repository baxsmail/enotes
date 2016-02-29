4th Course  
========

### Reentrance

* why it is called a "vector table"?

* we have these codes:
	* trap
	* kernel
	* invalid opcode
	* page fault
	* pxxxx violation

* interrupt 
	means by which code is executed

* vector 
	response to that

### goal

```c
while(1)
{
	/* for each priority level
	 * * check to see : foungding arrived fore me
	 * * check to see if anythin timedout
	 * * if yes start again
	 */
}
```

* trap handler
	* determine type
	* insert into messgage queue
* I/O int. handler
	* determine I/O dvice, init data struct
	* insert into messgage queue
* init process communication
	* init a lot of thing


### Reentrance again

property of being able to tolerate multiple invocations of a piece of cake 
at my queue time, HOW TO ---

1. DON'T SHARE DATA
	* use stacks
2. wrap the accesses to shared data in LOCKS, like
	* lock_acquire( ... )
		* disable interrupt
		* either grant lock to register or put him in a queue
		* enable interrupt
	* lock_release( ... )
		* disable  interrupt
		* if queue nonempty, grant lock to next ( something ), otherwiese FREE
		* enalbe interrupt
	```c
	lock_acquire( msgq );
	__modify( msgq, ... );
	lock_release( msgq );
	```

* Solution for MultiProcessor, ATOMIC TEST SET
	relies on cache coherence
3. don't use interrupt
	```c
		while(1)
		{
			// previous
				// check
		}
	```
	* upside
		* far far far simply code
		* far far far fewer bugs
	* downside 
		* responsiveness
		* you have to carefully tailor and tune your code
		* have to think like a state machine
			* send msg
			* wait for response
			* handle response
		* you don't get to use interrupt

### How to make stuff faster

* speed up the clock
* make more of them
* figure out how to get more parallelism
* rewrite your software 
* get a better memory system

### what's interrupt good for

* emulate in SW instructions, not supported in HW
* schedule context switch 
* handle VM, pagefaults
* pass certain int. to user code
* have watchdog st. a sync. error recovery
* multitask between HW devices
* set periodic BACKGROUND tasks
	* admin
	* data movement
	* performance conters

### egs.

goto sleep wake me up iff.

* something happens
* something timedout
* something arrives
* etc.
