# Avoid dangling references
- Dangling references -> source of bugs hard to understand 
- Possible solutions
  - Tombstone
  - Locks and keys 
- Prevent user from using memory
  - Automatic recovery of unused space 
    - Garbage collection
      $\gg$ Reference count
      $\gg$ Mark and Sweep
      $\gg$ ... (others?)

# Tombstone example![[Pasted image 20230327130128.png]]
- Heavy in space and time
  - check memory twice 
  - have to keep tombstones around
- Invalid tombstones remain allocated 
- Allocated in Special Memory (Cemetery)

# Locks and keys example ![[Pasted image 20230327130231.png]]
- Lock = word in memory with arbitrary value 
- key = initialized with lock value 
- Heavy (never used by default)
- used in Pascal when dynamic control of angling references is required
- Avoid accumulated problem of tombstones (memory can be reused)

# Garbage collection
- The user freely allocates memory
- Not allowed to deallocate memory
- The system periodically retrieves the allocated memory and no longer usable (no longer has a valid access path)

# Reference count
![[Pasted image 20230327130505.png]]
- Each allocated object has a (inaccessible) counter![[Pasted image 20230327130721.png]]
- When ref_count (object)=0, object is retrieved; recursively decrement ref_count of any other data whose pointer resides in the object
- Problems: waste of space; recognize what a pointer is; does not recover circular structures
![[Pasted image 20230327131313.png]]

# Garbage collection: Mark and sweep
- Can run out of computing power if there is a lot of allocated memory - all the computing resources will be used to figure out what to delete
1) Mark all the objects on the heap as unused 
2) Starting with pointers outside the heap, visits all the concatenated structures, marking each object as unused 
3) Retrieve all remaining objects from the heap that are unused
   - To use when free memory is low
   - Time proportional to the total length of heap 
   - Use wisely the space on the stack (point 2)
     - Schorr and Waite
       - Algorithm that implements mark and sweep. Uses the least significant bit of pointers in a linked data structure to represent the mark bit, allowing for the mark status to be stored without using additional memory. Marking objects is done by setting the least significant bit of their pointers. During the sweep phase, it frees unmarked objects and resets the least significant bit of their pointers.
 - Stop-the-world effect: When the space is retrieved the user experiences a significant slowdown in the system reaction

# Stack for the visit 
![[Pasted image 20230327131858.png]]
- Use the stack to keep track of visited objects
- Could have to store a large amount of things on the stack not that good

# pointer reversal ![[Pasted image 20230327131937.png]]
- Reverses the point so when going from A -> B you make B point to A

# Mark and compact & copy
- Go do a first pass to see which objects to keep and which to delete, then you delete the unused objects and compact the remaining objects to be in blocks next to each other
- More expensive since you have to copy and swap 
- avoid fragmentation

# Stop and copy 
![[Pasted image 20230327132407.png]]
- memory split into two half is used for objects
1) when memory gets low you do a sweep that copy all used objects to the other half of the memory and garbage collect the rest
- losses a lot of memory

# Cheney's Alg. copy
![[Pasted image 20230327132430.png]]
- Cheney's Algorithm is a garbage collection algorithm used in programming languages to manage memory allocation and deallocation. It is a variant of the copying garbage collection algorithm and divides the heap into two semispaces of equal size. During garbage collection, live objects are copied from one semispace to the other, leaving the original semispace empty. The semispaces are then swapped, and this process is repeated as needed. Cheney's algorithm is often used with the stop-and-copy method, which temporarily stops program execution during garbage collection to ensure efficient scanning of the heap.