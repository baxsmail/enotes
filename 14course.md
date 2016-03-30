### page table tricks
* pagetable location
	```c
	pagetable [ ( ASID * sizeof( table ) ) + VPN ];
	```
### some PTE intro.
* PTE
	| PFN | Status | valid bit | ( VPN ) |

### How to interact w/ the OS
* user's API to the HW
	you want this
* user code can make requests , e.g. to devices, facilities:
	* disk
	* network
	* caches
	* keyboard
	* monitor
* want OS protected from user

### options and solutions
1. function call `->` when OS is a library
	* advatages 
		* simple
		* fast
	* dis.
		* not secure
2. IPC-message-processing
	* advantages
		* kinda fast
		* totally secure
		* can be distributed across network
	* dis.
		* kinda slow
		* more complex
		* (most vital) send lots of msg. is impractical
3. trap( system call ) `->` SW caused an interrupt
	* essentially a context switch
	* data xmit via shared memmoy
	* advantages 
		* can "send" lots of data because not "sent"
		* fairly secure ( interrupt )
	* dis.
		* need to context siwth `->` slow and overhead
		* not quit as secure as msg-passing 

