![[Pasted image 20230228165125.png]]
![[Pasted image 20230306184043.png]]
![[Pasted image 20230228165133.png]]
``` java
function factorial(n = 5, acc = 1): 
	if n == 0: 
		return acc 
	else: 
		return factorial(n - 1, acc * n)
```
This will make n recursive calls and that is for certain each time the function is called it will call itself n times, which is predefined to be 5.
This can indeed be generalised to other function which have a recursive statement at the end of their block. but not to function which have probability of calling themselves or not depending on some other code they are executing or user input.

(Tail call elimination) - the call is in the tail of the function

![[Pasted image 20230228165158.png]]
![[Pasted image 20230228165208.png]]
![[Pasted image 20230228165224.png]]
``` java
{ 
	int x = 1;
	void foo() {
		x = 3;
	 }
	 void bar() {
		 int x = 5;
		 foo();
	 }
	 bar();
}
```
if the code looks like this and AR for x = 1 would be made then some function would be initialized bar would be called and create and AR then foo would be called and create and AR, which would result in the stack of AR's looking like this
x = 1
bar
foo
<----- Having to resolve x here would result in looking at foo and not x which is at the top.


![[Pasted image 20230228165240.png]]
P1 -> static G, dynamic G
P2 -> static P1, dynamic P1
P3 -> static P1, dynamic P2
P4 -> static P1, dynamic P3
P2 -> static P1, dynamic P4

Dynamic pointer points to the one proceeding it and the static pointer points to where it structurally is located.

![[Pasted image 20230306182837.png]]
Dynamic scoping is easier since you can just have a stack of scopes and just use the variables and such form the scope at the top of the stack