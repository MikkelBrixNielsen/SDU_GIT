Purpose of clustering
- Identify a finite number of categories in dataset
- similar objects grouped together in a cluster dissimilar object in different clusters
- "similarity" can vary widely depending on application scenario.

Unsupervised clustering
- No external knowledge to guide or supervise
- Can't learn rules to sort points
- Don't know the number of clusters
- Don't know how cluster characteristics
- No criteria to judge quality of the clustering 

Challenges
- Assume hypothetical quality function q
  - gives quality of given partition of a set of n points if its a good clustering
- Naïve method: test q on all partitions in k clusters ($2 <= k <= ?$)
  - Problems:
    - There are $O(k^n)$ partitions in k clusters
    - Don't have the q function
- Therefore, we need heuristic solutions for both problems:
  - Efficient search for solutions 
  - Efficient and effective modelling of q
  
Categories of clustering approaches
- Partitioning
  - Model: Clusters are compact sets of points
  - Parameter: (usually) number k of clusters, distance measure
  - Looks for a flat partitioning into k cluster with maximal compactness
  
- Density based
  - model: Clusters are areas of high density, separated by areas of low density
  - Parameter: minimal density in some cluster, distance measure
  - Looks for a flat partitioning into clusters exceeding some minimal density
  
- Hierarchical
  - Model: compactness, density
  - parameter: distance measure for points and for clusters
  - Looks for a hierachy of clusters joins the most similar clusters at a given level of the hierachy
  - flat clusters can be derived by cutting the tree on some level
  
- Alternative categorizations could sort approaches according to the algorithmic approach or to the application scenario of specialized approaches:
  - many variants of techniques, such as fuzzy clustering, graph-theoretic algorithms, neuronal nets
  - specializations to special data characteristics (time series, graphs, high-dimensional data, stream data, uncertain data etc.)


NO OBJECT CAN BELONG TO MORE THAN A SINGLE CLUSTER SO DONT YOU FUCKING DARE!

- The objects we are considering are points $x = (x_1, ~ ... ~ x_d)$ in the Euclidean vectors $\mathbb{R}^d$, where dist = Euclidean distance ($L_2$)
- Centroid $\mu_C$ mean vector of all points in a cluster C $\mu_{C_i}=\frac{1}{\left|C_i\right|} \cdot \sum_{o \in C_i} o$
![[Pasted image 20230216083600.png]]

$TD_2$ score:
-  A measure of compactness for a cluster C: $T D^2(C)=\sum_{p \in C} \operatorname{dist}\left(p, \mu_C\right)^2$
- Also called SSQ (sum of squares) or SSE (sum of squared error)
- Can also calculate compactness for a clustering $T D^2\left(C_1, C_2, \ldots, C_k\right)=\sum_{i=1}^k T D^2\left(C_i\right)$

Model selection based on the $TD^2$ score, of cluster groups etc. how good was the model, are there other starting parameters that are better than others?

![[Pasted image 20230216084050.png]]
- Iterative algorithm that stops when the new calculations stop changing from the previous once e.g., centroid is in the same place for multiplied iterative calculations. It will optimize according to the starting parameters, but some starting parameters are still better than other and can have an influence on the final result.

![[Pasted image 20230216084245.png]]
- Convergence: Visualization of evolving voroni parcelling from slides part 2 pp. 65-78
- Not the same as convex hull, which is the smallest geometric shape that contains all the datapoints.

K-means algorithm:
- MacQueen, 1967 - best know variant of the basic algorithm
  - A centroid is immediately upadted when some point changes its assignment
  - k-means has very similar properties, but the result now depends on the order of data points in the input file.
  - K-means describes many different variants of the basic algorithm in particular also for the Forgy (1965) and Lloyd (1982) algorithms.

K-means Lloyd/Forgy algorithm
- Calculate a centroid for a group of points.
- For each iteration of point assignment to a centroid the centroid is recalculated before it proceeds to reassign points again.
- When there are no changes to the location of the centroid after points are reassigned it has converged.

K-means MacQueen algorithm
- Calculate a centroid for a group of points.
- Assign first point to centroid recalculate centroid, assign second point recalculate centroid... 
- When there are no changes to the centroid location between point reassignment it has converged.

K-mean clustering quality
![[Pasted image 20230216085544.png]]

K-means pros / cons
- Efficient: $O(K*n)$ per iteration, with iterations usually in order of 10
- Easy to implement, thus very popular
---
- K-means converges towards a local minimum
- K-mean (MacQueen-variant) is order dependent
- Deteriorates with noise and outliers 
- Clusters need to be convex and of (more or less) equal extension.
- Number k of clusters is hard to determine
- Strong dependency on initial partition in determining result quality and runtime 

