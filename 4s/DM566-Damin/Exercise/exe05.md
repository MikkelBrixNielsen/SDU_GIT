### 5.1)
K = 3
---------------ITERATION 0---------------
Cluster 1:
----Centroid: (6.67, 8.33)
----Points: [(7, 8), (7, 9), (6, 8)]
----TD2-score: 1.3334000000000001

Cluster 2:
----Centroid: (1.5, 4.0)
----Points: [(2, 3), (1, 5)]
----TD2-score: 2.5

Cluster 3:
----Centroid: (6.67, 4.0)
----Points: [(10, 1), (3, 4), (7, 7)]
----TD2-score: 42.6667

---------------ITERATION 1---------------
Cluster 1:
----Centroid: (6.75, 8.0)
----Points: [(7, 8), (7, 9), (6, 8), (7, 7)]
----TD2-score: 2.75

Cluster 2:
----Centroid: (2.0, 4.0)
----Points: [(2, 3), (1, 5), (3, 4)]
----TD2-score: 4.0

Cluster 3:
----Centroid: (10.0, 1.0)
----Points: [(10, 1)]
----TD2-score: 0.0

---------------ITERATION 2---------------
Cluster 1:
----Centroid: (6.75, 8.0)
----Points: [(7, 8), (7, 9), (6, 8), (7, 7)]
----TD2-score: 2.75

Cluster 2:
----Centroid: (2.0, 4.0)
----Points: [(2, 3), (1, 5), (3, 4)]
----TD2-score: 4.0

Cluster 3:
----Centroid: (10.0, 1.0)
----Points: [(10, 1)]
----TD2-score: 0.0

K = 4, TD2 score becomes less
K = 5, TD2 score becomes even less


### 5.2)
a)
Recall = TP / (TP + FN)
Precision = TP / (TP + FP)

b)
Confusion matrix
![[Pasted image 20230313122354.png]]
A: TP=4, TN=5, FP=3, FN=1
B: TP=2, TN=7, FP=1, FN=3
C: TP=3, TN=6, FP, 2, FN=2

Recall A = 4 / (4+1) = 4/5 = 80%
Recall B = 2 / (2+3) = 2/5 = 40%
Recall C = 3 / (3+2) = 3/5 = 60%

Precision A = 4 / (4+3) = 4/7 = 57,143%
Precision B = 2 / (2+1) = 2/3 = 66,67%
Precision C = 3 / (3+2) = 3/5 = 60%

c)
![[Pasted image 20230313125557.png]]

d)
Total: TP=9, TN=18, FP=6, FN=6
MICRO:
Recall = 9 / (9+6) = 9/15 = 60%
Precision = 9 / (9+6) = 9/15 = 60%
$F1 = \frac{2*0.6*0.6}{0.6+0.6} = 0.6$

MACRO:
AVG recall = $\frac{80\%+ 40\% + 60\%}{3} = 60\%$
AVT precision = $\frac{57.143\% + 66.67\% + 60\%}{3} = 61.271\%$
$F1 = \frac{2*0.6*0.61271}{0.6+0.61271} = 0.6062883954$

Macro Average all classes have the same weight, often a desired property.
Micro-Average, the classes are weighted by their size, so classes with a small size play a very small role. 


### 5.3)
a)
Since both classes are the same size and and are assigned by random the best you can do is to guess the majority class resulting in an error rate of 50% 

b) 
Since each element from class A and B would be used for validation. Then when using all datapoints from one class and all but one from the other then the model would predict the majority class which due to A and B being of equal size would result in the element left out to be of the non-majority class which for each iteration of the validation would result in a 100% error rate

c)
10-fold cross-validation would at best have an error rate of 50%, when there is a totally equal distribution of A and B in both test and training data and at worst 100% error rate when there are only either A or B in the validation, so considering there would be an equal number of validation where there would be 100% error, somewhere in-between and 50% error it would probably end-up around 75% error rate and be worse than the bootstrap strategy.

The optimal classifier since each dataset is the same size would be to just remember what was seen previously. And if not seen predict randomly would yield 50% (Which can become 100% if enough runs are done). But following the formula it would be:
$ER = 0.632 * 0.5  + 0.368 * 0 = 31,6\%$, too optimistic.


### 5.4)
a)
since we examine 3 fuses and don't care what they are we have a sample space of size 3, which is $2^3$

b)
i) $A \cup B = \{0,1,2,3,4,5,6\}$
ii) $A \cup C = \{0,1,2,3,4,5\}$
iii) $A \cap B = \{3,4\}$
iv) $A \cap C = \{1,3\}$
v) $\overline{A} = \{5,6\}$
vi) $\overline{A \cup C} = \{6\}$

c)
i) $D = \{ [NND], [NDN], [DNN] \}$
ii)  $E = \{ [NND], [NDN], [DNN], [NNN]\}$
iii) $G = \{ [NND], [NDN], [NNN]\}$
iv) $\overline{G} = \{[DNN], [DDN], [DDD], [NDD], [DND]\}$
    $D \cap G = {[NND], [NDN]}$
    $D \cup G = \{[NND],[NDN],[DNN],[NNN]\}$
    $E \cup G = \{[NND],[NDN],[DNN],[NNN]\}$
    $E \cap G =\{ [NND], [NDN], [NNN]\}$
    


















