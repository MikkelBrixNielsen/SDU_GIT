![[Pasted image 20230313160029.png]]
``` python
def f(b):
	global x
	x += 1
	return b + x 
```
Left to right$(4 + f(0) * (2 + f(0) = (4 + 1) * (2 + 2) = 20$

Right to left$(4 + f(0) * (2 + f(0) = (4 + 2) * (2 + 1) = 18$


![[Pasted image 20230313160037.png]]
This is not tail recursion since the first ninetyone has to wait for the second one of the to evaluate before it can evaluate there is no accumulation of results during the recursive calls. 


![[Pasted image 20230313160049.png]]
Since its bounded iteration it will take z as being final when the loop is initialized and do 5 iterations and print from 1 to 5 and outside the for loop it will print 6