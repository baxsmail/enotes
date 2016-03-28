After midterm
=============

## ASIDs
### how does VM tell difference between processes

1. 0x0000ABCD : phy 37
2. 0x0000ABCD : phy 5
3. 0x0000ABCD : phy 37

### solutions
* define not as a problem: SASOS ( Single Adress Space OS )
* brute force
	* flush the TLB on context switch
* use ASIDs ( address space identifiers )
	* use ASID and VPN together as key to look up
	* if you want lots of processes you ( the OS ) need to MAP PIDs to ASIDs and flush wherever appropriate

### how can virtual cache distinguish VAs from diff processes
* define not as a problem
* brute force flush cache on context switch
* use ASIDs

### cacche aliasing problem
* use physical page as a tag
* virtual indexed physical tagged


## hypervisory
### old days

| App | App | App | App | ... |
| --- | --- | --- | --- | --- |
| 		Operating System      | 
| 		Hardware System       | 

### nowadays: OS for OSs

| Win | XP  |Unix | OSx | ... |
| --- | --- | --- | --- | --- |
| 		Hypervisor            | 
| 		Hardware System       | 

### How

* Guest OSes must be run throught virtual memories
* protection between OSes : don't allow them to turn it iff/ modify it
	* full priviledge ( hyp )
	* full except one  thing ( sys )
	* Apps ( usr )

