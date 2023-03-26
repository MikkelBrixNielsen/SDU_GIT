Taking data pre-processing it to extracts its characteristics giving it mathematical properties through a function, then processing it and giving the result to the user,
![[Pasted image 20230214082236.png]]

Nominal (categorise ):
- It is possible to tell whether two values are equal or not – but no direction (better, more,. . . ) or meaningful distance.
- Examples: sex, eye color, healthy/sick, amino acids

Ordinal
- there is an order relation (e.g., better/worse), but no uniform distance (Red = DANGER, Yellow = medium, green = good)
- Examples: grade, quality label, age class (e.g., 20-29, 30-39,. . . ), color (?)

Metric
- differences and relations between values are meaningful, values can be discrete or continuous
- Examples: weight, selling counts, age

Aggregations of Features
- absolute frequency: For each value a, we have f(a) as the number of occurences in the sample
- relative frequency: p(a) = f(a)/n
- mode. the value with the largest frequency
- median: Central element in the sample ordered by value
- Arithemtic mean: $\mu=\bar{x}=\frac{1}{n} \cdot \sum_{i=1}^n x_i$

Skweness
![[Pasted image 20230209142817.png]]
Skewness can be determined by the ordering og mean, meadian, and mode:
- Positively skewed: Mode, Medain, Mean
- Symmetric skewed: Mean - Median - Mean - same point
- Negatively skewed: Mean, Median, Mode

Centroid - The point which is in the center of all other points in a dataset 
(Arithmetic values)
$$\mu_{\mathcal{D}}=\frac{1}{|\mathcal{D}|} \cdot \sum_{o \in \mathcal{D}} o$$

medoid - point which is the shortest distance from all other points (ordinal values - Used in AlphaFold)

$$\arg \min _{o \in \mathcal{D}} \frac{1}{| \mathcal{D} |} \sum_{o^{\prime} \in \mathcal{D}} \operatorname{dist}\left(o, o^{\prime}\right)$$
Feature space and distance function
- A domain with a distance function:
$$F = (dom, dist)$$
- Dom is a sorted set of features.
- Dist: $\operatorname{dom} \times \operatorname{dom} \rightarrow \mathbb{R}_0^{+}$ is a total distance function with the following properties:
  - Strictness: $\forall p, q \in \operatorname{dom}, p \neq q: \operatorname{dist}(p, q)>0$
  - Reflexxivity: $\forall o \in \operatorname{dom}: \operatorname{dist}(o, o)=0$
  - Symmetry: $\forall p, q \in \operatorname{dom}: \operatorname{dist}(p, q)=\operatorname{dist}(q, p)$

Metric space
- A metric space, where the following properties are given.
$$M = (dom, dist)$$
- M is a feature space
- The triangle inequallity must hold:
$$\forall o, p, q \in \operatorname{dom}: \operatorname{dist}(o, p) \leq \operatorname{dist}(o, q)+\operatorname{dist}(q, p)$$
- The most common is Euclidean vector space:
   - dom = $\mathbb{R}^d$ (d: number of features dimensionality)
   - dist = $(x, y) \mapsto\|x-y\|_2$

Spaces and distance functions
- Common distance measure for Euclidean feature vectors is the LP-norm: $$\operatorname{dist}_{\mathcal{P}}(p, q)=\left(\left|p_1-q_1\right|^{\mathcal{P}}+\left|p_2-q_2\right|^{\mathcal{P}}+\ldots+\left|p_n-q_n\right|^{\mathcal{P}}\right)^{\frac{1}{\mathcal{P}}}$$
Or
$$dist_p(x,y) = (\sum^y_{i=1} |x - y|^p)^{\frac{1}{p}}$$

![[Pasted image 20230209145654.png]]

- Weighted Euclidean norm: 
$$\begin{aligned}
& \operatorname{dist}(p, q)=\left(w_1\left|p_1-q_1\right|^2+w_2\left|p_2-q_2\right|^2+\ldots+w_n\left|p_n-q_n\right|^2\right)^{\frac{1}{2}}
\end{aligned}$$
![[Pasted image 20230214085637.png]]

- Quadratic form*:
$$\begin{aligned}
& \operatorname{dist}(p, q)= ((p-q) M(p-q)^{\top})^{\frac{1}{2}}
\end{aligned}$$
![[Pasted image 20230214085646.png]]


Features and descriptions for images
- Color distribution (Color histogram)
- Texture (Roughness / smoothness)
- shapes (concave / convex)

