Addition:
(+) 123 123 = 246
123 + 123 = 246
-123 + 123 = 0
123 + (-123) = 0

Subtraction:
(-) 123 123 = 0
123 - 123 = 0
-123 - 123 = -246
123 - (-123) = 246
(-) 123 (-123) = 246

Multiplying:
(\*) 123 123 = 15129
123 \* 123 = 15129
-123 \* 123 = -15129
123 \* (-123) = -15129

Division:
3.0 / 1.5 =  2.0
16 / 0.5 = 32.0 
-1.7 / (-12) = 0.14166~
10 / 2 = 5
10 / 3 = 3.33~
10 / 111 = 9.009~e-2

What happens if you try to add a number and a string?
- '+' can't be used for (Num \[Char])

What happens if you try to add two strings?
- '+' can't be used for (\[char] \[char]

What happens if you try to compare things of different types?
- can't match 'first type' with actual type 'second type' in the '\=\=' expression

What happens if you try to add an integer and a floating point number?
- it  becomes a double

Simple function 
- succ - Basically i++
- min takes minimum of a tuple
- max takes maximum of a tuple
- can't use more functions in one line without () since it breaks the function syntax e.g., 'succ a' if a is another function it has to be in () for it to process its own variables

Simple function 
Write a function that doubles a number only if it is a smaller than 100, otherwise it doesn't change it.
- doubleSmall x | x < 100 = x + x 
		            | otherwise x

- infinite list with ranges: \[1..]
- infinite list with repeat: repeat "num"
- infinite list with cycle \["pattern"]


look in func.hs for rest of metods









