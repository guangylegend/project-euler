def gcd(a, b):
    while b: 
        a, b = b, a%b 
    return a
    
def issquare(n):
    x = n ** 0.5
    return abs(x - round(x)) < 0.0000001

def calc(n):
    cnt=0
    for a in xrange(2, int(n**(1.0/3))+1):
        b = 1
        while b < a and b * (a * a * a + b) < n:
            if gcd(a, b) == 1:
                u = 1
                x = b * (a * a * a  + b)
                while x < n:
                    if issquare(x): cnt+=x
                    u += 1
                    x = b * u * (u * a * a * a + b)
            if a%2 == 1: b+=1
            else: b+=2
    return cnt

print calc(10**12)
