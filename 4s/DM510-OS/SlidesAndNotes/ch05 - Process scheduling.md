Scheduler (or dispatcher) needs to decide which process that are in its ready state are going to get put on the CPU.

# Basic concepts
- Typical process has alternating CPU bursts and I/O bursts
- Yields maximum CPU utilization
- CPU burst distribution is of main concern
- Larger number of short burst
- Under heavy load can have small number of short burst
![[Pasted image 20230222153528.png]]

# Scheduler
- Selects processes from processes in ready queue and allocates A CPU core to one of them - Queue may be ordered in any way
- Decisions may take place when
  - 1. Switches from running to waiting state 
  - 2. Switches from running to ready state
  - 3. Switches from waiting to ready 
  - 4. Terminates
- Scheduling under 1 and 4 is non-preemptive
- All other scheduling is pre-emptive
  - Consider access to shared data
  - Consider pre-emption while in kernel mode
  - Consider interrupts occurring during crucial OS activities

# Dispatcher
- gives control of the CPU to the process selected by the short-term scheduler.
- This involves:
  - switching context
  - switching to user mode
  - jumping to the proper location in the user program to restart that program
- Dispatch latency - Time it takes dispatcher to stop a process and start another

# Scheduling criteria
- CPU utilization – keep the CPU as busy as possible
- Throughput – # of processes that complete their execution per time unit
- Turnaround time – amount of time to execute a particular process
- Waiting time – amount of time a process has been waiting in the ready queue
- Response time – amount of time it takes from when a request was submitted until the first response is produced, not output (for time-sharing environment)

# Scheduling algorithm optimization criteria
- Max COU utilization
- Max throughput
- Min turnaround time
- Min waiting
- Min response time

## First comes, first served (FCFS) scheduling
- Suppose that the processes arrive in the order: P1 , P2 , P3, with respective burst time 24, 3, 3
![[Pasted image 20230222155250.png]]
- Waiting time for P1 = 0; P2 = 24; P3 = 27
- Average waiting time: (0 + 24 + 27)/3 = 17

- Another ordering P2, P3, P1
![[Pasted image 20230222155356.png]]
- Waiting time for P1 = 6; P2 = 0; P3 = 3
- Average waiting time: (6 + 0 + 3)/3 = 3
- Convoy effect - short process behind long process

## Shortest-Job-First (SJF) scheduling
- Associate with each process the length of its next CPU burst
  - Use these lengths to schedule the process with the shortest time
- SJF is optimal – gives minimum average waiting time for a given set of processes
  - The difficulty is knowing the length of the next CPU request
  - Could ask the user
- Suppose P1, P2, P3, P4 with burst 6, 8, 7, 3
![[Pasted image 20230222155751.png]]
Average waiting time = (3 + 16 + 9 + 0) / 4 = 7

### Determining length of next CPU burst time
- Can only estimate the length – should be similar to the previous one
  - Then pick process with shortest predicted next CPU burst
- Can be done by using the length of previous CPU bursts, using exponential averaging
  - 1. $t_n$ = actual length of the $n^{th}$ CPU burst
  - 2. $t_{n-1}$ = predicted value for the next CPU burst
  - 3. $\alpha$, 0 $\leq \alpha \leq 1$ commonly set to $\frac{1}{2}$ 
  - 4. Define: $\tau_{n+1}=\alpha ~ t_n+(1-\alpha) \tau_n$
- Pre-emptive version called shortest-remaining-time-first
![[Pasted image 20230222160734.png]]

### Exponential Averaging
- $\alpha = 0$
  - $\tau_{n+1} = \tau_n$
  - Recent history does not count
- $\alpha = 1$
  - $\tau_{n+1} = \alpha * t_n$
  - Only the actual last CPU burst counts
