for i in range(1010101010,2000000000,10):
    s = str(i*i)
    f = True
    for j in range(1,10):
        if int(s[(j-1)*2])!= j:
            f = False
    if f:
        print(i)
        print(i*i)
        break
