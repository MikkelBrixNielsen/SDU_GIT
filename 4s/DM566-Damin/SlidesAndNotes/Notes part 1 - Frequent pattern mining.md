Funny Data science diagrams:  
- [Battle of the Data Science Venn Diagrams - KDnuggets](https://www.kdnuggets.com/2016/10/battle-data-science-venn-diagrams.html)

Frequent pattern mining (part 1):  
  

Data mining / machine learning:  
- Computational methods for learning from data  
- Different methods deliver different pictures of the data  
- Any assumptions made before extracting the data will influence the data extracted

Data science:  
- Meaning A: doing science based on (big) data  
- Meaning B: the science of working with data  
- Learning from data, finding patterns in data, understanding databases

Normal coding:  
- Errors occur due to a random bug because your code is wrong

Machine learning:  
- Errors can occur due to either the code being wrong, or the code is perfect, but the model is wrong

Machine learning is kind of like a journal in physics, you test a thesis (model) if the results are wrong you try another or redo the experiment (code).

KDD is the nontrivial process of identifying valid, novel, potentially useful, and ultimately understandable patterns in data.” Fayyad et al. 1996

·        data: set of facts (e.g., entries in a database)

·        pattern: expression in some language to describe a data subset (e.g., mathematical model)

·        process: can involve several steps or iterations

·        nontrivial: more complex than search, inference, simple aggregations

·        valid: applicable to new data with a certain degree of reliability

·        novel: for the system, better: for the user

·        potentially useful: beneficial for user of application

·        ultimately understandable: if not immediately then given some post processing

understandability ⇔ simplicity? (validity, novelty, usefulness, simplicity) ⇔ “interestingness”

validity (results that you expect to some extend)

novelty (something unexpected that can potentially give you a competitive edge)

  

The KDD process model:

Focusing: (difficult part)  
- Get the data  
- Organize data (file/database)  
- Extract relevant data

Pre-processing:  
- integrate heterogeneous data  
- Check for completeness  
- Check for consistency

Transformation:  
- Discretize numeric attributes  
- Inter new attributes  
- Select the relevant attributes

Data mining:  
- Generate patterns or models

Evaluation: (difficult part)  
- Asses “interestingness” for the user  
- Validate models statistically

(Hard to access high quality data, from which you can actually compute something)

Clustering:  
- Collecting data and grouping similar datapoints together based on their attributes and “labelling” them according to their attributes.  
- Problems: What happens with outliers, are they errors, or are they actual real occurrences you could expect to occur in the real world. Some boundary has to be established.

![[clip_image002 1.png]]

  

Classification:  
- Taking data and applying a function to it with the purpose of identifying what category the data belongs to e.g., pictures having to be classified to be an element of a list e.g. {cat, dog, face, etc…}  
- Can be modelled to provide a percentage (or other) confidence in whether or not a certain datapoint’s classification is accurate.

![[Pasted image 20230209181146.png]]

Supervised learning:  
- Close to clustering except the datapoints have an actual label along with its other attributes, that describes what the datapoint is e.g., nail, staple, car, dog or whatever.

Regression:  
- Can take on point (value, attributes on the real line), given previous values e.g., the value of a currency – tell me what it will be tomorrow, a week, a year, 10 years from now etc…

Frequent pattern mining:  
- Given a data set we want to extract some useful data from it. In this case it would be patterns that occur in the given data set and with what confidence if a part of it occurs, with what confidence can you say the rest also occurs.

![[Pasted image 20230209181153.png]]

(The rules are called association rules)

  

Data mining techniques from data knowledge:  
![[Pasted image 20230209181206.png]]

Predictive models:  
- A predictive model should describe (known) data in a way suitable to make predictions on unknown data.

Descriptive models:  
- A model should provide insight in the data, help to understand the underlying structure, correlations, properties etc.

A data mining model can be both, descriptive and predictive. I Based on both could be a prescriptive model: Learn from the data for the future: a model to tell you what to change, or how to implement details (typically related to optimization problems).

Supervise learning: (e.g., classification, regression, outlier detection):  
- An in general unknown attribute is learned, based on examples (training data) where the attribute is known. Emphasis on predictive modelling.

Unsupervised learning: (e.g., clustering, outlier detection, association rules)  
- The data are distinguished/organized in different groups without previously known examples. Emphasis on descriptive modelling.

Semi-supervise leaning: (e.g., clustering, outlier detection)  
- Semi-supervised techniques are guided by using some information (e.g., only one class is known, or some constraints restrict clustering results)

Self-supervised learning:  
- it is trained on a huge amount of data / text or whatever, which is supervised, and then in finds its own way to label the data it is given by creating a lot of supervised subproblems, which solves the larger problem.

  

Pre-processing is very important since e.g.:

Data may be:  
- noisy in the sense of containing errors, outliers  
- noisy in the sense of containing lots of irrelevant information  
- incomplete (e.g., missing values, missing attributes, that  
- would have been particularly interesting for some given task)  
- inconsistent (e.g., different scaling in student evaluation sheets for different cohorts, different questions in questionnaires for different universities)

Some typical data pre-processing might be:  
- Data cleaning: impute missing values, smoothing of noisy values, identify or remove outliers, resolve inconsistencies  
- Data integration: combination from different data sources: entity identification, value resolution- Data reduction: elimination of duplicates

(Many of these operations do actually change the data, based on some assumptions – handle with care if these assumptions are not explicit!)

Data descriptions:  
- Many techniques work on feature attributes (feature vectors).  
- Other techniques work directly on complex data such as text, sets, graphs.  
- If we are to perform data mining on some complex objects, it is an important preprocessing step to derive meaningful features to describe these objects.

  

Similarity as given by some distance measure is a central concept in datamining, clustering (similar objects are put together, dissimilar objects in different cluster)

Outlier detection, objects that are dissimilar from most other objects. Defining a suitable distance measure is often crucial for deriving meaningful data.

A data mining method will work on any feature set – thus the mapping is very important if any meaningful data is meant to be gathered.

Regarding a dataset before applying a data mining model to it some typical transformation tasks, which could be applied to it are, scale, normalize, generalize (e.g., by concept hierarchy), data reduction: aggregation, feature combination, dimensionality reduction, or one could derive new features.

Concept hierarchy:

![Concept Hierarchy - an overview | ScienceDirect Topics](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image010.jpg)

Depending on the feature space the data can be represented in different ways of which the easiest to separate is preferable:

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image012.png)

