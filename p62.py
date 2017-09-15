import math

ks=[0 for i in range(0,10001)]
he=[0 for i in range(0,15)]
haha={}


def add(x):
    for i in range(0,10):
        he[i]=0
    w=0
    tsum=0
    y=x**3
    for c in str(y):
        he[int(c)]+=1
        w+=1
    for i in range(1,w+1):
        j=9
        while 1:
            if he[j]>0:
                tsum+=j*(10**(w-i))
                he[j]-=1
                break
            j-=1
    if tsum not in haha:
        haha[tsum]=1
    else:
        tmp=haha.get(tsum)
        haha[tsum]=tmp+1
    ks[x]=tsum

def isproperty(x):
    if haha[ks[x]]==5:
        return True
    return False
    

for i in range(1,10000):
    add(i)
for i in range(1,10000):    
    if isproperty(i):
        print(i**3)
        break
