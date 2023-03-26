# Exercises

1. What output will be at LINE A for this program:
``` C
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int value = 5;
int main()
{
  pid_t pid;
  pid = fork();
  if (pid == 0) {
    /* child process */
    value += 15;
    return 0;
  }
  else if (pid > 0) {
    /* parent process */
    wait(NULL);
    printf("PARENT: value = %d",value); /* LINE A */
    return 0;
  }
}
```
- Since fork creates an exact copy of the parent process in different memory space actions performed by one will not affect the other, so the result will be 5.

2. How many processes are created by this program:
``` c
#include <stdio.h>
#include <unistd.h>
int main()
{
  /* fork a child process */
  fork();
  /* fork another child process */
  fork();
  /* and fork another */
  fork();
  return 0;
}
```
Parent ($2^n$, where n = number of forks)
|---> #1 child
	|---> #1.1 child
		|---> #1.1.1 child
	|---> #1.2 child
|---> #2 child
	|---> #2.1 child
|---> #3 child 

Depends, if there are no available pIDs any of the calls to fork can fail, so 1-7 children will be created and there can be a total of 1-8 processes.

3. Original versions of Apple’s mobile iOS operating system provided no means of concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.
   1) Having to share resources between concurrent processes. 
   2) Testing and debugging becomes hell
   3) Making sure no two processes overwrite each others memory 
   4) race conditions 
   5) interprocess communication
   6) process scheduling / context switching
   7) general complexity increase

4. Describe what happens when a context switch occurs if the new context is already loaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?
   - CPU just needs to be notified of witch register it needs to be switched to, which is the one where the instruction was just loaded into
   - The one stored in memory must be switched with the one stored in a register. The one in the register is put into memory the memory is flushed and the one originally in memory is put into the register.

5. When a process creates a new process using the `fork()` operation, which of the following states is shared between the parent process and the child process?    a) stack    b) heap    c) shared memory
   
   Only shared memory is shared between a child and a parent since when a child is created it gets placed into its own memory space with a new copy of the stack and heap. - Cant have several processes in a process block

6. Consider the “exactly once”-semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a network problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.
   - The sequence of messages in this algorithm is as follows:
     1.  The client sends an RPC request to the server with a unique sequence number / marked time stamp.
     2.  The server receives the request, checks the sequence number, and processes the request if it has not seen that sequence number / time stamp before.
     3.  The server sends an ACK message back to the client with the same sequence number / time stamp.
     4.  The client receives the ACK message and removes the request from its request buffer.

   - if the ACK message is lost, the "exactly once" semantic can be preserved using sequence numbers / marked time stamps if the server only processes a request for not seen sequence number / time stamp.

7. Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPCs?
   - To guarantee "exactly once" semantic for RPC execution in a distributed system susceptible to server failure, the system needs to ensure idempotency, assign unique sequence numbers to requests, send acknowledgments, set timeouts and retries, and use persistent storage for recording executed requests and state. This ensures that duplicate requests are ignored, requests are not lost due to network failures, and the system can recover from failures and execute RPC requests consistently.
   - Could also have a log and some none volatile storage so it can check its log to see what it has done needs to do and fetch the necessary information form the memory 

8. Describe the actions taken by a kernel to context-switch between processes.
   a) Reply to clock interrupt, save program counter, stack point, registers, allocated memory and gives charge to kernel clock interrupt handler 
   
   b) The clock interrupt handler gives control to the operating System call upon the scheduler to decide the next process that has to be executed. 
   
   d) The OS takes the status of the next process from its Process Control Block and fix up the registers. 

9. how many processes are created by this program:
``` c
#include <stdio.h>
#include <unistd.h>
int main()
{
  int i;
  for (i = 0; i < 4; i++)
     fork();
  return 0;
}
```
$2^n$ processes will be created. So, $2^4 = 16$

