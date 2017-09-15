cache = {}

def count(digits, nbs, prefix):
  if digits == 20:
    return int(prefix == 0)
  key = digits, tuple(nbs), prefix
  if key in cache: return cache[key]
  res = 0
  for d in xrange(10):
    if nbs[d] == 2: continue
    nbs[d] += 1
    res += count(digits+1, nbs, (prefix * 10 + d) % 11)
    nbs[d] -= 1
  cache[key] = res
  return res

res = 0
nbs = [ 0 ] * 20
for d in xrange(1, 10):
  nbs[d] += 1
  res += count(1, nbs, d)
  nbs[d] -= 1
  
print res
