What is classification:
- pattern recognition are often classification
Given a domain and a set of classes
- Domain: feature space where you collect samples- all possible pixel-values you can get taking e.g., a picture from a camera.
- The set C is a set of classes you want to recognize be that cats, dogs, dolphins etc.
  - Assume each datapoint has only one class assignment.
  - Assume function $f: D \rightarrow C$, that takes some input from the domain and maps it to its correct class. Based on already observed and classified objects - even if it is not seen before.
  - Supervise vs. unsupervised
    - In clustering, we don’t have any information on C (cluster).
    - in classification, we have examples (a training set) to guide (supervise) the learning process.

Oracle
- the person or thing that provides the labels for a given classification problem for the algorithm to be trained on.

Classifier
- Trained on a training set TR $\subseteq$ O (observation) to learn the mapping function / model or hypothesis described $h : D ~\rightarrow ~ C$
- I Ideally we have $\forall o \in T R: h(o)=f(o)$, where f() is the target/ground truth function and h() is the hypothesis / model, which is the output of the learning algorithm.
- After training the classifier should work on $D \backslash TR$ and predict the correct classes
- $h(o) \approx f(o)$
![[Pasted image 20230221083124.png]]

labels 
- Ground truth labels - provided by the oracle
- Predicted truth labels - made by the model
- You want the labels to match in classification

Training of a classifier
- trying to learn a set of universal rules that can predict a certain outcome given a datapoint based on some observations (a training set TR)

Intuition 
- Stochastic process (result trends towards the same result but may vary)
- Want to generate a model that can explain the process of getting from process to result
- $h$ is an approximation of $f$ , a hypothesis to explain the data.
- In the ideal case, the hypothesis h is interpretable and helps to understand the data-generating process - pragmatically h might predict but no be interpretable. 

Classification Algorithms and their Hypothesis-Space
- restricting the hypothesis-space by some design choice which is called inductive bias / bias.
- Based on training data, a classifier typically provides a hypothesis that separates the examples belonging to different classes from each other
- Each classification algorithm comes with (more or less strict) assumptions on how separation can be achieved or defined.
- These assumptions (implicitly) define a hypothesis space H, the space of hypotheses that could possibly be learned by the given algorithm.
![[Pasted image 20230221085607.png]]
Decision tree
![[Pasted image 20230221085538.png]]
Nearest neighbour
![[Pasted image 20230221085549.png]]

Bias free learning - (example slide 16-22)
- Just learning all exam questions (non-biased learning) vs understanding the question and being able to extrapolate, solve and understand it (biased learning)
- Hypothesis space and bias
  - Hypothesis space - manifestation of the "bias"
  - f does not necessarily exist in a hypothesis space - nice if it does 
  - if f is contained in the hypotheses H it will be consistent else there will be approximation error
  - algorithm restrictions for a hypothesis space prefer certain hypotheses based on the algorithms bias
  - Note: that a hypothesis space can be infinite and yet restricted.
  - Wildcards conditions in an rule that are not considered and can be anything - has no impact on the result.

Computational learning theory (COLT)
Statistical learning theory (VLAD, Vapnik)

![[Pasted image 20230221092728.png]]
Basic algorithm
![[Pasted image 20230221092749.png]]
- Specific hypotheses are preferred since they say more about the results than a general hypotheses 
- Easier to implement 
- You'd be able to prune more of the inputs

- Overfitting region - Doing and excellent job on the training data, not able to generalise to real world examples, because the model has been to well fitted to the specific training data.
- Underfitting - leaving performance on the table by not include e.g., enough parameters, the model could be more accurate in its predictions

Bias variance dilemma
- Finding the right balance between two bias error and variance error. 
- Bias = error introduced by overly simple assumptions regarding data
- variance = error introduced by making overly complex assumptions regarding data
- Simple model has high bias and low variance
- Complex model will have low bias and high variance.
- GOAL: Find a model that has a good balance between bias and variance given a problem to achieve optimal performance
- Large training error suggests underfitting 
- Large difference between test error and training error
- way to test train multiple models and check if error difference falls with an increase in model capacity
- Model capacity - "complexity of the model"

Evaluation of classifiers
- test error ($\neq$ generalization error) is the error which occurs during testing of the trained model 
- Overfitting if training error and test error are not similar (small variance = better)
- when is it overfitting - model learned training set to well, complex model
- when is it underfitting - model hasn't learned enough about training set, simple model

m-fold cross validation
- disjoint data set no datapoint can belong to more than one test
- partitioning (randomly)
- split dataset into as equally sized partitions as possible, so that all datapoint are in some partition and only appear once per partition 
- Held-out split, 1 split is taking out and used for testing the other m-1 splits are used for training trial 1 then taking then next split and using the rest m-1 splits for training in trail 2 until k trails have been made.
- Error from each trail is averaged and that is the test error for a given model
- Today test datasets are so massive you only need to run 1 test to get the test error
![[Pasted image 20230221165124.png]]
![[Pasted image 20230221165140.png]]

Stratification
- aims at representing the class proportions in each fold
  - minimum requirement: each class should be present in the training set.
  - stratified cross-validation: the distribution of classes within each training and test set should reflect the distribution of the classes in O (observations)
  - 10-fold, stratified cross-validation, repeated 10 times (rule of thumb)
  - The evaluation procedure has the purpose of estimating the performance on $D ~\backslash ~ O$. In order to get the best possible classifier, we would use all available labelled data (O) for training.

