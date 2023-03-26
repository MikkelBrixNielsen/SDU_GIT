# 1.3 - Differences between Interpretative and compiled implementations of a programming languages.

Interpretative implementations: very flexible - not very fast
- Is very flexible, you can easily change the behaviour of the program
- Not as efficient, since it has to re-read the program every time.
- Easy to debug since it read a single instruction at the time so if there is a bug is probably that instruction you have reached that causes it 

compiled implementations:
- efficient 
- Opportunity for static analysis 
- cost decoding compiler load 
- each instruction is translated only once 
- low flexibility
- loss of information on the structure - compiler does a lot of optimization and renaming of variables

# 1.5 - The advantages of using intermediate machines for implementation of a language.
- Decreases the number of compilers you would have to have from m machines to n machines, without the intermediate language you would have to create m\*n different compilers but with an intermediate language you would only have to create m compilers to the intermediate language and n compilers from the intermediate language to the n machines.

# 1.6 - How can one obtain a compiled implementation for the same host machine minimising the effort required.
- Given
  - Compiler in pascal -> P-code, $C^{Pa}_{Pa \rightarrow Pc}$ 
  - Compiler translated to P-code, $C^{Pc}_{Pa \rightarrow Pc}$
  - Interpreter in pascal -> P-code, $I^{Pc}_{Pc}$

- Translates $I^{Pa}_{Pc} \rightarrow I^L_{Pc}$ 
- Modifies $C^{Pa}_{Pa \rightarrow Pc} \rightarrow C^{Pa}_{Pa \rightarrow L}$
- $I^L_{Pc}[C^{Pc}_{Pa \rightarrow Pc}, C^{Pa}_{Pa \rightarrow L}] = C^{Pc}_{Pa \rightarrow L}$
- $I^L_{Pc}[C^{Pc}_{Pa \rightarrow L}, C^{Pc}_{Pa \rightarrow L}] = C^L_{Pa \rightarrow L}$

- Compiler translates the Pascal code directly into the required machine code.

# 1.7 - Interpreter $f_{L1}^L(x,y)$, written in language $L$, for a different language $L1$, where x is the program to be interpreted and y is its input data. Consider a program $P$ written in $L1$. What is obtained by evaluating $peval_L(f_{L1}^L, P)$
- We achieve a compiler which translates a program written in L1 to a compiled program in L. 
