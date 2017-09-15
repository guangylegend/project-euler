c = dict()
def solve(a, b):
    if c.has_key((a, b)):
        return c[(a, b)]
    if a == 0: return 1
    if a > b * 4 - 2: return 0
    ret = solve(a, b // 2)
    if a >= b: ret += solve(a - b, b // 2)
    if a >= b * 2: ret += solve(a - b * 2, b // 2)
    c[(a, b)] = ret
    return ret

print solve(10**25,2**84)
