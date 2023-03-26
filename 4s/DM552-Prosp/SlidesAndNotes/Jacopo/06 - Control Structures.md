Different ways to syntactically represent an expression
infix:              a + b
prefix:           + a b
postfix:          a b +

Expressions semantics:
- Priority of the operators does add come before multiplication or division??
- Usually arithmetic operator precede comparisons and they precede logical ones 
- Exceptions, APL, Smalltalk all operators have equal precedence


- Infix - not always obvious
- Infix precedence rules - parentheses are IMPORTANT
- Evaluating infix is not a simple task

15-4-3, normally (15-4)-3 in APL (1960) 15-(4-3)

Postfix
- Evaluating using the stack
- Read the next exp symbol. And put it on the stack
- . If the symbol is an operator:
  - Apply it immediately to the preceding items on the stack
  - Store the result in R
  - Delete operator and operands from stack
  - Stores the value of R on the stack.
- Repeat

Prefix
- Simpler than infix
- No precedence rules needed
- No rules of associativity are needed
- No parentheses needed
- Simple evaluation using stack - more complicated than postfix
- needs to count operands read 

Terminals - actual values
non-terminals - expression signatures like val + exp, exp + exp, v + v ...

### Expression **reading direction matters** in languages where function e.g., have **side effects**, reason being:
- Effects
- Undefined operands
- Optimizations
If guards are expressions
something that can be evaluated
Some languages do not allow functions with side effects
Java specifies left to right

Example:
![[Pasted image 20230306144011.png]]
![[Pasted image 20230306144048.png]]

Lazy evaluation 
- only some necessary operands are evaluated
eager evaluation
- all operands are evaluated

Short-Circuit evaluation
- Term often used to describe Lazy evaluation for Boolean expressions 
- Eager evaluation for Boolean can cause errors
![[Pasted image 20230306144747.png]] 
- if a = 0 there will be a division by zero exception

Commands
- **A command is a syntactic entity whose evaluation does not necessarily return a value, but it can have a side-effect.**
- Side effect: changing state of computation without necessarily returning a result.
- Typically of imperative paradigm
- are not present in functional and logical paradigms
- in some cases they return a value (like in C)

Variables
- In Mathematics the variable is an unknown that can take the values of a predefined set - Not editable
- In imperatives languages: we have changeable variables - container with some name the value in the container can be changed over time.

### **Assignment:**
- things on the left side of the assignment is called L-value, things on the right side is called the R-value.
- L-value - a value that denotes a location (and may appear to the left of an assignment)
- R-value - a value that can be contained in a location (and can appear to the right of an assignment)
- Assignments might return a value like in C where: 
  Y = X = 2 is possible since X = 2 returns 2. But normally they do not return values but produces side effects.
  - Imperative programming computes with side effects
  - x := 1
    x+:= 1 (Pascal)
    x += (C)
- e++ (gets value of e then increments)
- ++e (increments e then gets the value)
- Incrementing a pointer takes into account the size of the bulleted objects - Think like indexing p being a pointer then p+3 goes 3 bytes into the pointer.

Commands
- Sequence control
  - ; - sequential command some languages used to indicate end of line of code or block (terminator)
  - goto like assembly jmp but can go to a line in the code - creates unmaintainable spaghetti code...
- Conditional commands
  - if statements
  - case - switch cases
- Iterative commands 
  - Bounded - for loops
  - Unbounded iteration - while loops

Sequential commands
- C1; C2
  - Is the basic construct of imperative languages
  - It only makes sense if there are side-effects
  - In some languages the ";" more than a sequential command is a terminator
- ALGOL 60, C: The value of a composite command is that of the last command

Goto
- Access debate in the years 60/70 on the usefulness of the Goto
- Considered useful essentially for
  - Exiting the center of a loop, return from subprogram, handle exceptions
