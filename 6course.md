6th Course  
=============

### Simultaneous Issue

```c
#define RECVSIZE (10*1024)
#define CHUNKSIZE 4096
void send( target B, char * buf, size_t total_tosend)
{
	do {
		write ( &buf, <data>, CHUNKSIZE );
		signal(B, "ready");
		wait(B, "done");
		total_tosend -= CHUNKSIZE ;
	}while( total_tosend > 0 );
}
char * recv(target A , size_t RECVSIZE)
{
	char * buf = malloc( RECVSIZE );
	size_t total_recev = 0;
	do {
		wait(A,"ready");
		read( &buf, CHUNKSIZE );
		total_recv += CHUNKSIZE;
	}while( total_recev < RECVSIZE );
	return buf;
}

```
### Virtual and Physical cache

* most co. today are using physical caches

### cache coherence

* makes all calles in system "brave"
* can stall machine
* power hungry

mainthing: cache coherence guarantees that if A writes the shared location,
B will see it `relatively` soon

* but what about the signal?
	* A writes location X ( local cache )
		* cache cocherence(CC) hardware `->` check if someone got a local copy,  or invalid my local copy 
	* B reads X ( Hardware is not reached )
		* CC hardware `->` evryone do you have a copy of X, if so write it back
	* B gets data X from mem.

### on top of cache coherence

* Sequential Consistency
	* Everybody in the system sees all Memory Accesses ( reads and writes ) in same order
* cannot buffer wirtes
* writes take effect after system RTT
* they are "related" consistency models ( Total Store Order )

### some pts

* only happens in core-to-core sharing ( with sparate caches )
* only happens because we choose to use shared memory for communication ( e.g. messaging = no problem )
* argues for a primirue for core-to-core IPC

* coherence in GPUs ( 1000s of cores )
	* many cores share one cache
	* only sharing allowed between local cores
	* must use the global space to go outside local core set


