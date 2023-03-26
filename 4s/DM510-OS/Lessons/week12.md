1) Describe how deadlock is possible with the dining-philosophers problem.
   - if each of the picks up the fork to their left (or right) they'll all be waiting for the one on their other side which is held by another philosopher which is wating on the fork to their left (or right)

2) The Linux kernel has a policy that a process cannot hold a spinlock while attempting to acquire a semaphore. Explain why this policy is in place.
   - you would not want to give some resource to a process which is just waiting anyway while other potential processes could use that resource

1) List three examples of deadlocks that are not related to a computer system environment.
   - 1) If your colleague has the hammer you want the hammer but he wants the nails but you have the nails then you guys are fucked. 
   - 2) In a 4 way traffic light 4 cars arrive at the intersection at the same time the lights aren't working so you each follow the right of way principle so all of you want to give way for the vehicle to your right so no one ends up moving and you guys are fucked.
   - 3) ![[Pasted image 20230321162730.png]]

2) 
![[Pasted image 20230321163835.png]]
- if T2 never lets go of R1 then there will be a deadlock, since there is a cycle between T1 and T3 but if it does let go of R1 then the system can finish without deadlocking

3) Consider the following snapshot of a system
![[Pasted image 20230321161718.png]]
- What is the content of the matrix need
```
Need  | A | B | C | D |
T0    | 0 | 0 | 0 | 0 |
T1    | 0 | 7 | 5 | 0 |
T2    | 1 | 0 | 0 | 2 |
T3    | 0 | 0 | 2 | 0 |
T4    | 0 | 6 | 4 | 2 |
```
- is the system in a safe state 
T0 -> releases 0012 -> available 1532
T1 -> gets 0530 -> available 1002
T2 -> gets 1002 -> available 0000
T2 -> release 2356 -> available 2356
T3 -> gets 0020 -> available 2336
T3 -> release 0652 -> available 2988
T4 -> gets 0642 -> available 2346
T4 -> release 0656 -> available 299(12)
T1 -> gets 0220 -> available 277(12)
T1 -> release 1750 -> available 3(14)(12)(12)
- T0 -> T2 -> T3 -> T4 -> T1
- You can look at the need matrix if at one point the number of available resource becomes greater than any of the entries in the need matrix the state is safe without having to compute the rest


- if a request from thread T1 arrives for (0,4,2,0) can the request be granted immediately
  - Yes that would be possible since there are more than 4B's available and there is exactly 2C available, so this request can be granted immediately.

4) A possible method for preventing deadlocks is to have a single, higher-order resource that must be requested before any other resource. For example, if multiple threads attempt to access the synchronization objects A , …, E, deadlock is possible. (Such synchronization objects may include mutexes, semaphores, condition variables, and the like.) We can prevent deadlock by adding a sixth object F. Whenever a thread wants to acquire the synchronization lock for any object A, …, E, it must first acquire the lock for object F. This solution is known as containment: the locks for objects A, …, E are contained within the lock for object F. Compare this scheme with the circular-wait scheme of Section 8.5.4
   - For circular wait you need from R1 to Rn to get Rn+1, and for containment you just need F to get access to everything you don't need F then A to get B or something like that, which is needed for circular wait. But they are sort of the same since R1 can be seen as F since if you have R1 you get access to everything else if you don't have R1 you can't get shit.

5) Show that the safety algorithm presented in Section 8.6.3 requires an order of $m * n^2$ operations
   - There are 2 outer loops that are nested an run n times which provide the $n^2$ and then there are two inner loops that both run m times for the $n^2$ operations which yields $m*n^2$
     - To get 1 thread into the safe sequence you'd need to look at the other n-1 and you need to do that n time and for each thread to look at if it can go you need to look at all m resources 

6) Can a system detect that some of its threads are starving? If you answer “yes,” explain how it can. If you answer “no,” explain how the system can deal with the starvation problem.
   - Yes it is possible, how? AGING! Give priority to process that have waited for a long time or set timeouts and ask for resources again and keep track of each time a timeout has occurred and the time between them if one thread waited 5 years it should probably have something to eat (maybe???).

