Motivation
![[Pasted image 20230221125721.png]]

Multithreaded servers
![[Pasted image 20230221125351.png]]

Benefits
- Responsiveness – may allow continued execution if part of process is blocked, especially important for user interfaces
- Resource Sharing – threads share resources of process, easier than shared memory or message passing
- Economy – cheaper than process creation, thread switching lower overhead than context switching
- Scalability – process can take advantage of multiprocessor architectures

Multicore programming 
- divide activities
- Balance 
- data splitting
- data dependency
- testing and debugging 
- parallelism - implies a system can perform more than one task at the same time (needs more cores)
  - Data parallelism - distributes shared data to multiple cores
  - Task parallelism - distributes threads across cores so one core does not do all the work
- Concurrency - supports more than one task making progress at the same time - provided by a single processor / core
- As # of threads grows, so does architectural support for threading
- CPUs have cores as well as hardware threads
![[Pasted image 20230221130631.png]]
Single and multithreaded processes
![[Pasted image 20230221130924.png]]

Amdahl's law
- Identifies performance gains from adding additional cores to an application that has both serial and parallel components 
- S is the serial portion 
- N is # of cores
$$speedup \leq \frac{1}{S + \frac{(1-S)}{N}}$$
- Serial portion of an application has disproportionate effect on performance gained by adding additional cores
- Gustav's law - When scaling a program to e.g., use larger matrices the part of the program which is serial will be less of the computation compared to what can be parallelized 

User threads are threads created and used by the user while kernel threads are threads which the kernel has access to and uses for program execution, syscalls, etc...

Multithreading model 
- Many-to-one
  - Many user threads mapped to single kernel thread 
  - One thread blocks all threads block
  - many threads may not run in parallel on a multicore system - there may only be one core in kernel
  - Not that used (Solaris green threads, FNU portable threads)
  ![[Pasted image 20230221132410.png]]

- One-to-one
  - Each user-level thread maps to kernel thread
  - Creating a user-level thread creates a kernel thread
  - More concurrency than many-to-one
  - Number of threads per process sometimes restricted due to overhead
  - e.g., windows nt/xp/2000, linuxm Solaris 9 and later.
![[Pasted image 20230221132429.png]]

- Many-to-many
  - Allows many user level threads to be mapped to many kernel threads
  - Allows the operating system to create a sufficient number of kernel threads
  - e.g., Solaris prior to version 9, Windows NT/2000 with the ThreadFiber package
![[Pasted image 20230221132736.png]]

- Two-level model
  - Similar to M:M, except that it allows a user thread to be bound to kernel thread
  - E.g., IRIX, HP-UX, Tru64 UNIX, Solaris 8 and earlier.
![[Pasted image 20230221133042.png]]

Thread libraries / implementation of a specification
- Libraries for threading lives in either user-space  or has OS support in kernel space

Pthreads
- May be provided either as user or kernel level
- POSIX standard (IEEE 1003.1c) API for thread creation and synchronization
- Specification not an implementation
- API specific behaviour of the thread library implementation is up to development of the library 
- Common in UNIX OSes (Solaris, MAC OS X, Linux)
- Example slide 19-21

Java-Threads
- Managed by JVM
- Typically implemented with provided underlying OS threads
- May be created
  - Extending Thread class
  - Implementing runnable interface

Java multithreaded programs
- Thread pools
- Executioners 
- Completions services
- .parallel / .parallelStream

Implicit Threading
- Something that helps the user and takes responsibility for the correctness when using multithreading
- Creation and management of threads done by compilers and run-time libraries rather than programmers
- Some methods could include
  - Thread pools
  - fork-join
  - OpenMP
  - Grand Central Dispatch
  - Intel Threading Building Blocks (TBB)

Thread pools (example slide 29)
- A number of threads in a pool awaiting work
- advantages include:
  - Slightly faster to services a request - compared to having to also create the thread first
  - Allow for binding the number of threads in an application to the pool
  - Being able to separate tasks and run them periodically
  - Windows API (application programable interface) supports threads
``` java
DWORD WINAPI PoolFunction(AVOID param) {
/*
* this function runs a separate thread
*/
}
```

Fork-join
- Main thread has a task to do, parts of that task is forked by threads / tasks (Linux notation) and their result is then joined back into the main thread
![[Pasted image 20230221153818.png]]
- The ForkJoinTask is an abstract base class
- RecursiveTask and RecursiveAction classes extend ForkJoinTask
- RecursiveTask returns a result (via the return value from the compute() method)
- RecursiveAction does not return a result
![[Pasted image 20230221153950.png]]

