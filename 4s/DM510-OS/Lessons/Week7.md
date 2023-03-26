1) What is the purpose of system calls?
   - System calls are an interface used by applications to request the OSes kernel to perform some task or provide some information, and the kernel implements the request and returns the results to the application.
   
2) What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system
   - FORK!!!!, execute or clone (more fine grain control)
   
3) What is the purpose of system programs
   - To provide a convenient environment for program development and execution, so we don't have to write our own program to e.g., rename a file:
     - File manipulation
     - Status information (sometimes stored in a File modification)
     - Programming language support
     - Program loading and execution
     - Communications
     - Background services
     - Application programs
     - (most users view of the OS is defined by system programs and not system calls)
     - provides basic functionality and is often included in the OS.
   
4) What is the main advantage of the layered approach to system design? What are disadvantages of the layered approach?
   - Advantage of the layered approach is the is its modularity, abstraction, portability and improves security
   - Disadvantages of the layered approach overhead, complexity, implementation difficulties due to layer interaction.

5) List five services provided by an OS, and explain how each creates convenience for users. In which case would it be impossible for user-level programs to provide these services?
   - File system / manipulation: User-level-programs would need to interact with the underlying hard disk, not possible without the support of the OS.
   - Programming language support: User-level programs do not have access to the underlying system libraries and APIs required to support the execution of code.
   - Program loading and execution: User-level-programs do not have the privilege to be able to load and execute programs.
   - Interposes Communication: Difficult for user-level programs since because it would have to implement the low-level communication mechanisms and handle the complexities
   - Background services: Requires a high level of privilege and control over the OS and its resources, which user-level programs don't often have.
   
6) How could a system be designed to allow a choice of OS from which to boot? What would the bootstrap program need to do?
   - A system could be designed such that is bootstrap loader is capable of letting you select between different OSes (like GRUB) from multiple disks, versions or kernel options. This could be done in a single storage devices system by partitioning that one drive and giving each wanted OS is own partition. The bootstrap loader can detect this a let you choose between which OS to boot into.
   
7) What are the advantages and disadvantages of using the same system-call interface for manipulation both files and devices
   - Advantages include: Consistency - having only use consistent system calls can make it easier for the user to learn, portability - only having to port one set of syscalls for multiple actions  and simplicity - reduces the complexity of the OS and the amount of code having to be written and maintained. 
   - The disadvantages include: Complexity - must handle different behaviour and requirements, inefficiency - OS must handle the different behaviour and requirements of each type of resource can causes slow down, confusion for the user how should it be used for each type.
   
8) Describe why android uses ahead-of-time (AOT) rather than just-in-tim (JIT) compilation
   - Device compatibility: AOT compiled code can be generated for specific device architectures, making it easier to support a wide range of Android devices with different hardware configurations.
   - Reliability: AOT compiled code is less likely to encounter issues such as crashes and unexpected behavior than JIT compiled code, as it has already been optimized and tested at build time.
   - Performance: AOT compilation produces native machine code that is optimized for the target platform, providing better performance than JIT compiled code, which must be generated on the fly at runtime.
   
9) How are IOS and Android similar? How are they different?
   - Smiliarities: They have a similar stack, both run on phones, contrled through a touch interface, based on computer OS adapted and with added functionallity, they both sport an app store for downloading applications, 
   - Differences: Android based on Linux - IOS based on Mac OS X, Android is opensource - IOS is not, Andorid allows sideloading - IOS does not, Android offers a high level of comstumizability - IOS does not, Andorid supports apps in java - IOS supports swift and Objective-C.
   
10) What are the two models of interprocess communication? What are the strengths and seaknesses of the two approaches
    - Shared memory
      - Area of memory is shared among the communicating processes
      - Communication is under controll of the users processese
      - Major issues is to provide mechanism that will allow the user processes to synchronize their actions when they access shared memory. 
      - faster
      - needs sync.
      - can be complex to implement
    - Message passing: 
      - Processes communicate with each other without resorting to shared variables
      - Send & receive operations are provided
      - P and Q must establish a communication link and exchanges messages through the send/receive operations.
      - slower
      - easier to implement
      - does not need sync.
    