- At the end considered malicious
- Modern Languages
  - They use other constructs to manage the control of loops and subprograms (while, for, if then else, procedures... see ALGOL 60)
  - They use a structured exception handling mechanism (CLU, Ada, C++, Lisp, Haskell, Java, Modula 3)
  - Goto is not present in Java

Structured programming
- Goto "defeated" because considered against the principles of structured programming
- Structured programming (~ 70s), precursor of object oriented programming
  - Modular code
  - Meaningful identifiers - names
  - Extensive use of comments
  - structured data types (arrays, records)
  - structured flow controls

Structured control commands
- Only one entry point and one exit point
  - parsing in a linear way the text matches the flow of execution
  - this is a key for understanding the code
- Structured commands
  - for, if, while, case ...
  - not the case of goto
  - Allows structured code and not "spaghetti code"

Conditional commands
- if B then C_1 else C_2
- Introduced in ALGOL 60
- Various rules to avoid ambiguity in the presence of nested if
- Pascal, Java: else associates with the closest then
- ALGOL 68, Fortran 77: keyword at the end of the command if B then C_1 else C_2 endif

Case
- nice for visibility - does not have a standard convection
- can be faster if you have a smart compiler does not need to evaluate everything like else if ... else if ... but can potentially jump to a label
- Many versions in different langauges:
  - Modula: Possible multiple values in the same branch;
  - Pascal, C: No range in the label list;
  - Pascal: Each branch contains a single command, no branch default (unless else used);
  - Modula, Ada, Fortran: Default branch;
  - Ada: Labels cover all possible values in the EXP type domain;

Iteration
- Iteration and recursion are the two mechanisms that make it possible to obtain complete Turing powerful formalisms.
- Unbounded: Logically controlled cycles (while, repeat)
- Bounded: Numerically controlled cycles (do, for) with number of cycle repetitions determined at the time of the cycle start

Unbound iteration
- While condition do command 
- Introduced in Algol-W, remained in Pascal and many other languages
- In pascal also post-test version:
  - repeat command until condition = while not condition do command
  - Unbound because number of iteration not known before execution
  - The unbounded iteration allows the expressive power of the Turing Machines
  - It is easy to implement using the physical machine exploiting the conditional jump instruction

Bounded iteration
- for index := Start to END BY step DO ... END
- You cannot change Index, Start, End, Step inside the loop
- At the beginning of the cycle execution the number of repetitions of the cycle is bounded
- The expressive power is less than the indeterminate iteration: you cannot express computations that do not end
- In many languages (e.g., C, Java) the for is not a bounded iteration construct!
- Foreach - Variant of for that iterates over all elements of a data structure

Recursion
- Alternative way to iteration to get the expressive power of Turing Machines
- Intuition: a function (procedure) is recursive if defined in terms itself.

Recursion and iteration 
- Recursion is possible in any language that allows
  - Functions (or procedures) that can call themselves
  - Dynamic memory management (stack)
- Alternative ways to achieve the same expressive power:
  - Each recursive (iterative) program can be translated into an iterative (recursive) equivalent
  - Recursion is more natural with functional and logical languages
  - Iteration is more natural with imperative languages
  - In the case of naive implementations, recursion less efficient than iteration
    - optimizing compiler can produce efficient code

Tail recursion 
- only needs one activation record (AR), so you do not need to make an AR then use it passe its values delete it create a new AR ... like normal recursion
- A call of g in f it is tail if f returns the return value from g without further computation.
- f is tail recursive if it contains only tail calls
  - function tail_rec (n: integer): integer 
    begin … ; x:= tail_rec(n-1) end 
    function non_tail rec (n: integer): integer 
    begin … ; x:= non_tail_rec(n-1); y:= g(x) end
- No need for dynamic memory allocation with stack: just a single Activation Record

Example recursion not tail recursive
![[Pasted image 20230306154120.png]]

Example of tail recursion 
![[Pasted image 20230313135601.png]]
