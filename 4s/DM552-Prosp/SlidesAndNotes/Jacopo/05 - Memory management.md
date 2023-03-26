Type of memory allocation
- the life of an object often corresponds to the way it was allocated (static, dynamic, heap)

- Static: memory allocated at build time (global variables)
  - Written in protected memory cant be changed
  - global variables
  - local variables of subprograms (without recursion)
  - constants that are known at build time
  - tables used by runtime support for type checking, garbage collection, …

- Dynamic: memory allocated at run time (user defined variables)
  - each instance of a runtime subprogram has a portion of memory called activation record (or frame) containing information about the specific instance (return address) - this is stored on the stack
  - similarly each block has its own activation record
  - The stack is (LIFO - last in first out)

- Heap: Objects allocated and deallocated at any time (pointers)

example:
![[Pasted image 20230220170933.png]]
Activation record (frame) for anonymous block
![[Pasted image 20230227143624.png]]

Activations record (frame) for procedures figure:
![[Pasted image 20230220170744.png]]

Stack management
- Entering a block
  - Changing program counter
  - Activation record allocation on stack and updating pointers
  - Passing parameters
  - Saving registers
  - possible initializations
  - Transferring control 
- Exiting the block
  - Return values from call to the caller or the value computed by the function
  - Restoring registers - in particular the old AR point must be restored
  - Possible finalisation
  - Deallocating space on the stack
  - Restoring the program counter resuming computations from where you stopped before

Example 
![[Pasted image 20230227144310.png]]

Dynamic allocation with heap
- Memory regions whose (sub) block can be allocated and freed arbitrarily
- Stack cannot stored dynamically changing structures variables etc. like arrays that change in size.
- Necessary
  - Explicit allocation of memory at run-time (e.g. dynamic data structures and pointers such as lists, trees....)
  - Variable-size objects (strings, collections...)
  - Objects whose life does not have a pre-defined duration (i.e., no FIFO life)
- Heap management is non-trivial
  - Efficient space management
  - Access speed
- languages that allow only fixed size blocks to be allocated
- languages that allow variable size blocks to be allocated
- Getting a block of memory to use heap (fixed block size)
  - Heap divided into fixed size blocks
  - Originally: all connected blocks in the free list
  - Allocating: get one block, remove from free list
  - Deallocation: returning to free list
- Getting a block of memory to use heap (variable block size)
  - Start with only one block of memory
  - For each allocation request: search appropriate block size
    - First Fit: first block big enough
    - Best Fit: the smaller size, large enough
- If the chosen block is much larger than it is needed, it is divided into two and the unused part is added to the FL
- When a block is de-allocated, it is returned to the FL (if an adjacent block is free, the two blocks are "merged" into a single block).

Fragmentation
- Internal Fragmentation ???
  - the space required is X
    - a block of dimension Y > X is allocated.
    - Y-X space is wasted
- External Fragmentation: space needed but it is unusable because it is divided into too small scattered pieces ???

Heap management
- First fit or best fit with variable size:
  - First fit: Faster, worse memory occupancy
  - Best fit: Slower, better memory occupancy
  - With only one free list for fix size the cost allocation anyway linear in the number of free blocks.
  - Multiple free lists, for blocks of different sizes
  - Buddy system: k lists; the k list has blocks of size $2^k$
    - if request allocation of block of 2k but size not available, block 2k+1 divided into 2
    - If a block of 2k is de-allocated is pooled to his other half (Buddy), if available
- Could also use Fibonnaci number for slower growth
