# universal learners
- Given enough parameters it can learn any function
- cannot solve step functions - for some reason
- Does some overshooting
  - The fitted graph to the step function will curve instead of following the step

# What is machine learning:
- A computer program learning from experience, E, with respect to some class of tasks, T, and give it a measure of how well it performs at that task. It is then machine learning if the program improves after seeing data (learning from experience)
- GOALS:
  - Want small training error (underfitting)
  - Gap between training and test error small (overfitting otherwise)

# Supervised learning linear regression
- Predictor function $\hat y_n = f(x_n) = w^T*x_n$ 
- $w$ is a set of weights
- Learning is finding a suitable $w$ which accurately predicts y
- Validating performance is done by finding $w$'s that minimize the square distance between the predicted y and the actual y $MSE = 1/N ~ \Sigma_{N=1}^N||y_n - \hat y_n||^2_2$
- Loss function = MSE, for learning $L(w)$
## How to learn
- Calculating the gradient of the loss function and setting it equal to 0 and solving for the weights is the solution
![[Pasted image 20230320133904.png]]
![[Pasted image 20230320133910.png]]
![[Pasted image 20230320133918.png]]
![[Pasted image 20230320134059.png]]
![[Pasted image 20230320134106.png]]

# Underfitting and overfitting
![[Pasted image 20230320134257.png]]
- The continuum between underfitting and overfitting can be traversed by tuning the model capacity (e.g. the degree of a polynomial, number of neurons/layers in a deep neural net).
- Add capacity until the optimal capacity points is reached just before generalization error starts to increase

# Occam’s razor principle
- Among hypotheses explaining a set of observations with equal success, choose the simplest one - The law of Parsimony
- Applied to machine learning: “Among models performing equally well, choose the simplest one

#  Quantifying model capacity
- Vapnik Chervonenskis (VC) Dimension
  - Definition: Maximum number of arbitrarily placed data points that can be perfectly predicted
  - VC for linear regressions is D + , so since a line is 2D it would be 3 points and 4 points can't be predicted 
![[Pasted image 20230320135154.png]]
  - High capacity does not necessarily imply high parameter count 
  - The sine function only has the parameter $\alpha$ but infinite VC dimension
![[Pasted image 20230320135357.png]]

# Generalization bounds
- If this is the performance of the model on the test data, what performance can be expected in real life 
  ![[Pasted image 20230320135702.png]]
  (Only for binary classification)
- h = VC dimension of the predictor
- $err_{Tr}$ = training error 
- $err_{tS}$ = test error
- $a_1$ and $a2$ are arbitrary coefficients satisfying the given inequalities 
- $opt = Err_{Ts} − err_{Tr}$ = optimism of the training error

# estimator 
- Rule for inferring an unknown value of a quantity, which can only be guessed - A hypothesis $h_D(x)$ learned from training data $\mathcal{D}$
![[Pasted image 20230322163428.png]]
![[Pasted image 20230322163442.png]]

 - Loss function: The difference between the hypothesis and the true value of the quantity of interest. Examples:  ![[Pasted image 20230322163738.png]]![[Pasted image 20230322164002.png]]
   
# Bias of an estimator
![[Pasted image 20230322164038.png]]
- Sample mean is an unbiased estimator 
  ![[Pasted image 20230322164336.png]]
- Sample variance is a biased estimator by itself it can be fixed with bessel's correction, unbiased:![[Pasted image 20230322164322.png]]

# Standard error 
- The square-root of the variance of an estimator
  ![[Pasted image 20230322164410.png]]
  The sample mean as the estimator (standard error of the mean)
  ![[Pasted image 20230322164441.png]]
- When reporting performance return mean and standard error

# Bias, variance, and noise in supervised learning
- Bias free learning is futile
- Physics informed neural networks inferring bias by giving restrictions.
- Bias: Degree of inflexibility of the learning hypothesis (its level of ignorance to observations)
- Variance: Sensitivity of some of the collected datapoints having an impact on the outcome
- Noise: Incorrectly labeled data for classification or lack of measurement precision for regression
### Trade-offs
- High bias $\Rightarrow$ Assumptions dominate data ⇒ Low variance $\Rightarrow$ Underfitting
- High variance $\Rightarrow$ Data dominate observations $\Rightarrow$ Low bias $\Rightarrow$ Overfitting

# Epistemic and Aleatoric Uncertainty
Statistical Learning Theory is interested in bounding the expected risk with respect to all possible query samples
![[Pasted image 20230322170735.png]]
Then the bias-variance decomposition will read
![[Pasted image 20230322170750.png]]
As $|\mathcal{D}|$ goes to infinity both bias and variance reduces as both are epistemic in origin (i.e. lack of knowledge on $p_{true}$), but noise variance does not as it is intrinsic noise in the process.

# Ensembles
- Community effort to solve BIG problem
- Any individual classifier would have either a strong bias or a large variance on a non-trivial learning task
- The combination of classifiers can reduce both, bias and variance
- Weak bias, large variance -> average reduces overall variance
- Strong bias, small variance chosen in a way to diversify bias -> Average reduces overall bias
- Aggregated clustering - Get parameters from multiple and different models take them aggregate them and redistribute the aggregated parameters back to the models retrain the models take the new parameters and aggregate repeat...

