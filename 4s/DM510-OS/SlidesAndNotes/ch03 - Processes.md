using "$shmget$" you can create shared memory - but a file is needed to act as a key for the different processes to access the shared memory

shared memory can be semaphores locks etc...

# Process Concepts 
- System must provide mechanisms for process creation and termination
- OS executes programs - runs in a process
- Process - Program in execution, sequential fashion
- Multiple parts
  - Program code - Text section
  - Current activity including program counter, processor registers
  - Stack contains temp data
    - function params, return addr. local var
- Data section contains global vars
- Heap contains dynamically allocated memory during run time
- Program - passive entity stored in executable file, process (program loaded into memory and run) is active
- One program can be several processes
  - multiple user executing the same program
![[Pasted image 20230223144154.png]]

# Process creation
 - Parent process create children, which can create other processes forming a tree of processes
 - Managed and identified via process identifiers (pid)
- Resource sharing options
  - Parent - child,  share all
  - Children share a subset of parents 
  - Parent - child, share nothing
- Execution options
  - Parent - child execute concurrently 
  - parent waits until children terminates
- Address space
  - Child duplicate of parent
  - Child has a program loaded into it
- UNIX examples
  - fork() system call creates new process
  - exec() system call used after a fork() to replace the process’ memory space with a new program

# Process termination 
- Some operating systems do not allow child to exists if its parent has terminated. If a process terminates, then all its children must also be terminated
  - cascading termination. All children, grandchildren, etc. are terminated
  - The termination is initiated by the operating system.
- The parent process may wait for termination of a child process by using the wait()system call. The call returns status information and the pid of the terminated process
- pid = wait(&status);
- If no parent waiting (did not invoke wait()) process is a zombie
- If parent terminated without invoking wait , process is an orphan

# Process state
- Under execution a program can be:
  - New: Process being created
  - Running: Instructions are being executed
  - Wating: Process waiting for some event
  - Ready: Process waiting to be assigned a processor
  - Terminated: Process has finished execution
![[Pasted image 20230223144448.png]]


# Process Control Block (PCB)
- Information associated with process - task control block
- Process state – running, waiting, etc.
- Program counter – location of instruction to next execute
- CPU registers – contents of all process-centric registers
- CPU scheduling information- priorities, scheduling queue pointers
- Memory-management information – memory allocated to the process
- Accounting information – CPU used, clock time elapsed since start, time limits
- I/O status information – I/O devices allocated to process, list of open files
![[Pasted image 20230223145101.png]]

# Context switch
- When CPU switches to another process, the system must save the state of the old process and load the saved state for the new process via a context switch
- Context of a process represented in the PCB
- Context-switch time is overhead; the system does no useful work while switching
  - The more complex the OS and the PCB è the longer the context switch
- Time dependent on hardware support
  - Some hardware provides multiple sets of registers per CPU $\rightarrow$ multiple contexts loaded at once
![[Pasted image 20230223145156.png]]

# Threads
- So far, process has a single thread of execution
- Consider having multiple program counters per process
  - Multiple locations can execute at once
    - Multiple threads of control -> threads
- Must then have storage for thread details, multiple program counters in PCB

# Process scheduling 
- Maximize CPU use
- Quickly switch processes onto CPU core
- Process schedular selects available process to execute on CPU Core as next process.
- Maintain scheduling queue
  - Ready queue – set of all processes residing in main memory, ready and waiting to execute
  - Wait queues – set of processes waiting for an event (i.e. I/O)
  - Processes migrate among the various queues

Queueing slides examples from page 15-17

# Mobile process importance hierarchy - Android 
- Often have to terminate processes to reclaim system resources (memory, CPU time, cores, etc.) - Most to least important:
  - Foreground process
  - Visible process
  - Service process
  - Background process
  - Empty process
- Terminates processes that are least important

# Multiprocessor Architecture - Chrome Browser
- Many web browsers ran as single process (some still do)
  - If one web site causes trouble, entire browser can hang or crash
- Google Chrome Browser is multi-process with 3 categories
- Browser process manages user interface, disk and network I/O
- Renderer process renders web pages, deals with HTML, JavaScript, new one for each website opened
  - Runs in sandbox restricting disk and network I/O, minimizing effect of security exploits
