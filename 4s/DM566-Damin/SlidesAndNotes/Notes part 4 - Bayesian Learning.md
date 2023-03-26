## Important things
1) Bayesian model selection
   Bayes rule
   - Updating once believes based on the probability of the cause of some number of events  
   - $Pr(I|S) = \frac{Pr(S|I) ~ Pr(I)}{Pr(s)}$
   - $Pr(S|I) \rightarrow Likelihood$
   - $Pr(s) \rightarrow Evidence~/~all~ \mathcal{H}~/~Marginalisation$
   - $Pr(I) \rightarrow Prior knoweledge$
   - $Pr(I|S) \rightarrow Posterior~belif$
   - Likelihood = probability of an outcome given a model
   - Probability = given a model what is the frequency at which an outcome will occur

2) Bayes optimal predictor
   - Weighted distance, majority and class balance together will give the best average prediction when considering Bayes optimal predictor
$$\operatorname{Pr}\left(c_j \mid \mathcal{D}\right)=\sum_{h_i \in \mathcal{H}} \operatorname{Pr}\left(c_j \mid h_i\right) \operatorname{Pr}\left(h_i \mid \mathcal{D}\right)$$
   - for query point $c_j$ what is the probability giving training data $\mathcal{D}$ that it will occur considering all given hypothesis $\mathcal{H}$

3) Naïve Bayes classifier
   - Given $Pr(x,y) = Pr(x|y)Pr(x) = Pr(y|x)Pr(x)$
   - A Discriminative model like kNN would be $$Pr(y|x)$$
- And a generative model like Chat GPT would be $$Pr(x|y) Pr(y)$$
- Given $Pr(a_1, a_2 ... a_n | c_i) all Pr(a_1)Pr(a_2)...Pr(a_n)$ are assumed independent
- Better for categorical data


# Bayesian 
Bayesian describes the human decision process very well:
- Have prior belief + Experience new data (prejudice) => Updated belief / posterior belief (Aposterior)
- Probability is a score of belief 

Probability - Frequentist definition
- The frequency at which an event will appear if you repeat a trial infinitely many times
- $\lim_{trials \to \inf} \frac{events}{trials}$

# Sample space $\Omega$
- Sample space is a list of all possible events that can occur when observing a trail e.g., rolling a die = {1,2,3,4,5,6} or flipping a coin = {H,T}

# Event $\subseteq \Omega$
- Event will be any subset of the sample space, so for a die roll could have the event where all occurrences are even = {2,4,6}

# Power set space
- $\mathcal{P}(\Omega)$ is all possible outcomes that can occur when running a trail called the power space 

# Probability function 
- Probability measure a function that maps a subset of the sample space or power space Pr: $\mathcal{P}(\Omega) \rightarrow [0,1]$
- $\mathcal{P}=1 \rightarrow = 1$, called "sure event" an event that you are sure will occur when running a trail and an event occurs
- Probability of $E1 \cup E2 =$ Probability of $E1 + E2$
![[Pasted image 20230228084130.png]]
- ### Mutually disjoint event 
  - Two samples of the event space ($\Omega$)
  - If two events do not intersect $E1 \cap E2 = \mathcal{Ø}$ 

# Probability Space
![[Pasted image 20230228084642.png]]

# Event combinations
- $E1 \cap E2$, occurrences of both E1 and E2
- $E1 \cup E2$, occurrence of either E1 or E2
- $E1 ~\backslash~ E2$, occurrence of E1 without E2
- $\bar{E} = \Omega ~\backslash~ E$, Complementary event of E
![[Pasted image 20230228085621.png]]
- $\overline{E}$, is everything but E occurring
- $\overline{E1 \cup E2}$, complementary event but E1 & E2
- $\overline{E1 \cap E2}$, everything but intersection of E1 & E2

# Combined probability
![[Pasted image 20230228091940.png]]
- The probability of two events E1 and E2 to occur at the same time we have the probability of E1 + probability of E2 subtracted by the intersection of E1 and E2 because otherwise the intersection would be counted twice

# Union Bound
![[Pasted image 20230228092104.png]]
Based on combined probability this holds