Color historgram
- represent the distribution of colors over the pixels of an image.
- Can be in different color spaces (RGB, HSV, HLS, ...)
- Choose a number of representant / sample points in the color space
- Normalize to account for different image sizes

Different representations of color spaces
![[Pasted image 20230214090712.png]]
![[Pasted image 20230214090735.png]]

 Histogram of a reduction to 8 features of the original images - using valuesbetween 0-1 that sum to 1.
 ![[Pasted image 20230214091923.png]]
The created 8-dimensional can be feed into a classifier or the like. Not a very large difference between the different images.

Increased number of representants to 16, which gives more distinction to each picture but creates a very large features space (feature vector).
![[Pasted image 20230214092122.png]]

Want small feature space but it sacrifices information - fine balance to strike where feature space is small and information loss is kept to a minimum.

Psychologic distance
- Red is closer to pink than blue is visually
- But arithmetically they are the same distance apart 
![[Pasted image 20230214092648.png]]
- You can give weight to certain combination to satisfy psychological similarity with a matrix
![[Pasted image 20230214092627.png]]

Text as "Bag of words"
- Texts can be seen as sets of words or vectors of terms 
- A term can be
  - a single word
  - phrase or part of a sentence
- typical feature extraction from texts: transform a text (document) into a vector of term frequencies:
$$d \mapsto\left(f_{t_1 d}, f_{t_2 d}, \ldots, f_{t_n d}\right)$$
Problems with Term frequencies
1. Many words are totally pointless for distinguishing texts (the, a, it, that, . . . ). 
2. The same word can appear differently (learn, learning; go, went). 
3. The feature space typically becomes very high dimensional (often n > 10000). 
4. Not all terms are equally useful. 
5. Most words from a dictionary don’t occur at all in any of the compared documents (f = 0)
- Different words with the same meaning or very similar
- words with very different meanings Mouse animal/device

Problem 1
- Many words are totally pointless for distinguishing texts (the, a, it, that, . . . ). 
- Solution: eliminate these words before computing the term frequency vector. 
- Such words are called stopwords, list of stopwords for many languages exist.

Problem 2
- The same word can appear differently (learn, learning; go, went).
- Solution: stemming. Any word is mapped to its stem (base or root form).
- For English texts, algorithmic stemming is possible (Porter’s stemming algorithm, see 
  http://tartarus.org/~martin/PorterStemmer/index.html).
- For other languages, dictionaries are required.

Problem 3
- The feature space typically becomes very high dimensional (often d > 10000).
- Solution: selection of the most important terms (feature selection).
- Example: intermediate document frequency
  - very frequent terms appear in almost all documents
  - very rare terms appear in almost no document 
In both cases, these terms are not helpful to distinguish most of the documents

Approach
1. document frequency for all terms: $D F\left(t_i\right)=\frac{\left|\left\{d \mid t_i \in d\right\}\right|}{|\mathcal{D}|}$
2. sort terms according to $DF(t_i)$
   ![[Pasted image 20230214093628.png]]
3. sort terms according to score(ti) = DF(ti) · rank(ti) examples:
$$\begin{aligned} & \operatorname{score}\left(t_{23}\right)=0.82 \cdot 1 \\ & \operatorname{score}\left(t_{17}\right)=0.65 \cdot 2\end{aligned}$$
4. chose the k terms with largest score

Problem 4
- Not all terms are equally useful.
- Solution: TF-IDF (term-frequency - inverse document frequency)
  - Higher weights for rare words
  - Higher weights for more frequent terms 
- TF is the relative term frequency in some document d: $T F(t, d)=\frac{n(t, d)}{\sum_{t_i \in d} n\left(t_i, d\right)}$
- IDF is the inverse document frequency of t for all documents: $ID F(t)=\frac{|\mathcal{D}|}{|\{d \mid d \in \mathcal{D} \wedge t \in d\}|}$
- feature vector for document d = ![[Pasted image 20230214094324.png]]

Problem 5
- Most words from a dictionary don’t occur at all in any of the compared documents (f = 0).
- As a consequence, the Euclidean distance will be very similar for many documents.
- Solution: use different distance measures
- Jaccard coefficient: documents as sets of terms: 
$$\operatorname{dist}_{\text {Jaccard }}\left(D_1, D_2\right)=1-\frac{\left|D_1 \cap D_2\right|}{\left|D_1 \cup D_2\right|}$$
cosine coefficient (possibly for TF-IDF vectors):
$$\operatorname{dist}_{\text {cosine }}\left(D_1, D_2\right)=1-\frac{\left\langle D_1, D_2\right\rangle}{\left\|D_1\right\| \cdot\left\|D_2\right\|}$$