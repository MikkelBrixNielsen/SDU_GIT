1) In Section 6.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized
   - If there isn't any interrupts then the local incrementations cannot be updated and lacks behind since the interrupts incrementing the watch are occurring
   -  Don't disable interrupts and if they need to be disabled do it for short amounts of time

2) What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer
   - Busy waiting is when a process is stuck in a while loop while wating for some condition to change. Also called a spin lock 
   - Busy waiting can be avoided to some degree by having a process go to sleep and wait for some other process to wake it up when the condition / resource it is waiting for becomes available this can be done with e.g. a monitor / semaphore or mutex, but when you only have to wait for a short while it does not makes sense to not busy wait

3) Explain why spinlocks are not appropriate for single-processor systems yet are often used in multiprocessor systems.
   - Spin locks are not appropriate for single core systems since a spin lock would keep the only available core busy not allowing any other work to be done. For the first process to continue another needs to change the condition to two context switches would be needed and the first process should just sleep in the first place.
   - Spin locks can be used in multicore systems when one expects the condition of the lock to be changed soon instead of having to do context switching

4) Show that, if the `wait()` and `signal()` semaphore operations are not executed atomically, then mutual exclusion may be violated.
   - If A executes a wait() operation and is pre-empted by the scheduler before it can complete the operation, B could execute a signal() operation and increment the value of the semaphore. When A resumes execution, it will complete its wait() operation, decrement the value of the semaphore, and access the shared resource even though B has already signalled and incremented the semaphore value. Both processes will be accessing the shared resource simultaneously.
   - if a process is pre-empted at the while part of the wait after it has seen s == 0 and another process comes sees that s == 0 as well both will access the shared resources at the same time.

5) Illustrate how a binary semaphore can be used to implement mutual exclusion among n processes.
   - by using a semaphore since the wait and signal operations are atomic an arbitrarily amount of processes can try to use them at a time, so P1 comes and waits for the resource then decrements the semaphore to 0 all other processes Pn that comes after P1 will wait until P1 signals it is done with the resource increments the semaphore whereafter a single other of the n waiting processes can acquire the shared resource decrement the semaphore and so on...

6) Race conditions are possible in many computer systems. Consider a banking system that maintains an account balance with two functions: `deposit(amount)` and `withdraw(amount)`. These two functions are passed the amount that is to be deposited or withdrawn from the bank account balance. Assume that a husband and wife share a bank account. Concurrently, the husband calls the `withdraw()` function, and the wife calls `deposit()`. Describe how a race condition is possible and what might be done to prevent the race condition from occurring.
   - if both get the amount of money stored in the account, 100, to do their respective deposit or withdraw then if the withdraw(100) happens it would update the amount to e.g. 0 but deposit(100) also had the amount 100 and then updates the amount in the bank account to 200
   - How to fix use mutual exclusion e.g. semaphore.

7) The pseudocode below illustrates the basic `push()` and `pop()` operations of an array-based stack. Assuming that this algorithm could be used in a concurrent environment, answer the following questions:
``` java
 push(item) {
     acquire();
     if (top < SIZE) {
         stack[top] = item;
         top++;
     }
     else
         ERROR
             release();
 }
 pop() {
     acquire();
     if (!is empty()) {
         top--;
         item = stack[top];
         release();
         return item;
     }
     else
         ERROR
             release();
 }
 is empty() {
     if (top == 0)
         return true;
     else
         return false;
```
- What data have a race condition?
  - Top, Size, stack
- How could the race condition be fixed?
  - By making acquire giving some sort of lock to the process calling so that all other processes get blocked from accessing when another process has acquired the stack

8) The following program example can be used to sum the array values of size N elements in parallel on a system containing N computing cores (there is a separate processor for each array element):
   ```java 
    for j = 1 to log 2(N) {
     for k = 1 to N {
         if ((k + 1) % pow(2,j) == 0) {
           values[k] += values[k - pow(2,(j-1))]
         }
     }
 }
```
This has the effect of summing the elements in the array as a series of partial sums, as shown in the figure below.
![[Pasted image 20230313174630.png]]
After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.
- There is race conditions if one process reaches a layer where the value hasn't been computed by a  process from a previous layer yet, which would result in not getting the summed value for its own summation.

9) One approach for using `compare_and_swap()` for implementing a spinlock is as follows:
   ``` java 
void lock spinlock(int *lock) {
	while (compare_and_swap(lock, 0, 1) != 0)
	    ; /* spin */
}
```
A suggested alternative approach is to use the “compare and compareand-swap” idiom, which checks the status of the lock before invoking the compare_and_swap() operation. (The rationale behind this approach is to invoke compare_and_swap() only if the lock is currently available.)
``` java
 void lock_spinlock(int *lock) {
     while (true) {
         if (*lock == 0) {
             /* lock appears to be available */
             if (!compare_and_swap(lock, 0, 1))
                 break;
         }
     }
 }
```
Does this “compare and compare-and-swap” idiom work appropriately for implementing spinlocks? If so, explain. If not, illustrate how the integrity of the lock is compromised.
- Since the first compare part of compare and compare-and-swap does not do anything but refrain from activating the compare-and-swap part when the lock seems to be not available so in the end they do the same thing