# Joint event $Pr(A \cap B)$
Two event takin place at the same time 

# Conditional probability
![[Pasted image 20230228093847.png]]
![[Pasted image 20230228093854.png]]
- We look for the probability of E ∩ F within the sets of events defined by F.
- Because F restricts the sample space, we normalize the probabilities by dividing by Pr(F).
- If E and F are independent, information about F should not affect the probability of E.
![[Pasted image 20230228094202.png]]

# Independent Events
![[Pasted image 20230228092425.png]]
- Two events E and F are independent if the probability of their intersection is equal to the probability of E multiplied by the probability of F
- If events A and B are independent then knowledge about event A does not change the probability of B.
- If A and B are not independent, then we can quantify the conditional probability of A subject to our knowledge of event B
![[Pasted image 20230228094213.png]]

# Condition Defines a Probability Space
- Conditioning on an event only changes the sample space everything stays the same
![[Pasted image 20230228094441.png]]

# Quality Measures for Association Rules
### Support: $s(X \rightarrow Y)$ = $s(X \cup Y)$
- The frequency of an itemset in the database can be seen as an empirical estimate of its probability, given the sample represented by the database:
- Probabilistic: $Pr(X) = \frac{s(X)}{|\mathcal{D}|}$ 
![[Pasted image 20230228100204.png]]

### Frequency: $\mathcal{f}(X \cup Y) = \frac{s(X \cup Y)}{|\mathcal{D}|}$

### Confidence: $conf(X \rightarrow Y) = \frac{s(X \cup Y)}{s(X)}$
- The confidence is the conditional probability that a transaction contains the consequent Y given that it contains the antecedent X:
- Probabilistic: $\frac{Pr(X \cap Y)}{Pr(X)} = Pr(Y|X)$
- The confidence of a rule $X \rightarrow Y$ is not a useful measure unless we compare it with the frequency of Y, i.e., the prior (unconditional) probability.
- If we have $Pr(Y|X) < Pr(Y)$ this means that in the presence of X, Y becomes less likely as it is unconditionally!

### Lift: $Lift(X \rightarrow Y) = \frac{conf(X \rightarrow Y)}{\mathcal{f}(y)}$
- We can see Lift as normalization of the confidence by the prior probability of the consequent
- Probabilistic: $\frac{Pr(X \cap Y)}{Pr(x)*Pr(Y)}$
- ratio of the observed joined probability of X and Y to the joint probability expected for statistically independent events
- Lift is a (symmetric!) measure for the surprise of a rule, values of around 1 is boring.
- very small / very large values are interesting

### Jaccard: $Jaccard(X \rightarrow Y) = \frac{s(X \cup Y)}{s(X) + s(Y) - s(X \cup Y)}$
- The Jaccard coefficient in general is a measure for the similarity between two sets
- Probabilistic: $\frac{Pr(X \cap Y)}{Pr(X) + Pr(Y) - Pr(X \cap Y)} = \frac{Pr(X\cap Y)}{Pr(X \cup Y)}$
- A symmetric measure of how often both, X and Y, occur simultaneously, relative to the occurrence of both or either overall.
- Similarity of the itemsets X and Y based on their individual occurrences and their co-occurrences

### Conviction: $conviction(X \rightarrow Y) = \frac{1-\mathcal{f}(Y)}{1-conf(X \rightarrow Y)}$
- Conviction of a rule measures the expected error: how often does X occur in a transaction where Y does not
- $\begin{aligned} & \frac{\operatorname{Pr}(\bar{Y})}{1-\frac{\operatorname{Pr}(X \cap Y)}{\operatorname{Pr}(X)}}=\frac{\operatorname{Pr}(X) \operatorname{Pr}(\bar{Y})}{\operatorname{Pr}(X)-\operatorname{Pr}(X \cap Y)} \\ & =\frac{\operatorname{Pr}(X) \operatorname{Pr}(\bar{Y})}{\operatorname{Pr}(X \cap \bar{Y})}=\frac{1}{\operatorname{Lift}(X \Rightarrow \bar{Y})}\end{aligned}$
- Compares the observed joint probability of X and $\overline{Y}$ with their joint probability expected for independence
- Asymmetric measure

