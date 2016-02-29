3rd Course
=========


### p1 again

some insertion operation of the timeout queue;

some things about mem leakage and reliability;

### big picture

* user code
* kernel code

1. in exception situation
	when getting a exception int. 
	1. set a stack to save PC / PC+4
	2. save current state
	3. save mode
	4. change mode

2. in kerenel mode
	1. handle instructions
	2. return from exception

3. return from exception
	1. dont reuturn PC
	2. dont bother stack
	3. dont save mode
	4. jump to EPC( exception PC )
	5. do store previous mode

### we'r using mailbox interrupt
something about clean interrupt

### exception handler

* save any regs you'll step on
	push {reglist} `->` {r0-r12}

* clear the exception ( trap won't do this )
	clear interrupt()

* do the handler `<-` bl c-routine

* restore saved regs EXACTLY

* return from interrupt
```nasm
subs pc, lr, #4 
```