- If we expand the formula, we get:
$$\begin{aligned} \tau_{n+1} & =\alpha \cdot t_n+(1-\alpha) \cdot \tau_n \\ & =\alpha \cdot t_n+(1-\alpha) \cdot\left(\alpha \cdot t_{n-1}+(1-\alpha) \cdot \tau_{n-1}\right) \\ & =\alpha \cdot t_n+(1-\alpha) \cdot \alpha \cdot t_{n-1}+\ldots+(1-\alpha)^j \cdot \alpha \cdot t_{n-j}+\ldots(1-\alpha)^{n+1} \cdot \tau_0\end{aligned}$$
- Since both a and (1 - a) are less than or equal to 1, each successive term has less weight than its predecessor

Now we add the concepts of varying arrival times and pre-emption to the analysis of P1, P2, P3, P4 with burst time 8, 4, 9, 5 and arrival time 0, 1, 2, 3
![[Pasted image 20230222161849.png]]
Average waiting time = ((10-1)+(1-1)+(17-2)+(5-3))/4 = 26/4 = 6.5 msec

## Round Robin (RR)
- Each process gets a small unit of CPU time (time quantum q), usually 10-100 milliseconds
- When its time is used it is pre-empted and added to end of ready queue
- Each process gets 1/n of the CPU time in chunks of at most q time units at once
- No process waits more than (n-1)q time units
- n = amount of processors 
- q = time quantum (q is large => FIFO, q is small with respect to context switch => high overhead)
- Timer interrupts every quantum to schedule next process

Suppose P1, P2, P3 with burst time 24, 3, 3
![[Pasted image 20230222162608.png]]
- Typically, higher average turnaround than SJF, but better response
- q should be large compared to context switch time
- q usually 10ms to 100ms, context switch < 10 usec

### Time quantum and context switch time
![[Pasted image 20230222162711.png]]
![[Pasted image 20230222162720.png]]

## Priority scheduling 
- A priority number (integer) is associated with each process
- The CPU is allocated to the process with the highest priority (smallest integer º highest priority)
  - pre-emptive
  - Non-pre-emptive
- SJF is priority scheduling where priority is the inverse of predicted next CPI burst time 
- Problem = Starvation - low priority processes may execute
- Solution = aging - as time progresses increase the priority of the process

### Priority scheduling
![[Pasted image 20230222163259.png]]
### Priority scheduling w/ Round-Robin
![[Pasted image 20230222163327.png]]

# Multilevel queue
- With priority scheduling, have separate queues for each priority
- Schedule the process in the highest-priority queue!
![[Pasted image 20230222163434.png]]
- Prioritization based upon process type 
![[Pasted image 20230222163459.png]]

# Multilevel feedback queue
- A process can move between the various queues; aging can be implemented this way
- Multilevel-feedback-queue scheduler defined by the following parameters:
  - number of queues
  - scheduling algorithms for each queue
  - method used to determine when to upgrade a process
  - method used to determine when to demote a process
  - method used to determine which queue a process will enter when that process needs service

## Example 
![[Pasted image 20230222163704.png]]

# Thread scheduling
- Distinction between user-level and kernel-level threads
- When threads supported, threads scheduled, not processes
- Many-to-one and many-to-many models, thread library schedules user-level threads to run on LWP
  - Known as process-contention scope (PCS) since scheduling competition is within the process
  - Typically done via priority set by programmer
- Kernel thread scheduled onto available CPU is system-contention scope (SCS) – competition among all threads in system

# Pthread scheduling
- API allows specifying either PCS or SCS during thread creation
  - PTHREAD_SCOPE_PROCESS schedules threads using PCS scheduling
  - PTHREAD_SCOPE_SYSTEM schedules threads using SCS scheduling
- Can be limited by OS – Linux and macOS only allow PTHREAD_SCOPE_SYSTEM
- API things can be found on slides 31-32

# Multi-processor scheduling
- CPU scheduling more complex when multiple CPUs are available
- Multi-process may be any one of the following architectures:
  - Multicore CPUs
  - Multithreaded cores
  - NUMA systems
  - Heterogeneous multiprocessing
