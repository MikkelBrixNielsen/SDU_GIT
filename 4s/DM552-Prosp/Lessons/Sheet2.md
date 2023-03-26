-   `['a', 'b', 'c']`  - $[char]$
-   `('a', 'b', 'c')` - $(char, char, char)$
-   `(True, 'a')` - $(Bool, char)$
-   `[(True, 'a'), (False, 'b')]` - $[(Bool, cahr)]$
-   `([True, False], ['a','b'])` - $([Bool],[char])$ 
-   `tail` - $tail :: [a] \rightarrow [a]$
-   `reverse` - $reverse :: [a] \rightarrow [a]$
-   `[tail, reverse]` - $[reverse, tail] :: [[a] \rightarrow [a]]$

-   `length` - $Foldable t => t a \rightarrow Int$
-   `null` - $Foldable t => t a \rightarrow Bool$
-   `head` - $[a] \rightarrow a$
-   `take` - $int [a] \rightarrow [a]$
-   `maximum` - $(Foldable t, Ord a) => t a -> a$
-   `sum` - $(Foldable t, Num a) => t a \rightarrow a$
-   `elem` - $a ~[a] \rightarrow bool$
-   `repeat` - $a \rightarrow [a]$
-   `cycle` - $[a] \rightarrow [a]$
-   `succ` - $a => a \rightarrow a$

