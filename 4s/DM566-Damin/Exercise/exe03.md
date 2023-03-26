# exe3.1:
## a)
{} (9)
A(7), B(4), C(7), D(6), E(6)
AB(3), AC(5), AD(4), BC(4), BD(3), BE(3), CD(5), CE(6), DE(4)
ABC(3), ABD(2), ABE(2), ACD(2), ACE(4), ADE(2), BCD(3), BCE(3), BDE(2), CDE(3)
ABCD(2), ABCE(2), ABDE(1), ACDE(2), BCDE(2)
ABCDE(1)
![[Pasted image 20230222114144.png]]

## b) Identify the closed frequent itemsets for the support thresholds σ = 4 and σ = 2, respectively. What do you observe?
### support = 4: 
- ACE(4), AC(4), AD(4), BC(4), CD(5), CE(6), DE(4), A(7), C(7), D(6) 
### support = 2: 
- ABCD(2), ABCD(2), ACDE(2), BCDE(2), ABC(3), ACE(4), BCD(3), BCD(3), CDE(3), AC(5), AD(4), BC(4), CD(5), CE(6), DE(4), A(7), C(7), D(6)

## c) Sketch an algorithm (pseudo code) to find the support for all frequent itemsets, using only the set of closed frequent itemsets as information
- .............................


# exe3.2:
![[Pasted image 20230222114502.png]]
A(7), B(5), C(5), D(5), E(6), F(2), G(2)
Prune all not higher than two, so none:

Create all combinations of size 2 and count their occurrence: 
AB(4), AC(3), AD(2), AE(4), AF(2), AG(2), BC(2), BD(2), BE(2), BF(0), BG(1), CD(1), CE(4), CF(2), CG(2), DE(3), DF(1), DG(1), EF(2), EG(2), FG(2)

Prune all not higher than sigma equal two, so BF, BG, CD, DF, and DG:

AB(4), AC(3), AD(2), AE(4), AF(2), AG(2), BC(2), BD(2), BE(2), CE(4), CF(2), CG(2), DE(3), EF(2), EG(2), FG(2)

Create all combinations of size 3 and count their occurrence:
ABC(2), ABD(2), ABE(2), ABF(0), ACE(2), ADE(2), AEF(2), ABG(0), ACD(0), ACF(1), ACG(1), ADF(1), ADG(1) AEG(1), AFG(1) BCD(0), BCE(1), BDE(1), CEF(2), CEG(2), CFG(2), EFG(2)

Prune subset not in frequent itemsets, so ABF(BF), ABG(BG), ACD(CD), ADF(DF), ADG(DG), BCD(CD) and then prune not higher than sigma = 2 and subset, so  ACF, ACG, AEG, AFG, BCE, BDE:

ABC(2), ABD(2), ABE(2), ACE(2), ADE(2), AEF(2), CEF(2), CEG(2), CFG(2), EFG(2)

Then create combinations of 3:
ABCD(0), ABCE(1), ABDE(1), CEFG(2)

Prune subset not in frequent itemsets, so ABCD(BCD), ABCE(BCE), ABDE(BDE) and nothing can be pruned due to sigma, so we get:

CEFG(2)

# exe3.3:
![[Pasted image 20230222114523.png]]
## warm-up)
![[Pasted image 20230222134558.png]]

## a) Extract from each picture a color histogram with the bins red, orange, and blue (the white pixels are ignored)
![[Pasted image 20230222132039.png]]

## b) Which pictures are most similar to the query q, using Euclidean distance? Give a ranking according to similarity to
![[Pasted image 20230222132051.png]]

## c) The results are not entirely satisfactory. What could you change in the feature extraction or in the distance function to get better results? Report the improved feature extraction and features or the improved distance function
- You only take into consideration how many of each pixel exists in the two images not if they are place in similar positions, so to images that look complete different can be the exact same using this process.
- ![[Pasted image 20230222135304.png]]

# exe3.4:
![[Pasted image 20230222123443.png]]
