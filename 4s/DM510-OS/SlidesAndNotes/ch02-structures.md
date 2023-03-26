Operating system services:
 - User interface (UI) almost always present, different types: command-line (CLI), Graphics user interface (GUI), touch screen, batch.

- CLI allows direct command entry, sometimes directly into the kernel, sometimes by system programs. Can be implemented differently (various flavours of shells), its primary use is to fetch commands from the user and execute them (built in commands – requires shell modification, or names of programs – does not require shell modification)

- GUI is user-friendly desktop metaphor interface, usually mouse, keyboard, and monitor, icons represent files, programs, and actions etc. Different mouse buttons over objects cause actions like, providing information, executing a function, opening a directory (folder) etc. (Invented as Xerox PARC R&D centre in Palo Alto, California, founded 1970)  
examples: windows (GUI) with windows PowerShell or CMD (CLI), the same goes for the mac OS X and Unix and Linux OSes

- Touch interfaces, requires a new interface, here mouse not possible or desired, actions and selections are based on gestures, virtual keyboard for text entry and voice commands.

- program execution, being able to load and run a program in memory either normally or abnormally (error occurred)

- I/O execution, must be able to make use of I/O devices (network cards, headphones, keyboard, mouse, printer, scanner etc.), or files

File-system manipulation, programs needed to store, read, and write file and directories, create, and delete them, search them, list file information, permission management. 

- Communication, being able to exchange information from different processes on the same computer or between computers over a network, this may be via shared memory or through message passing (packets moved by the OS)

- Error detection, needs to be constantly aware of potential errors, may occur in the cpu, memory hardware, I/O devices, user programs, etc. The OS should be able to take an appropriate action to circumvent possible errors and provide consistent computing. Debugging facilities can improve user and programmer’s efficiently use the system.

- Resource allocation, when multiple users or processes are running at them same time resource must be allocated to each of them to ensure consistent operation. Theses resources include, CPU cycles, main memory, and file storage, may have I/O devices allocated, may have general request and release code. 

- Logging, keeps track of how much and of which kind of system resources a specific user has allocated.

- Protection and security, Information stores in a multiuser or networked computer system may want to limit the accessibility of certain information, such that concurrent processes do not interfere with one another. Protection regards ensuring access to system resources are controlled. Security regards protecting the system from outsiders often with user authentication, extends to defending external I/O devices from invalid access attempts. (Only as strong as weakest link)

![[clip_image002.png]]

Normally a user would not make system calls, normally a CLI or command interpreter would handle this. And it can be implemented in different ways e.g., kernel, system program, shells, which primarily fetches a command from user and executes it.

Filesystems does not necessarily have to give you access to a local file but could give you access to a variety of different things like google drive, programs currently running (temp files), e.g.

The dd command can be used to create large files and other things.

The &-sign is used to put a task into the background when calling it through the command line.

System calls:
- programming interface to the services provided by the OS, typically written in high level language such as C or C++, often accessed by programs via high level application program interface (API) rather than direct system calls. The 3 most commons once are Win32 – windows, POSIX – all POSIX-based systems virtually all UNIX, Linux and Mac OS X, and Java API – Java virtual machine (JVM)

The system call’s names are generic throughout this text.

Using an API lets the operating system manage the requests so your software is less likely to affect other software when it crashes. There are many APIs. They simplify system calls, implement cross-platform interface so you can port the app, manage access to secure areas, and do many other useful things. Not having an API would result in reinventing that API.

SYS-call example:
![[clip_image004.png]]
API example:
![[clip_image006.png]]