evaluation: the fundamental problem of measuring validity and novelty at the same time

Software validation – does it do what was intended

Software verification – is it correct

Definition of frequent item-sets
![[Pasted image 20230209181222.png]]

Confidence for itemset:

![[Pasted image 20230209181230.png]]

Itemset cover, frequency, frequent, and support
![[Pasted image 20230209181234.png]]

Cover = the set of item-sets, which contains all item-sets related to a specific query

  

Association rule mining (support, frequency, confidence):

![[Pasted image 20230209181239.png]]

Monotonicity and anti-monotonicity:

![[Pasted image 20230209181243.png]]

  

Positive and negative borders in conjunction with item-sets  
![[Pasted image 20230209181247.png]]

Closeness (closed frequent item-sets)

![[Pasted image 20230209181251.png]]

Apriori uses monotonicity property to prune the creates lattice to speed up computation.

- Maximal frequent itemset: Super set not frequent subsets frequent. It is at the border if none of its superset are frequent, but all its subsets are frequent. Motivation is concise reporting.

- Maximal closed frequent itemset: if an itemset has more support if none of its immediate supersets has more support than it has. Then if it is frequent, it is a closed frequent itemset. Motivation calculating association rules without a database scan.

Apriori is a greedy algorithm start from size 1 and increases the size after each run. It follow theses 3 steps:

![[Pasted image 20230209181257.png]]

![](file:///C:/Users/mikke/AppData/Local/Temp/msohtmlclip1/01/clip_image030.png)

![[Pasted image 20230209181302.png]]

![[Pasted image 20230209181307.png]]
![[Pasted image 20230209181319.png]]

More detailed example check slides 85 -> 88

O(|D| * 2|i|) – computational complexity of naïve / brute force apriori algorithm
![[Pasted image 20230209181325.png]]

Frequent itemsets are used since we don’t need to go back to the transaction database and because of the monotonicity property.

![[Pasted image 20230209181330.png]]

Pruning of association rules

MFI – reporting

CF – association rule mining – quarries of higher level of sigma (threshold)

FI – association rule mining – can safely pick up all association rules since it will apply to all confidence levels
![[Pasted image 20230209181334.png]]

Association rule with highest possible confidence and highest possible support.

![[Pasted image 20230209181339.png]]

{tea} -> {coffee}  
support = 150  
Confidence = s({tea union coffee}) / s(tea) = 150/200

{} -> {coffee}  
Support = 800  
Confidence = s({coffee}) / s({}) = 800/1000

Restricting and trying to predict high frequency events can result I lower confidence

Interestingness

![[Pasted image 20230209181343.png]]

Other algorithms and what apriori can be used for

![[Pasted image 20230209181347.png]]

Interestingness'
![[Pasted image 20230209181831.png]]

Support and confindece interpretation 
![[Pasted image 20230209181849.png]]