OpenMP
- Is a set of compiler directives and an API for C, C++, and FORTAN
- Provides support for parallel programming in shared memory environments
- Identifies parallel regions - block of code that can run in parallel

Grand Central Dispatch
- Made by apple for MaxOS and IOS
- Extension to C, C++, Objective C, API and run-time library
- Allows identification of parallel sections
- Manages most details of threading
- A block is defined by "^{}"
- A block is placed in a dispatch queue and assigned to an available thread when removed from queue
- Dispatch queues
  - Serial - Blocks removed FIFO (First in first out) queue is per process called main queue - a program can create additional serial queues within the program
  - Concurrent - Block removed FIFO but several may be removed at once 
  - Four distinct queues system wide divide by quality of service
    - QOS_CLASS_USER_INTERACTIVE
    - QOS_CLASS_USER_INITITATED
    - QOS_CLASS_USER_UTILITY
    - QOS_CLASS_USER_BACKGROUND
- For the Swift language a task is defined as a closure like this "{}"
- closures submitted to the queue using dispatch_async() function

Intel Threading Building Blocks (TBB)
- Template library for designing parallel C++ programs
- Serial for loop
``` C++
for (int i = 0; i < n; i++) {
	apply(v[i]);
}
```
- TBB parallel_for statement
``` C
parallel_for (size_t(0), n, [=](size_t i) { apply(v[i]); });
```

Issues with threading
- Semantics of fork() and exec() system calls 
  - Fork() - duplicates all threads or just the calling thread
  - Exec() - Usually works as normal - replace the running process including all threads
  
- Signal handling - synchronous (forking tasks to children and waiting for their response) and asynchronous (forking tasks to children and continuing its own task while wating for their response)
  - Used to notify processes that a event has occurred
  - Used to process signals 
    - generated by event
    - delivered to the process
    - Signals are handled by either default or user-defined handler
    - Every signal has default handler run by kernel for handling signals 
      - User-defined can overwrite default
      - Single-threaded gets signal delivered to its process 
      - Multi-threaded gets signal delivered 

- Thread cancellation of target thread - Asynchronous (forking to child processes and doing its own thing while waiting for results) or deferred (wait with its execution to later)
  - Terminating a thread before it is done
  - Thread to be terminated target thread
  - Approach to thread termination
      - Asynchronous cancellation terminates the target thread immediately
      - Deferred cancellation allows the target thread to periodically check if it should be cancelled
- Thread cancellation requests cancellation but actual cancellation depends on thread state
- If thread has cancellation disabled, cancellation remains pending until thread enables it
- default type is deferred and cancellation only occurs when thread reaches cancellation point
- On Linux thread cancellation is handled via signals 


- Thread-local storage (TLS)
  - allows each thread to have its own copy of data
  - Useful for thread pools
  - Local variables visible only during single function invocation
  - TLS visible across function invocations
  - TLS is unique to each thread


- Schedular activations 
  - Both M:M and Two-level models require communication to maintain appropriate number of allocated kernel threads for specific application 
  - Typically use an intermediate data structure between user and kernel threads – lightweight process (LWP)
    - Appears to be a virtual processor on which process can schedule user thread to run
    - Each LWP attached to kernel thread
- Scheduler activations provide upcalls - a communication mechanism from the kernel to the upcall handler in the thread library
- This communication allows an application to maintain the correct number kernel threads

Operating system examples
- Windows thread
  - Windows implements the Windows API - for Win 98, Win NT, Win 2000, Win XP, and Win 7
  - Kernel level is one-to-one mapping
  - Thread structure
    - ID
    - Register for representing the state of the process
    - separate kernel and user stacks depending on which mode it is run in
    - private data storage area used by runtime libraries and dynamic link libraries
    - Theses are known as a threads context
- Primary data structure of a thread:
  - ETHREAD (executive thread block) – includes pointer to process to which thread belongs and to KTHREAD, in kernel space
  - KTHREAD (kernel thread block) – scheduling and synchronization info, kernel-mode stack, pointer to TEB, in kernel space
  - TEB (thread environment block) – thread id, user-mode stack, thread-local storage, in user space
  - For windows XP ETHREAD an KTHREAD are in kernel space and TEB is in user space

- Linux Thread
  - Linux refers to them as tasks rather than threads
  - Thread creation is done through clone() system call
  - clone() allows a child task to share the address space of the parent task (process)
  - Clone flags ![[Pasted image 20230221162843.png]]
  - struct task_struct points to process data structures (shared or unique)