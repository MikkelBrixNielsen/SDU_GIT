A program in Haskell is a sequence of declarations, of which there are two types - Program => declaration program => nothing:
1. Type declaration (var1, var2 :: type):
   - example: length :: [a] -> int
   - Start with a number of variable(s) 
   - E.g., square, cube :: int -> int // defines square and cube to be of type int, takes int and gives int.'
   - Type-declaration -> "data" type-const | var* "=" constructor type+  ("|" constructor type+)*
   - constructors -> ("A .. "Z")("A" .. |"Z"|"a"|) 
   - E.g., Data Bool = False | True, Data List a = EMPTY | INSERT a (list a) 

2. Function declaration ():
   - example: length (\_ : xs) = 1 + length xs
   - LHS can be a function, pattern or variable.
   - RHS can be an expression, or | $condition_1 ~|~ ... ~|~condition_n$

Function's conditions are evaluated from top to bottom.

Haskell has lazy evaluation
- Starts from outmost expression and evaluates inwards.

expressions:
- var | const | var exp | "\[" exp "|" (gen | exp) "\]""  

Pattern matching:
- (x : xs) - takes first element of a list in x and then the rest in xs
- (x:(y:ys)) = y - returns second element of a list
- _ - can match to anything like x can but just throws it away

Different ways to write functions: 
and :: Bool -> Bool -> Bool
and x y | x = y
			| otherwise = false

and :: (Bool, Bool) -> Bool
and (x, y) | x = y
			| otherwise = false

Partial application: 
- Partial application in Haskell involves passing less than the full number of arguments to a function that takes multiple arguments.

Currying: 
- Currying is the process of transforming a function that takes multiple arguments in a tuple as its argument, into a function that takes just a single argument and returns another function which accepts further arguments, one by one, that the original function would receive in the rest of that tuple.

Boolean gates as functions
and :: Bool -> Bool) -> Bool
and True y = y
and _ _ = False	

or :: Bool -> Bool) -> Bool
or False y = y
or _ _ = True

not :: Bool -> Bool
not True = False
not _ _ = True
