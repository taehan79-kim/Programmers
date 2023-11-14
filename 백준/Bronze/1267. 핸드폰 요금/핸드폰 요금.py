import math
n = int(input())
x = list(map(int,input().split()))
yresult = int()
mresult = int()
for i in range(n):
    yresult = yresult + 10 * math.ceil(x[i] / 29.99)
    mresult = mresult + 15 * math.ceil(x[i] / 59.99)
if mresult > yresult:
    print("Y " + str(yresult))
elif yresult > mresult:
    print("M " + str(mresult))
else:
    print("Y M " + str(mresult))