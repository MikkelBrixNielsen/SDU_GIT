Exception: Structured exit
- Terminate part of computation
  - Exiting from a construction
  - Passing data through jumps
  - Returning control to the newest management point 
  - AR no longer needed are deallocated
    - Other resources include heap space, can be freed
- Two constructs
  - Declaration of the exception manager 
  - Command/expressions to raise exception

# Propagate the exception 
- Exception not handled in current routine - exception raise to call point
- Exception not handled by caller it is propagated along call chain
- Continues until reaches handler or top-level provide default handler
- Respective frames are not removed from the stack
  - For each frame that is removed, the status of the registers are restored
- Each routine has a "hidden" handler that restores the state and propagates the exceptions along the stack

# Exception propagates along the dynamic chain
![[Pasted image 20230314140551.png]]
The inner most one since it is the first handler to be meet when looking at the stack

# Implement exceptions
- Simple
  - At the beginning of a protected block
    - Put on the stack the handler 
- when an exception is raised
  - remove the first handler on the stack and see if its the right one
  - if not, raise again the exceptions and repeat
- Inefficient in the (most frequent) case where the exception does nor occur
  - Every try block we have to put and take stuff of the stack
- Better solution
  - The compiler generates a table where for each protected block and for each handler there is a pair <Block_addr,handler_addr>
  - The table is sorted on the first element (statically)
  - When an exception is raised
    - Binary search in the table on the first element
    - Transferring the control to the corresponding handler address
- If the handler re-raises the exception repeat

# Finally block (Java, C#, Python)
- Practically always executed (usually clean up code)
- avoid having clean-up code accidentally bypassed by a return continue or break
- + readability and maintainability of code

### Finally example
``` java
try {
throw null; // throws NullPointerException!
} catch (Exception e) {
 int oops = 1/0; // throws ArithmeticException!
} finally {
 System.out.println("Finally!");
 // still gets executed!
}
System.out.println("What about me???");
 // doesn't get executed!
```

### Finally and return
``` java
int i = 0;
try {
 i = 2;
 return i;
} finally {
 i = 12;
}
``` 

# Finally and Return in Java
- Specification: A return statement with an expression attempts to transfer control to the invoker of the method contains it; the value of the expression becomes the value of the method invocation.
- The preceding descriptions say "attempts to transfer control" rather than just "transfers control" because if there are any try statements within the method or constructor whose try blocks contain the return statement then any finally clauses of those try attempts will be executed, in order, innermost to outermost before control is transferred to the invoker of the method or constructor. Abrupt completion of a finally clause can disrupt the transfer of control initiated by a return statement.
- With throw in both try and finally block
  - Try block throws someException
  - Finally block throws someOtherException
  - Second throw wins and the first is discarded 
  - Return in a finally block will cause an exception thrown from a try block to be discarded 
  - Throw in a finally block will cause a normal return value a true block to be discarded