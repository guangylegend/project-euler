import math

cnt=0

for i in range(1,1000):
    j=1
    while 1:
        tmp = len(str(j**i))
        if tmp>i:
            break
        if tmp==i:
            cnt+=1
        j+=1

print(cnt)
