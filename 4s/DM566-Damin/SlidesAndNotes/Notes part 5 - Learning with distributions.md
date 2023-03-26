# Important things
- Cumulative distribution functions (CDF)
- Algebraic/geometric view of data vs Statistical/probabilistic view of data 
- Data set of vectors sometime called design matrix


# Event vs Values associated with the event
- Throwing two die $\Omega = \{(1,1), (1,2)...(6,6)\}$ 36 basic events
- Interested not in the event but some value associated with the event e.g., the sum, x, of the two die. 
- $Pr(x = 2) = \frac{1}{36}$, $Pr(x = 2) = \frac{2}{36}$

# Random variable 
- A random variable X on a sample space Ω is a real-valued function from Ω to the real numbers $X : \Omega \rightarrow \mathbb{R}$ -> continues
- A discrete random variable is a random variable that takes on only a finite or countably infinite number of values. E.g., I ⊆ N: X : Ω → I is a discrete variable, if I is finite countably infinite.

# Random variables and basic events
- Discrete random variable $X$ and $a \in \mathbb{R}$ the event "$X = a$" includes all basic event of the $\Omega$ where $X$ assumes the value of $a$
- "$X=a$" : $\{s \in \Omega | X(s) = a\}$
- Probability of the event is given $$\operatorname{Pr}(X=a)=\sum_{s \in \Omega: X(s)=a} \operatorname{Pr}(s)$$
### Example 
![[Pasted image 20230307093245.png]]

# Probability Distribution
![[Pasted image 20230307093259.png]]
- The probability distribution of $X$ says how the total probability of 1 is distributed among all possible values of $X$

### Example
![[Pasted image 20230307093349.png]]

# Cumulative distribution function
![[Pasted image 20230307093408.png]]
- For any number $x$ the value of the cmf F(x) is the probability that the observed value of X will be at most x.

### Example 
![[Pasted image 20230307093459.png]]

# Independent events
- The same as for non-random variable
![[Pasted image 20230307093528.png]]

# Expectation (or: Mean) first order of uncertainty
- One number representation of entire dataset
- Weighted average of the values assumed by the random variable
- The weight of a value is the probability that the variable assumes that value
![[Pasted image 20230307093707.png]]

### Example 
![[Pasted image 20230307093721.png]]
![[Pasted image 20230307093736.png]]
- $E[X]$ in theses examples are known as the first moment of the variable X

### Note
- the expected value of $X, E(X)$ is not necessarily a possible value of $X$.


# Variance (second order of uncertainty) and standard Deviation
![[Pasted image 20230307094137.png]]
- Right hand side is known as the second moment of the random variable X

![[Pasted image 20230307094150.png]]
- Interesting since it is at the same scale as the variable X itself.

### Note
- If a random variable is constant, then its variance and standard deviation is zero

# Covariance
![[Pasted image 20230307094915.png]]
- Defined on two variables 
- how much the variables X and Y diverges from its expectations multiplied
- Covariance of a random variable with itself is its variance
![[Pasted image 20230307094921.png]]
- setting Y = X would give the identity: $$Var(2X) = Var[X] + Var[X] + 2*Var[X] = Var[2X] = 4Var[X]$$ That would mean left side being $C$ right side would be $C^2$

# Correlation
![[Pasted image 20230307095427.png]]
![[Pasted image 20230307095435.png]]

# Independence and expectation 
![[Pasted image 20230307095531.png]]
![[Pasted image 20230307095538.png]]

# Variance of sum and sum variance
![[Pasted image 20230307095723.png]]
- For non-independent variables the right hand side would be smaller even though that would not make any sense since the equality is broken

### Example 
![[Pasted image 20230307095808.png]]

# Mean and median also called expectation
- For any random variable $X$ with finite expectation $E[X]$ and finite median $m$
  1) The expectation $E[X]$ (=mean) is the value of $c$ that minimizes $E[(x - c)^2]$
  2) The median $m$ is a value of $c$ that minimizes $E[|X - c|]$ 
### Note
This is why we use different objective functions, $TD^2,~TD$ for k-means and k-medoids respectively 

