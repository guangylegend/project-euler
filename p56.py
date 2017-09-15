import math

tmax=0

def digitalsum(n):
    sum = 0
    for c in str(n):
        sum += int(c)
    return sum

for i in range(1,100):
    for j in range (1,100):
        sum = digitalsum(i**j)
        if sum > tmax:
            tmax = sum

print(tmax)