# The law of total probability
![[Pasted image 20230228122752.png]]
![[Pasted image 20230228122800.png]]
- Given a sample space covered entirely by 5 events
- $E1 \cup E2 \cup E3 \cup E4 \cup E5 = \Omega$ (Sample space)
- $E_i \cap E_j = \mathcal{Ø}, for~i \neq j$

# Bayes' Rule
- Updating once believes based on the probability of the cause of some number of events  

Likelihood = probability of an outcome given a model 
Probability = given a model what is the frequency at which an outcome will occur

$Pr(I|S) = \frac{Pr(S|I) ~ Pr(I)}{Pr(s)}$
$Pr(S|I) \rightarrow Likelihood$
$Pr(s) \rightarrow Evidence$
$Pr(I) \rightarrow Prior knoweledge$
$Pr(I|S) \rightarrow Posterior$

![[Pasted image 20230302123702.png]]

![[Pasted image 20230228093847.png]]

![[Pasted image 20230228122752.png]]

![[Pasted image 20230302123941.png]]

## Example 1)
- Have three coins, two are fair, 1 is biased showing head 2/3. of a time.
- Each coin flipped: 1st & 2nd = head, 3rd = tail
- Probability of 1st coin being the biased one?
- $E_i$ event that the $i^{th}$ coin is biased
- $B$ event that three coin flips cam up head, head, tail
- Prior probability: $Pr(E_i) = \frac{1}{3}$ for $i = 1,2,3$
![[Pasted image 20230302125426.png]]

## Example 2)
- Doctor sees patient with fewer and rash
- 80% patients flu, 45% allergy, 90% have fewer and rash symptoms
- Knows 50% have flu, 40% allergy, 10% infection
- Should doctor treat patient for infections?

Example 3)
- Test shows patient has infection
- Test error rate 10%
- Probability patient has infection
![[Pasted image 20230302132946.png]]
![[Pasted image 20230302133044.png]]

# Bayesian Reasoning
- Alternative models to explain a fact
- Each model defines probability for observed data 
- Which is the best model, explanation ?
- $E_1$, $E_2$, . . . , $E_n$ are the alternative models
- For each model $Pr(B|E_j)$ how well a model explains the facts
- $\operatorname{Pr}\left(E_j \mid B\right)=\frac{\operatorname{Pr}\left(E_j \cap B\right)}{\operatorname{Pr}(B)}=\frac{\operatorname{Pr}\left(B \mid E_j\right) \operatorname{Pr}\left(E_j\right)}{\sum_{i=1}^n \operatorname{Pr}\left(B \mid E_i\right) \operatorname{Pr}\left(E_i\right)}$

# Uncertainty
- Goal / Motivation
  - Robustness
  - Safety
  - Reliable
  - Sample-efficiency
- Epistemic Uncertainty
  - Uncertainty refers to uncertainty that arises from a lack of knowledge or understanding. It is often associated with model uncertainty or errors in measurement.
- Aleatoric Uncertainty
  - Uncertainty, on the other hand, refers to uncertainty that arises from the inherent randomness or variability of a system. It is often associated with the variability of the data or the system's behavior.

# Probabilistic classification
- A classifier predicts for some objects $x_q$ which class $c_i$ it belongs to
- Often the prediction can be expressed as probability estimate $Pr(c_i~|~x_q)$
- The classifier would then decide for the most likely class: $h(x_q)=arg~max_{c_i \in C} Pr(c_i~|~x_q)$
- Often this estimate is based on an estimate of how likely the object would be if it would belong to this or to that class: $Pr(x_q ~|~ c_i)$