# Probability distribution in $\mathbb{R}$
- Outcomes evenly distributed around a e.g., a circle
- $\Omega = [0..1]$
- all probabilities are equally likely 

# Probability in infinite sample space
- number of elements in sample space reaching infinity $Pr(x)$ for all x $\rightarrow$ 0, where x = single point
![[Pasted image 20230309084712.png]]

# Cumulative distribution function (CDF)
- can be designed however you like, there are no rules for how it should be calculated.
![[Pasted image 20230309084830.png]]

# Probability density function (PDF)
- the derivative of the cumulative distribution function
![[Pasted image 20230309084841.png]]
- For events in $\mathbb{R}$ the integral is the analogue to the sum of probabilities simple events (probability space)
![[Pasted image 20230309084916.png]]

# joint distribution
- multiple random variables being evaluated by one cumulative distribution function
![[Pasted image 20230309085836.png]]

# Uniform distribution
- Everything outside the uniform distribution has a probability of zero
![[Pasted image 20230309091854.png]]
![[Pasted image 20230309092348.png]]

# Two-dimensional uniform distribution
- a joint distribution of two in the interval [0, 1] independently uniformly distributed random variables X and Y a two-dimensional uniform distribution with a density function
![[Pasted image 20230309093824.png]]
![[Pasted image 20230309093905.png]]
![[Pasted image 20230309093932.png]]

# The normal distribution
![[Pasted image 20230309094333.png]]
- $\mu$ is the expectation of the normal distribution
- $\sigma^2$ is the variance of the distribution
- Standard normal distribution (bell distribution) is given by $\sigma^2 = 1$ and $\mu = 0$
![[Pasted image 20230309094714.png]]
- $\mu$ the center of the symmetric, bell-shaped curve f(x)
- $\mu + \sigma$ and $\mu - \sigma$ are the infection point of the curve 
- - Area under the curve cannot be greater than one but the value of the highest placed point can go towards infinity
![[Pasted image 20230309095102.png]]

# Central limit theorem
- In summary, the central limit theorem states that, under certain conditions, the distribution of the sum or average of a large number of independent and identically distributed random variables will be approximately normal, regardless of the distribution of the individual random variables.

The conditions required for the central limit theorem to hold are as follows:

1.  The random variables must be independent and identically distributed.
2.  The sample size must be large enough.
3.  The random variables must have a finite mean and variance.

- The central limit theorem has many practical applications, including in hypothesis testing, confidence interval estimation, and statistical modelling. It is one of the key concepts in modern statistical inference and is widely used in various fields, including finance, engineering, and the natural sciences.

# Bivariant normal distribution
![[Pasted image 20230309101506.png]]

# Multivariate normal distribution 
![[Pasted image 20230309101527.png]]

# Standardizing
- z-score normalization
- consider each column of a matrix as their own random variable 
- which sums to 1
- take the large values and normalize them

# Difference between probability and probability density
- In summary, probability is used to describe the likelihood of an event occurring, while probability density is used to describe the probability distribution of a continuous random variable.

# Expectation maximization
- Each cluster represented by an EM and follows a multivariate normal distribution
- Goal: fit normal distribution on different parts of the dataset and assign each to a cluster
- Cluster representation:
  - $\mu_k$ mean vector for all points in C
  - $d x d$ covariance matrix $\Sigma_k$ for points in $C_k$
  - Probability density: $f_k(x) = \frac{1}{\sqrt{(2*\pi)*d|\Sigma_k|*}}*e^{-\frac{1}{2} (x-\mu_k)*\Sigma_k^-1*(x-\mu_k)^T}$

# Idea of EM Clustering
- Each point belong to several clusters, k, with different probability $Pr(x|C_k)$
- algorithm consists of two alternating steps:
  - Assignment of points to their clusters, not absolute but relative, according to probability
  - computation of new cluster representatives
- computation of µk needs to consider relative assignment

