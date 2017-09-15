import math

cnt=0

def test(i):
    tmp=str(i)
    for i in range(0,len(tmp)):
        if tmp[i]!=tmp[len(tmp)-1-i]:
            return False
    return True


def isproperty(i):
    tcnt=0
    while (tcnt<50):
        tmp=str(i)
        for j in range(0,len(tmp)):
            i+=(10**j)*int(tmp[j])
        if(test(i)):
            return True
        tcnt+=1
    return False


for i in range(1,10000):    
    if(isproperty(i)):
        cnt+=1
        
print(9999-cnt)