10. Identify the values of pid at lines A , B , C , and D . (Assume that the actual pids of the parent and child are 2600 and 2603, respectively.)
``` C
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
  pid t pid, pid1;
  /* fork a child process */
  pid = fork();
  if (pid < 0) {
     /* error occurred */
     fprintf(stderr, "Fork Failed");
     return 1;
  }
  else if (pid == 0) {
     /* child process */
     pid1 = getpid();
     printf("child: pid = %d",pid);   /* A */
     printf("child: pid1 = %d",pid1); /* B */
  }
  else {
     /* parent process */
     pid1 = getpid();
     printf("parent: pid = %d",pid);   /* C */
     printf("parent: pid1 = %d",pid1); /* D */
     wait(NULL);
  }
  return 0;
```
LINE A: 0 - since to even get into the if pid = 0
LINE B: 2603 - since the current process calling is the child
LINE C: 2603 - since fork returns the pid of the child
LINE D: 2600 - since the current process calling is the parent

11. Give an example of a situation in which ordinary pipes are more suitable than named pipes and an example of a situation in which named pipes are more suitable than ordinary pipes.
    - Ordinary pipes are typically used for communication between two related processes e.g., if a process needs to send data to another process it created only goes one way from parent to child, so when using fork - Parent / child relationship. (one-to-one)
    - Named pipes are better suited for multi-processes-communication, or where communication needs to be bi-directional, since they have a fixed location in the file system and can be accessed by all with permission e.g., client server communication a server could have a named pipe where it receives client requests. (one-to-many / many-to-one)

12. Using the program shown below, explain what the output will be at lines X and Y
```C
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 5
int nums[SIZE] = {0,1,2,3,4};
int main()
{
  int i;
  pid t pid;
  pid = fork();
  if (pid == 0) {
     for (i = 0; i < SIZE; i++) {
       nums[i] *= -i;
       printf("CHILD: %d ",nums[i]); /* LINE X */
     }
  }
  else if (pid > 0) { wait(NULL);
     for (i = 0; i < SIZE; i++)
       printf("PARENT: %d ",nums[i]); /* LINE Y */
  }
  return 0;
}
```
LINE X: 
	"CHILD: 0", 
	"CHILD: -1", 
	"CHILD: -4", 
	"CHILD: -9", 
	"CHILD: -16"
LINE Y:
	"PARENT: 0", 
	"PARENT: 1", 
	"PARENT: 2", 
	"PARENT: 3", 
	"PARENT: 4"


13. What are the benefits and the disadvantages of each of the following? Consider both the system level and the programmer level.
- Synchronous communication
      - Benefits:
        - The sender knows that the receiver has received the message.
        - The sender can wait for the receiver to respond before continuing with other tasks.
        - Simpler to implement for applications with communication between two processes.
        - Easier to implement as a programmer
    
    - Disadvantages:
        - Receiver slow responds or slow network, sender may block - reduces overall performance.
        - Difficult to implement for applications with communication between multiple processes.
        - Big deal to implement in OS
- Asynchronous communication
    - Benefits:
      - The sender does not need to wait for the receiver to respond before continuing with other tasks, which can increase overall performance.
      - It is easier to implement for some applications, especially when the communication is between multiple processes.
      - Easier to implement in OS
    
    - Disadvantages:
       - The sender does not know whether the receiver has received the message or not.
      - The receiver may need to buffer messages, which can increase memory usage and introduce latency.
      - It may be more difficult to implement for some applications, especially when the communication is between two processes.
      - Big deal to implement as a programmer 
- Automatic buffering
   - Benefits:
     - The system automatically manages the buffer, which can simplify programming.
     - The system can optimize buffer usage for maximum performance.

   - Disadvantages:
     - The system may use more memory than necessary to buffer messages.
     - The programmer may not have control over when messages are buffered, which can introduce latency.
- Explicit buffering   
  - Benefits:
    - The programmer has control over when messages are buffered, which can reduce latency.
    - The programmer can optimize buffer usage for specific application needs.

  - Disadvantages:
    - The programmer must manage the buffer, which can be complex.
    - The programmer may not optimize buffer usage for maximum performance.