# Density function to model a cluster
- The model for a cluster Ck is a Gaussian pdf with cluster-specific mean and covariance matrix: $f_k(x) = \frac{1}{\sqrt{(2*\pi)*d|\Sigma_k|*}}*e^{-\frac{1}{2} (x-\mu_k)*\Sigma_k^-1*(x-\mu_k)^T}$
![[Pasted image 20230314104453.png]]
- For our purpose, we can use fk(x) as a relative probability.
- However: this would hold if some point is exclusively assigned to the cluster
- We therefore set the conditional relative probability as $p\left(x \mid C_k\right) \propto \frac{1}{\sqrt{(2 \pi)^d\left|\Sigma_k\right|}} e^{-\frac{1}{2}\left(x-\mu_k\right) \cdot\left(\Sigma_k\right)^{-1} \cdot\left(x-\mu_k\right)^{\top}}$

# Mixture of Gaussians (MoG)
![[Pasted image 20230314104624.png]]
![[Pasted image 20230314104822.png]]
- Soft assignment of a row n in a matric belongs to a cluster k. For k-means its either 1 or 0, here it can be between 0 and 1 

# The joint distribution 
- Assume we have a data set consisting of N observations D = {x1, . . . , xN} independently sampled from the MoG data generating process, the joint distribution of all variables in the model is
  ![[Pasted image 20230314104948.png]]
  Where:
  ![[Pasted image 20230314105005.png]]

# Marginalizing the cluster variables
- Marginalizing probability of given data given all means and covariances 
- Do not know Z, only able to infer a probabilistic estimation - Two options:
  - Interested in the estimation itself. Done just calculate the posterior.
  - Account for or explain the uncertainty of estimation and move forward to our downstream task - Need to marginalize $Z$ accounting for all possible outcomes weighted by their probability $p(\mathcal{D} \mid \mu, \Sigma)=\prod_{n=1}^N \sum_{k=1}^K \pi_k \mathcal{N}\left(x_n \mid \mu_k, \Sigma_k\right)$

  # Maximum likelihood estimation
  - Need to find the µ, Σ values that explain the observations best, i.e. the values that maximize the probability of our observations (i.e. the likelihood of parameters). 
  - A function has an extremum when its derivative is zero. We wonder for which µ, Σ we have $$$\begin{aligned} \nabla_\mu p(\mathcal{D} \mid \mu, \Sigma) & =0 \\ \nabla_{\Sigma} p(\mathcal{D} \mid \mu, \Sigma) & =0\end{aligned}$$
  - Here ∇ is the gradient operator defined as
    $$\nabla_x f\left(x_1, \ldots, x_M\right)=\left[\frac{\partial f}{\partial x_1}, \ldots, \frac{\partial f}{\partial x_M}\right]$$
    

# The log likelihood
![[Pasted image 20230314105843.png]]
![[Pasted image 20230314105853.png]]

# Updating the means 
![[Pasted image 20230314105907.png]]
![[Pasted image 20230314105918.png]]

# The expectation maximization (EM) Alg.
![[Pasted image 20230314110236.png]]
EM Example iterative fitting of the model parameter $\mu_k$ and $\Sigma_k$ slides 75

# Discussion EM Alg.
- Usually requires a lot of iterations $O(n*k)$ 
- Result quality and runtime depend strongly on initial model and good choice of k
- Modification for returning K disjunct clusters: each object belongs only to the cluster with highest (relative) probability $p(x|z_{nk} = 1)$

# Multivariate Normal Distribution 
![[Pasted image 20230314112052.png]]
![[Pasted image 20230314112357.png]]
- Covariance matrix is symmetric and non-negative on the diagonal ignoring constant dimension it can usually be inverted 
- Singular value decomposition:
$$\Sigma = V\Lambda V^{-1} \Rightarrow \Sigma^{-1} = V \Lambda^{-1} = V\Lambda^{-1}V^T$$
- Because
  - $V$ is an orthonormal matrix of eigenvectors, i.e. $VVT = I$
  - $\Lambda$ contains the eigenvalues on the diagonal and zero elsewhere.
  - $V ∼= rotation$, $\lambda ∼= scaling$ as in Principal Component Analysis
![[Pasted image 20230314113226.png]]

