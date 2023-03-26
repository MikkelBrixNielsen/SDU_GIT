#### 1)
A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.
- The amount of possible scheduling's will be equal to the number of permutations, which for n element can be described as n!

#### 2)
Explain the difference between pre-emptive and non-pre-emptive scheduling.
- pre-emptive scheduling 
	  - makes scheduling decisions regarding When a process switches from the running state to the waiting state or ready state, from waiting to ready or when the process terminates
- non-pre-emptive scheduling
  - Only makes scheduling decisions regarding when a process switches from the running state to the waiting state (for example, as the result of an I/O request or an invocation of wait() for the termination of a child process) or when the process itself terminates

#### 3)
Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use non-pre-emptive scheduling, and base all decisions on the information you have at the time the decision must be made.
![[Pasted image 20230306202715.png]]
- What is the average turnaround time for these processes with the FCFS scheduling algorithm?
  P1 = 8
  P2 = (8-0.4) + 4 = 11.6
  P3 = (12-1) + 1 = 12
  AVG = 10,5333

- What is the average turnaround time for these processes with the SJF scheduling algorithm?
  P1 = 8
  P3 = (8-1) + 1 = 8
  P2 = (8 - 0.4) + 1 + 4 = 12.6
  AVG =9,5333   

- The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling
  P3 = 1
  P2 = 0.6 + 1 + 4 = 5.6
  P1 = 1 + 1 + 4 + 8 = 14
  AVG = 6,8667

#### 4) 
Consider the following set of processes, with the length of the CPU burst time given in milliseconds:
![[Pasted image 20230306202826.png]]
The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.

- Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, non-pre-emptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).
  ##### FCFS
  P1: 0 -> 2
  P2: 2 -> 3
  P3: 3 -> 11
  P4: 11 -> 15
  P5: 15 -> 20
    
  #### SJF
  P2: 0 -> 1
  P1: 1 -> 3
  P4: 3 -> 7
  P5: 7 -> 12
  P3: 12 -> 20
  
  #### NPEP
  P3: 0 -> 8
  P5: 8 -> 13
  P1: 13 -> 15
  P4: 15 -> 19
  P2: 19 -> 20
  
  #### RR - FCFS 
  P1: 0 -> 2      (P1, done)
  P2: 2 -> 3      (P2, done)
  P3: 3 -> 5      (P3, 6 remaining)
  P4: 5 -> 7      (P4, 2 remaining)
  P5: 7 -> 9    (P5, 3 remaining)
  P3: 9 -> 11  (P3, 4 remaining)
  P4: 11 -> 13  (P4, done)
  P5: 13 -> 15  (P5, 1 remaining)
  P3: 15 -> 17  (P3, 2 remaining)
  P5: 17 -> 18  (P5, done)
  P3: 18 -> 20  (P3, done)

- What is the turnaround time of each process for each of the scheduling algorithms in part a?
  #### FCFS
  P1 = 2
  P2 = 3
  P3 = 11
  P4 = 15
  P5 = 20
  
  #### SJF
  P2: 1
  P1: 3
  P4: 7
  P5: 12
  P3: 20
  
  #### NPEP
  P3: 8
  P5: 13
  P1: 15
  P4: 19
  P2: 20
  
  #### RR - FCFS 
  P1: 2
  P2: 3
  P4: 13
  P5: 19
  P3: 20
  
- What is the waiting time of each process for each of these scheduling algorithms?
  #### FCFS
  P1: 0
  P2: 2
  P3: 3
  P4: 11
  P5: 15
  
  #### SJF
  P2: 0 
  P1: 1
  P4: 3
  P5: 7
  P3: 12
  
  #### NPEP
  P3: 0
  P5: 8
  P1: 13
  P4: 15
  P2: 19
  
  #### RR - FCFS 
  P1: 0
  P2: 2
  P3: 3 + 4 + 4 + 2= 13
  P4: 5 + 4 = 9
  P5: 7 + 4 + 2 =13

- Which of the algorithms results in the minimum average waiting time (over all processes)?
  #### FCFS
  AVG = 0 + 2 + 3 + 11 + 15 = 31 / 5 = 6,2
  
  #### SJF
  AVG = (0 + 1 + 3 + 7 + 12) / 5  = 4,6
  
  #### NPEP
  AVG = 0 + 8 + 13 + 15 + 19 = 55 / 5 = 11
  
  #### RR - FCFS 
  AVG = 0 + 2 + 13 + 9 + 13 + 13 = 50 / 5 = 10

