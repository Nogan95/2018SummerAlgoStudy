# -*- coding: utf-8 -*-
"""
Created on Sat Jul  7 15:37:07 2018

@author: SangJin
"""

# 미완성 코드 입니다.

def classify(a, b):
    M = N[a:b+1]
    
    print(M)
    
    if M.count(M[0]) == len(M):
        return 1
    
    prograssive = True    
    
    for i in range(1,len(M)-1):
        if int(M[i+1]) - int(M[i]) != int(M[1]) - int(M[0]):
            prograssive = False

    if (prograssive and (abs(int(M[1]) - int(M[0])) == 1)):
        return 2;
    
    alternating = True
    
    for i in range(len(M)):
        if int(M[i]) != int(M[i%2]):
            alternating = False
            
    if alternating:
        return 4
    if prograssive:
        return 5
    return 10

def Memorize(begin):
    if begin == len(N):
        return 0
    global cache
    ret = cache[begin]
    if ret != -1:
        return ret
    ret = 987654321
    for L in range(3,6):        
        if begin + L < len(N):
            print(L, begin, begin + L -1)
            tmp = Memorize(begin + L) + classify(begin,begin+L-1)
            print("= ", tmp)
            if ret < tmp:
                cache[begin] = ret
            else:
                cache[begin] = tmp
        ret = cache[begin]
    return cache[begin]

roof = int(input())
for R in range(roof):
    N = input()    
    cache = [-1 for i in range(10)]    
    print(Memorize(0))
    print(cache)
    
    