## Model
- (relative) assignment of points to closest cluster representative
- “closest” is given by Mahalanobis distance:
  - quadratic form distance
  - distance matrix depends on the corresponding cluster (covariance matrix of the cluster points)
![[Pasted image 20230314113325.png]]

# Linear discriminant analysis (LDA)
- Model each class $k$ as multivariate gaussian:
  ![[Pasted image 20230314113644.png]]
- Estimate the model parameters mean $\mu_k$ and covariance matrix $\Sigma_k$ for each class k from the training data $TR \subseteq \mathbb{R}^d$
- Let $C_k \subseteq TR$ be the set of observations belonging to class $k$
  ![[Pasted image 20230314113944.png]]
- Given the gaussian model for each class we can predict the maximum likelihood class: ![[Pasted image 20230314114013.png]]

## Global covariance matrix 
- Problem: sometimes the amount of available training examples per class is not sufficient to significantly determine the covariance matrix for each class.
- Combine the covariance matrices to a global covariance matrix:
  ![[Pasted image 20230314114142.png]]
- classification rule:
  ![[Pasted image 20230314114157.png]]

## Linear discriminant analysis 
![[Pasted image 20230314114223.png]]

# Parametric learning
![[Pasted image 20230314114247.png]]

# Non-parametric learning
![[Pasted image 20230314114310.png]]

# The problem of density estimation 
- The point-wise local approximation of a probability density distribution function is more generally treated as non-parametric "density estimation"
- Problem statement: given a data set consisting of the n points $x_1, ... x_n \in \mathbb{R}^d$
- Assume these values are sample values assumed by a random variable $X ~ f(x)$ (probabilistic POV)
- Do not know the underlying probability density distribution function $f$ in general
- Would like to know value of x for f(x)

# Estimation of the cumulative distribution function
- In one dimension CDF can be estimated directly from the data
- count points less than or equal to x
  ![[Pasted image 20230314115051.png]]
  - CDF and PDF ![[Pasted image 20230314115102.png]]

# Estimation of the probability density function around x from CDF
- From the estimation $\hat{F}$ of $F$ the function $f$ can be estimated by the derivative of $\hat{F}$ 
- Take a small window of width h, centred at x: ![[Pasted image 20230314115526.png]]
- where k is the number of points located within the window of size h around
- The density estimate is therefore given as the ratio of the fraction of points within the window k n to the volume h of the wind
- Choice of h:
  - Too large will consider many neighbours and smoothen the estimated function 
  - too small will not take enough neighbours into account and not give an accurate estimate

# Kernel Estimator
- Uses a kernel function $K$:
  - non-negative
  - symmetric
  - integrates
- K qualifies as a probability density function itself 
# Discrete kernel
- Counts the number of points in a window of width h
  ![[Pasted image 20230314121157.png]]
  - if $|Z| = |\frac{x-x_i}{h}| \leq \frac{1}{2}$ the point $x_i$ is within the windows of width h centred at $x$
  - density estimate from ![[Pasted image 20230314115526.png]]
    by using the discrete kernel
    ![[Pasted image 20230314121536.png]]
# Kernel density estimation with discrete kernel
![[Pasted image 20230314121544.png]]

# CDF and PDF
![[Pasted image 20230314121553.png]]
# Gaussian Kernel
- All or nothing contribution of the points around x to the estimate (for discrete kernel):
  - If some point falls in the window around x, it contributes $\frac{1}{hn}$ to the probability estimate $\hat{f}(x)$
  - If some point is outside the window, it contributes 0
- A Gaussian kernel results in a smoother change of the influence of some point:
![[Pasted image 20230314121917.png]]
- The center of the window, x, relates to the mean, window size h relates to the standard deviation.

# KDE with gaussian kernel
![[Pasted image 20230314121607.png]]
# Multivariate density estimation
- To estimate the density around a d-dimensional point $x \in \mathbb{R}^d$, we replace the one-dimensional window by a d-dimensional hypercube.
- Instead of the window length h, we need to account for the volume $h^d$.
- With some multivariate kernel function K, the density estimate becomes:
![[Pasted image 20230314122254.png]]


