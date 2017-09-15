import math

a=[0 for i in range(1,1001)]
b=[0 for i in range(1,1001)]
c=[0 for i in range(1,1001)]
d=[0 for i in range(1,1001)]

def gcd(x,y):
    if y>x :
        x,y=y,x
    if y==0:
        return x
    return gcd(x-y,y)


def test(x):
    cnt=0;
    for i in range(1,1000):
        a[i]=b[i]=c[i]=d[i]=0
    aa=1
    bb=x
    cc=0
    dd=1
    while(1):
        tmp=int(((aa+0.0)*math.sqrt(bb)+cc)/dd)
        atmp=aa*dd
        ctmp=(cc-dd*tmp)*(-dd)
        dtmp=aa*aa*bb-(cc-dd*tmp)*(cc-dd*tmp)
        ktmp=gcd(gcd(ctmp,atmp),dtmp)
        aa=int(atmp/ktmp)
        cc=int(ctmp/ktmp)
        dd=int(dtmp/ktmp)
        a[cnt]=aa
        b[cnt]=bb
        c[cnt]=cc
        d[cnt]=dd
        for i in range(0,cnt):
            if(a[i]*dd==d[i]*aa)and(c[i]*dd==d[i]*cc):
                return cnt-i
        cnt+=1

sum=0
for i in range(2,10001):
    if((math.sqrt(i)-(int)(math.sqrt(i)))>1e-8):
        #print(test(i))
        if(test(i)%2==1):
            sum+=1

print(sum)