10) The first known correct software solution to the critical-section problem for two processes was developed by Dekker. The two processes, P0 and P1 , share the following variables:
``` java
 boolean flag[2]; /* initially false */
 int turn;
```
The structure of process Pi (i == 0 or 1) in Dekker’s algorithm is shown below. The other process is Pj (j == 1 or 0).
```java
 while (true) {
     flag[i] = true;

     while (flag[j]) {
         if (turn == j) {
             flag[i] = false;
             while (turn == j)
                 ; /* do nothing */
             flag[i] = true;
         }
     }

     /* critical section */

     turn = j;
     flag[i] = false;

     /* remainder section */
  }
```
Prove that the algorithm satisfies all three requirements for the critical-section problem.
- Mutual exclusion: The while loop checking the flag for the other process and while loop checking for the others turn ensures that no two process can be in their CS at the same time and only when one process is done does it itself give the turn to the other process.
  
- Progress: It should be some ones turn it is either P1's or P2's turn to do something otherwise if both are doing nothing that would suggest that no more work needs to be done.
   
- Bound waiting: You will always have to wait the time the other process takes in its CS there is no other processes that can pre-empt the waiting process or the executing process in this code so one or the other will always be making progress and at some point presumably finish and give its turn to the other process

11) Consider how to implement a mutex lock using the `compare_and_swap()` instruction. Assume that the following structure defining the mutex lock is available:
``` java 
typedef struct {
     int available;
} lock;
```
- The value (available == 0) indicates that the lock is available, and a value of 1 indicates that the lock is unavailable. Using this struct, illustrate how the following functions can be implemented using the compare_and_swap() instruction:
  - void acquire(lock *mutex)
  - void release(lock *mutex)
- Be sure to include any initialization that may be necessary.
``` java
typedef struct {
    int available;
} lock;

int expected = 0;

void acquire_lock(lock *l) {
    while (!compare-and-swap(&l->available, 0, 1)) {
        // wait until lock is released
    }
    return;
}

void release_lock(lock *l) {
    l->available = 0;
    return;
}
```


12) Assume that a system has multiple processing cores. For each of the following scenarios, describe which is a better locking mechanism—a spinlock or a mutex lock where waiting processes sleep while waiting for the lock to become available:
    - The lock is to be held for a short duration.
      - Just seeeeend it in a spinlock to omit context switches
    - The lock is to be held for a long duration.
      - Mutex lock
    - A thread may be put to sleep while holding the lock
      - Mutex lock since if a thread is put to sleep it would probably be sleeping for a longer while otherwise it wouldn't make sense to sleep otherwise spin locking would hog resources

13) A multithreaded web server wishes to keep track of the number of requests it services (known as hits). Consider the two following strategies to prevent a race condition on the variable hits. The first strategy is to use a basic mutex lock when updating hits:
    ``` java
     int hits;
     mutex lock hit lock;
     hit lock.acquire();
     hits++;
     hit lock.release();
    ```
    A second strategy is to use an atomic integer:
    ``` java
     atomic t hits;
     atomic inc(&hits);
    ```
    Explain which of these two strategies is more efficient.
    - It is better to use atomic since it does not have the overhead of acquiring and releasing a lock

14) Servers can be designed to limit the number of open connections. For example, a server may wish to have only N socket connections at any point in time. As soon as N connections are made, the server will not accept another incoming connection until an existing connection is released. Illustrate how semaphores can be used by a server to limit the number of concurrent connections.
``` C
#include <semaphore.h>

int max_connections = N;
int current_connections = 0;
sem_t connection_semaphore;

void server_init() {
    sem_init(&connection_semaphore, 0, max_connections);
}

void handle_request() {
    sem_wait(&connection_semaphore);  // Wait until a connection is available
    ++current_connections;
    // Handle request...
    --current_connections;
    sem_post(&connection_semaphore);  // Release the connection
}
```

```C
// initialize semaphore, s, counting variable to be n 
wait(s);
open();
...
close();
signal(s);
```


15) Describe how the `signal()` operation associated with monitors differs from the corresponding operation defined for semaphores.
- A monitors signal will not have an effect on subsequent processes executing a wait. If no process is wating when a signal is executed it will simply be ignored where as if a signal is executed for a semaphore when there are no processes waiting the semaphore value will be incremented.