# Multivariate kernel function
- The discrete kernel function generalizes directly to a d-dimensional vector space:
![[Pasted image 20230314122344.png]]
- For the d-dimensional Gaussian kernel, we assume that the covariance matrix is the identity matrix:
  ![[Pasted image 20230314122405.png]]

# Two-dimensional KDE
![[Pasted image 20230314122417.png]]

# Nearest neighbours density
- So far we kept the volume fixed by a fixed window width (or hypercube edge length) h.
- Problem: how to choose h in order to capture enough, but not too many points?
- Alternative: fix the number k of points, allow the volume to vary in order to capture k points
- With Euclidean distance, we get the volume Vk(x) of a d-dimensional hypersphere with the distance from x to its kth nearest neighbour as radius.
- The resulting k nearest neighbor density estimation is:
  ![[Pasted image 20230314122820.png]]
- Cf. the probabilistic reasoning on the knn classifier)

# Density based clustering
- Gaussian = Normal distribution
- parametric learning approximate some density function of a given family (e.g. Gaussian)
  - Don't keep entire dataset - just looks at the density function describing the normal distribution covering a certain cluster
- non-parametric no assumption on family of density function, identify areas of high density
- Choosing threshold density is important too high of a threshold can cause you to miss an entire cluster too low could cause two or more cluster to merge to one.

## Basic concepts
- Hyper parameter - need to know before learning does not change during learning
- Parameter - Learned during training can change
- Core point - The point from which you put a radius around and then contains at least MinPts points in the given radius
- direct density reachable - points within the radius of a core point
- Density reachability ????
- Density connected ????
- Single link effect due to a single points (outlier) two large clusters merge together creating one large cluster with a bad fit / density potentially

# DBSCAN
????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????



# Shared nearest neighbour (SNN)

Hierarchical clustering
- Instead of deriving a partition of the dataset into a flat set of clusters, derive a hierarchy (dendrogram) of clusters.
- A cluster at a higher level can contain several smaller clusters at a lower level
- A tree represents a hierarchical clustering:
  - root: represents the complete database
  - leaf: represents a single object 
  - inner node: represents a cluster containing all the objects of the subtree rooted at this node

# Agglomerative Algorithm

## complexity 
![[Pasted image 20230316131838.png]]

## Distances between clusters 
- There are different approaches
- Using particular distance measure allows for algorithmic enhancements - Examples:
  - Single link
  - Complete link
  - Average link

# Single link
- Chains two points together which has less length between each other than specified 
- Clusters have high variance
- Clusters have an extended structure

# Complete link
- Chains points together if they are less than a given length a part if an only if the other points they are connected to are also less than the given length away from the point which you want to connect to.
- Small, strongly delimited clusters 
- convex clusters with similar diameters 

# Average link
- Compromise between single and complete link
- No efficient Alg. $O(n^3)$
- Beginning adds two points with a smaller length between them than the given length
- The length from the middle of two points in a cluster needs to be less than the specified length for another points to be added to the cluster

## Pros
  - Does not require knowledge of number of clusters 
  - not only flat partition but a hierarchy of clusters
  - A single partition can be retrieved by some horizontal cut
## Cons
  - Want flat partition where is a good place to cut?
  - Greedy - cannot correct bad decisions
  - Single link effect, complete link effect 
  - Generally inefficient

# OPTICS
- $\epsilon$ and MinPts smooth the clustering 
- The number of valleys indicates the number of clusters found by the OPTICS Alg. 
- The output if the OPTICS Alg. is presented often in the from of a reachability diagram 
- Use optics to find a number of clusters and use that number for k-means to get a better outcome
- Steep points in the reachability diagram indicates that a hierarchy is not possible more gentle slope from peak to a cluster indicates that there can be hierarchies
- cut: ≈ density-level as ε for DBSCAN
- cluster order relatively robust against parameter choices
- reasonable result when parameters are “big enough”![[Pasted image 20230316135121.png]]
- The meaning and effect of ε is quite different from the meaning of the equally named parameter in DBSCAN.



