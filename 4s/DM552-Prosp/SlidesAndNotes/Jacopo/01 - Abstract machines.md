A machine - one language 
- Exists to run a single language
- machine corresponds to its language 
- a language can be run from multiple machines
- the fundamental cycle fetch-decode-execute

Abstract machines (AM)
- set of data structures and algorithms that can store and run programs
- abstraction of physical computer is data and interpreter

interpreter component that interprets instructions 
the structure of the interpreter is the same for an AM AM Store å interpreter 

Machine language
- M = AM
- $L_M$= Language machine
- $L_M$ = Language understod by the machine

Chinese's boxes
- User codes in $L_mb$
- AM machine talks $L_mb$ and converts to $L_ma$
- MA machine (physical) talks $L_ma$ and understands user code
- can use many AM's to go from one language to other languages

Making abstract machines
- Realization in hardware (Not very flexible)
- Emulcation or simulation via firmware 
- Interpretation or simulation via software
- Firmware / software can be patched

1 is always theoretically possible but 
- Used only for low level machines or dedicated machine 
- maximum speed
- no flexibility

2 data structures and algorithms but realized by micro-programs residing in read-only memory
- Microprogrammable (physical) machine
- High speed
- Greater flexibility than pure HW.

3 data structures and algorthm of the abstract machine but realized through programs written in the language of the host mahine 
- any hsot machine works
- less speed
- maximum flexibility

What is a program
- Partial function: F: A -> B, Correspondence between elements of A and B that can be undefined on some a existing in A
- $P^L$ Program written in the language L
- $P^L$ performs a partial function
- $P^L: D \rightarrow D$ (D is the domain of the input and output)
- $P^L(input) = Output$
- A program is partial because it has the possibility of not terminating

Interpretative implementation
- Physical machine (M0) can perform computation but have program written in L
- Need and interpreter that takes L and interprets the instructions written in M0
- Interpreter = program that implements partial function, takes input of program in a certain language and outputs it in another language retaining the result and behaviour from the original program

compiled implementation
- Program written in L translates it to L0
- Translation made by other program
- $C^La$
- Compiler is a function that goes from program to program
- Programs translated by a compiler that translates from L to L0 will make sure that the two programs run with the same input will give the same output

Interpretative implementation 
-  is very flexible, you can easily change the behaviour of the program
- Not as efficient, since it has to re-read the program every time.
- Easy to debug since it read a single instruction at the time so if there is a bug is probably that instruction you have reached that causes it 

Compiled implementation
- efficient 
- cost decoding compiler load 
- each instruction is translated only once 
- low flexibility
- loss of information on the structure - compiler does a lot of optimization and renaming of variables

The mix - what to translate and what to interpret
- translation for those constructs of L that correspond closely ro construct of L0
- - simulation of the rest
- Privileges efficiency (compilative solution)
- Priviliges flexibility and protability (interpretive solution)
- beginning start with interpreter compiler comes later

Real languages
- typically implemented in a compilative way (c, c++, Fortran, Pascal)
- typically implemted in an interpretive way (LISP. ML, perl, postscript, prolog, smaltalk, java, python)

Just in time compliation
- Dynamic translation or run-time compilation 
- Bytecode translation to machine code at run time more difficult if from source code
- JIT compiler analyes the code being executed and translates parts if the code where you can obtain speedup
  - can be done per file per function or arbitrary code fragment
  - code cached and reused later without needing to be recompiled
  - somtimes better performance than static compilation some optimizations only possible at runtime 
- combines the speed of compiled code with the flexibility of interpretation
- JIT causes a delay in the initial execution (warm up time)
- classical example is hte JIT compiler for java browsers for JavaScript

Partial evaluation
- Take a program and instanciate it for certain parts of an input 
- taking a program and taking parts of the input and using parts of the input to simplify while still yielding the same output removing e.g., ifs, jumps and reduced number of jumps.
- The simplifyed program has to take the remaning part of the input and yelding the same output as the original program and input. 

First futumura projection
- partial evaluation of L0 and interpreter from L0 to L can take dataset of L1 and spit out the compiled version of L0.
- ![[Pasted image 20230213142826.png]]

Second futumura projection
- Partial evalution of L0 to L0 for (partial evaluation of L0 to L0, and interpritor L0 to L1) creates a compiler for any program written i L1 to L0.
- ![[Pasted image 20230213143032.png]]