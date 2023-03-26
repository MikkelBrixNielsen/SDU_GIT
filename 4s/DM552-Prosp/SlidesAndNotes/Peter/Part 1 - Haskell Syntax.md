[] = empty list
(x: l') = a list starting with x and continuing with the list l'
[23, 42] = (23: (43:[]))

Function for length:
```Haskell
length :: [a] -> int      // [a] list of type a 
length [] = 0             // empty list = 0
length (_ : xs) = 1 + length xs
```

Function for summing 
``` haskell
sum :: Num a =>[a] -> a
sum [] = 0
sum (x : xs) = x + sum xs
```

Function for reversing a list
```haskell
rev :: [a] -> [a]
rev [] = []
// ++ append operator
rev (x : xs) = (rev xs) ++ [x] 
```

Function for reversing with back insert function
```haskell
revr :: [a] -> [a]
revr [] = []
revr (x : xs) = bi (rev xs) x

(:) :: a -> [a] -> [a]
bi :: [a] -> a -> [a]
bi [] x = [x]
bi (x : xs) y = x : bi xs y
```

List constructor: (:) :: a -> [a] -> [a]
- does not compute anything just create the list

Faster reverse function with accumulator
```haskell
frev :: [a] -> [a]
frev xs = help xs []

help :: [a] -> [a] -> [a]
help [] ys = ys
help (x : xs) ys  = help xs (x : ys)
```
