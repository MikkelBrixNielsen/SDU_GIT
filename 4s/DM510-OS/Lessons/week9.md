![[Pasted image 20230228211203.png]]
- Operating systems
- Sorting and analysing data
- Video games - graphics / physics calcs
- networking (many clients -> one server)
- Multiple I/O

![[Pasted image 20230228211213.png]]
- speed-up = $\frac{1}{S+\frac{1-S}{N}}$
  - Where S = serial portion
  - Where N is processing cores
1->2 processors
$\frac{1}{0.4+\frac{(1-0.4)}{2}}=1.428571429$
1->4 processors
$\frac{1}{0.4+\frac{(1-0.4)}{4}}=1.818181818$

![[Pasted image 20230228211225.png]]
- if the request handler is the same for all the requests it will be data parallelism 
- if the request handler is different for each request it will be task parallelism

TASK: A set of independent tasks running in parallel 

DATA: Same code working on distributed data


![[Pasted image 20230228211234.png]]
User-threads are managed by user-level thread libraries (POSIX Pthreads, Win32 Threads ...) and kernel-threads are supported by the kernel.

Each kernel-thread has its own stack and kernel-level data structures, which can make them slower to create and manage. User-threads require fewer system resources to manage. However, user threads rely on a kernel thread to provide scheduling and execution on the CPU.

Kernel-threads are often better suited for tasks requiring access to low level system resources such as devices driver. User threads are typically better suited for applications that don't require direct access to system resources, such as user-level applications

Kernel-threads are also better suited for applications that require a high degree of parallelism and scalability. While user threads can be more efficient for applications with low to moderate concurrency requirements.

Kernel only knows about the kernel level threads
Kernel-level threads are associated with the execution of user-level threads 
user-level threads are mapped to a process which is to be executed


![[Pasted image 20230228211242.png]]
1. Save current kernel threads state, registers etc. to ensure it can continue execution when progress is resumed.
2. Select the next thread from the ready threads to run
3. The state of the next thread from its TCB is retrieved by OS and restores the registers.
- Does not need to switch PCB (process control block) if threads are working in the same process

![[Pasted image 20230228211257.png]]
- Since a thread is a part of a process the only additional resources used are allocation of a memory to a register set, stack, and priority.
- A process on the other hand needs a PCB (process control block), which includes memory mappings, list of open files, stack and heaps ...

![[Pasted image 20230228211307.png]]
It may be necessary it depends on the implementation of the OS if the OS schedular can provide sufficient priority and resources to the real time threads it may not be necessary but since real time threads have a strict time execution requirement it might be necessary.

![[Pasted image 20230228211317.png]]
Preventing UI lock up by doing concurrency having more threads lets processes waiting on I/O they can be switched out on another thread and wait there so that it does not lock up and the rest of the system just waits

![[Pasted image 20230228211329.png]]
- Heap memory since it contains things like arrays and shit which other threads might need to manipulate 
- Global variables since threads share variables amongst each other. (shared through process control block)

![[Pasted image 20230302102058.png]]
![[Pasted image 20230302102510.png]]

![[Pasted image 20230302102520.png]]

![[Pasted image 20230302102526.png]]

![[Pasted image 20230228211339.png]]
- Data, because there is a collection of photos for which the same task is executed
- data, each transposition of a row is doing the same thing
- Task, since 1 thread reads from network while other threads does other things
- data, since the summation of an array is a bunch of subtask doing the same thing on the same data
- Task, since a lot of different tasks are submitted and executed either in serial or parallel independent of each other. (GCDS -. central dispatch in MacOS for parallelising tasks)

![[Pasted image 20230228211345.png]]
``` java 
    pid t pid;
    pid = fork();
    if (pid == 0) { /* child process */
        fork();
        thread create( . . .);
    }
    fork();
```
![[Pasted image 20230228211408.png]]
parent + 2
-> child + 2 + thread create (-> forks)
     |-> child + 1 + thread create (-> forks) 
7 processes
2 threads

![[Pasted image 20230228211420.png]]
``` java
#include <pthread.h>
#include <stdio.h>
int value = 0;
void *runner(void *param); /* the thread */
int main(int argc, char *argv[])
{
    pid t pid;
    pthread t tid;
    pthread attr t attr;

    pid = fork();

    if (pid == 0) { /* child process */
        pthread attr init(&attr);
        pthread create(&tid,&attr,runner,NULL);
        pthread join(tid,NULL);
        printf("CHILD: value = %d",value); /* LINE C */
    } else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d",value); /* LINE P */
    }
}

void *runner(void *param) {
    value = 5;
    pthread exit(0);
}
```
pthread_join will wait for the created thread to terminate at which time the value of value is 5 and then line C will print "CHILD: value = 5" and since the parrent awaits the termination of the child process by calling wait(NULL) on line P the values of value will be 0 and therefor the parrent will print "PARENT: value = 0", since children do not share variables with their parent.

![[Pasted image 20230228211448.png]]
User level threads > number of processing cores

Kernel threads < processing cores:
- Performance will be hindered

Kernel threads = processing cores:
- Performance will be optimal
- Unless I/O is involved then waits would occur

Processing cores < Kernel threads < user threads
- Can result in reduced performance due to high context switching penalties
- But also not will not be penalized for having to wait for I/O since a new kernel threads can just be switched in