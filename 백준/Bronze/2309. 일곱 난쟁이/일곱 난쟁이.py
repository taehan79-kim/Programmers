x= []
for i in range(9):
    x.append(int(input()))
cntx = sum(x) - 100
for i in range(9):
    for a in range(i+1, 9):
            cnt = x[i] + x[a]
            if cnt == cntx:
                b = x[i]
                c = x[a]
                break
x.remove(b)
x.remove(c)
x.sort()
for i in range(7):
    print(x[i])