- Symmetric multiprocessing (SMP) is where each processor is self scheduling.
- All threads may be in a common ready queue (a)
- Each processor may have its own private queue of threads (b)
![[Pasted image 20230222164343.png]]
- Recent trend to place multiple processor cores on same physical chip
- Faster and consumes less power
- Multiple threads per core also growing
  - Takes advantage of memory stall to make progress on another thread while memory retrieve happens
 ![[Pasted image 20230222164542.png]]

# Multithreaded multicore system
![[Pasted image 20230222165131.png]]

# Multithreaded multicore system
- Chip-multithreading (CMT) assigns each core multiple hardware threads. (Intel refers to this as hyperthreading.)
- On a quad-core system with 2 hardware threads per core, the operating system sees 8 logical processors.
 ![[Pasted image 20230222165211.png]]

# Multiple-Processor Scheduling
## Load balancing
- If SMP, need to keep all CPUs loaded for efficiency
- Load balancing attempts to keep workload evenly distributed
- Push migration – periodic task checks load on each processor, and if found pushes task from overloaded CPU to other CPUs
- Pull migration – idle processors pulls waiting task from busy processor

## Processor Affinity
- When a thread has been running on one processor, the cache contents of that processor stores the memory accesses by that thread.
- We refer to this as a thread having affinity for a processor (i.e. “processor affinity”)
- Load balancing may affect processor affinity as a thread may be moved from one processor to another to balance loads, yet that thread loses the contents of what it had in the cache of the processor it was moved off of
- Soft affinity – the operating system attempts to keep a thread running on the same processor, but no guarantees.
- Hard affinity – allows a process to specify a set of processors it may run on.

# NUMA (None uniform memory access ) and CPU Scheduling
- If the operating system is NUMA-aware, it will assign memory closes to the CPU the thread is running on
![[Pasted image 20230222165641.png]]

# Real-time CPU Scheduling
- Can present obvious challenges
- **Soft real-time systems – Critical real-time tasks have the highest priority, but no guarantee as to when tasks will be scheduled
- **Hard real-time systems – task must be serviced by its deadline**
- Event latency – the amount of time that elapses from when an event occurs to when it is serviced.
- Two types of latencies affect performance
  - 1. Interrupt latency – time from arrival of interrupt to start of routine that services interrupt
  - 2. Dispatch latency – time for schedule to take current process off CPU and switch to another
![[Pasted image 20230222165839.png]]

# Interrupt Latency
![[Pasted image 20230222165905.png]]

# Dispatch Latency
- Conflict phase of dispatch latency:
  - 1. Pre-emption of any process running in kernel mode
  - 2. Release by low priority process of resources needed by high priority processes
![[Pasted image 20230222165951.png]]

# Priority-based Scheduling 
- For real-time scheduling, scheduler must support pre-emptive, priority-based scheduling
  - But only guarantees soft real-time
- For hard real-time must also provide ability to meet deadlines
- Processes have new characteristics: periodic ones require CPU at constant intervals
  - Has processing time t, deadline d, period p
  - $0 \leq t \leq d \leq p$
  - Rate of periodic task is 1/p
![[Pasted image 20230222170154.png]]

# Rate Monotonic Scheduling
- A priority is assigned based on the inverse of its period
- Shorter periods = higher priority
- Longer periods = lower priority
- P1 is assigned a higher priority than P2.
- P1 = 50 determines that P1 needs to be executed once each periode of 50 time units
![[Pasted image 20230223100942.png]]

# Missed Deadlines with Rate Monotonic Scheduling
![[Pasted image 20230223100957.png]]

# Earliest deadline first scheduling (EDF)
- Prioritises by lowest deadline
- Earlier deadline = higher priority
- Later deadline = lower priority
![[Pasted image 20230228124110.png]]

