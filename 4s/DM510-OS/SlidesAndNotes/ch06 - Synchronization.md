# Background
- Processes can execute concurrently 
  - may be interrupted at any time, partially completing execution
- Concurrent access to shared data may result in data inconsistency
- Maintaining data consistency requires mechanisms to ensure the orderly execution of cooperating processes
- re-entrant (multi-instance) - code is **a reusable routine that multiple programs can invoke, interrupt, and reinvoke simultaneously**.

# Race condition
- When the OS makes a context switch after process (A) has called i++ to a counting variable that has value 5 which becomes 6. This is not written to memory then process (B) calls i++ reads from memory that i = 5 increments it and exits so memory has 6. Now process (A) writes 6 to memory, which changes nothing and 6 is the result even though it should be 7.
- Two processes A and B are creating child processes concurrently using fork() this might create a race condition on the kernel variable `next_available_pid` unless there is mutual exclusion a child from A can be assigned the same id as a child from B.

# Critical section problem
- Considering n processes 
- Each process has a critical section segment of code
  - may be changing shared data structures, writing to a file, changing shared varaibles
  - One process in critical section no other process may be in critical section
- The problem is to solve this
- Process must ask permission to enter critical section in entry section, may follow critical section with exit section, then remainder section.
``` java
do {
# Entry section code
	# Critical section code
# exit section
	# remainder section
} while (True);
```
# Solution to critical-Section problem
- Mutual exclusion 
  - If process Pi is executing in its critical section, then no other processes can be executing in their critical sections
- Progress
  - If no process is executing in its critical section and there exist some processes that wish to enter their critical section, then the selection of the processes that will enter the critical section next cannot be postponed indefinitely
- Bounded waiting
  - A bound must exist on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted
  -  Assume that each process executes at a nonzero speed
  - No assumption concerning relative speed of the n processes

# Critical-section handling in OS
- Two approaches depending on if kernel is pre-emptive or non-pre-emptioen
- Pre-emptive allows pre-emption of process when running in kernel mode
- Non-pre-emptive solution runs until exits kernel mode, blocks, or voluntarily yields CPU
- Essentially free of race conditions in kernel mode

# Peterson's solution
- Two process solution 
- Assume that the load and store machine-language instructions are atomic - cannot be interrupted
- The two processes share two variables
  - int turn;
  - boolean flag[2]
- The variable turn indicates whose turn it is to enter the critical section 
- The flag array is used to indicate if a process is ready to enter the critical section flag[i] = true implies that process $P_i$ is ready.
![[Pasted image 20230228163232.png]]
Provable that the three CS requirement are met: 
1. Mutual exclusion is preserved Pi enters CS only if: either flag[j] = false or turn = i 
2. Progress requirement is satisfied 
3. Bounded-waiting requirement is met

- Although useful for demonstrating an algorithm, Peterson’s Solution is not guaranteed to work on modern architectures. 
- Understanding why it will not work is also useful for better understanding race conditions.
- To improve performance, precessors and/or compilers may reorder operations that have no dependencies
- For single-threaded this is ok as the result will always be the same 
- For multithreaded the reordering may produce inconsistent or unexpected results!

### Example 
Assume the shared variables are:
Boolean flag = false;
int x = 0;

