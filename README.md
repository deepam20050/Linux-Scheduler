# Linux Scheduler
 Modified the Linux kernel ([linux-5.14.3](https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.14.3.tar.xz)) in a way to 
1. Induce a user defined delay for a selected process every time this selected process is chosen by the linux scheduler
2. And, for processes with the same nice value as the above selected process log their timestamps when they are first selected by the linux scheduler and dispatched to run.

### To patch :
+ `patch -p1 -i deepam20050_patch.patch` then type the following in order
+ `linux-5.14.3/arch/x86/entry/syscalls/syscall_64.tbl`
+ `linux-5.14.3/include/linux/sched.h`
+ `linux-5.14.3/kernel/sched/core.c`
+ `linux-5.14.3/kernel/sched/fair.c`
+ `linux-5.14.3/kernel/sys.c`

### To log and view timestamps :
+ `test.c` contains source code for creating and testing two processes with the same nice value  
+ `make && ./test`
+ `sudo dmesg` for viewing logs

Full writeup [here](Writeup.pdf)

A cleaner patch file to view all changes made to the linux kernel source code is [clean_patch.patch](clean_patch.patch) 
  
*Written for an assignment in [CSE231 - Operating Systems](http://techtree.iiitd.edu.in/viewDescription/filename?=CSE231) course*
