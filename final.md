## final examples
1. virtual memory 
	* OS structures
		* hierachy architecture
		* physical cache vs. virtual cace
			* same page pointed by two different virtual address, called aliasing
			* page coloring : OS assign blocks for certain coloring ( coloring 0 goes to 0,2,4,6, and 1 can only go to odd blocks )
	* interaction with various cache types
		* virtual cache, physical tagged
2. file systems
	* BSD
	* log structures
		* in memory, you keep a map in memory ( and write it in disc in case bad things happen )
	* FLash filesystems
	* caching in FFS
		* block # as a key, and a hash table
			| LRU | AGE | Lock |
			|-----|-----|------|
			|node |node | node |
			|node |node | node |
			|node |node | node |
			|empty|node | empty|
			| ... | ... | ...  |

3. System calls
4. Hypervisor
5. Disk / Flash physical stuff

## Questions

