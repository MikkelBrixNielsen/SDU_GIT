Pattern declarations:
 - pi :: float
   pi = 3.14159...

function declarations 
map, map' :: (a->b) -> [a] -> [b]
map f xs = [f x | x <- xa]
map' f (x:xs) = f(x):(map' f xs)

filter, filter' :: (a -> Bool) -> [a] -> [b]
filter t xs s= [x | x <- xs, t x]
filter' _ [] = []
filter' t (x:xs) 
	| t x = x : (filter' t xs)
	| otherwise = filter' t xs

reduce :: b -> (a->b)->[a]->b
reduce n _ [] = n
reduce n f (x:xs) = f x (reduce n f xs)

flatten = reduce [] (++)

infix declaration 
- you can use infix tag to do left and right association
- precedence is infix l or r and is ranked 0-9 with 9 being the strongest