# Information
- Degree of surprise after observing x
- Devise a function h(x) to quantify information gained from x.
- E.g. seeing x when it has low probability is surprising
- Devise a function h(x) to quantify information gained from x
  - Observing two independent binary variables x and y, the information received should be the sum of the individual events
  - Because independence implies p(x, y) = p(x)p(y), it is suitable to measure information by $h(x) = -log_2~p(x)$ ![[Base 2 Note]]
  - Negative sign assures that information with surprise (low probability event)

# Entropy
- Entropy is a measure of the impurity or uncertainty in a set of data or related to compression, rare bit patterns long bitstrings frequent bit patterns short bit string
- Expected amount of information for random variable x living in a sample space $\mathcal{X}$ and following a distribution $p(x)$ ![[Pasted image 20230322210632.png]]
- For binary random variables ![[Pasted image 20230322210703.png]]

# N-ary entropy (Uniform) 
![[Pasted image 20230322210728.png]]

# Intuition
![[Pasted image 20230322210824.png]]

# Measure of information'
- $-log_2~p(x) \rightarrow bits$
- $-ln~p(x) \rightarrow nats$
- Distributions that maximize the entropy
  - Discrete -> Uniform
  - Continous (for a given location spread) -> normal

# Entropy in the continuous domain
- No exact counterpart 
- Using mean value theorem entropy of a continuous density p(x) differs by $-ln \Delta$ for differential entropy![[Pasted image 20230322211223.png]]
- Differential entropy diverges from the exact entropy as ∆ → 0, often a replacement of plain entropy for continuous densities

# Relative entropy or KL (Kullback-libler) divergence
- Approximate $p(x)$ by $q(x)$ (another density more pleasant properties) additional required information in nats when using $q(x)$ instead of $p(x)$ ![[Pasted image 20230322211659.png]]
- x following $p(x)$ suggests additional information is ![[Pasted image 20230322211722.png]]
  Relative entropy or Kullback-Leibler divergence 

# Convexity
- A line passing between f(a) and f(b) always staying above f would make f convex in that interval ![[Pasted image 20230322211943.png]]
- The reverse is not concave but non-convex, but when the line is under the function that function can be called convex
- the sin curve is non-convex and non-concave
- A loss function or any other function being convex it follows that where the determinant is 0 is the best solution for minimizing the x value (GYM MATH!!)

# Jensen's inequality
![[Pasted image 20230327103819.png]]

# KL divergence is a statistical distance
![[Pasted image 20230327104835.png]]
- KL used to see how different two values are
- not a distance measure - divergence

# Entropy of class distributions
- Low entropy:
  - Lower disorder
  - minimal randomness in the represented classes
  - low uncertainty - very predictable
  - one classes represents almost all datapoints 
- High entropy
  - More disorder
  - Maximal randomness
  - high uncertainty - no that predictable

# Gini index
![[Pasted image 20230327105229.png]]
- How impure is a dataset
- Minimal impurity the Gini index would be 0, e.g. dataset with 1 class probability of that class = 1, Gini index = 0
- Each class equally represented $Pr(c_i | D) = \frac{1}{k}$, dataset maximally impure Gini index = $\frac{k-1}{k}$
- Probabilistic interpretation of the square: randomly draw two objects from D, how likely are they belonging to the same class

# Decision tree
  ![[Pasted image 20230327113223.png]]
- Inner node -> test
- edge -> result of test
- leaf node -> class
- Constructed top down
- The alg. is greedy - makes bad choice that's it can't be corrected 
  ![[Pasted image 20230327113519.png]]
- splits to maximize purity

### Types of splits
![[Pasted image 20230327113536.png]]

# Where to split?
- where errors that would occur is smallest
- while still maximizing separation of classes
- or fit to each class a Gaussian distribution intersections of the Gaussian pdfs are potential split points

# Quality measure for splits
![[Pasted image 20230327113921.png]]

# Measure: information Gain
- Information gain is a measure based on the entropy.
  ![[Pasted image 20230327114553.png]]
- Information gain measures the reduction of entropy (i.e., gain of information) by a split of set T into partitions T1, . . . , Tm:![[Pasted image 20230327114606.png]]
- Higher information gain means larger reduction of entropy
- We choose the attribute and split point that maximize the information gain.
- Wants to reduce entropy on the dataset making better predictions reducing impurity
- Example slides 60

# Measure - Gini index
- maximize information gain minimize impurity
  ![[Pasted image 20230327115227.png]]
  - Example slides 64

# Axis-parallel hyperplanes 
![[Pasted image 20230327120054.png]]

# Hyperplanes and split points
- For decision trees on real-valued attributes, axis-parallel hyperplanes relate to split points.
- A hyperplane splits the data space R d into two half-spaces.
- All points with h(x) < 0 are on one side of the hyperplane, all points with h(x) > 0 are on the other side of the hyperplane.
- We can therefore write the split point as: h(x) ≤ 0 ⇔ $x_i$ − b ≤ 0 ⇔ $x_i$ ≤ b

# Bias axis parallel piecewise linear separation
![[Pasted image 20230327115951.png]]

# Bias prevents detection of certain simple decision rules
![[Pasted image 20230327115933.png]]

# Overfitting example
![[Pasted image 20230327120117.png]]
- can prevent this by making it not go to deep
- can also be prevented by choosing the impurity

































Loss function:

![[Pasted image 20230320133252.png]]
(w) ->
   w = a set of weights