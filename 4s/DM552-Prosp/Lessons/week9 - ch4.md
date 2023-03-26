1. Consider the following program fragment written in a pseudo-language which uses static scope and where the primitive read(Y) allows the reading of the variable Y from standard input.
``` java
int X = 0; 
int Y; 
void fie() { 
  X++; 
} 
void foo() { 
  X++; 
  fie();
} 
read(Y); 
if Y > 0 {
  int X = 5; 
  foo();
} else foo(); 
write(X);
```
- State what the printed values are:
  - if y > 0 then x = 2 else then x = 2

2. Consider the following program fragment written in a pseudo-language that uses dynamic scope.
``` java
int X;
X = 1;
int Y;
void fie() {
  foo();
  X = 0;
}
void foo() {
  int X;
  X = 5;
}
read(Y);
if Y > 0 {
  int X;
  X = 4;
  fie();
} else fie();
write(X);
```
- State which is (or are) the printed values:
  - if y > 0 then x = 1 else then x = 0

3. Consider the following code fragment in which there are gaps indicated by (\*) and (\*\*). 
   - Provide code to insert in these positions in such a way that - The function foo declared at (\*):
   - a) If the language being used employs static scope, the two calls to the procedure foo assign the same value to x. 
   - b) If the language being used employs dynamic scope, the two calls to the procedure foo assign different values to x.
``` java
{ int i; 
int j = 0;
foo() { return j; }
for (i=0; i<=1; i++) { 
  int x; 
  int j = i; 
  x = foo(); 
} }
```
 

4. Provide an example of a denotable object whose life is longer than that of the references (names, pointers, etc.) to it.
``` java
// someFile was on the computer before the myFile variable was created. 
File myFile = new File("someFile.txt");
...
return 0;
// program exits but somefile.txt still remains on the computer.
```

``` java 
int x = 0;
void foo(int *y) { write *y }
foo(x)
```

5. Provide an example of a connection between a name and a denotable object whose life is longer than that of the object itself.
``` java
// x is declared
int x;
... // some time passes on now x is assinged the integer "object" 42
x = 42;
... // some time passes and x is assigned a new value 42 no longer exists but x does, so it has lived longer.
x = 100
return 0;
```

``` java
int *foo() {
	int x = 0;
	return x * x;
}

int *y = foo();
```


# HASKELL
- Make list of numbers except for 5
  a = [x | x <- [0..10], x/=5]
  
  - Add your favourite number to all the numbers in your list: 
    [x + 42 | x <- a]

  - Double the numbers as long as they don't exceed some threshold: 
    [if (x+x > thres) then x + x else x | x <- a]
    
  - Let each element become its own list (inside the list).
    [[x] | x <- a]

- Remove all vowels (or some other set of letters you dislike) from a string.
   [x | x <- a, not(x `elem` "aeiou")]

Make list of strings to do:
a = ["Hello", "World", "You", "is", "Ugly", "Fuck", "You,", " You", "dumb biatch"]
- Get the length of each string.
  [length(x) | x <- a]
  
- Get the strings with at least fx. 4 characters.
  [x | x <- a, length(x) >= 8]

Make a list of names and a list of ages.
ages = [12, 21, 7, 41, 50, 7]
names = ["Theis", "Thomas", "Steffen", "Mikkel", "Nicolai", "Bastain"]
- Use `zip` to make a list of persons (name, age tuple)
person = zip names ages
- filter the persons
  starting with `'T'`
  [x | x <- person, (fst x) !! 0 /= 'T']
  
  people with more than 5 letters in their name
  [x | x <- person, length(fst x) > 6]
  
  people older than 21.
   [x | x <- person, (snd x) < 21]
   
  - Make a function with different patterns, which given a person (either the tuple or the two values), says something about that person, e.g. given a person starting with `'A'` , the function may respond with the string `"You're in the T-club"`.
   [if (fst x) !! 0 == 'T' then "you are in the T-club" else "you are not in the T-club" | x <- person]

Another exercise regarding people and ages:

- Make a function that takes two triples `(d,m,y)` which represents two dates (day, month, year), a birthday and a "current" date, and returns a single integer that is their "current" age in whole years.
  - is located in the func.hs


1.  Make a function that takes a point (an (x,y)-tuple) and returns the distance between the point and the origin (0,0). (Just Google the formula if you forgot.)
	see func.hs file pointDist

2.  Make a list of x-coordinates and a list of y-coordinates and use `zip` to make a list of points.
   x = [1,2,3], y = [3,2,1]
   cords = zip x y 

3.  Make a list of numbers and use a single list comprehension on it to make a list of points. (Hint: You can reference the same list multiple times in a list comprehension.) Can be skipped if you have trouble.
   q = [65,34,28,49,9,19,24,85,12,59,58,39,93
   [(x,y) | x <- q, y <- q]


4.  Make a list of the distances to the origin.
   [(1,9),(2,8),(3,7),(4,6),(5,5),(6,4),(7,3),(8,2),(9,1)]
   [pointDist(x) | x <- cords]
   
5.  Make a new distance function that takes two points and returns the distance between them.
   see func.hs
   
6.  Make a list of pairs of points, using list comprehensions.
   [((x,y), (z,w)) | x <- [1..5], y <- [5,4..1], z <- [1,2..5], w <- [1..5]   
   
7.  Make a list of their distances.
[pointDistPoint (fst x) (snd x) | x <- points]
