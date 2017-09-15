import math

tmp1=3
tmp2=2
cnt=0

for i in range(1,1000):
    tmp2=tmp1+tmp2
    tmp1=tmp2-tmp1+tmp2
    if len(str(tmp1))>len(str(tmp2)):
        cnt+=1
print(cnt)




