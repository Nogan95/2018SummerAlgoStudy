# -*- coding: utf-8 -*-
"""
Created on Fri Jul  6 14:30:21 2018

@author: SangJin
"""

def FindFriends(flist,friendsMap):
    global count
    if len(flist) > 2:
        node = flist.pop()
        for i in range(len(flist)):
            if friendsMap[node][flist[i]] == 0:
                tmp = flist.pop(i)
                FindFriends(flist,friendsMap)
                flist.insert(i,tmp)
        flist.append(node)
    else:
        if friendsMap[flist[0]][flist[1]] == 0:
            count += 1

N = int(input())

for n in range(N):
    tmp = input().split(' ')
    numOfStudent = int(tmp[0])
    numOfFriends = int(tmp[1])
    
    friendsList = input().split(' ')
    friendsMap = [[-1]*numOfStudent for i in range(numOfStudent)]
        
    for i in range(numOfFriends):
        friendsMap[int(friendsList[i*2])][int(friendsList[i*2+1])] = 0;
        friendsMap[int(friendsList[i*2+1])][int(friendsList[i*2])] = 0;
    
    friendsList = [i for i in range(numOfStudent)]
    count = 0
        
    FindFriends(friendsList, friendsMap)
    print(count)