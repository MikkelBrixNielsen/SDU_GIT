![[Pasted image 20230320164655.png]]
To fille op the first "page" and reach the second "page" of the multidimensional array you would need 10 elements, which would be $A[0][1][0]$, and for the third page you would need 10x that amount of elements, so 100 elements would be $A[1][0][0]$, then $A[2][2][5]$ would be 225 elements that each use 4 bytes of space meaning the 225th element is stored at address $225*4 = 900$ 

![[Pasted image 20230320164705.png]]
![[Pasted image 20230320164712.png]]



![[Pasted image 20230320164720.png]]
``` C
struct intList {
    int head;
    struct intList *tail;
};

typedef struct intList *IntList;

bool intListEqual(IntList l1, IntList l2) {
    if (l1 == NULL && l2 == NULL) {
        return true;
    } else if (l1 == NULL || l2 == NULL) {
        return false;
    } else if (l1->head != l2->head) {
        return false;
    } else {
        return intListEqual(l1->tail, l2->tail);
    }
}
```

![[Pasted image 20230320164741.png]]
- Well since we use struct type equivalence and struct T1 and T2 are identical in their structure the assignment of a, T3, = b, T4, would be allowed since T3 & T4's u and v variables would be considered of the same type since T1 is equivalent to T2

![[Pasted image 20230320164759.png]]
fun g) G : (a -> a) -> a -> a
- Or takes a function and a value x and returns f applied to x twice

fun H) H : (a -> bool) -> a -> a -> a
- takes three arguments, a predicate function t and two values x and y. If t(x) is true returns x; otherwise y. Therefore x and y must be of the same type since they are interchangeable

fun K) F : a -> b -> a
- Takes two potentially different arguments and returns the first of them



![[Pasted image 20230327214651.png]]


![[Pasted image 20230327214708.png]]

![[Pasted image 20230327214717.png]]
![[Pasted image 20230327214725.png]]


![[Pasted image 20230327214735.png]]

![[Pasted image 20230327214745.png]]