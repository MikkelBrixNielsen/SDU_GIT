## Exercise 2.1
a) {("apples"), ("bananas"), ("cherries"), ("apples, bananas"), ("apples", "cherries"), ("bananas", "cherries"), ("apples", "bananas", "cherries"), ()}

b) $2^7$ = 128


c) $2^n$, where n is the number of items in the database.

d) 
- when having 3 items in the database the amount of 2-itemssets are 3.
- when you have 5 items in the database the amount of 2-itemssets are 10.
- When it is a k-itemset  $\prod_{i=0}^{k-1}(n-i)$ or $\frac{n!}{k!(n-k)!}$, where n is the number of items in a database and k is the itemset size.

## Exercise 2.2
a) 
Support = 4
Confidence = 4/5 = 80%

b)
Support = 4 
confidence = 4/7 = 57,14%

c)
milk, beer, diapers, bread, butter, cookies
can make 20 different combinations, following the formula from 2.1 we get:
$\frac{6!}{3!(6-3)!} = 20$



d)
We have the formula $3^n - 2^{n+1} + 1$, where n is the number of items in the data set replacing n with 6 it yields 602 rules.

or 

$\sum_{i=1}^{d-1}(d,i)*(2^{d-i}-1)$

e)
That would be a 4-itemset, which are sets 9 and 6.

f)
{bread, butter} - frequency of 5 in tID 6, 7, 9, 2 and 4.

g)
milk support = 5
butter support = 5
butter and milk = 3

Confidence for {milk} => {butter} = 3/5 = 60%
Confidence for {butter} => {milk} = 3/5 = 60%


## Exercise 2.3
Combination step: 
(1,2,3,4), (1,2,3,5), (1,2,4,5), (2,3,4,5), (2,3,4,6), (2,3,5,6)

Pruning step:
(1,2,3,5), (2,3,5,6)

## Exercise 2.4
a)
Since Y' is a subset of Y it would have at least the same frequency of Y or greater than that. This would lead to a possible increase in support and as the support increases for a single item in the set the confidence will fall for the union of all the items in the set.

b)
Look at solution for exe02

## Exercise 2.5
look at solution for exe02

