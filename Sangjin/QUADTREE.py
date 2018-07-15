# -*- coding: utf-8 -*-
"""
Created on Sat Jul  7 15:37:07 2018

@author: SangJin
"""

# 미완성 코드 입니다.

depth = 0
maxDepth = 0
count =[0]

text = "xxwbbwxwbbwxwbbwxwbbw"
for k in text:
    if k == 'x':
        depth += 1
        count.append(0)
    else:
        tmp = count.pop()
        if tmp != 2:
            tmp += 1
            count.append(tmp)
        else:
            depth -= 1
    if depth > maxDepth:
        maxDepth = depth

quadTreeMap = [[0]*pow(2,maxDepth) for i in range(pow(2,maxDepth))]

def fillMap(quadTreeMap, depth, count):
    size = len(quadTreeMap)
    start = [0,0]
    finish = [size,size]

   
    for i in range(1,depth):
        block = int(size/(pow(2,depth)))    
        if count[i] == 0:
            finish[0] = finish[0] - block
            finish[1] = finish[1] - block
        elif count[i] == 1:
            start[1] = start[1] + block
            finish[0] = finish[0] - block
        elif count[i] == 2:
            start[0] = start[0] + block
            finish[1] = finish[1] - block
        elif count[i] == 3:
            start[0] = start[0] + block
            start[1] = start[1] + block
                
    for i in range(start[0],finish[0]):
        for j in range(start[1],finish[1]):            
                quadTreeMap[i][j] = 1

depth = 0
count =[0]

for k in text:    
    if k == 'x':
        depth += 1     
        count.append(0)
    else:
        if k == 'b':
            fillMap(quadTreeMap, depth, count)
        tmp = count.pop()        
        if tmp < 3:
            tmp += 1
            count.append(tmp)            
        else:
            tmp2 = count.pop()
            tmp2 += 1
            count.append(tmp2)
            depth -= 1
    print(count)

print(quadTreeMap)      
