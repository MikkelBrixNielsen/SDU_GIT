Names
- sequence of characters that denotes something.
  - const pi = 3,14
  - int x
  - void F() {...}
- names are often identifiers (alphanumeric tokens)
- but they can also be other symbols (=, + , -, etc...)

Denotable objects
- Object can be associated with a name 
- names defined by a user - variables, formal parameters, procedures (broadly), types defined by user labels, modules, constants defined by the user exceptions. 
- language defined names - primitive types, primitive operations, predefined constatns 

Binding time (Static or dynamically)
- Static:
  - primitive types, names for predefined operations and constants
  - writing the program - definition of some names - variables functions etc... whose link will be completed later
  - compilation (+ linking and deployment) - binding of some names (global variables)
  - if variable to be used is not found in block jumps on block out and tries to find it
- Dynamic:
  - runtime - definitive link of all names not yet tied (local variables in blocks etc...)
  - The newest defined variable will be used 

Environment
- associations between names and objects that exist at run time - exists at run time at some point in a specific execution.
- Declarations - Mechanism with which you create an association in environment
- The same name can denote distinct objects in different part of the program (points changing in c)

Blocks
- Textual region of a program that is defined as having a beginning and and end (scope)
- declarations local to that region
- anonymous (in-line)
- associated with a procedure
- local name management (can choose whatever name and give clarity)
- With appropriate memory allocation 
  - optimize the memory occupation
  - allow recursion 

Nesting for blocks
- Don't want things that are local to a block be shared with another local block unless they are nested - no overlapping if not nested.

Operations on the environment
- naming name object association block local declaration
- referencing object denoted by its name using a name 
- disabling name object association a declaration masks a name 
- reactivation name object association block exit with the declaration that was masked 
- Unnameing name objects association block exit with local declaration 

Operations on denotable objects
- creating 
- access
- modifications (if object is editable)
- destruction

"life" of objects
- name living longer than an object - creating a pointer and making it points to an object then freeing that object will no destroy the name
- and the reverse is true a procedure can be created and defined long before a name that would hold the value for the result of the executed procedures

Static scoping
- complete information from the program text
- bindings are known at compile time
- principles of independence
- conceptually more complex to implement but more efficient 
- algo, pascal, C, java
- more efficient harder to implement

Dynamic scoping
- variable to update and use
- information derived at run time
- often causes less readable programs 
- conceptually simpler to implement but less efficient
- lisp (some Versions), Perl, Bash

Some specific rule
- Where is a declaration visible in the block in which it appears? – Starting from the declaration and until the end of the block Java: Declaring a variable
```java 
{a = 1; // NO!
int a;}
```
Always (so also before) of the declaration Java: Declaring a method – Allows mutually recursive methods
``` java
{ void f() { g(); } // yes!
void g() { f(); } } // yes!
```

Mutual recursion
- Mutual recursion (functions, types) in languages where a name must be declared before being used
- Release this constraint for functions and/or types
  - java for methods
  - pascal for pointer types
![[Pasted image 20230220170626.png]]
![[Pasted image 20230220170653.png]]
![[Pasted image 20230220170701.png]]
![[Pasted image 20230220170708.png]]
