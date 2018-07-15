# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 16:17:38 2018

@author: SangJin

Google Code Jam Qualification Round 2016 A

"""

f = open("A-large-practice.in",'r')
d = open("result.txt",'w')

R = int(f.readline())
for roof in range(R):
    N = int(f.readline())
    if N == 0:
        d.write("Case #" + str(roof + 1) + ": INSOMNIA\n")
    else:
        ret = True
        check = [0,0,0,0,0,0,0,0,0,0,0]
        i = 1
        while ret:
            num = str(i * N)
            for c in num:
                check[int(c)] = 1
            if check.count(1) == 10:
                d.write("Case #" + str(roof + 1) + ": " + str(num)+"\n")
                ret = False
            i += 1

f.close
d.close