import copy

def FindKind(_X,_Y,curMap,x,y):
    global count
    if y == _Y:
        y = 0
        x += 1
    if x == _X-1:
        for k in range(_Y):
            if curMap[_X-1][k] == '.':
                return
        count += 1       
        return
    if curMap[x][y] == '.':
        if y < _Y-1:            
            if curMap[x][y+1] == '.' and curMap[x+1][y+1] == '.':
                newMap = copy.deepcopy(curMap)
                newMap[x][y] = '#'
                newMap[x][y+1] = '#'
                newMap[x+1][y+1] = '#'
                FindKind(_X,_Y,newMap,x,y+1)
            if curMap[x][y+1] == '.' and curMap[x+1][y] == '.':
                newMap = copy.deepcopy(curMap)
                newMap[x][y] = '#'
                newMap[x][y+1] = '#'
                newMap[x+1][y] = '#'
                FindKind(_X,_Y,newMap,x,y+1)        
            if curMap[x+1][y] == '.' and curMap[x+1][y+1] == '.':
                newMap = copy.deepcopy(curMap)
                newMap[x][y] = '#'
                newMap[x+1][y] = '#'
                newMap[x+1][y+1] = '#'                
                FindKind(_X,_Y,newMap,x,y+1)
        if y > 0:
            if curMap[x+1][y] == '.' and curMap[x+1][y-1] == '.':
                newMap = copy.deepcopy(curMap)
                newMap[x][y] = '#'
                newMap[x+1][y] = '#'
                newMap[x+1][y-1] = '#'
                FindKind(_X,_Y,newMap,x,y+1)
    else:
        FindKind(_X,_Y,curMap,x,y+1)

N = int(input())
for n in range(N):        
    tmp = input().split(' ')
    x = int(tmp[0])
    y = int(tmp[1])
    
    totalMap = [['#']*y for i in range(x)]
    
    for i in range(x):    
        text = input()    
        for j in range(y):
            if text[j] == '.':            
                totalMap[i][j] = '.'    
        
    count = 0    
    FindKind(x,y,totalMap,0,0)    
    print(count) 