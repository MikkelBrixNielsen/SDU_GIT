# Equivalence and compatibility between types
- Two types T1 and T2 are equivalent if each object of type T1 is also an object of type T2 and vice versa
- • T1 is compatible with T2 if an object of T1 can appear where a T2 would be expected

![[Pasted image 20230320154043.png]]
- Depending on the language theses types may be equivalent, but the compiler might save things in order in the memory so for the structs when accessing a in the last struct you might actually access b compared to the middle struct

# Structural equivalence
- Used in ALGOL 68, Modula-#, C, ML
- Two types are equivalent if they have the same structure:
  - Examples struct 1 and 2 are equivalent 
  - Example 3: depends on the language
- Structural equivalence: low level, does not respect the abstraction that the programmer uses with the name:
![[Pasted image 20230320154709.png]]

# Structural equivalence definition 
- The minimum equivalence relationships between types that satisfies the following three properties:
  - A name type is equal to itself
  - If a type T is introduced with a definition type T = expression T is equal to expression
  - If two types are constructed by applying the same type constructor to equivalent types then they are equivalent

# Equivalence by name
- Two types are equivalent if they have the same name used in pascal, Ada, Java, Haskell
- Loose equivalence by name /Pascal, Modula-2)
  - Declaration of a type alias does not generate a new type but only a new name:    ![[Pasted image 20230320155153.png]]

# Compatibility
- T is compatible with S when T objects can be used in a context where S values are expected
- The definition depends critically on the language! T is compatible with S if
  - T and S are equivalent
  - The values of T are an subset of the value of S (range)
  - All operations on S-values are also possible on the values of T (records defined differently)
  - The values of T correspond canonically to some S values (int and float)
  - The values of T can be matched to some S values (float and int with truncation)

# Type conversion
- If T compatible with , however some type conversion is needed. Two main mechanisms
  - Implicit conversion (coercion): The abstract machine inserts the conversion without any trace of it at the linguistic level
  - Explicitly conversion or cast when the conversion indicated in the program text 

# Compatibility and coercion
- Coercion is used to indicate a compatibility situation and what the implementation should do.
- Three possibilities. The types are different but:
  - With same values and same representation. Example: Structurally equal types, different names
    - conversion to compile-time only; no code
    - Different values and representation. Example: integers and reals.
      - Conversion code
  - Different values, but same representation at the intersection. Example: ranges and integers
    - code for dynamic control over membership at the intersection

# Casting
- In certain context the programmer must insert explicit type conversion (cast in C and Java)
  - Annotations in the language that specify that a value of a type should be converted to another type 
- Not all explicit conversion are allowed
  - Only those which the language knows how to implement 
  - You can always insert a cast where there is compatibility (useful for documentation)
- Modern languages tend to favour casts than coercions

# Type interface
- Infer the type of an expression from the type of the components 
- In principle simple but compatibility equivalence casting makes things difficult 
















HASEKLL HAS EQUIVLANECE BY NAME 