- Plug-in process for each type of plug-in

# Inter-process communication
- Processes within a system may be independent or cooperating
- Cooperating process can affect or be affected by other processes, including sharing data
- Reasons for cooperating processes:
  - information sharing
  - Computation speedup
  - Modularity
  - Cooperating processes need interprocess communication (IPC)
  - Two models of IPC
## Message passing (b)
  - Mechanism for processes to communicate and to synchronize their actions
  - Message system – processes communicate with each other without resorting to shared variables
  - IPC facility provides two operations:
    - send(message) – message size fixed or variable
    - receive(message)
- If P and Q wish to communicate, they need to:
  - establish a communication link between them
  - exchange messages via send/receive
- Implementation of communication link
  - physical (e.g., shared memory, hardware bus)
  - logical (e.g., direct or indirect, synchronous or asynchronous, automatic or explicit buffering)
- Implementation of communication link either physical, shared memory, hardware bus or network, or logical direct or indirect, synchronous or asynchronous, automatic or explicit buffering
### Shared memory (a)
  - An area of memory shared among the processes that wish to communicate
  - The communication is under the control of the users processes not the operating system.
  - Major issues is to provide mechanism that will allow the user processes to synchronize their actions when they access shared memory.
## Direct communication
- Processes must name each other explicitly:
  - send (P, message) – send a message to process P
  - receive(Q, message) – receive a message from process Q
- Properties of communication link
  - Links are established automatically
  - A link is associated with exactly one pair of communicating processes
  - Between each pair there exists exactly one link
  - The link may be unidirectional, but is usually bi-directional
## Indirect communication
- Operations
  - create a new mailbox
  - send and receive messages through mailbox
  - destroy a mailbox
- Primitives are defined as: 
  - send(A, message) – send a message to mailbox A 
  - receive(A, message) – receive a message from mailbox A
### Mailbox sharing
  - P1, P2, and P3 share mailbox A
  - P1, sends; P2 and P3 receive
  - Who get the message?
  - Solutions
    - Allow a link to be associated with at most two processes
    - Allow only one process at a time to execute a receive operation
    - Allow the system to select arbitrarily the receiver. Sender is notified who the receiver was

![[Pasted image 20230223154058.png]]

# Cooperating Processes
- Independent process cannot affect or be affected by the execution of another process 
- Cooperating process can affect or be affected by the execution of another process 
- Advantages of process cooperation
  - Information sharing
  - Computation speed-up
  - Modularity
  - Convenience

# Producer-Consumer Problem
- Paradigm for cooperating processes, producer process produces information that is consumed by a consumer process
- unbounded-buffer places no practical limit on the size of the buffer
- bounded-buffer assumes that there is a fixed buffer size

# Synchronization
- Message passing may be either blocking or non-blocking
- Blocking is considered synchronous
  - Blocking send has the sender block until the message is received
  - Blocking receive has the receiver block until a message is available
  - Non-blocking is considered asynchronous
    - Non-blocking send has the sender send the message and continue
    - Non-blocking receive has the receiver receive a valid message or null
- Different combinations possible
  - If both send and receive are blocking, we have a rendezvous
  - Producer-consumer becomes trivial
![[Pasted image 20230223160038.png]]

# Buffering 
- Queue of messages attached to the link; implemented in one of three ways 
  - 1. Zero capacity – 0 messages Sender must wait for receiver (rendezvous) 
-  2. Bounded capacity – finite length of n messages Sender must wait if link full 
- 3. Unbounded capacity – infinite length Sender never waits

# Examples of IPC (Inter Process Communication) Systems

## POSIX Shared Memory
  - Process first creates shared memory segment shm_fd = shm_open(name, O CREAT | O RDRW, 0666); ! 
  - Also used to open an existing segment to share it
  - Set the size of the object ftruncate(shm fd, 4096);
  - Now the process could write to the shared memory sprintf(shared memory, "Writing to shared memory");

