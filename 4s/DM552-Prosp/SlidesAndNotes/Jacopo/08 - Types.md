# Types
- Collection of effectively presented homogeneous values equipped with a set of operations to manipulate the values
  - Integer 
  - Bool
  - Strings
  - Records
  - Int -> bool
- What a type is depends strongly on the programming language

# What are types
- Design level organizing the information
  - Different type for different concepts
  - Info on intended use of the identifiers
- Programming level identifies and prevents errors
  - Types can be controlled automatically
- Implementation level allows some optimizations
  - bool requires less bits than real
  - pre-calculation of record/struct access offsets

# Type systems
- Each language has a type system
  - predefined types
  - Mechanisms for defining new types
### Rules for type checking
- Equivalence, compatibility, inference
- Control: static compilation or dynamic
### High level languages 
- Systems with expressive types 
- Elaborate checks
### Machine languages
- Simple systems
  - Integers and floating-point
- No control (semantic errors may not be detected)
### Type equivalence
- Two expressions have the same type
### Type compatibility
- When a type is allowed in a different context
  - is 3 + 4.6 legitimate
### Type inference
- How to derive the type of a composite expression
### Type checking
- What errors are detected and when
- Language strongly types; no unreported errors resulting from a type error can occur at run time

# Static or dynamic checking
### Dynamic checking (e.g. Lisp)
  - Each data has a type descriptor
  - Before each operation you check the compatibility
    - (head x) → interpreter checks before x is a list
- An error causes the execution to stop
### Static checking (compilation) (e.g. Pascal, Java)
- More binding syntax
  - x = 4.6 illegal in java x is an int 
- Execution without types
- An error causes non-compilation

### Better static or dynamic?
- Both prevent type errors
- Dynamic control inefficient at run time
- Static checking restricts flexibility
  - In static checking 
    int x; x = if true then 3 + 4 else "foo"; 
    is always rejected, while it is dynamically corrected
- In General it is impossible (undecidable) to statically know if a running error will occur
- Static checking is always "conservative"

# Categories of types
- Scalar types (simple types): Values not composed of aggregations of other values
- Composite types: obtained by combining other types with appropriate constructors

# Scalar types
### Boolean
- Values: True, False
- Operations: or, and, not, conditionals
- Repr: 1 bit
- Note: C does not have a bool type

### Characters
- Values: A, a, B, B, ...
- Operators: equality code/decode; language-dependent
- Repr: 1 byte (ASCII) or two bytes (UNICODE)

![[Pasted image 20230320151656.png]]
![[Pasted image 20230320151702.png]]
![[Pasted image 20230320151709.png]]

# Enumerations
![[Pasted image 20230320152215.png]]

# Intervals (Subrange)
![[Pasted image 20230320152231.png]]

# Composite types
![[Pasted image 20230320152244.png]]

# Records
![[Pasted image 20230320152253.png]]

# Varying records
- Possible in many languages such as C using union + struct and pascall (modula, Ada) use unions and records
![[Pasted image 20230320152305.png]]
### Memory layout 
![[Pasted image 20230320152318.png]]
### Issues
- Discriminating tags is an editable field with an ordinary assignment
![[Pasted image 20230320152510.png]]

# Array 
![[Pasted image 20230320152523.png]]
### Array operations
![[Pasted image 20230320152534.png]]
### Array shape 
![[Pasted image 20230320152545.png]]

# Pointers 
![[Pasted image 20230320152558.png]]
### High or low level?
![[Pasted image 20230320152616.png]]

# Pointers and arrays in C
![[Pasted image 20230320152917.png]]
![[Pasted image 20230320152927.png]]

# Recursive Type
![[Pasted image 20230320152949.png]]
