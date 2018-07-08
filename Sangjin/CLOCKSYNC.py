# -*- coding: utf-8 -*-
"""
Created on Fri Jul  6 17:53:59 2018

@author: SangJin
"""

def checkAnswer(switch,clock):
    result = 0
    
    result += (clock[0] + switch[0] + switch[3] + switch[5]) % 4
    result += (clock[1] + switch[0] + switch[8]) % 4    
    result += (clock[2] + switch[0] + switch[5] + switch[8]) % 4
    result += (clock[3] + switch[1] + switch[6] + switch[8] + switch[9]) % 4

    result += (clock[4] + switch[2] + switch[3] + switch[7] + switch[8] + switch[9]) % 4
    result += (clock[5] + switch[3] + switch[7] + switch[8] + switch[9]) % 4
    result += (clock[6] + switch[3] + switch[4]) % 4
    result += (clock[7] + switch[1] + switch[3] + switch[4] + switch[7]) % 4
    
    result += (clock[8] + switch[4]) % 4
    result += (clock[9] + switch[1] + switch[9]) % 4
    result += (clock[10] + switch[2] + switch[4]) % 4
    result += (clock[11] + switch[1]) % 4

    result += (clock[12] + switch[4]) % 4
    result += (clock[13] + switch[9]) % 4
    result += (clock[14] + switch[2] + switch[5] + switch[6] + switch[7]) % 4
    result += (clock[15] + switch[2] + switch[5] + switch[6] + switch[7]) % 4

    if result == 0:
        return True
    else:
        return False

def findAnswer():
    clock = input().split(' ')
    switch = [0,0,0,0,0,0,0,0,0,0]
    
    for c in range(len(clock)):
        clock[c] = int(int(clock[c])/3)%4
    
    
    if clock[8] != clock[12]:
        print(-1)
        return
    if clock[14] != clock[15]:
        print(-1)
        return
    else:
        switch[4] = (4 - clock[8])%4
        switch[1] = (4 - clock[11])%4
        switch[9] = (4 - clock[13])%4
        
        if (clock[9] + switch[1] + switch[9]) % 4 != 0:
            print(-1)
            return
        else:    
            switch[2] = (4 - (clock[10] + switch[4]) % 4) % 4
            switch[3] = (4 - (clock[6] + switch[4]) % 4) % 4
            switch[7] = (4 - (clock[7] + switch[1] + switch[3] + switch[4]) % 4) % 4
            switch[8] = (4 - (clock[4] + switch[2] + switch[3] + switch[7] + switch[9]) % 4) % 4
            switch[0] = (4 - (clock[1] + switch[8]) % 4) % 4
            switch[6] = (4 - (clock[3] + switch[1] + switch[8] + switch[9]) % 4) % 4
            switch[5] = (4 - (clock[14] + switch[2] + switch[6] + switch[7]) % 4) % 4
            
            result = 0
            for i in switch:
                result += i
            
            if checkAnswer(switch,clock):
                print(result)
            else:
                print(-1)
            return

N = int(input())
for n in range(N):
    findAnswer()