- Send by copy
  - Benefits:
    - The receiver cannot modify the original message.
    - The system can optimize message delivery.

  - Disadvantages:
    - Copying large messages can be expensive in terms of memory and CPU usage.
    - Sending large messages can introduce latency.
- Send by reference
  - Benefits:
    - Sending large messages can be more efficient since the message is not copied.
    - The receiver can modify the original message, which can be useful in some cases.

  - Disadvantages:
    - The receiver may accidentally or intentionally modify the original message, which can cause errors.
    - The system may need to manage shared memory, which can be complex.
- Fixed-sized messages
  - Benefits:
    - The system can optimize message delivery for fixed-size messages.
    - The programmer can optimize memory usage.

  - Disadvantages:
    - Fixed-size messages may not be appropriate for all applications.
    - The programmer may need to add padding to messages, which can waste memory.
- Variable-sized messages
  - Benefits:
    - The programmer can send messages of varying sizes, which can be useful in some cases.
    - The system can optimize memory usage by only allocating the necessary amount of memory.

  - Disadvantages:
    - The system may need to allocate and deallocate memory frequently, which can reduce performance.
    - The system may need to use a variable-length header, which can be more complex.

14. What is the following bpftrace one-liner doing? What is the output you would expect? 
`bpftrace -e 'tracepoint:raw_syscalls:sys_enter { @ = count(); } interval:s:1 { print(@); clear(@); }'`
- Tracepoint captures the entry of a syscall, when a syscall is executed count() is incremented (the @ variable)
- Interval is how often it should execute the print
- The expected output of this command would be the number of system calls made by processes on the system, printed once per second. Each line of output would show the count of system calls made during the previous second.

15. What are the probes, what are the filters, and what are the actions of the bpftrace script? What happens on execution and what is the output of the program?
``` C
BEGIN { @i = 10; }
interval:s:1
/@i > 0/
{
   @i--;
   printf("Tick %d\n",@i);
}

interval:s:1
/@i == 0/
{
   printf("blastoff!");
   exit();
}
```
Probes: BEGIN and everything in { }
Filters: the two checks for the value of i (/@i > 0/ and /@i == 0/)
Execution: the program will print "TICK i" until i reaches 0, where it will print "blastoff!" and exit.

``` C
dtrace:::BEGIN
{
   i = 10;
}

profile:::tick-1sec
/i > 0/
{
   trace(i--);
}

profile:::tick-1sec
/i == 0/
{
   trace("blastoff!");
   exit(0);
}
```
Probes: dtrace:::BEGIN
Filters:  the two checks for the value of i (/i > 0/ and /i == 0/)
Execution: the program will trace i until it is no longer greater than 0, where the program will trace "blastoff!" and exit.


# C programming
Analyse the following C program(s), and discuss the code given below wrt. correctness, readability and efficiency of the code. Is the first version more efficient than the naïve recursive approach (2nd version) to compute the power of a number?
``` C
/* Version 1 */
#include <stdio.h>
#include <inttypes.h>

float power(float x, uint32_t exp);
float power(float x, uint32_t exp)
{
  float result;
  /* base case */
  if (exp == 0)
    return 1.0;

  result = power(x, exp >> 1);
  result = result * result;

  if (exp & 1)
    result = result * x;
  return result;
}

int main(int argc, char **argv)
{
  float p;
  p = power(10.0, 5);
  printf("p = %f\n", p);
  return 0;
}
```

``` C
/* Version 2 */
#include <stdio.h>
#include <inttypes.h>

float power(float x, uint32_t exp)
{
  /* base case */
  if (exp == 0) {
    return 1.0;
  }
  /* recursive case */
  return x*power(x, exp - 1);
}

int main(int argc, char **argv)
{
  float p;
  p = power(10.0, 5);
  printf("p = %f\n", p);
  return 0;
```