Bootstrapping - (or 0.632 bootstrap)
- generating another randomly chosen dataset from your original datasets of the same size to use for testing
- One element can be drawn several times
- covers on average about 63% of the original dataset in the new test set
- Each element has chance $1 / n$ to be drawn and not drawn $1 - 1 / n$
- After n draws an object has not been drawn with probability $(1 - 1/n)^n$
- Large n: $(1 - 1/n)^n \approx ~ e^{-1} \approx 0.368$ 

Leave-one-out Jackknife Test
![[Pasted image 20230221170234.png]]
- Used for very small datasets in e.g., medicine or so
- basically m-fold cross validation with m = # datapoints
- For |O| = n, this is an n-fold cross-validation.
- Pro: no random effect
- Con: stratification not possible
- Leads to relatively pessimistic performance estimate

Confusion Matrix
- Represents the number of correctly and incorrectly predicted classes made by the hypotheses.
- Correctly predicted are seen on the diagonal
- Confused classes are seen outside the diagonal
![[Pasted image 20230221170455.png]]

Quality Measures Classifiers
- Given a classifier h, a training set TR ⊆ O, and a test set TE ⊆ O. f(o) is the actual class of o, h(o) is the class predicted by the classifier h. Then we have:
- accuracy of h on TE:
  - $\operatorname{acc}_{T E}(h)=\frac{|\{o \in T E \mid h(o)=f(o)\}|}{|T E|}$

- true classification error:
  - $\operatorname{err}_{T E}(h)=\frac{|\{o \in T E \mid h(o) \neq f(o)\}|}{|T E|}$

- apparent classification error:
  - $\operatorname{err}_{T R}(h)=\frac{|\{o \in T R \mid h(o) \neq f(o)\}|}{|T R|}$


Focus on Individual Classes
- If we focus on a single class (the “positive” class) vs. all other classes (the “negative” class), the confusion matrix can be read as follows:
![[Pasted image 20230223085721.png]]
This notation is also often used in two-class problems, where we have a particular interest to detect cases of the “positive” class, e.g., medical tests on specific diseases.

Quality Measures for individual classes
![[Pasted image 20230223090326.png]]

- Recall proportion of tests that have been predicted correctly
    $\begin{aligned} & f_i=\left\{o \in T E \mid f(o)=c_i\right\}: \\ & \operatorname{recall}_{T E}(h, i)=\frac{\left|\left\{o \in f_i \mid h(o)=f(o)\right\}\right|}{\left|f_i\right|}\end{aligned}$
    - Recall = TP / (TP + FN)

- Precision Proportions of test predicted as a class which actually belong to that case
    $\begin{aligned} h_i=\left\{o \in T E \mid h(o)=c_i\right\} & : \\ \operatorname{precision}_{T E}(h, i) & =\frac{\left|\left\{o \in h_i \mid h(o)=f(o)\right\}\right|}{\left|h_i\right|}\end{aligned}$
    - Precision = TP / (TP + FP)


If you have to increase the number of parameters means you have to increase the model size would suggest that you have a none parametric model otherwise it would be a parametric model.

K-nearest neighbours classification (None parametric model)
- a simple classifier: assign to a new object the class of the k-nearest neighbour in the training data
- potential problem: nearest neighbour might be an outlier, somehow unusual, misleading
- decision set: the set of (k) nearest neighbours considered for the classification decision
- Lazy learner - No training face
- needs entire dataset present to be able to function inside a device with low memory its unacceptable 
- prediction time proportional to dataset size
- decision rule: how to decide the class, given the potentially different classes of the k nearest neighbours
  - Take majority vote
  - Potentially weighted
  - K should be odd
$h\left(x_q\right)=\arg \max _{c \in C} \sum_{i=1}^k w_i \delta\left(c, f\left(x_i\right)\right)$ where $\delta(a, b)=\left\{\begin{array}{l}1 \text { if } a=b \\ 0 \text { otherwise }\end{array}\right.$
![[Pasted image 20230223092614.png]]
Decision boundaries with an increase in k se slides 43-44

Decision set:
![[Pasted image 20230223093356.png]]
- k too small: classifier is sensitive to outliers
- k too large: potentially takes objects belonging to other classes into the decision set
- medium k: best quality
- rule of thumb: 1 << k $\leq$ 10, but consider, e.g., size of classes in training set 

Decision rule
- Standard: chose majority
- advanced: put weights on the class votes
  - by distance, typically squared inverted distance
    - weight $($ dist $)=\frac{1}{\text { dist }^2}$
    - by class proportions: If a class is small, it has a smaller chance of being the majority in some decision set.

Bias <-----> Variance

High variance only data speaks - memorizing test data and becomes overfitted 

High bias means that the model doesn't care about the data it generates random data.

For KNN we have that:
Bias <-----> Variance
K = inf          K = 1

Pros:
- Easy to apply: requires only training data and distance function
- Often good classification accuracy
- Incremental: easy adaptation to new training data
- No training required (“lazy learner”)

Cons:
- Inefficient prediction: each decision requires k nearest neighbour query
- Does not deliver explicit knowledge about classes
- Difficult to choose k, esp. if classes are of very different size