#### 5)
The following processes are being scheduled using a round-robin scheduling algorithm.
![[Pasted image 20230306203001.png]]
Each process is assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes listed below, the system also has an idle task (which consumes no CPU resources and is identified as P_idle. This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.

- Show the scheduling order of the processes using a Gantt chart.
  P1: 0 -> 10,        (P1, 10 remaining)
  P1: 10 -> 20,      (P1, done)
  P_idle: 20 -> 25,
  P2: 25 -> 35,      (P2, 15 remaining)
  P3: 35 -> 45,      (P3, 15 remaining)
  P2: 45 -> 55,      (P2, 5 remaining)
  P3: 55 -> 60,      (P3, 10 remaining)
  P4: 60 -> 75,      (P4, done)
  P2: 75 -> 80,      (P2, done)
  P3: 80 -> 90,      (P3, done)
  P_idle: 90 -> 100, 
  P5: 100 -> 105,  (P5, 5 remaining)
  P6: 105 -> 115,  (P6, done)
  P5: 115 -> 120,  (P5, done) 

- What is the turnaround time for each process?
  P1: 20
  P2: 55
  P3: 60
  P4: 15
  P5: 20
  P6: 10

- What is the waiting time for each process?
  P1: 0
  P2: 30
  P3: 35
  P4: 0
  P5: 10
  P6: 0

- What is the CPU utilization rate?
  1-(15/120) = 87.5%

#### 6)
What advantage is there in having different time-quantum sizes at different levels of a multilevel queueing system?
- Improved fairness - 
- Better throughput - Can reduce overall waiting time so that one process does not block a lot of smaller processes
- Better response - same as through put
- Prioritization


#### 7) 
Many CPU-scheduling algorithms are parameterized. For example, the RR algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithms for each queue, the criteria used to move processes between queues, and so on. These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the FCFS algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?

- Priority and SJF
  Priority scheduling and SJF can be said to be related in regards to priority being a special case of SJF where low burst time equals high priority

- Multilevel feedback queues and FCFS
  Not really related since FCFS executes the first to arrive and MLFQ uses different queues processes can move between.

- Priority and FCFS
  FCFS can be views as a special case of priority where processes that arrived first are assigned a high priority just like in the queues in the supermarket.

- RR and SJF
  RR and SJF aren't really related since RR gives each process an equal time slice they can be on the CPU where as SJF prioritises picking processes with low execution time. But in a case where priority is linked to execution time and RR also picked based on Priority they would pick similar processes. 

#### 8)
Suppose that a CPU scheduling algorithm favours those processes that have used the least processor time in the recent past. Why will this algorithm favour I/O-bound programs and yet not permanently starve CPU-bound programs?
- It will favour I/O bound programs since they will spend a good part of their time off the CPU waiting for I/O, so that when they have something to process they they will not have used much CPU time recently so they will be favoured
- It will not starve CPU bound processes since if enough time passes their recent CPU utilization 

#### 9)
Distinguish between PCS and SCS scheduling.
- PCS - Process contention scope
  - Scope where we have threads that can run at the same time (How are the threads mapped to the processes)
- SCS - System contention scope
- Scope where we have threads that needs to be scheduled (how are the processes mapped to the CPUs)

#### 10)
The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function:

Priority = (recent CPU usage / 2) + base

where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage for process P1 is 40, for process P2 is 18, and for process P3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?
- P1 = 40 / 2 + 60 = 80
- P2  = 18 / 2 + 60 = 69
- P3 = 10 / 2 + 60 = 65
- The traditional UNIX schedular would raise lower the priority of a CPU-bound process since it would have high CPU usage, which lowers its priority.

#### 11) 
Of these two types of programs
-   I/O-bound
-   CPU-bound
which is more likely to have voluntary context switches, and which is more likely to have nonvoluntary context switches? Explain your answer.
- I/O bound is more likely to voluntarily context switch while it is waiting for I/O resources
- CPU bound processes are more likely to be nonvoluntarily context switched

#### 12)
One technique for implementing lottery scheduling works by assigning processes lottery tickets, which are used for allocating CPU time. Whenever a scheduling decision has to be made, a lottery ticket is chosen at random, and the process holding that ticket gets the CPU. The BTV operating system implements lottery scheduling by holding a lottery 50 times each second, with each lottery winner getting 20 milliseconds of CPU time (20 milliseconds × 50 = 1 second). Describe how the BTV scheduler can ensure that higher-priority threads receive more attention from the CPU than lower-priority threads.
- By giving threads with high priority more lottery tickets for a higher chance to "win".

#### 13)
Consider the exponential average formula used to predict the length of the next CPU burst. What are the implications of assigning the following values to the parameters used by the algorithm?
- α = 0 and τ0 = 100 milliseconds
  - The weight given to past observations is zero, which means that the predicted length of the next CPU burst is based solely on the initial estimate τ0
- α = 0.99 and τ0 = 10 milliseconds
  - the weight given to past observations is very high, which means that the predicted length of the next CPU burst is based highly on previous observations and not much on the initial estimate τ0

#### 14)
A variation of the round-robin scheduler is the regressive round-robin scheduler. This scheduler assigns each process a time quantum and a priority. The initial value of a time quantum is 50 milliseconds. However, every time a process has been allocated the CPU and uses its entire time quantum (does not block for I/O), 10 milliseconds is added to its time quantum, and its priority level is boosted. (The time quantum for a process can be increased to a maximum of 100 milliseconds.) When a process blocks before using its entire time quantum, its time quantum is reduced by 5 milliseconds, but its priority remains the same. What type of process (CPU-bound or I/O-bound) does the regressive round-robin scheduler favour? Explain.
- it will favour and give more CPU time to task which can utilize it and those tasks are CPU bound tasks and it will remove time from tasks that just blocks.

#### 15)
The following processes are being scheduled using a pre-emptive, priority-based, round-robin scheduling algorithm.
![[Pasted image 20230306203642.png]]
Each process is assigned a numerical priority, with a higher number indicating a higher relative priority. The scheduler will execute the highest priority process. For processes with the same priority, a round-robin scheduler will be used with a time quantum of 10 units. If a process is pre-empted by a higher-priority process, the pre-empted process is placed at the end of the queue.
- Show the scheduling order of the processes using a Gantt chart.
  P1: 0 -> 15 - DONE
  P2: 15 -> 20 - 15 remaining
  P3: 20 -> 30 - 10 remaining
  P4: 30 -> 40 - 10 remaining
  P3: 40 -> 45 - 5 remaining
  P5: 45 -> 50 - DONE
  P4: 50 -> 55 - 5 remaining
  P6: 55 -> 70 - DONE
  P3: 70 -> 75 - DONE
  P4: 75 -> 80 - DONE
  P2: 80 -> 95 - DONE  
  
- What is the turnaround time for each process?
  P1: 15
  P2: 95
  P3: 55
  P4: 55
  P5: 5
  P6: 15  
  
- What is the waiting time for each process?
  P1: 0
  P2: 75
  P3: 35
  P4: 35
  P5: 0
  P6: 0

#### 16) 
Which of the following scheduling algorithms could result in starvation?
- First-come, first-served - NO
- Shortest job first - YES
- Round robin - YES, if priority based
- Priority - YES, if continuous high priority jobs and one low priority job which priority no change

#### 17)
Consider a system running ten I/O-bound tasks and one CPU-bound task. Assume that the I/O-bound tasks issue an I/O operation once for every millisecond of CPU computing and that each I/O operation takes 10 milliseconds to complete. Also assume that the context-switching overhead is 0.1 millisecond and that all processes are long-running tasks. Describe the CPU utilization for a round-robin scheduler when:
- The time quantum is 1 millisecond
  - An I/O bound task would get 1ms compute, issue I/O and wait 10ms which leaves an almost perfect loop including the CPU bound task (disregarding context switching, with it would be slightly off):
    IO1: 0->1,            (waits until 11)
    IO2: 1->2,            (waits until 12)
    IO3: 2->3,            (waits until 13)
    IO4: 3->4,            (waits until 14)
    IO5: 4->5,            (waits until 15)
    IO6: 5->6,            (waits until 16)
    IO7: 6->7,            (waits until 17)
    IO8: 7->8,            (waits until 18)
    IO9: 8->9,            (waits until 19)
    IO10: 9->10,        (waits until 20)
    CPU: 10->11,       (repeat)
       
- The time quantum is 10 milliseconds
  - Giving an I/O 10ms is bad idea since it would issue I/O at 1ms have 9ms left on CPU wait do nothing those 9ms context switch + 0.1ms next I/O would start 10.1 issue I/O at 11.1 where IO1 gets its I/O back so it waits ... same pattern for all 10 I/O tasks so 90% of I/O's time on CPU basically wasted... BAAAAD!!!
    IO1: 0->10,              (I/O at 11)
    IO2: 10->20,            (I/O at 12)
    IO3: 20->30,            (I/O at 13)
    IO4: 30->40,            (I/O at 14)
    IO5: 40->50,            (I/O at 15)
    IO6: 50->60,            (I/O at 16)
    IO7: 60->70,            (I/O at 17)
    IO8: 70->80,            (I/O at 18)
    IO9: 80->90,            (I/O at 19)
    IO10: 90->100,        (I/O at 20)
    CPU: 100->110,       (repeat)

#### 18)
Explain the how the following scheduling algorithms discriminate either in favour of or against short processes:
- FCFS - Favours the first to arrive, discriminates against short processes since they'll wait a while compared to their size
- RR - doesn't really care, just gives each process their time quantum - but generally shorter processes will get through the system faster
- Multilevel feedback queues - favour short processes because it uses priority aging and pre-emption to ensure that shorter processes are executed first, discriminates against newly arrived processes.

#### 19)
Assume that an SMP (symmetric multi processing) system has private, per-processor run queues. When a new process is created, it can be placed in either the same queue as the parent process or a separate queue.
- What are the benefits of placing the new process in the same queue as its parent?
  - placing a new process in the same queue as its parent can improve cache performance, resource sharing, and manageability, 
- What are the benefits of placing the new process in a different queue?
  - while placing it in a separate queue can improve overall system performance, prevent starvation, and avoid competition for resources, load balancing.

#### 20)
Explain why interrupt and dispatch latency times must be bounded in a hard real-time system.
- If they are not bound it can result in the system not keeping its time constraints resulting in system failure, loss of date etc... 
- Interrupt latency is the time delay between the occurrence of an interrupt and the execution of the corresponding interrupt handler. Not binding this the system may not be able to respond to the interrupt in time - missed deadlines / incorrect system behaviour.
- Dispatch latency is the time delay between the decision to execute a process and the actual start of its execution. Dispatch latency not being bound system may not meet timing constraints - missed deadlines / incorrect system behaviour.