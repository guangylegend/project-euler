import math

p1 = [0 for i in range(1,105)]
p2 = [0 for i in range(1,105)]

def dsum(x):
    tsum=0
    for c in str(x):
        tsum+=int(c)
    return tsum



def cnt(x):
    tmp=(x-1)%3
    if tmp==2:
        p1[1]=int((x/3)*2)
    else:
        p1[1]=1
    p2[1]=1
    for i in range(2,x):
        tmp1=p2[i-1]
        tmp2=p1[i-1]
        tt=0
        ii=(x-i)%3
        if ii==2:
            tt=int(((x-i+1)/3)*2)
        else:
            tt=1
        p1[i]=tmp1+tmp2*tt
        p2[i]=tmp2
    p1[x]=p1[x-1]*2+p2[x-1]
    p2[x]=p1[x-1]
    print(dsum(p1[x]))

cnt(100)