Thread 1 performs:
while (!flag) { // busy waiting; }
print(x);

Thread 2 performs:
x = 100;
flag = true;

The expected result would be:
- Thread 1 will perform busy waiting until thread 2 sets the flag to true, which it does after setting x = 100 so when the flag becomes true thread 1 will stop busy wating and print x, which is 100

- Unless the operations for thread 2 is reordered to be
  flag = true 
  x = 100
  If this occurs the output may be 0.
  - The effects of instruction reordering in Peterson's solution  ![[Pasted image 20230228164555.png]]
- This would allow both processes to be in their critical section at the same time

# Synchronization hardware
- Systems provide hardware support for implementing CS code
- Uniprocessors - could disable interrupts
  - Currently running code would execute without pre-emption
  - Generally too inefficient on multiprocessor systems not scalable
- Put synchronization into compiler, hardware or somewhere else so that the programmer does not have to deal with it
- 3 types of hardware suppor 


# Memory Barriers
- Memory model - Memory guarantees a PC architecture makes to an application
- Strongly / strictly ordered - Memory modification of one processors must be seen by all others (not really possible)
- Weakly / sequential ordered - Memory modification of one processor may not be immediately visible to all other processors
- Memory barrier - Instruction that forces changes in memory to be propagated to all other processes 


# Hardware instruction
Special hardware instructions that allow us to either test-and-modify the content of a word, or two swap the contents of two words atomically (uninterruptible)

### Test-and-Set (Instruction)
  ![[Pasted image 20230307124827.png]]
  - Atomic assembly instruction that cannot be interrupted
  - Returns the original value of passed parameter
  - Set the new value of passed parameter to true
#### CS-problem solution using Test-and-Set (lock = 0 @ start)
``` java
do {
while (test_and_set(&lock))
; /* do nothing */
/* critical section */
lock = false;
/* remainder section */
} while (true);
```

# Compare-and-Swap
![[Pasted image 20230307125237.png]]
- Executes atomically 
- Return the original value passed parameter value
- Set the variable value the value of the passed parameter new_value only if $*$value == expected is true. That is the swap takes place only under this condition.
#### CS-problem solution using compare-and-swap (lock = 0 @ start)
![[Pasted image 20230307125647.png]]

#### Bounded-waiting mutual exclusion with compare-and-swap
![[Pasted image 20230307125751.png]]

# Atomic variables
- Instructions like compare-and-swap used as building blocks for other synchronization tools
- One tool is atomic variables - provides atomic (uninterruptible) update on basic data types (ints, bools, etc...)
- E.g., the increment() operation on the atomic variable sequence ensures sequence is incremented without interruption: increment(&sequence)
- Increment implementation
``` java
void increment(atomic_int *v) {
	int temp;
	do {
		temp = *v;
	}
	while (temp != 
	(compare_and_swap(v,temp,temp+1));
} 
```
# Semaphores / counting semaphores
- Only wants a certain number of processes, n, doing something at one time, so if more than n processes are doing that thing other processes will have to wait for one of the executing processes to finish before that one can start execution.
- Only accessed via two indivisible (atomic) operations
- wait() and signal() - Originally p() v()
  ``` java
wait(S) { // S integer variable
	while (S <= 0) ; 
		// busy wait 
	S--; 
}

signal(S) { 
	S++; 
}
```
- Counting semaphore - Integer value can range over an unrestricted doamin
- Binary semaphore - integer value can range only between 0 and 1 (Basically mutex lock)
- Must guarantees that no two processes cam execute wait() and signal() on the same semaphore at the same time
- Thus, wait and signal are placed in critical section
- Could have busy waiting 
- Implementation code is short 
- Little busy waiting if CS rarely occupied 
- Note that applications may spend lots of time in critical sections and therefore this is not a good solution

### Example
- Consider P1 and P2 that require S1 to happen before S2
  ``` java
  // Create a semaphore “synch” initialized to 0
	P1:
		S1;
		signal(synch);
	P2:
		wait(synch);
		S2;
```
- Can implement a counting semaphore S as a binary semaphore

# Semaphore implementation with no busy waiting
- Waiting queue associated
- Each queue entry has two data items
  - Value (of type integer)
  - Pointer to next record in the list
- Two Operations
  - block - Process invoking the operation on the appropriate waiting queue
  - wakeup - remove one of processes in the waiting queue and place it in the ready queue

### Problems
- Incorrect use of semaphore operations
  - Signal (mutex) ... wait (mutex)
  - wait (mutex) ... wait (mutex)
  - Omitting of wait (mutex) and/or signal (mutex)
  - These (and others) are examples of what can occur when semaphores and other synchronization tools are used incorrectly

### Implementation
  ``` java
typedef struct {
	int value;
	struct process *list;
} semaphore;

wait(semaphore *S) {
	S->value--;
	if (S->value < 0) {
		add this process to S->list;
	block();
	}
}

signal(semaphore *S) {
	S->value++;
	if (S->value <= 0) {
		remove a process P from S->list;
	wakeup(P);
	}
}
```
# Mutex Locks
- Binary version of Semaphores. Only a single process can do any one thing at one time, so if another process want to do that things as well it has to wait for the first process to finish
- Can be spin-/non-spin locking locks
- First acquires the lock then releases it (Boolean var)
- acquire and release must be atomic instructions (compare-and-swap, test-and-set)
  ``` java
acquire() {
	while (!available); 
		/* busy wait */
	available = false;;
} 

release() { 
	available = true; 
}
```
- requires busy waiting
- the lock is called a spinlock
``` java
while (true) {
	|acquire lock|
	critical section
	|release lock|
	remainder section
} 
```
# Monitors
- High-level abstraction that provide convenient and effective mechanism for process synchronization
- Abstract data type, internal variables only accessible by code within the proccedure
- Only one process may be active within the monitor at a time 
- Pseudocode syntax of a monitor
``` java
monitor monitor-name {
	// shared variable declarations
	function P1 (…) { …. }
	function P2 (…) { …. }
	function Pn (…) {……}
	initialization code (…) { … }
}
```
### Schematic view 
![[Pasted image 20230307134411.png]]

# Condition variables
- Condition variables are **synchronization primitives that enable threads to wait until a particular condition occurs**. 
- Condition variables are user-mode objects that cannot be shared across processes. 
- Condition variables enable threads to atomically release a lock and enter the sleeping state
- x.wait() - process that invokes operation is suspended until x.signal()
- x.signal - resumes one of processes (if any) that invoked x.wait()
- No x.wait(), x.signal() has no effect 

# Monitor with condition variables 
![[Pasted image 20230307134543.png]]
- All shared data now has queues associated with the conditions x, y
- Several processes queued on condition variabl x, and x.signal() executedm which process should be resumed?
  - Different strategies FCFS frequently not adapted
  - Conditional-wait construct of the from x.wait(c)
    - c is priority number
    - Processes with lowest number (highest priority) scheduled next

# Condition variables choices
- P invokes x.signal() and Q is suspended x.wait()
  - Q and P cannot execute in parallel. If Q is resumed P must wait and vice versa
  - Options
    - Signal and wait - P waits until Q leaves the monitor or Q wait for another condition
    - Signal and continue Q waits until P either leaves the monitor or wait for another condition
    - Both have pros and cons – language implementer can decide
    - Monitors implemented in Concurrent Pascal compromise
      - P executing signal immediately leaves the monitor, Q is resumed
  - Implemented in other languages including Mesa, C#, Java

### Monitors implementation
#### using semaphores
``` java
semaphore mutex; // (initially = 1)
semaphore next; // (initially = 0)
int next_count = 0;

wait(mutex); 
	… 
	body of F; 
	… 
if (next_count > 0) 
	signal(next) 
else 
	signal(mutex);
```
- Mutual exclusion in a monitor is ensured
#### Condition variables
``` java
semaphore x_sem; // (initially = 0)
int x_count = 0;

void x.wait() {
	x_count++;
	if (next_count > 0)
		signal(next);
	else
		signal(mutex);
	wait(x_sem);
	x_count--;
	
void x.signal() {
	if (x_count > 0) { 
		next_count++; 
		signal(x_sem);
		wait(next); 
		next_count--; }
	}
}
```
## Single resource allocation 
- Allocate single resource among competing processes using priority numbers that specify the maximum time process plans to use the resource 
``` java
R.acquire(t);
      ... 
   access the resource;
      ...
R.release(t);
```

# Monitor to allocate single resource
``` java
monitor ResourceAllocator {
	boolean busy;
	condition x;
	void acquire(int time) {
		if (busy)
			x.wait(time);
			busy = true;
	}
	
	void release() {
		busy = FALSE;
		x.signal();
	}
	initialization code() {
	busy = false;
	}
}
```

# Liveness
- Live event - an event that no matter where in the system / code you are you can reach that point again
- If there is a part in your code that cannot be reach no matter what you do it is not live
- Going into a scenario where an previous event cannot be executed again Quazi life????????
- Refers to a set of properties an OS must adhere to to ensure that processes can make progress
### Deadlock 
 - two or more processes are waiting indefinitely for an event that can be cause by only one of the waiting processes
![[Pasted image 20230307143835.png]]
- P0 executes wait(s) get interrupted then P1 executes wait(Q) and tries to execute wait(s), which P0 already has so P1 will wait for S to be release to progress and P0 will wait for Q to be released resulting in a deadlock since the signal() operations will not be executed
- Starvation - process never removed from semaphore queue where it is suspended
- Priority inversion - Scheduling problem when lower priority process holds a lock needed by higher-priority process (solved by priority inheritance)

# Priority inheritance
- Allows the priority of the highest thread waiting to access a shared resource to be assigned to the thread currently using the resource. Thus, the current owner of the resource is assigned the priority of the highest priority thread wishing to acquire the resource.

- Prevents the scenario where three processes P1, P2, and P3. P1 has the highest priority, P2 the next highest, and P3 the lowest. Assume a resource P3 is assigned a resource R that P1 wants. Thus, P1 must wait for P3 to finish using the resource. However, P2 becomes runnable and pre-empts P3. What has happened is that P2 - a process with a lower priority than P1 - has indirectly prevented P3 from gaining access to the resource.