# Proportions of classes in the decision set
- Let x1, . . . , xk = kNN(xq) be the k nearest neighbors of instance $x_q$, i.e., the decision set for the instance $x_q$.
- For a given instance $x_q$ and classes $C = \{c_1, ..., c_m\}$
$$E_j = "f(x_q)=c_j"$$
$$\Omega = \cup_{j=1}^{m}E_j$$
- The relative frequency of a class $c_j$ in the decision set KNN($x_q$) is an empirical estimate of the probability of the event "$f(x_q)=c_j$"
$$Pr(E_j~|~x_q) = \frac{|\{x_i|x_i \in kNN(x_q)\wedge f(x_i)=c_j\}|}{k}$$
$$\frac{\Sigma^k_{i=1}δ(c_j,f(x_i))}{k}, with~δ(a,b) = 1~if~a=b~,0~otherwise$$
# Decision Rule - Weighted by Distance
- Weight can be introduced to the components in the decision rule. 
$h\left(x_q\right)=\arg \max _{c \in C} \sum_{i=1}^k w_i \delta\left(c, f\left(x_i\right)\right)$
- e.g., $w_i=\frac{1}{\operatorname{dist}\left(x_i, x_q\right)^2}$
- $\operatorname{Pr}_w\left(\left\{f\left(x_q\right)=c_j\right\} \mid x_q\right)=\frac{\sum_{i=1}^k w_i \delta\left(c_j, f\left(x_i\right)\right)}{\sum_{i=1}^k w_i}$

# kNN classifier as application of Bayes' rule
- Let $k_i = |\{x|x \in kNN(x_q) \wedge f(x) = c_i\}|$
- let $n_i = |\{x|x \in O \wedge f(x) = c_i\}|, i.e. Pr(c_i) = \frac{n_i}{|O|}$
- let $V_k(x)$ be the volume of the kNN(x)
$\begin{aligned} & \operatorname{Pr}\left(x \mid c_i\right)=\frac{\frac{v_i}{n_i}}{V_k(x)}=\frac{k_i}{n_i \cdot V_k(x)} \\ & \operatorname{Pr}\left(x \mid c_i\right) \cdot \operatorname{Pr}\left(c_i\right)=\frac{k_i}{n_i \cdot V_k(x)} \cdot \frac{n_i}{|O|}=\frac{k_i}{|O| \cdot V_k(x)} \\ & \operatorname{Pr}\left(c_i \mid x\right)=\frac{\operatorname{Pr}\left(x \mid c_i\right) \cdot \operatorname{Pr}\left(c_i\right)}{\sum_{j=1}^m \operatorname{Pr}\left(x \mid c_j\right) \cdot \operatorname{Pr}\left(c_j\right)} \\ & \quad=\frac{\frac{k_i}{|O| \cdot V_k(x)}}{\sum_{j=1}^m \frac{k_j}{|O| \cdot V_k(x)}}=\frac{k_i}{k} \\ & h(x)=\arg \max _{c_i \in C}\left(\operatorname{Pr}\left(c_i \mid x\right)\right)=\arg \max _{c_i \in C}\left(\frac{k_i}{k}\right)=\arg \max _{c_i \in C}\left(k_i\right)\end{aligned}$
# Decision rule - weighted by prior class probability
- To account for very imbalanced proportions of class sizes, we can adjust the prior probability.
- Because we want each class a priori to be equally likely, we set $Pr(c_i) = \frac{1}{m}$
$\begin{aligned} \operatorname{Pr}\left(x \mid c_i\right) \cdot \operatorname{Pr}\left(c_i\right) & =\frac{k_i}{n_i \cdot V_k(x)} \cdot \frac{1}{m}=\frac{k_i}{n_i \cdot m \cdot V_k(x)} \\ \operatorname{Pr}\left(c_i \mid x\right) & =\frac{\operatorname{Pr}\left(x \mid c_i\right) \cdot \operatorname{Pr}\left(c_i\right)}{\sum_{j=1}^m \operatorname{Pr}\left(x \mid c_j\right) \cdot \operatorname{Pr}\left(c_j\right)} \\ & =\frac{\frac{k_i}{n_i \cdot m \cdot V_k(x)}}{\sum_{j=1}^m \frac{k_j}{n_j \cdot m \cdot V_k(x)}}=\frac{\frac{k_i}{n_i}}{\sum_{j=1}^m \frac{k_j}{n_j}} \\ h(x) & =\arg \max _{c_i \in C}\left(\operatorname{Pr}\left(c_i \mid x\right)\right)=\arg \max _{c_i \in C}\left(\frac{k_i}{n_i}\right)\end{aligned}$
## Example
![[Pasted image 20230306163703.png]]

