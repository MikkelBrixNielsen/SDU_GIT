# ch4
![[Pasted image 20230314143351.png]]
```java
{
	int x = 2;
	int fie (int y) {
		x = x + y // uses global x, x = 2 + 5
	}
	{
		int x = 5
		fie(x); 
		write(x); // local x = 5
	}
	write(x) // global x = 7
}
```

![[Pasted image 20230314143402.png]]
```java
{
	int x = 2;
	int fie (int y) {
		x = x + y
	}
	{
		int x = 5
		fie(x); // uses local x, x = 5 + 5
		write(x); // local x = 10
	}
	write(x) // global x = 2
}
```

![[Pasted image 20230314143538.png]]
```java
{
	int x = 2;
	void fie(reference int y){
		x = x + y; // changes global x
		y = y + 1;
	}
	{
		int x = 5;
		int y = 5; // this can be deleted
		fie(x); // uses global x, x = 2 + 5
				// local x = 5 + 1
		write(x); // x = 6
	}
	write(x); // x = 7
}
```

![[Pasted image 20230314143522.png]]
``` java
{
	int x = 2;
	void fie(value int y){
		x = x + y; // changes global x
	}
	{
		int x = 5;
		fie(x++); // parses 5, updates x -> 6
		write(x); // x = 6
	}
	write(x); // x = 7
}
```

![[Pasted image 20230314143555.png]]
```java
{
	int x = 2;
	void fie(name int y){
	x = x + y; // x = 2 + 5, global x
	}
	{
		int x = 5;
		{
			int x = 7 // fucking irrelevant
		}
		fie(x++); // x++ passed in name only
				  // update local x -> 6 
		write(x); // x = 6
	}
	write(x) // x = 7
}
```

![[Pasted image 20230314143712.png]]
``` java
{
	int x = 1;
	int y = 1;
	void fie(reference int z){
		z = x + y + z; // z = 1 + 3 + 3
			           // z reference to y
	}
	{
		int y = 3;
		{
			int x = 3
		}
		fie(y); // references y, result 7
		write(y); // y = 7
	}
	write(y) // y = 1
}
```

![[Pasted image 20230314143948.png]]
``` java
{
	int x = 0;
	int A(reference int y) {
		int x = 2;
		y = y + 1;
		return B(y) + x;
	}
	int B(reference int y){
		int C(reference int y){
			int x = 3;
			return A(y) + x + y;  
		}
		if (y == 1) return C(x) + y;
		else return x + y;
	}
	write(A(x)); // references x, result
}
int x = 0 // updated to 1, updated to 2
wirte(A(x)) // A(0) -> 15
	int A(reference int y) { // y = 0
		int x = 2;
		y = y + 1; // y = 1, global x = 1
		return B(y) + x; 
		// B(1)->(13) + 2
	}
	int B(reference int y){ // y = 1
		int C(reference int y){ // y = 1
			int x = 3;
			return A(y) + x + y;
			// A(1)->(6) + 3 + 2
		}
		if (y == 1) return C(x) + y;
		// C(1)->(11) + 2
		else return x + y;
	}
	int A(reference int y) { // y = 1
		int x = 2;
		y = y + 1; // y = 2, global x = 2
		return B(y) + x; // B(2)->(4) + 2
	}
	int B(reference int y){ // y = 2
		int C(reference int y){
			int x = 3;
			return A(y) + x + y;  
		}
		if (y == 1) return C(x) + y;
		else return x + y;
		// global x + y, return 2 + 2
	}
```


![[Pasted image 20230314144206.png]]
![[Pasted image 20230314144259.png]]
```java
{
	int z = 0;
	int Omega(){
		return Omega();
	}
	int foo(int x, int y){// x=z, y=Omega() + z
		if (x == 0) return x; 
		// x evaluated is 0 returns x = 0 
		else return x + y; // is not evaluated
	}
	write(foo(z, Omega() + z));
	// z and Omega() + z both passed as names, 
	// which mean they are not evaluated before 
	// they are used
}
```
![[Pasted image 20230314144313.png]]
```java
{
	int z= 0;
	int Omega(){
		return Omega();
	}
	int foo(int x, int y){
		if (x==0) return x;
		else return x+y;
	}
	write(foo(z, Omega()+z));
}
```
Omega returning itself without any base case or evaluation would result in a infinite loop when passing it as a value.

