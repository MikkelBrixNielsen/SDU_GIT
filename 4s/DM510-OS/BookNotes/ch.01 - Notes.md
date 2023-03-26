OS  
Software that manages a computer’s hardware and provides a basis for application programs and acts as an intermediary between the computer user and the computer hardware. It is very versatile and can accomplish a wide variety of tasks in various environments like toasters, cars, ships, spacecraft, homes, and businesses, etc… Including Internet of Things devices (IOT) like phones computers (personal and enterprise) and cloud computing environments. A fundamental responsibility of the OS is to allocate resources to the CPU, memory, I/O devices, and storage. Due to the large size and complexity of an operating system, it is created in pieces. Each which should be a well-delineated portion of the system, with carefully defined inputs, outputs, and functions.

## User View

Most users view of a **computer** consist of either a laptop or desktop with a **monitor**, **mouse** and **keyboard** attached to it. Such a system is designed for **one user** to **monopolize** all the **system resources** to **maximize work** (or play) with some **attention** paid to **performance** and **security** and **not** much to **resource utilization**.

Abstract view of components would be user <-> Application programs <-> OS <-> hardware

For many **smartphones or tablets are replacing desktops or laptops** for many users. Theses devices **typically use cellular or other wireless technologies**. The interface is **no longer mouse and keyboard** **but touch input and voice controls**.

Some computers like the **embedded computers** found in home appliances or cars **have little to no user view** since they are **designed to run** largely **without** any user **intervention**. They **might** still **have LED indicators**, which show the status of the device **or** maybe **a numpad** for input

## System view

From the computers points of view the **OS** is the most **intimately involved with the hardware**, as such **the OS** can be viewed as a **resource allocator** that **manages CPU time, memory space, storage space, I/O devices** etc… These devices can create **conflicting requests** which the **OS manages** and properly allocate resource **to ensure fair and efficient operation**. A **different view** could be that the **OS is a control program** which **manages the execution of user programs** to prevent errors and improper use of the computer **especially regarding I/O devices**.

  

## Defining Operating systems

Since OSes were born, they have evolved rapidly and now have many roles and function due to being present in toasters, cars, ships, spacecraft, homes, and businesses and are the basis for game machines, cable TV tuners, and industrial control systems, or military use for code breaking, trajectory plotting and governmental uses (census calculations).

Moore’s law doubling of transistors every 18 months has held true.

No completely adequate definition of what an OS is. They exist to offer a reasonable way to solve the problem of creating a usable computing system, which general goal is to execute programs and make user problems easier. Bare hardware is difficult to use so the OS is there as an interface for the user along with providing common operations like control over I/O devices for different programs. The common functions of controlling and allocating resources are then brought together into one piece of software namely the OS. (No universal definition for what is part of the OS)

One definition is that it includes everything a vendor ships  
Other more commons is that it is a program running always called the kernel

Along with the kernel, there are two other types of programs: system programs, which are associated with the operating system but are not necessarily part of the kernel, and application programs, which include all programs not associated with the operation of the system.

The matter of what constitutes an operating system became increasingly important as personal computers became more widespread and sophisticated. In 1998 US Department of justice filed a suit against Microsoft for including a web browser in their OS and were found guilty for limiting competition. Today OSes for mobile devices include not just the kernel but also middleware to provide additional features to application developers. Database, multimedia, graphics etc…

The OS includes the alwaysrunning kernel, middleware frameworks that ease application development and provide features, and system programs that aid in managing the system while it is running

## Computer-System Organization

The computer’s CPU(s) controls connected devices through a bus, which provide access between components and shared memory. Each device controller oversees a specific type of device depending on the controller, more than one device may be attached. A device controller maintains some local buffer storage and a set of special-purpose registers. The device controller is responsible for moving the data between the peripheral devices that it controls and its local buffer storage.

An OS typically has a device driver for each device controller. The device driver understands the device controller and provide a uniform interface to the device for the OS. The CPU and device controller can compete for memory cycles. To ensure orderly memory access a memory controller synchronizes access to the memory.

  

