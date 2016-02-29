2nd Course
========

### submission a homework

email professor and cc TA with a name ENEE447Projxxx

### Interrrupts

when signal comes in, something happens, HW does i

* Intterrupt type ( 0 to 7 in ARM )
	* trap(SW)
	* external I/O
	* TLB Miss
	* Put Variable
	* Bad address
	* Bad oprole
	* divide byy zero
	* etc

* Save user PC ( or PC+4 ) value  `->` puts it/them intto r14(lr) 
* save some state ( user/kernel ) `->` ARM saes CPSE/SPSR 
* turn on new mode ( u/k ) `->` ARM: 0 to 7 
* jump to int. handler `->` PC  # `<<` 2 

### What doees SW do

* saves state( esp r14, r13 )
* handle interrupt
* handle interrupt
* restore state
* return from interrupt

```nasm
	sub 
	( I missed some codes here )
```


### Registers in the ARM


| mode   | sys/usr | IRQ | FIQ |
| ------ | ------- | --- | --- |
| ris    | linkr   | LR  | LR  |
| sp=r15 | stackp  | sp  | sp  |
| ...... | ......  | ..  | ..  |

### stacks on the ARM

reference to ` STACKS on the ARM ` paper

```cpp

int * callefunc1( int *a, int *b, int *c, int *d, int *e, ... )
{

	// return a; 
	// mov r0, r1

	// return b;
	// mov r0, r1

	// return e;
	// ldr r0, [sp]

	return f;
	// ldr r0, [sp, #4]

	// assembly bx lr
}

```



