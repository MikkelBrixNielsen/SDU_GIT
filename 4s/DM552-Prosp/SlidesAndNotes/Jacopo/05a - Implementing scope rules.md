Static scope
- Static chain
- Display
- Is syntactic

Dynamically Scope
- A-List
- Central referencing table (CRT)

How to determine correct linking
- Have to be aware of the scope (Dynamic / static)
- Identifying where which variables are located

Activation record
- Dynamic link depends on the sequence of execution of the program - Pointer to previous AR on stack (caller AR)
- Static link depends on static nesting (in text) of procedure declarations - Pointer to the AR block that immediately contains the text of the running block
![[Pasted image 20230227151954.png]]

Allocations of tasks
- Compiler
  - Associates the information K at every call
  - Associates to every name an index k
    - K = 0 local name
    - K != 0 non-local name defined h blocks above
- Cost
  - for every access to a non-local variable
    - k static chain steps more than access to local variable

Display???
- Display[i] = pointer to AR of procedure level i, last active
- With Display, an object is found with two accesses: one for the display and one for the object
![[Pasted image 20230228161922.png]]

Display vs static chain
- Rare depth nesting > 3, so max length of static chain = 3
- Optimization techniques can improve access to frequently used chains (keeping pointers in registers)
- The display is more expensive to maintain than the static chain in the call sequence...
- Conclusion: display little used in modern implementations...

Dynamic scope 
- With dynamic scope the name object association depends on
  - the flow of control at run-time
  - the order in which the sub-programmes are called
- The general rule is simple: the current binding for a name is the last one determined in the execution (not yet destroyed)

static vs dynamic 
- Static you see a block and know which variable is referenced
- Dynamic if a local variable is changed in local block and there is a name clash good luck

Static implementation
- Storing names in AR
- Search by name going up the stack
- has K search time if k is the size of the memory
![[Pasted image 20230227153231.png]]

Variant: A-List
- The associations are stored in a special structure, used like a stack
![[Pasted image 20230227153333.png]]
- Costs
  - Easy to implement 
  - Names in memory explicitly present only once per name
  - Management is entering and exiting from block, inserting and removing block on the stack
  - Access time scales linearly with the number of names

CRT (control referencing table)
- Avoid long scans of A-list - can reach variable in constant time 
- A table maintains all the distinguished names of the program
  - If the names are known statically, you can access the table element in constant time
  - Otherwise, hash access
- Each name is associated with the list of associations of that name
  - The most recent is the first
  - The others (deactivated) follow
- Constant access time (two indirect accesses)
- More complex to implement 
- Occupies less memory, statically known names results in not having to know name locally 
- each name is stored only once
- Management
  - entering and exiting from the block
  - managing all lists of names defined in the block



cannot use stack for recursion since it will overwrite the same block of memory

What is the stack
- Where we put activation records (keep information regarding a block or procedure)
- static / dynamic links
- static / dynamic chain pointers
What is the heap
- Variable memory where variables can grow in size
Why is the stack not enough
- variable size data structures if put on a stack where things are close together things like a vector or list would not be able to grow