## Interrupts

Interrupts are used to notify the OS when e.g., a program performing I/O has completed its task. This could be the device controller leading a read from keyboard instruction, then it transfers the data to its local buffer. Then the device driver is informed that the data transfer is finished. The device driver then gives control along with potential data or a pointer to the data back to other parts of the OS via an interrupt.

### Overview

Hardware can trigger interrupts at any time by sending a signal to the CPU usually through the system bus (there are other buses), which is the main communication bus between major components. Interrupts re used for many other purposes as well and are a key part of how OSes and hardware interact.

When The CPU ins interrupted it stops what it is doing immediately transfers execution to a fixed location usually containing the starting address where the service routine for the interrupt is located. This executes and the CPU continues its interrupted computation.

There a many different interrupt mechanisms but several functions are common. The interrupt must transfer control to the appropriate interrupt service routine (generic routing to examine interrupt information) which calls the interrupt specific handler. Interrupts must be handled quickly since they are frequent. Instead of examining a table of pointers to interrupt routines can be used to improve speed. Called directly though the table no intermediate routine needed. Table stored in low memory (first 100 or so location). these locations hold the addresses of the interrupt service routines for the various devices. This array (interrupt vector) of addresses is then indexed by a unique number given with the interrupt request to provide the address of the interrupt service routine for the interrupting device. (Windows and Unix does it this way)

Interrupt architecture must also save the state information of whatever was interrupted so that it can restore this information after servicing the interrupt. After the interrupt is performed the saved return address is loaded into the program counter and the interrupted computation resumes.

### Implementation

The Device controller raises an interrupt by asserting a signal on the interrupt request line, the CPU catches the interrupt and dispatches it to the interrupt handler, and the handler clears the interrupt by servicing the device

The CPU hardware has a wire called the interrupt-request line that the CPU senses after executing every instruction. When the CPU detects that a controller has asserted a signal on the interrupt-request line, it reads the interrupt number and jumps to the interrupt-handler routine by using that interrupt number as an index into the interrupt vector. It then starts execution at the address associated with that index. The interrupt handler saves any state it will be changing during its operation, determines the cause of the interrupt, performs the necessary processing, performs a state restore, and executes a return from interrupt instruction to return the CPU to the execution state prior to the interrupt.

  

This enable the CPU to respond to an asynchronous event as when a device controller becomes ready for service in a modern OS more sophisticated interrupt-handling is required:

1. We need the ability to defer interrupt handling during critical processing.  
2. We need an efficient way to dispatch to the proper interrupt handler for a device.  
3. We need multilevel interrupts, so that the operating system can distinguish between high- and low-priority interrupts and can respond with the appropriate degree of urgency.

In modern OS this is handled by the CPU and the interrupt-controller hardware.

Most PCUs have two interrupt request lines. One is the non-maskable interrupt which is reserved for events such as unrecoverable memory errors. The second interrupt line is maskable. It can be turned off by the CPI before the execution of critical instruction sequences that must not be interrupted. This line is used by device controllers to request services.

Since there are more devices than addresses in the allocated memory the interrupt vector can’t hold all interrupt handlers  for all devices this is solved by interrupt chaining in which each element in the interrupt vector points to the head of a list of interrupt handlers. When the interrupt is raised the handlers on the corresponding list are called one by one until one is found that service the request this structure is a compromise between the overhead of a huge interrupt table and the inefficiency of dispatching to a single interrupt handler.

The events from 0 to 31, which are non-maskable, are used to signal various error conditions. The events from 32 to 255, which are maskable, are used for purposes such as device-generated interrupts.

There is also interrupt priority levels which enables the CPU to defer the handling of low priority interrupts without masking all interrupts and make it possible for a high priority interrupt to pre-empt the execution of a low priority interrupt

In summary, interrupts are used throughout modern operating systems to handle asynchronous events (and for other purposes we will discuss throughout the text). Device controllers and hardware faults raise interrupts. To enable the most urgent work to be done first, modern computers use a system of interrupt priorities. Because interrupts are used so heavily for time-sensitive processing, efficient interrupt handling is required for good system performance.

