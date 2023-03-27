# Polymorphism
- the same function identifier can operate on operand of different types 
- Three form of polymorphism
  - ad hoc polymorphism, or overloading
  - Parametric polymorphism (explicit and implicit)
  - Subtype polymorphism (we'll treat this in the oo context)

# Ad hoc polymorphism: overloading
- The same symbol denotes different meanings: plus sign can add floats and integers
- Compiler translates + in different ways 
- Always done at compile time - after type inference
- Do not confuse with compatibility (automatic conversion) - int + float is actually converted to float + float
- ML has overloading but has no automatic coercions

# Parametric polymorphism
- A value has Parametric Universal Polymorphism when it has an infinity of different types, they are obtained by instantiation from a single general-type scheme (java generics basically)
- polymorphic function consists of a single code that applies uniformly to all instances of its general type![[Pasted image 20230327124059.png]] ![[Pasted image 20230327124237.png]]

# Subtype polymorphism
- Not all types can be used equally 
- if T is a subtype of S, S can be used where T can be used but T might not be useable where S is
- A polymorphic function consists of a single code that applies uniformly to all "legal" instances of its general type

# Summary
![[Pasted image 20230327124406.png]]

# A first conclusion: type-safe languages
- Type safe -> no unreported errors that results from a type error at runtime all errors should be caught at compile time
- Non-Safe: Descendants of BCPL, including C and C++ -> Cast, pointer arithmetic
- Almost safe: Descendants of Algol, Pascal, Ada.
  - Union types (Pascal)
  - Dangling pointers -> Languages with explicit deallocation cannot be fully type-safe
- Safe: Lisp, ML, Smalltalk, Haskell, (and Java - implemented generics in a bad way for compatibility reasons)
  - Lisp, Smalltalk: Dynamic control
  - ML, Haskell, Java: Static control
![[Pasted image 20230327124855.png]]
