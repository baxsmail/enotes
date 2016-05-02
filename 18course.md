## BFS

### "buffer pool" 

* block ID `->` Hash `->` buf_hash_table

* each entry is under following few list :
	* locked
	* LRU
	* AGE
	* free

* locked, LRU, AGE
	* ordered lists
	* locked holds things that should never be thrown away ( e.g. copy of the super block )
	* LRU holds blocks in a time-ordered first
		* when block accessed, moved to the load of the list
		* periodically more bottom entries to AGE
	* AGE holds things that
		* things moved from LRU
		* things speculatively protected

### log structured file systems

#### main problems

( I miss this part, will borrow others notes )

#### do you use it today not on spining disks, why not?
* garbage collection gets in the way
* observed up to 40% degradation
* worst case : filesystem X% full, every segment X% full
	* produce one clean segment requires
		* collect data from N= floor( 1/ (1-\lambda) ) segments
		* write out the data to N-1 of those segments

### intro to flash

* flash doesn't let you overwrite data
* flash does best in large blocks (R/W)
* flash requires garbage collection
* flash needs wea leveling + LFS prossvides