# ch5
![[Pasted image 20230314144359.png]]
```java
	{
		int x = 0;
		int A(reference int y) {
			int x = 2;
			y = y + 1;
			return B(y) + x;
		}
		int B(reference int y){
			int C(reference int y){
				int x = 3;
				return A(y) + x + y;
			}
			if (y == 1) return C(x) + y;
			else return x + y;
		}
		write(A(x));
	}
```
![[Pasted image 20230314144550.png]]
```
G <-------|
A         |
B         |
C <-------|-------| <- inactive
A <-------|---|   |
        | G | A | C |   |
```
Point from lowest A to B and from B to first a since the lowest A overwrites the B which has overwritten the first A

# ch6
![[Pasted image 20230314144821.png]]
```java
{
	int x = 5;
	int P(name int m){ // m = x++
		int x = 2;
		return (m++) + x; 
		// x++ -> 5 & local x -> 6
		// return 6 + 2 = 8
	}
	write(P(x++) + x); // 8 + 5 = 13
}
```

# ch7
![[Pasted image 20230314145159.png]]
```java
int foo (int n, int a) {
	int tmp=a;
	if (tmp==0) return n;
	else return n+1;
}
...
int x;
x = foo(3,0);
x = foo(x+1,1);
```
To be able to call foo recursively 

![[Pasted image 20230314145211.png]]
```java
int X[10];
int i = 1;
X[0] = 0;
X[1] = 0;
X[2] = 0;
void foo (reference int Y,J){ // y = 0, j = 1
	X[J] = J+1; // X[1] = 1+1
	write(Y); // X[j] -> X[1] = 2
	J++; // j, 1 -> 2
	X[J]=J; // X[2] = 2
	write(Y); // X[2] = 2
}
foo(X[i],i);
write(X[i]); // X[2] = 2
```

![[Pasted image 20230314145249.png]]
```java
int X = 2;
void foo (valueresult int Y){ // Y = 2
	Y++; // Y, 2 -> 3 
	write(X); // Global X = 2
	Y++; // Y, 3 -> 4, connects with X
}
foo(X);
write(X); // X = 4
```

![[Pasted image 20230314145346.png]]
![[Pasted image 20230314145424.png]]
```java
int X = 2;
void foo (constant int Y){ // Y = 2
	write(Y); // Y = 2
	Y = Y + 1; // Not allowed / compiler err
}
foo(X); // dies do to interpreter error
write(X); // X = 2, does not happen
```
Could also just die do to interpreter error 

![[Pasted image 20230314145437.png]]
```java
int X = 2;
void foo (name int Y){
	X++; // global X, 2 -> 3
	write(Y); // write(global X + 1) -> 4
	X++; // global X, 3 -> 4
}
foo(X+1);
write(X); // X = 4
```

![[Pasted image 20230314145518.png]]
Deep binding using closures in a language with dynamic scope involves creating a closure that captures the current state of the calling environment when a function is defined. When the function is called, a new environment is created for it to execute in, and any variables not defined in the local environment are looked up in the closure. This allows the function to access and modify variables in the calling environment. However, dynamic scope can be tricky to use correctly and can lead to unexpected behaviour, so it should be used with caution.

![[Pasted image 20230314145553.png]]
(i) By value-result
```java
{
	int y=0;
	void f(int x){ // x = 0
		x = x+1; 
		// x = 1 not connected to global y
		throw E; // quits function 
		x = x+1; // not executed 
	}
	try{ 
		f(y); 
	} catch E { }; // catches e, does nothing
	write(y); // y = 0
}
```
(ii) By reference
```java
{
	int y=0;
	void f(int x){ // x = 0
		x = x+1; 
		// x = 1, connected to global y
		throw E; // quits function 
		x = x+1; // not executed 
	}
	try{ 
		f(y); 
	} catch E { }; // catches e, does nothing
	write(y); // y = 1
}
```

![[Pasted image 20230314145630.png]]
![[Pasted image 20230314145747.png]]
```java
void ecc() throws X {
	throw new X();
}
void g (int para) throws X {
	if (para == 0) {ecc();}
	try {ecc();} catch (X) {write(3);}
}
void main () {
	try {g(1);} catch (X) {write(1);} // 3
	try (g(0);) catch (X) (write(0);) // 0
}
```

![[Pasted image 20230314145802.png]]
```java
int f(int x){ // x = 4
	if (x==0) return 1;
	else if (x==1) throw E;
	else if (x==2) return f(1);
	else try {
		return f(x-1);
	} catch E {
		return x+1;
	}
}
```
f(4)
x = 4 goes to the else try:
    -> return f(x-1) // calls f(3)
    goes to the else try:
	    -> returns f(x-1) // calls f(2)
	    goes to the else if (x == 2) 
		    -> return f(1)
		    goes to else if (x == 1) throws E

The call for else if (x == 2) receives thrown E can't handle it so it throws it again, then the call return f(x-1), where x = 3 receives thrown E, catches it and returns 3 + 1 = 4.   