# Linux Scheduling
- When you start a task on Linux you start with a priority of 120 but you can use the nice command along with a value option to lower you priority. The nice -15 command will increase your priority value by 15 thereby lowering the priority of a task
- Users lives between 100 -> 140 in priority 
- OS lives in <100 priority, memory management 

## CFS
  - Each process assuming there are n processes will get 1/n of the process time 
  - When a process progresses its priority is lowered
  - Ahead / behind values indicating if a progress has progressed more than it should have if it was treated fairly in conjunction to the virtual runtime
  - Ahead decreases priority
  - Behind increases priority
  - Implemented as red-black-trees

## Scheduling classes
- Each has specific priority
- Schedular picks highest priority task
- Based on proportion of CPU time not fixed time allotments
- 2 default scheduling classes - default / real-time

## Quantum calculated based on nice value from -20 to +19
- Lower value higher priority
- Calculates target latency - time between each task running once on the CPU
- Target latency can increase if number of active tasks increase

# Windows scheduling
- Windows uses priority-based pre-emptive scheduling
- Highest-priority thread runs next
- Dispatcher is scheduler
- Thread runs until (1) it blocks, (2) uses its time slice, (3) pre-empted by higher-priority thread.
- Real-time threads can preempt non-real-time
- 32-level priority scheme - all variable except REAL TIME 
![[Pasted image 20230228131919.png]]
- Variable class is 1-15, real-time class is 16-31![[Pasted image 20230228132308.png]]
- Priority 0 is memory-management thread
- Queue for each priority
- If no run-able thread, runs idle thread
- A thread within a given priority class has a relative priority
  - TIME_CRITICAL, HIGHEST, ABOVE_NORMAL, NORMAL, BELOW_NORMAL, LOWEST, IDLE
- Priority class and relative priority combine to give numeric priority
- If quantum expires, priority lowered, but never below base
- Wait can boost priority depending on what was waited for 
- foreground tasks is boosted by 3x
- Win7 added user mode scheduling (ums)
  - Applications create and manage threads independent of kernel
  - For large number of thread , much more efficient
  - UMS schedulers come from programming language libraries like C++ concurrent runtime (ConcRT) framwork

# Solaris 
?????????????????????????????
## Solaris dispatcher
????????????????????????????????
## Solaris scheduling 
??????????????????????????????????

5.64 -> 5.67


# Algorithm Evaluation
- How to select CPU-scheduling algorithm for an OS
- Determine criteria, then evaluating algorithms
- Deterministic modelling
  - Type of analytic evaluation 
  - Takes a particular predetermined workload and defines the performance of each algorithm for that workload 
## Example
- Consider P1 through P5 arriving at time 0 with 10, 29, 3, 7 and 12 as burst time respectively
- For each algorithm, calculate minimum average waiting time
- Simple and fast, but requires exact numbers for input, applies only to those inputs
![[Pasted image 20230228132723.png]]

# Queueing Models
- Describes the arrival of processes, and CPU and I/O bursts probabilistically
  - Commonly exponential, and described by mean
  - Computes average throughput, utilization, waiting time, etc
- Computer system described as network of servers, each with queue of waiting processes
  - Knowing arrival rates and service rates
  - Computes utilization, average queue length, average wait time, etc

# Little's Formula
- n = average queue length
- W = average waiting time in queue
- $\lambda =$ average arrival rate into queue
- Little's Law is a steady state, processes leaving the queue must equal processes arriving
- Thus $n = \lambda ~*~ W$

# Implementation
- Even simulations have limited accuracy
- Just implement new scheduler and test in real systems 
  - High cost, high risk
  - Environments vary
- Most flexible schedulers can be modified per-site or per-system
- Or APIs to modify priorities 
- Environments vary













Criteria for designing a CPU schedular 
- High throughput 
- low wait time 
- responsiveness 

- Hard real-time scheduling guarantees time to complete a certain task 
- Soft real-time scheduling does not guarantees time to complete a certain task
