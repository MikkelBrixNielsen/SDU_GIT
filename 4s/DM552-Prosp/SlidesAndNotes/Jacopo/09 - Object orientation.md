# Control abstraction
![[Pasted image 20230327134118.png]]
- Control abstraction – Hide realization in the body of procedures 

# Data abstraction
![[Pasted image 20230327134128.png]]
- Data abstraction
  - Hide decisions about the representation of data structures and the implementation of operations
  - Example: A priority queue made by
    - A binary search tree
    - A partially ordered vector

# Abstract Data Types (ADT)
- Major contribution to languages of the seventies
- Separates the interface from the implementation
  - Sets have Empty, Insert, Union, Is_member?
  - Sets implemented as... vector, concatenated list
- Use type control to ensure separation
  - The developer has access only to the operations of the interface
  - The implementation is encapsulated

# Primitive types VS abstract type 
- Declare variables x: int 
- Set of operations +,-,*...
- No other operations applicable for integers
- Declare abstract type
- define operations (interface)
- The language ensures that only these operations are applicable

# Encapsulation principle
- Implementation of code hidden from the user 
- Don't need to know how it is coded to use it 
- Two correct implementations of a (abstract) type are not distinguishable from users of that type

# Reality or ideal
- In Clu, ML,... the independence from representation is a theorem - Demonstrable because the language restricts access to implementation: only through the interface
- In C, C++, it's an ideal – The independence of representation is supported by "Good programming practices" and the language does not guarantee it Example: access to bit representation of -1

# Modules
- General construct for hiding information
- Has two parts - Interface: A collections of names and their types, implementation: declaration of types function for each interface name, additionally hidden declarations (to the user)
- Examples: Modula modules, Ada packages, ML structures

# Data forms and abstraction
![[Pasted image 20230327175959.png]]
- Modules can be used to define ADT's (abstract data types)
- Some languages separate interface from implementation
- An interface can have multiple implementations

# Abstraction and modularity
- Component: Programming unit, function, data structure, module
- Interface: Types and operations defined in a component that are visible outside the component
- Specification: "Intended semantics" of the component, expressed though properties observable through the interface 

# Example 1
![[Pasted image 20230327175746.png]]

# Example 2
![[Pasted image 20230327175753.png]]

# Object-Oriented languages
- Information hiding and encapsulation: primitive language concepts
- In an extensible context
  - Allows re-use of the code
  - Easy programming - Close to how we think
- Languages - Historical: Simula, Smalltalk, Commercial: C++, C#, java, ...

# Objects and classes
- A object is a box that contains
  - Hidden data: variables, values, functions
  - public: operations: methods
- An object oriented program
  - Sends messages to objects
  - An object responds to the message
  - State confined in objects
- Organization allows groups of objects with same structure (a class) allows extendibility and reuse
- First language to introduced this was Simula

# Object-oriented programming
- Object oriented programming is simultaneously:
  - A programming methodology
    - Organize concepts using objects and classes 
    - Build extensible systems
- A series of linguistics concepts
  - Encapsulation of data and functions in objects
  - Subtypes: allows extension of data types
  - Inheritance: allows reuse of implementations