Compiler GOD (not possible)
- Cannot make a compiler that can catch all syntax errors.
- while (k == k) would be correct syntax but while(true) can be caught and is incorrect even though the code do the same thing.
- does not realises k == k

The halting problem?
- not being able to write a program that takes any other program as an input that can tell you with certainty if a program given as an input will terminate.
- very simple and dumb programs would allow the halting program to exist e.g., a program that can only execute a skip command.
- powerful languages (languages with high expressive power) (like touring complete languages) will not allow the halt algorithm to exists since the contain while, ifs, jumps and for loops.
- can't decide everything algorithmically 

Undecidable problems
- if a function is constant 
- if a function x is equal to function y
- if a program always terminates 
- if a program always diverges

Other formalism 
- functional programming 
- 2 registers counter machine (with inc and jmp or set to zero instructions.
- rule 110 cellular automaton - an elementary cellular automaton with interesting behaviour on the boundary between stability and chaos. In this respect, it is similar to Conway's Game of Life. Like Life, Rule 110 with a particular repeating background pattern
- church thesis (~1930): A function that can be "computed by any algorithm" coincides with a function calculable by a Turing machine. (might discover something better than the Turing machine - seems unlikely)
  - Everything that can be computed or calculated using an algorithm is also achievable by a touring machine

- We will not be able to do everything with a program
- a touring complete program will not be able to write a program that can compute all output given a given input