# Probabilities and learning
- The aim of machine learning (or actually of science as such) could be put as "find the best hypothesis to explain the observations"
- If we approach learning probabilistically "best" means "most probable" given the data $\mathcal{D}$ plus any initial knowledge about the prior probabilities of the various hypotheses in $\mathcal{H}$
- The prior probability $Pr(h)$ denotes the initial probability of hypothesis $h$ before we observe the training data
- the prior probability could reflect any backround knowledge 
- The prior probability $Pr(\mathcal{D})$ denotes the probability of the data (observations) without any knowledge on which hypothesis holds

# Prior and posterior probabilities and Bayes' Theorem
- The conditional probability Pr(D |h) denotes the probability of the observations (likelihood of the hypothesis), given some hypothesis h (i.e., assuming, h is correct).
- The probability $Pr(h|\mathcal{D})$ is called the posterior probability, because it reflects our confidence that hypothesis h is correct after we have seen the training data $\mathcal{D}$
- Given prior probabilities $Pr(h), Pr(\mathcal{D})$ and conditional probability $Pr(\mathcal{D}|h)$ the posterior probability $Pr(h|D)$ can be computed by Bayes' theorem (1.8)
$$\operatorname{Pr}(h \mid \mathcal{D})=\frac{\operatorname{Pr}(\mathcal{D} \mid h) \cdot \operatorname{Pr}(h)}{\operatorname{Pr}(\mathcal{D})}$$
- Intuitive interpretation: $Pr(h|\mathcal{D})$ increase with $Pr(\mathcal{D}|h)$ and with $Pr(h)$ it decreases as $Pr(\mathcal{D})$ increases

# Maximum likelihood and maximum a posteriori hypothesis
- A classifier shall identify the most probable hypothesis h ∈ $\mathcal{H}$, given the observed data. I We call such a maximally probable hypothesis a maximum a posteriori (MAP) hypothesis:
$$\begin{aligned} h_{\mathrm{MAP}} & \equiv \arg \max _{h \in \mathcal{H}} \operatorname{Pr}(h \mid \mathcal{D}) \\ & =\arg \max _{h \in \mathcal{H}} \frac{\operatorname{Pr}(\mathcal{D} \mid h) \cdot \operatorname{Pr}(h)}{\operatorname{Pr}(\mathcal{D})} \\ & =\arg \max _{h \in \mathcal{H}} \operatorname{Pr}(\mathcal{D} \mid h) \cdot \operatorname{Pr}(h)\end{aligned}$$
- If we assume equal prior probabilities for all hypotheses (i.e., $Pr(h_i) = Pr(hj)∀hi , hj ∈ \mathcal{H})$, MAP is given by the maximum likelihood hypothesis:$$h_{\mathrm{ML}} \equiv \arg \max _{h \in \mathcal{H}} \operatorname{Pr}(\mathcal{D} \mid h)$$
# Most probable hypothesis vs most probable classification
- Consider some hypothesis space $\mathcal{H} = \{h_1,h_2,h_3\}$ with $Pr(h_1|\mathcal{D}) = 0.4, Pr(h_2|\mathcal{D}) = 0.3, Pr(h_3|\mathcal{D} = 0.3)$
- Obviously $h_1$ is the MAP hypothesis 
- Suppose a new instance x is encountered where $h_1(x) = A, h_2(x) = B, h_3(x) = B$ all hypotheses would then yield $Pr(A|x) = 0.4, Pr(B|x) = 0.6$
- This classification is different than the one generated by the MAP hypothesis

# Bayes Optimal classification
- We obtain the most probable classification by combining the predictions of all hypotheses weighted by the posterior probabilities.
- For the set of classes C, for any $c_j$ ∈ C, we have
$$\operatorname{Pr}\left(c_j \mid \mathcal{D}\right)=\sum_{h_i \in \mathcal{H}} \operatorname{Pr}\left(c_j \mid h_i\right) \operatorname{Pr}\left(h_i \mid \mathcal{D}\right)$$
- Therefore the optimal classification is
$$\operatorname{Pr}\left(c_j \mid \mathcal{D}\right)=\sum_{h_i \in \mathcal{H}} \operatorname{Pr}\left(c_j \mid h_i\right) \operatorname{Pr}\left(h_i \mid \mathcal{D}\right)$$
- This is called bayes optimal classifier

