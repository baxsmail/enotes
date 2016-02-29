### inter processor communication

SIG_DF()
SIG_IGN()
SIGNAL()


kernel -> signal ->
```c
struct user_interrupt_state()
{
	interrupt_state;
	user stack;
	user esp;
	// selector
	// currently stack seg. = data seg. for each process
}

```

only worry 4 signals:

SIGKILL()
SIGUSR1
SIGUSR2
SIGALARM

mainly implement
	* Sys_SIGNAL()
	* Sys_REGDELIVER()
	* Sys_Kill()
	* Sys_RETURNSIGNAL()
	* Sys_ALARM()

SIGKILL()
	call terminate
SIGIGN()

pending signal
handle signal

interrupt related issue: int.h

Kill()
	interminated from itself

STR

difference between syskill this time
this:
	this kernel thread send that process a signal,
	that process killed itself and exit
	

CS - Kernel_CS ( current_state ? not sure )

