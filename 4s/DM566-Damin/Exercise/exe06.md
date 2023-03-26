### 6.1)
a)
$Pr(A|B) = \frac{Pr(A\cap B)}{Pr(B)} = \frac{0.3}{0.4} = 3/4$

b)
$Pr(B|A) = \frac{Pr(A\cap B)}{Pr(A)} = \frac{0.3}{0.6} = 1/2$

### 6.2)
S = "sick"
$D =$ "positive detection"
$P(S) = 0.001$
$P(D + S) = 0.99$ 
$P(D + !S) = 0.02$
$P(D) = P(S\cap D) + P(!S\cap D)$$$P(S|D) =\frac{P(S\cap D)}{P(D)} \Rightarrow$$ $$ \frac{P(D + S)* P(S)}{P(S\cap D) + P(!S\cap D)} \Rightarrow$$ $$ \frac{0.99*0.001}{(0.001*0.99) + (0.999*0.02)} = 4.721\%$$
### 6.3)
a)  k = 4
![[Pasted image 20230315191842.png]]
more circle so circle

b) k = 7
![[Pasted image 20230315191904.png]]
More circle so circle

c) k = 11 
![[Pasted image 20230315191802.png]]
More squares so square

6.4)
Having n >= 4 points in a sample space, when querying a point in the sample space with k = 1, that point would only find itself, so it wouldn't know it is a part of another cluster. But when using all other points but itself to train it would become a part of a cluster with more points than itself. 