# Probabilistic Outlier Model: Statistical Tests
- Data mining: get understanding of data do more advanced model
- Then machine learning starts
- Outlier = something a model cannot capture, something you don't know what is.
### General idea
- given a certain kind of statistical distribution (e.g., Gaussian)
- compute the parameters assuming all data points have been generated by such a statistical distribution (e.g., mean and standard deviation)
- outliers are points that have a low probability to be generated by the overall distribution (e.g., deviate more than 3 times the standard deviation from the mean)
### Basic assumption
- normal data objects follow a (known) distribution and occur in a high probability region of this model
- outliers deviate strongly from this distribution

## Statistical tests
![[Pasted image 20230318161400.png]]
- µ is the mean value of all points (usually data are normalized such that µ = 0) 
- Σ is the covariance matrix centred at the mean'
- MDist= (x − µ) · (Σ)−1 · (x − µ) T is the Mahalanobis distance of point x to µ
- MDist follows a $χ^2$ -distribution with d degrees of freedom (d = data dimensionality)
- all points x, with MDist(x, µ) > χ2 (0.975) $[≈ 3 · σ]$ are considered outliers

# Distance based outliers
- A point p is considered an outlier if at most π percent of all other points have a distance to p less than ε ![[Pasted image 20230318161716.png]]
- Choosing parameters example slides 176

# Density based local outliers
![[Pasted image 20230318161948.png]]
- DB-outlier model: no parameters ε, π such that $o_2$ is an outlier but none of the points of $C_1$ is an outlier
- kNN-outlier model: kNN-distances of points in $C_1$ are larger than kNN-distances of $O_2$
- Local Outlier Factor (LOF)
  - reachability distance (smoothing effect):
    - reachdistk(p, o) = max{k dist(o), dist(p, o)}
- local reachability density (lrd):
  ![[Pasted image 20230318162124.png]]
- Local outlier factor (LOF) of point p: average ratio of lrds of neighbours of p and lrd of p:
  ![[Pasted image 20230318162147.png]]
- LOF ≈ 1: homogeneous density
- LOF >> 1: point is an outlier

# Global / Local outliers
- Local outliers exhibit a lower local density than their neighbours.
  ![[Pasted image 20230320131701.png]]
  - Same density <-> relative density = 1
  - les dense <-> relative density > 1
  - LOF(p) >> 1 outliers!

# Outlier / Inlier classification problem
- class imbalance: the “class” outlier is substantially smaller, but often more important than the “class” inlier
- resulting problems:
  - training of a classifier is difficult due to lack of training data
  - evaluation measures are hard to interpret (e.g., typically very low precision values even for a rather good result)
- most (unsupervised) outlier detection methods deliver not a decision but a score (“outlier score”, “outlier factor”)
- Outlier detection result based on scores is a ranking

# ROC Curves
- ## True positive rate and True negative rate
  - $TPR = \frac{TP}{TP+FN}$
  - $FPR = \frac{FP}{FP+TN}$
- the worst AVG of the curve is 0.5

# Unavoidable False Positives and False Negatives
- objects truly generated by a different mechanism can fit very well to the “normal” data distribution
- inliers in the tail of the “normal” distribution must appear suspicious
![[Pasted image 20230320160751.png]]
![[Pasted image 20230320160746.png]]

# External vs. Internal evaluation
- Evaluation with ROC needs class labels (external information)
- This kind of evaluation is therefore called external evaluation.
- In an application of an unsupervised method, we would actually not have external information available.
- We need internal evaluation, relying only on the data itself.

# Masking and Swamping
- mean and standard deviation are sensitive to outliers themselves
- these values are computed for the complete data (including potential outliers) – masking and swamping:
  ![[Pasted image 20230320161022.png]]
  ![[Pasted image 20230320161108.png]]
  ![[Pasted image 20230320161116.png]]
- the MDist is used to determine outliers although the MDist values are influenced by these outliers (advanced approaches try to alleviate this effect)
- applies to any model (some are more robust, some are more susceptible to these effects)

# Curse of dimensionality
- The distance becomes irrelevant when increasing the number of features