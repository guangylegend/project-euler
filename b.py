from decimal import Decimal
reader = open("B-large.in","r")
writer = open("B-large.out","w")
t = int(reader.readline())
for tt in xrange(t):
	n, m = map(int,reader.readline().split())
	s = map(int,reader.readline().split())
	for i in range(1,len(s)):
		s[i] *= s[i - 1]
	writer.write("Case #%d:\n"%(tt+1))
	for i in xrange(m):
		l, r = map(int,reader.readline().split())
		writer.write("%s\n"%(str(Decimal(s[r]/(s[l-1] if l!=0 else 1))**Decimal(1.0/(r-l+1)))))
writer.close()