7) Consider the following resource-allocation policy. Requests for and releases of resources are allowed at any time. If a request for resources cannot be satisfied because the resources are not available, then we check any threads that are blocked waiting for resources. If a blocked thread has the desired resources, then these resources are taken away from it and are given to the requesting thread. The vector of resources for which the blocked thread is waiting is increased to include the resources that were taken away. For example, a system has three resource types, and the vector Available is initialized to (4,2,2). If thread T0 asks for (2,2,1), it gets them. If T1 asks for (1,0,1), it gets them. Then, if T0 asks for (0,0,1), it is blocked (resource not available). If T2 now asks for (2,0,0), it gets the available one (1,0,0), as well as one that was allocated to T0 (since T0 is blocked). T0 ’s Allocation vector goes down to (1,2,1), and its Need vector goes up to (1,0,1).
   - Can deadlock occur? If you answer “yes,” give an example. If you answer “no,” specify which necessary condition cannot occur.
   - No it cannot since pre-emption since one process can usurp another which is holding resource that it needs.

   - Can indefinite blocking occur? Explain your answer.
     - Yes, if there is on process that needs a lot of resource then if there is a lot of small process that does not need a lot of resource they just take from the one that needs a lot and it will never complete.

8) Consider the following snapshot of a system
![[Pasted image 20230321175641.png]]
Using the banker’s algorithm, determine whether or not each of the following states is unsafe. If the state is safe, illustrate the order in which the threads may complete. Otherwise, illustrate why the state is unsafe.

- Available = (0, 3, 0, 1)
T2 -> 0200 -> available 0101
T2 -> release 3321 -> available 3422
T1 -> gets 1001 -> available 2421
T1 -> release 3211 -> available 5632
T3 -> gets 4102 -> available 1530
T3 -> release 4612 -> available 5(11)42
Neither T0 or T4 can finish with only 2D, they'd both need an additional D to finish, so deadlock

- Available = (1, 0, 0, 2)
T1 -> gets 1001 -> available 0001
T1 -> release 3211 -> available 3212
T2 -> gets 0200 -> available 3012
T2 -> release 3321 -> 6333
T3 -> gets 4102 -> available 2231
T3 -> release 4612 -> available 6843
T4 -> gets 2113 -> available 4730
T4 -> release 6325 -> available (10)(10)55
T0 -> gets 2103 -> available 8952
T0 -> release 5117 -> available (13)(10)69
T1 -> T2 -> T3 -> T4 -> T0

9) Suppose that you have coded the deadlock-avoidance safety algorithm that determines if a system is in a safe state or not, and now have been asked to implement the deadlock-detection algorithm. Can you do so by simply using the safety algorithm code and redefining Max_i = waiting_i
   - They are the same - You can just use bankers algorithm to determine if there is a safe sequence if there is no safe sequence in the current state we are deadlocked

11) Is it possible to have a deadlock involving only one single-threaded process? Explain your answer
    - You can't wait on something you already hold, so no wait and hold and therefore no circular wait and that was two of the deadlock criteria's which aren't available so no deadlocks

12) Draw the resource-allocation graph that illustrates deadlock from the program example shown in Figure 8.1 in Section 8.2.
    T1 has R1 wants R2 T2 has R2 wants R1
    ![[Pasted image 20230323153003.png]]


13) Assume that a multithreaded application uses only reader–writer locks for synchronization. Applying the four necessary conditions for deadlock, is deadlock still possible if multiple reader–writer locks are used?
    - Mutual Exclusion: At least one resource must be held in a non-sharable mode. Only a single process can write at one time - does not matter for read
    - Hold and Wait: A thread must be holding at least one resource and waiting to acquire additional resources held by other threads. In the case of reader-writer locks, this condition can be met if a thread is holding a read lock and waiting to acquire a write lock, or holding a write lock and waiting to acquire a read or write lock.
    - No Preemption: Resources cannot be preempted from threads; only the thread holding a resource can release it. In the case of reader-writer locks, this condition is met as only the thread holding the lock can release it.
    - Circular Wait: There must be a circular chain of two or more threads, each of which is waiting for a resource held by the next thread in the chain. In the case of reader-writer locks, this condition can be met if there are multiple threads waiting for a write lock, which can only be acquired by releasing all read locks. If the threads are holding read locks, they cannot proceed until all read locks are released, which can create a circular wait if one or more threads are waiting for a write lock.
    - So there are potential for deadlocks

14) The program example shown in Figure 8.1 of the book (2 mutex deadlock example) doesn’t always lead to deadlock. Describe what role the CPU scheduler plays and how it can contribute to deadlock in this program.
    - If the schedular pre-empts the first thread right after is has acquired first before it acquires second and then schedules thread 2 which then acquires second and then is pre-empted then thread 1 cannot proceed since it needs second which is held by thread 2 and thread 2 cannot proceed since it needs first which is held by thread 1

