import math
ks=[]
ks.append(1)
ks.append(1)
cnt=3
while 1:
    ks.append(ks[cnt-2]+ks[cnt-3])
    if len(str(ks[cnt-1]))>=1000 :
        print(cnt)
        break
    else :
        cnt+=1