## Mach communication is message based
- Even system calls are messages
  - Each task gets two mailboxes at creation - Kernel and Notify
  - Only three system calls needed for message transfer msg_send(), msg_receive(), msg_rpc()
  - Mailboxes needed for commuication, created via port_allocate()
  - Send and receive are flexible, for example four options if mailbox full:
    - Wait indefinitely
    - Wait at most n milliseconds
    - Return immediately
    - Temporarily cache a message

## Windows
- Message-passing centric via advanced local procedure call (ALPC) facility
  - Only works between processes on the same system
  - Uses ports (like mailboxes) to establish and maintain communication channels
  - Communication works as follows:
    - The client opens a handle to the subsystem’s connection port object.
    - The client sends a connection request.
    - The server creates two private communication ports and returns the handle to one of them to the client
    - The client and server use the corresponding port handle to send messages or callbacks and to listen for replies.

# Communications in Client-Server Systems

## Socket 
- Defined as endpoint for communication
- Concatenation of IP addr. and port number (differentiates network service on host)
- The socket 161.25.19.8:1625 refers to port 1625 on host 161.25.19.8
- Communications is between pairs of sockets
- port < 1024 are "well known" / used for standard services
- Special IP addresses 127.0.0.1 local host

### Java
- Three socket types
- Connection-oriented (TCP)
- connection-less (UDP)
- MulticastSocket class-data can be sent to multiple recipients 

## Remote procedure calls (RPC)
- Remote procedure call (RPC) abstracts procedure calls between processes on networked systems
  - uses port for service differentiation
- Stubs – client-side proxy for the actual procedure on the server
- The client-side stub locates the server and marshalls the parameters
- The server-side stub receives this message, unpacks the marshalled parameters, and performs the procedure on the server
- On Windows, stub code compile from specification written in Microsoft Interface Definition Language (MIDL)
- Data representation handled via External Data Representation (XDL) format to account for different architectures
  - Big-endian and little-endian
- Remote communication has more failure scenarios than local
  - Messages can be delivered exactly once rather than at most once
- OS typically provides a rendezvous (or matchmaker) service to connect client and server

## Pipes
- "conduit" allowing two processes to communicate
### Ordinary pipes
- Allow communication in standard producer-consumer style
- Producer write to one end (write end)
- Consumer reads from the other end (read end)
- Unidirectional
- Require parent-child relationship between communicating processes
![[Pasted image 20230223162234.png]]
- called anonymous pipes

### Named pipes
- Named Pipes are more powerful than ordinary pipes
- Communication is bidirectional
- No parent-child relationship is necessary between the communicating processes
- Several processes can use the named pipe for communication
- Provided on both UNIX and Windows systems

# Port mapper
- A port mapper is a service that runs on a networked device and helps to map the different network services and applications to the ports on which they run. The port mapper works by maintaining a database of the port numbers that are currently in use and the corresponding services or applications that are associated with each port.

- When a client initiates a connection with a server, the client typically specifies the port number on which it expects the server to be listening for incoming connections. The port mapper then checks its database to find the service or application associated with that port number, and forwards the client's request to the appropriate server process.

- In addition to mapping port numbers to services or applications, port mappers can also perform other functions such as translating network addresses, managing network security policies, and providing load balancing and failover capabilities. Overall, the port mapper plays an important role in facilitating communication between networked devices and ensuring that data is delivered to the correct destination. 

# process handles
- C read or write to a pipe
- Parent child both have a handler they are supposed to close
- The handler is their way of communicating with and sending things through a pipe

- A process handle is a reference to a running process in an operating system. When a program runs on a computer, it is loaded into memory and executed as a process. A process handle is used by the operating system to keep track of and manage the resources associated with a specific process.

- A process handle typically contains information such as the process identifier (PID), which is a unique identifier assigned to each process by the operating system, and a set of resources that the process has access to, such as memory, files, and network connections.

- Programs can use process handles to perform various operations on a running process, such as monitoring its performance, sending it signals or commands, and retrieving information about its state. For example, a program might use a process handle to obtain the amount of CPU time that a particular process has used, or to terminate a misbehaving process.

- Process handles are an important part of the operating system's process management system, which is responsible for scheduling and controlling the execution of processes on the computer.