## Properties
- The predictions of the Bayes optimal classifier can correspond to the predictions of a hypothesis that is not contained in the original hypothesis space $\mathcal{H}$!
- The Bayes optimal classifier considers effectively a different hypothesis space $\mathcal{H'}$ , including hypotheses that perform comparisons between linear combinations of predictions from multiple hypotheses in $\mathcal{H}$.
![[Pasted image 20230306175602.png]]
## Example
![[Pasted image 20230306174301.png]]

## Estimates of prior probabilities
![[Pasted image 20230306180232.png]]
![[Pasted image 20230306180317.png]]

# Bayes classification
- For a given attribute value $a_q$ we can compute the posterior probability according to Bayes' rule $$\operatorname{Pr}\left(c_j \mid a_q\right)=\frac{\operatorname{Pr}\left(a_q \mid c_j\right) \operatorname{Pr}\left(c_j\right)}{\operatorname{Pr}\left(a_q\right)}=\frac{\operatorname{Pr}\left(a_q \mid c_j\right) \operatorname{Pr}\left(c_j\right)}{\sum_{c_i \in C} \operatorname{Pr}\left(c_i\right) \operatorname{Pr}\left(a_q \mid c_i\right)}$$
- Estimating probability from training data
![[Pasted image 20230306180458.png]]

# Maximum likelihood classification 
![[Pasted image 20230306180553.png]]

# Discrete attributes
- We can count relative frequencies to estimate probabilities
![[Pasted image 20230306180621.png]]
![[Pasted image 20230306180643.png]]

# Zero probabilities
![[Pasted image 20230306180800.png]]

# Multidimensional data
- Estimate combined probabilities of specific attribute values
![[Pasted image 20230306180912.png]]
![[Pasted image 20230306180917.png]]

# Problems for bayes classifier in multi-dimensional data
- If we have n attributes, and each can take on r different values, we have r n different attribute combinations.
- Typically, there are not enough training instances available to reliably estimate probabilities
## Example 
![[Pasted image 20230306181021.png]]
- The probability estimates are unreliable, because the sample size is too small for each instance.

# Naïve assumption 
- Assume independence among the attributes. The estimated combined probabilities based on
![[Pasted image 20230306181305.png]]
![[Pasted image 20230306181339.png]]
![[Pasted image 20230306181405.png]]

# Naïve bayes classifier
- The “Naïve Bayes classifier” relies on the assumption of independence of attributes.
- The various Pr(ci) and Pr(aj |ci) terms are estimated based on the relative frequencies of corresponding examples in the training data
- The set of these estimates constitutes the learned hypothesis.
- The class prediction is based on these estimates according to:
![[Pasted image 20230306181604.png]]
- Because of the multiplication, the replacement of zero probabilities by some heuristic minimum probability ε (cf. slide 66) is particularly important.

## Example
Given the following data should we play tennis today?
![[Pasted image 20230306181626.png]]
Prediction
![[Pasted image 20230306181652.png]]
- The Naïve Bayes classifier decides by finding the class maximizing the product of probabilities
![[Pasted image 20230306182049.png]]
![[Pasted image 20230306182056.png]]
- If we are interested in the conditional probability for “no”, we could normalize these quantities to sum up to one:
![[Pasted image 20230306182122.png]]

# Assumption of independence is a bias 
- The assumption of independence can be seen as the bias inherent to the naïve bayes classifier
- An unbiased probabilistic classifier is not practical due to a notorious lack of training examples
  - In any scenario it would overfit
- For data consisting of two classes and only 30 binary attributes we would need more than 2 billions examples just to see each combination once which is not good enough to derive reliable probability estimates
- Relying on the bias the classifier may have a tendency to be wrong if the assumption does not hold 
- the bias is necessary to make generalization feasible


Marginalisation = model averaging