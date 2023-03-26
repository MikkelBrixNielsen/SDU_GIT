![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image002.png)  
- Manage the computers resources (memory, disk, I/O devices, CPU)  
- Establish a user interface (GUI, Touch, CLI – Command line)  
- Prime, Execute and provide services for applications, programs and software

![[Pasted image 20230209101029.png]]

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image006.png)  
- Keeping the operating system within the fixed time constraints of a real-time system.
- Real time enviroment has deadline which has to be kept.
- Supporting a lot of potential hardware configurations and devices.

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image008.png)
- It should since those programs are so essential to how a computer is used now adays that you pretty much can’t do anything on it without an internet browser or a mailing application.
- It should not since those programmes are not needed for the operating system to boot run and perform its rudimentary actions.
- BLOOOOOOAAAATTT!!!!!
- Depends on the application of the system imdedded systems does not need a webbrowser.

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image010.png)  
- Kernel mode and user mode distinction work as a form of security since it creates a boundary between sensitive system calls and the normal system calls  a user can use without doing to much damage. In kernel mode the cpu has access to and authority over all hardware and can do as it pleases, which with an inexperienced user could be catastrophic. (user mode can't interact directly with hardware or directly manipulate memory).

![[Pasted image 20230209101110.png]]
- Set value of timer – should be privliged if not a program could infinite loop an keep control away from the OS.  
- Read the clock – Should not, The user should have access to  
- Clear memory – The user should not be able to clear memory since if user program can clear memory it could crash  
- Issue trap instruction – should not be privileged, since they would be used for app crashes, and telling when an app is done
- turn of interrupts – should be privileged, a program not being able to inform the system that it is done or has completed at certain task should not be configured by the user.  
- Modify entries in device-status table – privileged  
- Switching from user to kernel mode – Should be privileged not just anyone should be able to gain complete control over the system hardware and its processes. The part of requesting something be executed in kernel mode should not be privileged 
- Access to I/O device – Priviliged want the driver running in the kernel to take care of direct interaction.

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image014.png)  
- Assuming this question regards to User mode and kernel mode etc. two uses could:  
- Differentiate between different privilege levels  
- allowing the system to separate user processes from system processes and enforce access controls, which helps prevent malicious user processes from interfering with the OS.
- Virtualization  

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image016.png)Caches solve the problem of slow memory access time.  
- It’s faster memory which information can be copied to from the main storage system giving the CPU faster access to it.  
- They store frequently used data and instructions, reducing the number of accesses to the slower main memory.

Problems regarding cache:
- Non-volitile (loses stored data when power off)
- Having to adhere to Cache coherency  (increase in CPU makes it hard)
- Having to check whether the data in the cache is valid  
- Higher power consumption

Why not make it main storage and eliminate other storage:  
- Cache is expensive, so high cost  
- High power consumption  
- Access latency, making the cache larger would mean more entries and more entries would mean increased access to find the entry you are looking for.

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image018.png)
Multiprocessor system advantages include:  
- Increased throughput  
- Economy of scale  
- Increased reliability  
There are two types (1) Asymmetric Multiprocessing (each processor is assigned a specific task), (2) Symmetric multiprocessing (each processor performs all tasks)

Clusters instead of being a part of the same chip different CPUs connect to each other via a Storage-area network (SAN). This provides high availability, which survives failures. Here there are again two types of clustering (1) asymmetric clustering has one machine in hot-standby mode (2) symmetric clustering has multiple nodes running applications, monitoring each other. Some clusters are for high-performance computing (HPC) theses applications must be written to use parallelization.

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image020.png)  
- An interrupt is a program, application, or software telling the CPU that it has performed its task and is ready to let go of its allocated resources. 
- The trap (Exception) is a software-generated interrupt cause either by an error or a user request. 
- Traps can be generated and used to make system calls or if an expection happens like division by 0 a trap will occur.
- DMA is usefull since the fast CPU can omit the slow speed hardrive so it can be ofloaded to a controller in the hardware, so the CPU does not have to be involved.

![[Pasted image 20230209101132.png]]
- The CPU interfaces with teh device through the DMA controller
- The CPU is notified of the completion of the trasfer through DMA completion interrupts. 
- The DMA process does not interfere with the executuion of user programs but there mau be some minor performance impacts if the CPU and DMA controller are accessing memory at the same time.
- No direct interferance but they both haveto compete for memory, so it might make CPU memory access slower.

![[Pasted image 20230209101144.png]]
1. Register  
2. Cache  
3. Main memory  
4. Non-volatile memory  
5. Hard-disk drives  
6. Optical disk  
7. Magnetic tapes  

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image026.png)  
- On a mobile device there is often a lack of a dedicated keyboard and mouse so another input option is required.  
- Limited resources the OS can be too intensive on the hardware, since it will have to run on a plethora of devices.  
- In the same vein battery life.  
- Compatibility
