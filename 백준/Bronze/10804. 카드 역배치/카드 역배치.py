x = list(str(i) for i in range(1,21))
for i in  range(10):
    startnum, endnum = map(int, input().split())
    buff = x[startnum-1: endnum]
    buff.reverse()
    x[startnum-1: endnum] = buff
a= ' '.join(x)
print(a)