# Bound buffe problem
- n buffer, each can hold one item
- Semaphore mutex initialized to the value 1 
- Semaphore full initialized to the value 0
- Semaphore empty initialized to the value n
``` java
// The structure of the producer process
while (true) {
...
/* produce an item in next_produced */
...
wait(empty);
wait(mutex);
...
/* add next produced to the buffer */
...
signal(mutex);
signal(full);
}

// The structure of the consumer process
while (true) {
wait(full);
wait(mutex);
...
/* remove an item from buffer to next_consumed */
...
signal(mutex);
signal(empty);
...
/* consume the item in next consumed */
...
}
```

Readers-Writers problem
- Reader - can only read
- Writers- can read and write
- Multiple readers are allowed to read a certain data point a the same time if it is not currently being written to
- Only a single writer is allowed to write to a data point a the time
- Shared data
  - Data set 
  - Semaphore rw_mutex initialized to 1
  - Semaphore mutex initialized to 1
  - Semaphore read_count initialized to 0
``` java
// The structure of a writer process
while (true) {
	wait(rw_mytex);
	...
	/* writing is perfomred */
	...
	signal(rw_mutex);
}

// the structure of a reader process
while (true) {
	wait(mutex);
	read_count++;
	if (read_count == 1)
		wait(rw_mutex);
	signal(mutex);
	...
	/* reading is performed */
	...
	wait(mutex);
	read_count--;
	if (read_count == 0)
		signal(rw_mutex);
	signal(mutex);
}
```
#### Variations
- First variation – no reader kept waiting unless writer has permission to use shared object
- Second variation – once writer is ready, it performs the write ASAP
- Both may have starvation leading to even more variations
- Problem is solved on some systems by kernel providing reader-writer locks

Dining-Philosophers problem algorithm
- They spend their lives alternating thinking and eating
- Don't talk with the neighbour
- Tries to pick up fork to eat - needs two

### Example 
- 5 Philosophers
- Bowl of rice (shared data)
- Forks (Semaphore set to 1) 
- Every philosopher taking the fork to the right would result in a deadlock...

### Example Semaphore
```java
//The structure of Philosopher i:
while (true) {
	wait (chopstick[i] );
	wait (chopStick[ (i + 1) % 5] );
	/* eat for awhile */
	signal (chopstick[i] );
	signal (chopstick[ (i + 1) % 5] );
	/* think for awhile */
}
```
- Here there no is test to see if you can get a both chopsticks so you might get one and then never get the other since it could taken by another who is also waiting for another chopstick.

### Example monitor
``` java
monitor DiningPhilosophers {
	enum { THINKING; HUNGRY, EATING) state [5] ;
	condition self [5];
	void pickup (int i) {
		state[i] = HUNGRY;
		test(i);
		if (state[i] != EATING) self[i].wait;
	}
	void putdown (int i) {
		state[i] = THINKING;
			// test left and right neighbors
		test((i + 4) % 5);
		test((i + 1) % 5);
	}
	
	void test (int i) {
		if ((state[(i + 4) % 5] != EATING) &&
		(state[i] == HUNGRY) &&
		(state[(i + 1) % 5] != EATING) ) {
			state[i] = EATING ;
			self[i].signal () ;
		}
	}
	initialization_code() {
		for (int i = 0; i < 5; i++)
		state[i] = THINKING;
	}
}
```

- Each philosopher $i$ invokes operations pickup() and putdown() in the following sequence:
``` java
DiningPhilosophers.pickup(i);
/** EAT **/
DiningPhilosophers.putdown(i);
```
 - No deadlocks but starvation may occur

# Kernel synchronization
## Windows
- Spinlocks
- Dispatcher objects: mutex / Semaphore / Events (conditional variable) - Either in signalled-state (available) or non-signalled state (thread blocks)
- Timers used to notify threads of time expiration
![[Pasted image 20230308150302.png]]

## Linux
- Prior to version 2.6 interrupts could be disabled
- Semaphores
- atomic integers (set, add, sub, inc)
- spinlocks 
- reader writer versions of both 
- Single CPU system, spinlocks replaced by enabling and disabling kernel pre-emption

## POSIX API
- Mutex
``` java
// creating and initialzing the lock
# include <pthread.h>
pthread_mutex.t mutex;
/* create and initialize the mutex lock */
pthread_mutex_init(&mutex, NULL);

// Acquiring and releasing the lock
pthread_mutex_lock(&mutex);
/* critical section */

/* release the mutex lock */
pthread_mutex_unlock(&mutex);
```
- Semaphores (named - used by unrelated processes, unnamed only related processes)
- condition variables - associated with a POSIX mutex lock to provide mutual exclusion
- Used in UNIX, Linux, MacOS

# Java synchronization
- 7.27 -> 7.39

# Transactional memory
- Leaves the thinking to the OS and not the user
- Hardware to allow for a group of load and store to be executed atomically.
- Memory transaction sequence of read-write operations to memory that are performed atomically. A transaction can be completed by adding atomic{S} which ensure statements in S are executed atomically.
- Call back - if the OS can't handle it and breaks down the user is prompted to fix it.