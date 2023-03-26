What is a language (syntax, semantics, pragmatics, implementation)
- Syntax (Grammar rules - when is a sentence correct)
  - Formal generative framers
  - Quasi-formal: typing contextual constraints
  - Lexical error writing integer instead of integer
  - Gramma error if a > 0 then C else C  to if a > 0 else c then c
  - Automata takes sentence applies the syntax rules of the language and tells you if it is correct or not 
  - BNF (Backus and Naur notation) Syntax trees and rules.
- Semantics (Meaning of sentence - meaning of a correct sentence)
  - Informal: Natural language manual 
  - Formal: denotational operational (axiomatic, algebraic)
- Pragmatic (Relationships between sign meaning and user)
  - Informal examples
  - Semi-formal: programming methodologies
- Implementation (execute a correct sentence respecting semantics)
  - derivation from semantics
  - abstract machines

The dangling else, depending on where and how a scope is defined in different programming-languages it might evaluate to different semantical meaning despite the syntax being correct.

Operational semantic - defines how certain syntax should be interpreted and what is should do and it is defined mathematically.