15)  Which of the six resource-allocation graphs shown in Figure below illustrate deadlock? For those situations that are deadlocked, provide the cycle of threads and resources. Where there is not a deadlock situation, illustrate the order in which the threads may complete execution.    ![[Pasted image 20230321231806.png]]
    a) 
        T2 -> release R2
        T3 -> gets R2 -> work -> release R2
        T1 -> release R1 -> gets R2 -> work -> releases R2
    b)
        T1 -> R3 -> T3 ->R1 -> T1 -- deadlock
    c)
        T3 -> release R2 & R1
        T1 -> gets R2 & R1
        T2 -> release R2 & R1
        T1 -> release R2 & R1
    d)
        T1 -> R2 -> T3 -> R1 -> T1 -- deadlock
        R1 -> T2 -> R2 -> T4 -> R1 -- deadlock
    e)
        T2 -> release R2
        T1 -> gets R2 -> work -> release R1 & R2
        T3 -> gets R2
        T4 -> gets R1
        T3 & T4 -> release R1 & R2
    f)
        T2 & T4 -> release R2 & R4
        T1 & T3 -> gets R2
        T1 -> release R1 & R2
        T3 -> gets R1 
        T3 -> release R1 & R2
        Error R2 has 2 instance but points to 3 threads??

16) Consider the version of the dining-philosophers problem in which the chopsticks are placed at the center of the table and any two of them can be used by a philosopher. Assume that requests for chopsticks are made one at a time. Describe a simple rule for determining whether a particular request can be satisfied without causing deadlock given the current allocation of chopsticks to philosophers.
    - A philosopher should not pick up a chopstick if it is the last one unless it itself holds a chopstick.

18) Consider the following snapshot of a system: ![[Pasted image 20230321231900.png]]
    Using the banker’s algorithm, determine whether or not each of the following states is unsafe. If the state is safe, illustrate the order in which the threads may complete. Otherwise, illustrate why the state is unsafe.
    - Available = (2, 2, 2, 3)
      T4 -> gets 2111 -> available 0112
      T4 -> release 3112 -> available 3224
      T0 -> gets 3114 -> available 0110
      T0 -> release 4316 -> available 4426
      T1 -> gets 2312 -> available 2114
      T1 -> release 2424 -> available 4538
      T2 -> gets 2411 -> available 2127
      T2 -> release 3651 -> available 5778
      T3 -> gets 1422 -> available 4356
      T3 -> release 2623 -> available 6979
      T4 -> T0 -> T1 -> T2 -> T3      
      
    - Available = (4, 4, 1, 1)
      T2 -> gets 2411 -> available 2000
      T2 -> release 3651 -> available 5651
      T4 -> gets 2111 -> available 3540
      T4 -> release 3112 -> available 6652
      T1 -> gets 2312 -> available 4340
      T1 -> release 2424 -> available 6764
      T3 -> gets 1422 -> available 5342
      T3 -> release 2623 -> available 7965
      T0 -> gets 3114 -> available 4851
      T0 -> release 4316 -> 8(11)67
      T2 -> T4 -> T1 -> T3 -> T0      
      
    - Available = (3, 0, 1, 4)
      Unsafe there is not enough B available for any process to make any progress

    - Available = (1, 5, 2, 2)
      T3 -> gets 1422 -> available 0100
      T3 -> release 2623 -> available 2723
      T4 -> gets 2111 -> available 0612
      T4 -> release 3112 -> available 3724
      T0 -> gets 3114 -> available 0610
      T0 -> release 4316 -> available 4926
      T1 -> gets 2312 -> available 2614
      T1 -> release 2424 -> available 4(10)38
      T2 -> gets 2411 -> available 2627
      T2 -> release 3651 -> available 5(12)78
      T3 -> T4 -> T0 -> T1 -> T2

19) A single-lane bridge connects the two Vermont villages of North Tunbridge and South Tunbridge. Farmers in the two villages use this bridge to deliver their produce to the neighbouring town. The bridge can become deadlocked if a northbound and a southbound farmer get on the bridge at the same time. (Vermont farmers are stubborn and are unable to back up.) Using semaphores and/or mutex locks, design an algorithm in pseudocode that prevents deadlock. Initially, do not be concerned about starvation (the situation in which northbound farmers prevent southbound farmers from using the bridge, or vice versa).
    - There is a single key once you want to go on the bridge you take the single key and take it with you over the bridge and put it on the other side of the bridge when you arrive
    - 