Selection of representative points: k-medoids
- works in a general metric space: 
- Requires only distance measure dist for pairs of objects
- Medoid as representative: a central object of the cluster
- Measure of compactness for a cluster C with medoid $m_c$
$$T D(C)=\sum_{p \in C} \operatorname{dist}\left(p, m_C\right)$$
- Measure of compactness for a clustering $$T D\left(C_1, C_2, \ldots, C_k\right)=\sum_{i=1}^k T D\left(C_i\right)$$
- The medoid of a cluster is the point among the cluster members that minimizes TD.

k-modes - Huan, 1997
- For categorical data use the mode as an analogue to the centroid
  - In numerical attributes a centroid $\overline{x}$ of C minimizes $TD^2(C, \overline{x})$ = $\sum_{p \in C} \operatorname{dist}(p, \bar{x})^2$
  - categorical attributes: mode m of C minimizes $T D(C, m)=\sum_{p \in C} \operatorname{dist}(p, m)$, where m is not necessarily an element of C
  - Distance function for categorical attributes, e.g.: $$\operatorname{dist}(x, y)=\sum_{i=1}^d \delta\left(x_i, y_i\right)$, where $\delta\left(x_i, y_i\right)= \begin{cases}0 & , \text { if } x_i=y_i \\ 1 & , \text { else }\end{cases}$$
Finding the mode
- $T D(C, m)=\sum_{p \in C} \operatorname{dist}(p, m)$ is minimized, iff for $m=\left(m_1, \ldots, m_d\right)$ and all attributes $A_i, i = 1,...,d$ hold There is no attribute value more frequant than $m_i$ in $A_i$
- The mode is not necessarily unique
- Example: $\mathcal{D}=\{(a, b),(a, c),(c, b),(b, c)\}$
- possible modes: $(a,b),~(a,c)$

K-modes algorithm:
- Initialization: randomly selected objects as initial modes 
- Use mode instead of centroid
- Use categorical distance measure instead of squared Euclidean distance
- Then follow
![[Pasted image 20230216091237.png]]

Choice of initial model - Fayyad et al., 1998
- Clustering on small sample usually delivers good initial cluster, but some samples are deviating too much from the overall data distribution.
- Draw independently m samples
- Clustering of each sample results in m estimates of the k cluster centres
- Run clustering on D m-times with m estimated starting configurations.
- choose the clustering result with the best value for some quality criterion.
- Using the result from the sample runs as input for the big k-mean alg. and whichever yields the smallest $TD^2$ is the result. 

k-means++ initialization - Arthur and Vassilvitskii, 2007
![[Pasted image 20230216092024.png]]
![[Pasted image 20230216091237.png]]

Choice of K
- do a clustering for k = 2, 3, 4, . . . , n − 1 (or some other reasonable upper limit, e.g., $\frac{n}{2}$, $\sqrt{n}$
- choose the best of the results
What is the best
- Quality measure needs to be independent of k
- k-means, k-medoid etc.: $TD^2$ and $TD$ improve (i.e., become smaller) with increasing k.

Evaluation of clusterings
- For the evaluation of clusterings we are mainly interested in two aspects: 
  - cohesion: how tightly are members of one cluster connected, how compact are clusters? 
  - separation: how well are different clusters separated?
  - Validity measure for clusterings is typically some combination of cohesion and separation.
  - Weights $w_i$ could consider, e.g., the cluster size. For a clustering C with k clusters C1, . . . , Ck, e.g.: $$overall\_validity(C)=\sum_{i=1}^k w_i \cdot \operatorname{validity}\left(C_i\right)$$
  - Validity can also be based on a measure of proximity: $$\begin{aligned} \operatorname{cohesion}\left(C_i\right) & =\sum_{(x, y) \in C_i \times C_i} \operatorname{proximity}(x, y) \\ \operatorname{separation}\left(C_i, C_j\right) & =\sum_{(x, y) \in C_i \times C_j} \operatorname{proximity}(x, y)\end{aligned}$$
$TD^2$ is not a good measure for choosing k or as a goodness score since it would suggest that the best clustering is the on with the largest amount of clusters.

![[Pasted image 20230216113413.png]]
![[Pasted image 20230216113436.png]]
![[Pasted image 20230216113502.png]]

Silhouette score wants large separation between each cluster as to not prefer just increasing the number of clusters in the clustering
- Given the individual silhouette values s(o)
- The silhouette $s_c$ of a clustering C is the avg. silhouette of all n points: $s_C=\frac{1}{n} \sum_{o \in \mathcal{D}} s(o)$
- Interpretation: $s_c > 0.7$: strong cluster structure, $s_c > 0.5$: reasonable.

Problem with K-means clustering Lloyd/Forgy alg.
- A cluster can potentially become empty after reassigning points
![[Pasted image 20230216094839.png]] 
<= Now there are no points in blue cluster=>
![[Pasted image 20230216094849.png]]

Handling empty clusters
- There is no golden (standard) solution. Possibilities are: I Report one cluster less.
- Choose the point that is farthest away from any current centroid as a new centroid.
- Choose (randomly) a point from that cluster that currently exhibits the largest $TD^2$ as a new centroid.
- ![[Pasted image 20230216095532.png]]



