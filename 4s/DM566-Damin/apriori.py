from itertools import combinations as cmbs

# transactions = [[1,2,3], [1,2,4], [1,3,4], [1,3,5], [2,3,4]]
transactions = [['B','E','G','H'],['A','B','C','E','G','H'],['A','B','C','E','F','H'],['B','C','D','E','F','G','H','L'],['A','B','E','K','H'],['B','E','F','G','H','I','K'],['A','B','D','G','H'],['A','B','D','G'],['B','D','F','G'],['C','E','F'],['A','C','E','F','H'],['A','B','E','G']]
sigma = 4

def findFrequentItemSets(transactions):
    res = []
    cnt = []
    for trans in transactions:
        for obj in trans:
            if [obj] not in res:
                res.append([obj])
                cnt.append(1)
            else: 
                cnt[res.index([obj])] += 1
    return res, cnt

def isCombsInFreq(iCombs, freq):
    # print("Subsets: ")
    for c in iCombs:
        # print(list(c))
        if not list(c) in freq:
            return 0
    return 1

def pruneCands(cands, freq):
    res = []
    for c in cands:
        # print("checking candidate " + str(c) + "...")
        combs = cmbs(c, len(c) - 1)
        if (isCombsInFreq(combs, freq)):
            res.append(c)
    return res

def matchElems(fis1, fis2, k):
    matching = 0
    for i in range(len(fis1)):
        if fis1[i] == fis2[i]:
            matching += 1
        else:
            return matching >= k-2

def joinLists(lst1, lst2):
    lst1.append(lst2[-1])
    return lst1

def create(freq, k):
    res = []
    n = len(freq)
    for i in range(n):
        fis1 = freq[i]
        for j in range(n):
            fis2 = freq[j]
            if not fis1 == fis2 and matchElems(fis1, fis2, k):
                cand = joinLists(fis1.copy(), fis2.copy())
                cand.sort()
                if cand not in res:
                    res.append(cand)
    return sorted(res, key=lambda x: x[0] )

def makeCandidates(freq, k):
    cands = []
    combs = []
    #if k == 2: 
     #   combs = cmbs(freq, k)
        # flattens the tuples created by cmbs to lists of potential candidates 
      #  combs = [[obj for sub in sublist for obj in sub] for sublist in combs] 
       # for c in combs:
            # print(c)
        #    if c not in cands:
         #       cands.append(c)
    #else: 
    cands = create(freq, k)
    print("Frequent " + str(k-1) + "-itemsets: " + str(sorted(freq)))
    print("Candidates for " + str(k) + "-itemsets: " + str(cands))
    return pruneCands(cands, freq)

def removeNoneSubSet(trans, cands):
    res = []
    cnt = []
    for t in trans:
        for c in cands:
            if all(obj in t for obj in c):  # checks if c is subset of t
                c.sort()
                if c not in res:
                    res.append(c)
                    cnt.append(1)
                else:
                    cnt[res.index(c)] += 1
    return res, cnt

def apriori(transactions, sigma):
    s, cnt = findFrequentItemSets(transactions)
    k = 2
    print("Initial 1-itemsets:")
    zippedS = sorted(zip(s,cnt), key=lambda x: x[0])
    for pair in zippedS:
        print(pair)
    # prunes initial list of cands with < sigma support  
    s = [cand[0] for cand in zip(s, cnt) if cand[1] >= sigma]
    # for lst in s:
        #lst.sort()
    #s.sort()    
    print("Candidates after initial prunning of support < sigma: " + str(sorted(s)))
    while len(s) > 0:
        cands = makeCandidates(s, k)
        c, cnt = removeNoneSubSet(transactions, cands)
        #for lst in c:
            #lst.sort()
        #c.sort()
        print("Candidates after prunning candidates which weren't a subset of a transaction:")
        zippedC = (sorted(zip(c, cnt), key=lambda x: x[0])) 
        for pair in zippedC:
            print(pair)
        s = [cand[0] for cand in zip(c, cnt) if cand[1] >= sigma]
        k += 1
        print("Candidates after prunning for candidates with support < sigma:")
        print(sorted(s))
        print("\n\n")

apriori(transactions, sigma)
