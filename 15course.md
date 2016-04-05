## Recap 

### syscall
* put # into register
* put args into regs. and into your struct
* call trap instruction
* in handler: 
	```cpp
	call syscalls[#](args);
	```

### when you open something
inside OS : hey-something, do an initilization sequence
* so the something does what's neccessary to set up base access
* ( basically there's an object for everything xxxx of being open()-ed )

### The OS keeps that object associated by the 'something'
By putting it into an array ( per process )
* fd[ num_open_descriptors ++ ] ;
* return usercode;