12) What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a micro-kernel architecture? What are the disadvantages of using the microkernel approach
    - Advantage: 
      - Increased flexibility and modularity 
      - cleaner separation between the core of the OS and the services it provides, making it easier to add or remove services as needed, and reducing system complexity.
      - reliability
      - security
    - Disadvantages: 
      - Performance - The abstraction of system services to the user space can cause a performance overhead
    - Complexity - the microkernel requires a higher degree of complexity in its design and implementation as well as its system services and their communication
    - compatibility - difficult to achieve compatibility with existing software and hardware.
---
C
The following is the code to allocate memory for a 2-dimensional array of fixed size 8×8.
``` C
#include <stdio.h>
int main() {
int x;
int y;
int array[8][8];
for ( x = 0; x < 8; x++ ) {
  for ( y = 0; y < 8; y++ )
    array[x][y] = x * y;
```
-   Where in the memory is the matrix stored?
  - It is stored on the stack
-   Provide the code for a variant of the code that allocated the memory dynamically.
  - You would have to use the malloc command to allocate an array of pointers and the malloc again to allocate an array for each pointer.
-   Where is your dynamically allocated memory stored?
  - The dynamically allocated memory is stored on the heap.
---
-   What is the output of the following C program?
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  stupid();
  stupid();
  return 0; 
}

int stupid()
{
  static int i=17;
  printf("i is %d\n", i);
  i++;
}
```
This program will call stupid initialize a static int i to 17 print it and increment it by 1 to 18. Then stupid is called again now printing 18 and then incrementing i to 19.

---

-   Discuss the following C program, and put it in relation to the function declaration as found by the man page of the library function for sorting an array: `void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));`
```c
#include <stdio.h>
#include <stdlib.h>

static int comp(const void * x, const void * y)
{
  int a = (int)(*(int*)x);
  int b = (int)(*(int*)y);

  if (a==b)
    return 0;
  else
    if (a < b)
        return -1;
    else
        return 1;
}

int main(int argc, char* argv[])
{
   int numbers[10]={1892,45,200,-98,4087,5,-12345,1087,88,-100000};
   int i;

  /* Sort the array */
  qsort(numbers,10,sizeof(int),comp) ;
  for (i=0;i<9;i++)
    printf("Number = %d\n",numbers[ i ]) ;
  return 0;
```
This is a program that takes an array of 10 numbers and sorts them from lowest to highest using the qsort function. The qsort function takes, the array, the size of the array, the size of the type contained in the array (this case ints), and a comparator to compare the elements in the array to each other. 

---
-   Discuss the result of the following C program. If possible, try it on different machines. In order to understand the results, find out what a sequence point is.

```c
#include <stdio.h>

#define SQR(a)((a)*(a))
#define CUB(a)((a)*(a)*(a))


inline static int cub(int x) { return x*x*x; }

int main()
{
        int x;

        x=3;
        printf("square? :%d\n",SQR(x));
        printf("x:       %d\n",x);

        x=3;
        printf("square? :%d\n",SQR(++x));
        printf("x:       %d\n",x);

        x=3;
        printf("cub?    :%d\n",CUB(x++));
        printf("x:       %d\n",x);

        x=3;
        printf("cub?    :%d\n",CUB(++x));
        printf("x:       %d\n",x);

        x=3;
        printf("cub?    :%d\n",cub(++x));
        printf("x:       %d\n",x);

        return 0;
}
```
A sequence point is a point in the execution of a program where all side effects of previous evaluations are completed and no side effects of subsequent evaluations have yet occurred.

A sequence point occurs at specific points in the program, such as:

1.  At the end of each full expression, such as an assignment or function call
2.  After the evaluation of the controlling expression of a control structure, such as an `if` or `while` statement
3.  After the evaluation of each of the expressions in a `for` loop
4.  At the end of the evaluation of the first operand of the conditional operator

---
-   Follow the C-tutorial for FILE I/O on [https://www.cprogramming.com/tutorial/cfileio.html](https://www.cprogramming.com/tutorial/cfileio.html) and answer the quiz questions.

1. What object do you use to represent a file in C?  
   - FILE*  

2. Before you can read or write to a file in C, what do you need to do?  
   - Call fopen on the file  

3. How do you write a string of text into a file?
   - Open file and use fprintf.
   - Open a file, and use fputc repeatedly.  

4. What flag do you need to pass to fopen to append to an existing file instead of recreating the file?
   - a

5. How do you open a file for binary IO?
   - Use the "b" flag to fopen  