## Storage structure

The CPU can only load instruction from memory so any program must first be loaded into memory to run. In regards to most computers this memory is referred to as main memory and is rewriteable or RAM (random access memory) and is commonly implemented in semiconductor technology called dynamic random-access memory (DRAM). RAM is volatile, loses its contents when no power, so the program needed to launch the OS called the bootstrap program needs to be stores some other place. Here Electrically erasable programmable read-only memory (EEPROM) is used to store it and other firmware that is infrequently written to and is non-volatile. EEPROM is slow cannot be changed frequently contains mostly static programs and data that aren’t frequently used. (Serial numbers or hardware information.

The load instruction moves a byte or word from main memory to an internal register within the CPU, whereas the store instruction moves the content of a register to main memory. Aside from explicit loads and stores, the CPU automatically loads instructions from main memory for execution from the location stored in the program counter.

A typical instruction–execution cycle, as executed on a system with a von Neumann architecture, first fetches an instruction from memory and stores that instruction in the instruction register. The instruction is then decoded and may cause operands to be fetched from memory and stored in some internal register. After the instruction on the operands has been executed, the result may be stored back in memory.

The memory unit sees only a stream of memory addresses not how they are generated, what generated them or what they are. Only interested in the sequence of memory addresses generated by the running program.

Ideally all program and data would always be in main memory, but this is not possible on most systems for two reasons:

1. Main memory is usually too small to store all needed programs and data permanently.  
2. Main memory, as mentioned, is volatile—it loses its contents when power is turned off or otherwise lost.

Thus, secondary storage is provided as an extension of main memory. This should be able to hold large quantities of data permanently.

The most common secondary storage devices are HDD and NVM devices. Other storage device include:

![Diagram
Description automatically generated](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image002.png)

The top four uses semiconductor technology which consists of semiconductor-based electronic circuits. NVM devices, at the fourth level, have several variants but in general are faster than hard disks. The most common form of NVM device is flash memory, which is popular in mobile devices such as smartphones and tablets. Increasingly, flash memory is being used for long-term storage on laptops, desktops, and servers as well

Volatile storage -> memory, non-volatile storage NVA (either mechanical or electrical (NVM – Flash, FRAM, NRAM, SSD))

## I/O structures

Large portion of OS code dedicated to managing I/O devices due to importance of reliability and performance as well as the varying nature of the devices.

To solve the problem of bulk data movement in interrupt driven I/O direct memory access (DMA) is used. After setting up buffers, pointers, and counters for the I/O device, the device controller transfers an entire block of data directly to or from the device and main memory, with no intervention by the CPU. Only generating 1 interrupt per block at completion. CPU is free to do other work while device driver does these operations.

Some high-end systems use switch rather than bus architecture. On these systems, multiple components can talk to other components concurrently, rather than competing for cycles on a shared bus. In this case, DMA is even more effective.

## Computer system architecture

The core of the CPU is the component that executes instructions and registers for storing data locally. This core is capable of executing a general-purpose instruction set including instructions from processes. There might also be device specific processors. (Disk, keyboard, graphics controller)

Special purpose processors run a limited instruction set and do not run processes. They can be managed by the OS, which sends them information regarding their next tasks and monitors their status.

E.g., A disk-controller microprocessor receives a sequence of requests from the main CPU core and implements its own disk queue and scheduling algorithm. This arrangement relieves the main CPU of the overhead of disk scheduling. PCs contain a microprocessor in the keyboard to convert the keystrokes into codes to be sent to the CPU.

In other systems or circumstances, special-purpose processors are low-level components built into the hardware. The operating system cannot communicate with these processors; they do their jobs autonomously.

SPECIAL PURPOSE PROCESSORS DO NOT TURN A PC INTO A MULTICORE MACHINE.

## Multiprocessor systems

![Diagram
Description automatically generated](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image004.png)They dominate the landscape of computing. Traditionally multiple processors with a single core CPU. Processors share the computer bus and sometime the clock, memory, and peripheral devices. Their advantages is increased throughput. The speed up ration is not linear since some overhead to ensure all parts are running correctly is generated as well as contention for shared resources.

Most common is symmetric multiprocessing (SMP) each peer CPU processor performs all task including OS functions and user processes.

Dynamically shared memory ensures that no CPU sits idly while the other is overloaded. Such as system must be written very carefully.

![Diagram
Description automatically generated](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image006.png)Multiprocessors systems have evolved to include multicore system where a single CPU has multiples cores. Theses systems can be more efficient since internal CPU communications is faster than between two chips. And they use significantly less power, which is important for mobile devices and laptops.

![Text
Description automatically generated](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image008.png)

Virtually all modern operating systems (Windows, macOS, Linux, Android, IOS) support SMP systems.

Adding multiple CPUs or multiprocessor systems will increase computing power and contention for shared resources and does therefore not scale very well. To circumvent this is to provide each CPU or group of CPUs with its own local memory accessible via a small fast local bus and connect the CPUs via a shared system interconnect so all CPUs share on physical address space (non-uniform memory access (NUMA)).

NUMA yields:  
- Fast local memory with no contention  
- Increased latency when accessing remote memory

Blade servers are systems in which multiple processor boards, I/O boards, and networking boards are placed in the same chassis. The difference between these and traditional multiprocessor systems is that each bladeprocessor board boots independently and runs its own operating system. Some blade-server boards are multiprocessor as well, which blurs the lines between types of computers. In essence, these servers consist of multiple independent multiprocessor systems.

## Clustered systems

Also, multiprocessors system which is comprised of two or more individual system (or nodes) joined together each node is typically a multicore system. (Loosely coupled). And used to provide high-availability service – will continue if one or more systems in the cluster fails – redundancy through a monitoring machine which can take ownership over a failed nodes memory an continue its processes yielding increased reliability this is known as graceful degradation, some systems go beyond this is called fault tolerant – can suffer failure of any single component and continue operation.

Asymmetric clustering has one machine in hot standby mode (nothing but monitoring), while the others run applications. If one were to fail the machine in hot standby mode becomes active.

Symmetric clustering two or more hosts are running applications and are monitoring each other. This structure is obviously more efficient, as it uses all the available hardware. However, it does require that more than one application be available to run.

Since a cluster consists of several computer systems connected via a network, clusters can also be used to provide high-performance computing environments and supply significantly greater computational power than single-processor or even SMP systems because they can run an application concurrently on all computers in the cluster. Application must have been written to take advantage of this, which is called parallelization – dividing a program into separate components which run in parallel on individual cores alle the node combines the individual result into a final solution.

Other forms of clusters include parallel clusters and clustering over a wide-area network (WAN) Parallel clusters allow multiple hosts to access the same data on shared storage. Because most operating systems lack support for simultaneous data access by multiple hosts, parallel clusters usually require the use of special versions of software and special releases of applications.

Distributed lock manager (DLM) software that tracks access to the shared disk. Each machine has full access to all data in the database. To provide this shared access, the system must also supply access control and locking to ensure that no conflicting operations occur.

storage-area networks (SANs) allow many systems to attach to a pool of storage. If the applications and their data are stored on the SAN, then the cluster software can assign the application to run on any host that is attached to the SAN if a host fails any other can take over.

Clustered has no concrete definition many wrestles to define it. But the generally accepted definition is that clustered computers share storage and are closely linked via a local-area network LAN.

  

## Operating system operations

An operating system provides the environment within which programs are executed. Internally, operating systems vary greatly, since they are organized along many different lines. There are, however, many commonalities, which we consider in this section.

For OS to run computer needs simple bootstrap program typically stored within the hardware in firmware and initializes all aspects of the system from CPU registers to device controllers to memory contents. The bootstrap program must know how to load the OS and how to start executing the system. Load OS kernel into memory. Once the kernel is loaded it can start to provide services to the system and its users.

Some services are provided outside of the kernel by system programs that are loaded into memory at boot time to become system daemons, which run the entire time the kernel is running. On Linux the first program is “systemd”, which starts many other daemons.

If an OS has nothing to respond to it will sit quietly and wait for something to happen. Event almost always signaled by an interrupt. Other interrupts can be traps – exceptions – signal system errors division by zero invalid memory access, specific user request via a system call etc…

## Multiprogramming and multitasking

Important aspect of OS is to run multiple programs as a single program can hardly keep the CPU or I/O devices busy at all times. Users typically want more programs to run at the same time anyway. Multiprogramming increases CPU utilization as well as keeping users satisfied by organizing programs so that the CPU always has one to execute. A program in execution is a process.

Multiple programs are stored in memory when a process has to wait for I/O in a non-multiprogram machine the CPU will sit idly until i/O response but on a multiprogram machine the CPU will switch to another process until the other process is done

Multitasking is a logical extension of multiprogramming. In multitasking systems, the CPU executes multiple processes by switching among them, but the switches occur frequently, providing the user with a fast response time.

Most processes will not operate long before they need e.g. to wait for I/O and if that is user input that is limited to the users typing speed which is incredibly slow for a computer. Rather than wait for that the OS switches the CPU to another process. If several processes are running at the same time CPU scheduling is needed to decide which process is to run next. Finally, running multiple processes concurrently requires that their ability to affect one another be limited in all phases of the operating system, including process scheduling, disk storage, and memory management.

OS most ensure reasonable response time in multitasking systems. Here virtual memory, a technique that allows the execution of a process that is not completely in memory – enable user to run programs larger than physical memory. Abstract main memory into large uniform array of storage sperating logical memory (user) from physical memory (system) removes convers from memory storage limitations.

The system must provide a filesystem. The file system resides on a secondary storage; hence, storage management must be provided. In addition, a system must protect resources from inappropriate use. To ensure orderly execution, the system must also provide mechanisms for process synchronization and communication, and it may ensure that processes do not get stuck in a deadlock, forever waiting for one another.

## Dual mode and multimode operation

To not allow malicious or incorrect code to be executed, which hinder other programs there is a distinguish between user code and OS code. This is done by providing hardware support that allows differentiation between various execution modes. (User mode and kernel mode (supervisor mode, system mode, privileged mode)) This is kept track of by a mode bit. Kernel mode is 0 and user mode is 1. When the user ask the system to make a system call it must transition from user mode to kernel mode.

![Diagram
Description automatically generated](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image010.png)

Under boot the system is in kernel mode when an interrupt happens, and the controls are handed to the user the OS always first puts the system in user mode. Dual mode operation gives protection to the OS form errant users and errant user from one another. This is done by having some instruction be privileged instruction, which if executed in user mode is treated as illegal and hardware does not execute them. These instructions can only be executed in kernel mode. The instruction to switch to kernel mode is an example of a privileged instruction. Some other examples include I/O control, timer management, and interrupt management. Many additional privileged instructions are discussed throughout the text.

There can also be more than just two modes intel has 4 where ring 0 is kernel mode and ring 3 is user mode. (Although rings 1 and 2 could be used for various operating-system services, in practice they are rarely used.) ARMv8 systems have seven modes and machines supporting virtualization often has a separate mode to indicate when the virtual machine manager (VMM) is in control of the system. VMM has fewer privileges than the kernel but more than the user.

System calls provide the means for a user program to ask the operating system to perform tasks reserved for the operating system on the user program’s behalf, and usually takes the form of a trap to a specific location in the interrupt vector. This trap can be executed by a generic trap instruction, although some systems have a specific syscall instruction to invoke a system call.

Hardware sees it as a software interrupt. Control passes through the interrupt vector to the service routine in the operating system and the mode bit is set to kernel mode. The interrupt is examined and the appropriate syscall is executed the kernel verifies extra parameters, variable etc. and ensure that they are correct and legal before executing the request and returning control to the instruction following the systemcall.

With hardware protection in place errors violating modes are handled by the OS (illegal instructions) Hardware traps to the OS, transfers control through interrupt vector to OS. OS terminates program abnormally, error message given and program may be dumpe, memory dumped to file for correction

## Timer

To make sure a program does not infinite loop or fails to give control back to the OS a timer is implemented. A timer can be set to interrupt the computer after a specified period. The period may be fixed or variable. A variable timer is generally implemented by a fixed-rate clock and a counter. The operating system sets the counter. The clock ticks a decrement the counter when the counter reaches 0 an interrupt occurs. After a interrupt caused by the timer the OS may interpret it as a fatal error or give the program more time. Instruction that modifies the content of the timer are privileged.

## Resource managment

The operating system is responsible for the following activities in connection with process management: • Creating and deleting both user and system processes • Scheduling processes and threads on the CPUs • Suspending and resuming processes • Providing mechanisms for process synchronization • Providing mechanisms for process communication

## Memory managment

The CPU reads instructions from main memory during the instruction-fetch cycle and both reads and writes data from main memory during the data-fetch cycle (on a von Neumann architecture)

The operating system is responsible for the following activities in connection with memory management: • Keeping track of which parts of memory are currently being used and which process is using them • Allocating and deallocating memory space as needed • Deciding which processes (or parts of processes) and data to move into and out of memory

## program execution in regards to memory

For a program to be executed, it must be mapped to absolute addresses and loaded into memory. As the program executes, it accesses program instructions and data from memory by generating these absolute addresses. Eventually, the program terminates, its memory space is declared available, and the next program can be loaded and executed.

several programs need to be in the memory at one time for user convinience - memory manager is nedded

## File managment

The operating system is responsible for the following activities in connection with file management: • Creating and deleting files • Creating and deleting directories to organize files • Supporting primitives for manipulating files and directories • Mapping files onto mass storage • Backing up files on stable (nonvolatile) storage media

## Mass storage management

The operating system is responsible for the following activities in connection with secondary storage management: • Mounting and unmounting • Free-space management • Storage allocation • Disk scheduling • Partitioning • Protection

## Caching 

Information is normally kept in some storage system (such as main memory). As it is used, it is copied into a faster storage system— the cache—on a temporary basis. When we need a particular piece of information, we first check whether it is in the cache. If it is, we use the information directly from the cache. If it is not, we use the information from the source, putting a copy in the cache under the assumption that we will need it again soon.

Because caches have limited size, cache management is an important design problem. Careful selection of the cache size and of a replacement policy can result in greatly increased performance

For instance, data transfer from cache to CPU and registers is usually a hardware function, with no operating-system intervention. In contrast, transfer of data from disk to memory is usually controlled by the operating system.

In a hierarchical storage structure, the same data may appear in different levels of the storage system
![[Pasted image 20230212185425.png]]
Fine in single CPU systems but can cause problems in multiprocessor systems where each CPU can have its own cache - Cache coherency is neede to syncronize the different CPU's caches. Even worse for distributed systems since multiple version of the same file can be on different machines. One replicat updated all of them have to be updated.

## Security and protection

For multy user / concurrent systems memory-addressing hardware ensures that a process can execute only within its own address space. The timer ensures that no process can gain control of the CPU without eventually relinquishing control. Device-control registers are not accessible to users, so the integrity of the various peripheral devices is protected

Protection can improve reliability by detecting latent errors at the interfaces between component subsystems. Early detection of interface errors can often prevent contamination of a healthy subsystem by another subsystem that is malfunctioning. A protection-oriented system provides a means to distinguish between authorized and unauthorized usage

The job of security to defend a system from external and internal attacks. Such attacks spread across a huge range and include viruses and worms, denial-ofservice attacks (which use all of a system’s resources and so keep legitimate users out of the system), identity theft, and theft of service (unauthorized use of a system). Prevention of some of these attacks is considered an operatingsystem function on some systems, while other systems leave it to policy or additional software.

Protection and security require the system to be able to distinguish among all its users. Most operating systems maintain a list of user names and associated user identifier (user IDs).

Groupe identifier - An owner might be allowed to do anything but a selected set of users may be allowed only to read the file. To accomplish this, we need to define a group name and the set of users belonging to that group. Group functionality can be implemented as a system-wide list of group names

a user sometimes needs to escalate privileges to gain extra permissions for an activity. The operating systems provide various methods to allow privilege escalation. On UNIX, for instance, the setuid attribute on a program causes that program to run with the user ID of the owner of the file, rather than the current user’s ID. The process runs with this effective UID.

## Virutalization

In summary, emulation is a form of software-based simulation that creates a virtual environment for a specific device or system, while virtualization is a broader concept that creates virtual versions of physical devices, operating systems, or resources.

On laptops and desktops, a VMM allows the user to install multiple operating systems for exploration or to run applications written for operating systems other than the native host. Apple laptop running macOS on the x86 CPU can run a Windows 10 guest to allow execution of Windows applications.

## Distributed systems

A distributed system is a collection of physically separate, possibly heterogeneous computer systems that are networked to provide users with access to the various resources that the system maintains. Access to a shared resource increases computation speed, functionality, data availability, and reliability.

Networks are characterized based on the distances between their nodes. A local-area network (LAN) connects computers within a room, a building, or a campus. A wide-area network (WAN) usually links buildings, cities, or countries. metropolitan-area network (MAN) could link buildings within a city. BlueTooth and 802.11 devices use wireless technology to communicate over a distance of several feet, in essence creating a personal-area network (PAN) between a phone and a headset or a smartphone and a desktop computer

## Network operating system

A network operating system is an operating system that provides features such as file sharing across the network, along with a communication scheme that allows different processes on different computers to exchange messages. A computer running a network operating system acts autonomously from all other computers on the network, although it is aware of the network and is able to communicate with other networked computers. A distributed operating system provides a less autonomous environment. The different computers communicate closely enough to provide the illusion that only a single operating system controls the network

## Traditional computing environments

Companies establish portals, which provide web accessibility to their internal servers. Network computers (or thin clients)—which are essentially terminals that understand web-based computing—are used in place of traditional workstations where more security or easier maintenance is desired. Mobile computers can synchronize with PCs to allow very portable use of company information. Mobile devices can also. connect to wireless networks and cellular data networks to use the company’s web portal (as well as the myriad other web resources).

Many homes use firewall to protect their networks from security breaches. Firewalls limit the communications between devices on a network

20th century, computing resources were relatively scarce. (Before that, they were nonexistent!) For a period of time, systems were either batch or interactive. Batch systems processed jobs in bulk, with predetermined input from files or other data sources. Interactive systems waited for input from users. To optimize the use of the computing resources, multiple users shared time on these systems. These time-sharing systems used a timer and scheduling algorithms to cycle processes rapidly through the CPU, giving each user a share of the resources. The same scheduling technique is still in use on desktop computers, laptops, servers, and even mobile computers, but frequently all the processes are owned by the same user (or a single user and the operating system).

## Mobile computing
Handheld computing - Smarhphone or tablet. Historically, compared with desktop and laptop computers, mobile systems gave up screen size, memory capacity, and overall functionality in return for handheld mobile access to services such as e-mail and web browsing. Now no longer the case. The increase in features on mobile devices such as GPS, which isn't as usefull on a desk- or laptop have app been developed for them such as google maps for telling directions on the go. IEEE standard 802.11 wireless or cellular data networks. Still limited by power consuption and storage options.

## Client server computing

ontemporary network architecture features arrangements in which server systems satisfy requests generated by client systems. This form of specialized distributed system, called a client–server system.

![[Pasted image 20230212195955.png]]The compute-server system provides an interface to which a client can send a request to perform an action (for example, read data). In response, the server executes the action and sends the results to the client. A server running a database that responds to client requests for data is an example of such a system.

The file-serve system provides a file-system interface where clients can create, update, read, and delete files. An example of such a system is a web server that delivers files to clients running web browsers. The actual contents of the files can vary greatly, ranging from traditional web pages to rich multimedia content such as high-definition video.

## peer to peer computing

In this model, clients and servers are not distinguished from one another. Instead, all nodes within the system are considered peers, and each may act as either a client or a server, depending on whether it is requesting or providing a service. In a client–server system, the server is a bottleneck; but in a peer-to-peer system, services can be provided by several nodes distributed throughout the network.

Determining what services are available is accomplished in one of two general ways:
- When a node joins a network, it registers its service with a centralized lookup service on the network. Any node desiring a specific service first contacts this centralized lookup service to determine which node provides the service. The remainder of the communication takes place between the client and the service provider.
- An alternative scheme uses no centralized lookup service. Instead, a peer acting as a client must discover what node provides a desired service by broadcasting a request for the service to all other nodes in the network. The node (or nodes) providing that service responds to the peer making the request. To support this approach, a discovery protocol must be provided that allows peers to discover services provided by other peers in the network. Figure 1.23 illustrates such a scenario.

![[Pasted image 20230212200446.png]]
Skype is another example of peer-to-peer computing. It allows clients to make voice calls and video calls and to send text messages over the Internet using a technology known as voice over IP (VoIP). Skype uses a hybrid peerto-peer approach. It includes a centralized login server, but it also incorporates decentralized peers and allows two peers to communicate.

## Cloud computing

Cloud computing is a type of computing that delivers computing, storage, and even applications as a service across a network. In some ways, it’s a logical extension of virtualization, because it uses virtualization as a base for its functionality. For example, the Amazon Elastic Compute Cloud (ec2) facility has thousands of servers, millions of virtual machines, and petabytes of storage available for use by anyone on the Internet.

types of cloud computing:
• Public cloud—a cloud available via the Internet to anyone willing to pay for the services 
• Private cloud—a cloud run by a company for that company’s own use 
• Hybrid cloud—a cloud that includes both public and private cloud components 
• Software as a service (SaaS)—one or more applications (such as word processors or spreadsheets) available via the Internet 
• Platform as a service (PaaS)—a software stack ready for application use via the Internet (for example, a database server) 
• Infrastructure as a service (IaaS)—servers or storage available over the Internet (for example, storage available for making backup copies of production data)

![[Pasted image 20230212201640.png]]

## Real time embedded systems
car engines and manufacturing robots to optical drives and microwave ovens. They tend to have very specific tasks. The systems they run on are usually primitive, and so the operating systems provide limited features. Usually, they have little or no user interface, preferring to spend their time monitoring and managing hardware devices, such as automobile engines and robotic arms.

- Some are general-purpose computers, running standard operating systems.
- Others are hardware devices with a special-purpose embedded operating system providing just the functionality desired.
- Yet others are hardware devices with application-specific integrated circuits (ASICs) that perform their tasks without an operating system

Embedded systems almost always run real-time operating systems. You wouldn't want you cars engine to missfire because of a computational delay, would you?

## Free and open source OS

The study of operating systems has been made easier by the availability of a vast number of free software and open-source releases. Both free operating systems and open-source operating systems are available in source-code format rather than as compiled binary code. Note, though, that free software and open-source software are two different ideas championed by different groups of people. Free software not only makes source code available but also is licensed to allow no-cost use redistribution and modification. Open source software doen not necessarily offer such licensing.

- GNU/Linux mix some open source and others free software
- Windows closed software 
- macOS hybrid kernel (darwin) opensource other closed source proprietary components.

benefits to open-source operating systems, including a community of interested (and usually unpaid) programmers who contribute to the code by helping to write it, debug it, analyze it, provide support, and suggest changes. Arguably, open-source code is more secure than closed-source code because many more eyes are viewing the code. Certainly, open-source code has bugs, but open-source advocates argue that bugs tend to be found and fixed faster owing to the number of people using and viewing the code.