SYS-call implementation, there is typically a number associated with each call, which a system call interface maintenance an index table over. The interface invokes the intended system call in OS kernel and returns the status of the system call and any return values. Caller needs to know nothing about how the actual call is implemented, only needs to obey API and understand what OS will do as a result of the call. Most of the details regarding the OS interface are hidden from the programmer by the API and is managed by run-time support libraries (functions built into libraries included with compiler.

API- System call os relationship:
![[clip_image008.png]]

Standard C example:
![[clip_image010.png]]

A system call often requires more than just its identification number, type and amount of information can vary according to OS and the call itself. There are 3 general methods for passing parameters to the OS:

Register passing – as it sounds but there may be more parameters than registers.

Address passing – parameters stored as blocks or tables in memory and the address of the block / table is passed as a parameter in the register (used by Linux and Solaris) and does not limit the number or length of parameters being passed.

Stack passing – parameters are placed / pushed onto a stack by the program and popped off the stack by the OS, which does not limit the number or length of parameters being passed.

Parameter passing via table:
![[clip_image012.png]]

System calls are often proprietary, so calling a system call directly in your code will limit portability, since it might be called write on one system and something completely different on another system.

Types of system calls – There are many different systemc calls which does many different things, like process control, file management, device management, and control.

Process control:  
- end, abort  
- load, execute  
- create process, terminate process  
- get process attributes, set process attributes  
- wait for time  
- wait event, signal event  
- allocate and free memory

- Dump memory if error  
- Debugger for determining bugs, single step execution  
- Locks for managing access to shared data between processes

File management:  
- create file, delete file  
- open, close file  
- read, write, reposition  
- get and set file attributes

Device management:  
- request device, release device  
- read, write, reposition  
- get device attributes, set device attributes  
- logically attach or detach devices

Information maintenance  
- get time or date, set time or date  
- get system data, set system data  
- get and set process, file, or device attributes

Communications:  
- create, delete communication connection  
- send, receive messages if messages passing model to host name or process name 4 From client to server  
- Shared-memory model create and gain access to memory regions  
- transfer status information  
- attach and detach remote devices

Protection:  
- Control access to resources  
- Get and set permissions  
- Allow and deny user access

Examples of windows and UNIX system calls:
![[clip_image014.png]]

Arduino examples:
![[clip_image016.png]]

  

Example MS-DOS:

![[clip_image018.png]]

Example FreeBSD:

![[clip_image020.png]]

  

System services and programs provide a convenient environment for program development and execution, which can be divided into file manipulation, status information (often stored in a file modification), programming language support, program loading and execution, communications, background services, and application programs. These are also what defines most user’s view of the OS and not the actual system calls.

File management: Create, delete, copy, rename, print, dump, list, and generally manipulate files and directories.

Status information: some ask the system for information about data, time, available memory, disk space, number of users, others provide detailed performance, logging, and debugging information. Typically, these program format and print the output to the terminal or other output device, some systems implement a registry used to store and retrieve configuration information.

File modification: Text editors to create and modify files , special commands to search contents of files or perform transformations of the text.

Programming-language support: compilers, assemblers, debuggers, and interpreters are sometimes provided.

Program loading and execution – absolute loaders, relocatable loaders, linkage editors, and overlay loader, debugging systems for higher level machine language.

Communications: provide the mechanism for creating virtual connections among processes, users, and computer systems. It allows users to send messages to one another’s screens, brows webpages, send electronic-mail messages, log in remotely, transfer files from one machine to another.

Background services: launch boot time for either system start-up, then terminate or for the system boot to shut down. Provides facilities like disk checking, process scheduling, error logging, printing. Can run in user context and not kernel context. Theses are known as services subsystems or daemons.

Applications programs: don’t pertain to the system, are run by the user and not typically considered a part of the OS and can be launched via command line, mouse click or finger poke.

  

# Linkers and loaders:

Relocatable object file: source code compiled into object files designed to be loaded into any physical memory location.

Linker: combines these object files into a single binary executable file (can also link with libraries)

Loader: brings a program (aka binary executable), which normally resides on secondary storage, into memory to be executed.

Relocation: assigns final addresses to program parts and adjusts code and data in program to match those addresses.

Dynamically linked libraries: modern general-purpose systems don’t link libraries into executables, rather they are linked dynamically (in windows DLLs) are loaded as needed, shared by all that use the same version of that library (only loaded once).

Objects (executable files) have standard formats, so that the OS knows how to load and start them.

The role of the linker and loader: (how a program is compiled, and libraries are added)
![[clip_image022.png]]

Applications compiled on one system are usually OS specific due to the OS providing its own unique system calls and file formats etc. Although apps written in an interpreted language such as Python, Ruby etc. and have an interpreter available on multiple OSes, or apps written in a language that includes a VM containing the running app (java), or apps which use standard language (C, C++ ) that compiles separately on each OS to run are not OS specific.

Design and implementation of an OS is not “solvable”, but some approaches have proven successful, internal structures of different OSes can vary widely. To start goals and specifications should be defined. These can be affected by type of system or choice of hardware. Some different goals can be user goals and system goals. User goals could be how convenient, easy to use, to learn, reliable, safe and fast it is, while system goals could be easy to design, implement, maintain, as well as being flexible, reliable, error-free, and efficient.

Some important principles to separate are policy and mechanism. Policy is what will be done, while mechanism is how to do it. A mechanism determines how to do something while policies decide what will be done. The separation of policy from mechanism is a very important principle, which allows for maximum flexibility if policy decisions are to be changed later. Specifying and designing an OS is a highly creative task of software engineering.

There are more than 27 million lines of code in the linux kernel since it wants to support a lot of different hardware, so a wide varaity range of users can use the OS without implications.

![[clip_image024.png]]

Dominated by C code with a sprinkle of assembly when you really need explicit access to certain variables or instructions.

Unix is a base for many different OSes like linux, MAC OS X and so on… (derivitives)
![[clip_image026.png]]

Traditional system structure  
![[clip_image028.png]]

It is all in one big blob. The kernel lives in on big address space. Everything that is system relevant is in kernel mode

So, if there is an exploit in the kernel you can exploit, you’d be able to get access to everything in the kernel , which is the entire system and do whatever you want.

The essence of a kernel is – Micro kernel (present on e.g. MAC computers:  
1. Memory management  
2. Process communication  
3. CPU Scheduling

Due to virtualization, there is many modes a CPU can go in e.g., kernel mode, virtual kernel mode, user mode, etc… (gives some level of security to have different levels)

Standard for kernels is having one giant blob, which is modularised (windows, MAX OS X, Linux)

System boot is a multistage process, a small boot loader (stored ROM or EEPROM - 512KiB) locates the kernel into memory and starts it.

Other time it can be a two-step process where boot block at fixed location is loaded by ROM code, which loads bootstrap loader from disk and then the kernel is loaded.

Modern systems replace BIOS with Unified Extensible Firmware Interface (UEFI). A common bootstrap loader, GRUB, allows selection of kernel from multiple disks, versions, kernel options and loads the kernel and the system is then running. Boot loaders frequently allow various boot states, such as single user mode.

FORK BOMB!!!!!! For (int I = 0; i < 100; ++i) Frok();

Layered approch 
![[Pasted image 20230209171657.png]]

Micro kernels
- Moves as much as possible from kernel space to user space.
- Mach is a microkernel example
- communication is via message passing
- - easier to extend a microkernel
- easier to prot the OS to new acrhitectures
- more reliable (less code is running)
- more secure
- A detriment is the amount of overhead in the user space communication.
![[Pasted image 20230209171846.png]]

Modules
- Modern OS implements loadable kernel modules
- uses object oriented apporch
- each core componente is seperate
- each talks to the others over known interfaces
- each os loadable as needed within the kernel 
- similar to layers but more flexible (linux, solaris etc...)

Hybrid systems
- most modern OS not one pure mode
- combines multiple approches to address security, performance, useability.
- Linux and Solaris kernels in kernel address space, so monolithic, plus modular for dynamic loading of functionality
- Windows mostly monolithic, plus microkernel for different subsystem personalities
- Apple Mac OS X hybrid, layered, Aqua UI plus Cocoa programming environment
- Next slide: kernel consisting of Mach microkernel and BSD Unix parts, plus I/O kit and dynamically loadable modules (called kernel extensions)

maxOS ans IOS structures
![[Pasted image 20230209173044.png]]

DARWIN
![[Pasted image 20230209173306.png]]

Hybrid kernels
- based on combining aspects of microkernels and monolithic kernels achitectures.

IOS
![[Pasted image 20230209173427.png]]

Android
![[Pasted image 20230209173437.png]]

Bulding and booting an OS
- Designed to run a class of systems with vaiety of peripherals
- commonly OS aæready installed on purchased PC
- can built and instal others
- OS from sratch
  - write OS source code
  - configure OS for inteded system
  - compile
  - install
  - boot PC and OS

Building and booting OS for linux
- power on execution starts at fixed memory addresse
- OS must be available to hardware so it can start it
- Bootstrap loader, BIOS stored in ROM or EEPROM locates the kernel loads into memory and starts it.
- sometimes two step process boot bloc kat fixed location loaded by ROm code, which loads bootstrap loader from disk
- modern systems replace BIOS with UEFI - unified extensible firmware interface.
- common bootstrap loader GRUB, allows selection of kernel from multi disks
- Kernel loads and system runs 
- Boot loader allow various boot states 

Performance tuning and tracing
- Improve perofrmnace 
- OS must provide means of measuring sytem behaviour
- E.g., Windows task manager
- Collecting data for specific events involved in a system call
- Some tools to do this:
  - Strace - trace system calls invoked by process
  - gdb - source level debugger
  - perf - collection of linux perofrmance tolls
  - tpcdumo - collect network packets

DTrace usage and overview
- Allows live instrumentation on production systems
- toubleshoot performance and logic problems in user applications 
- user dynamic binary intrumentation
- insert intrumentation code in running processes
- specialized C-like language
- Probes: points of instrumentation proves fire when code is executed capturing state data and sending it ro consumers of those proves 
- providers: make proves available (loadable kernel models)
- mean to be used on production systems
- D programs collect information at runtime
- users can invoke dtrace to insert intrumentation code into kernel and user processes
- security mechanisms ensure code can only be inserted by authorized users
- events at runtime triggers user's D code, which causes information to be recorded data to be printed whatever else users degines in their D programs
- syscall makes a prove available at the entry to and return from every syscall
- vminfo makes a probe available on VM activity
- profile makes a prove available that can run every X milisecond
- fpuinfo makes a probe available whene hardware floating point operations are emulated in software
- users can also create their own providers by using the DTrace API
![[Pasted image 20230209175646.png]]

BCC
- BCC can be used for debuggin interaction between user-level and kernel code nearly impossible without toolset thatunderstand both and an instrument their actions
- BCC (BPF compiler collection) is a rich toolkit providing tracing featurs for linux 

Many other programs for Linux
![[Pasted image 20230209175958.png]]

Linux bcc/BPF Tracing tools
![[Pasted image 20230209180029.png]]
![[Pasted image 20230209180035.png]]

Kernel instrumentation in linux 
Hardware events
Software events
Tracepoints events 
Tracepoint events