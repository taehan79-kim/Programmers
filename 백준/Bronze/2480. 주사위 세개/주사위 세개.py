x = list(map(int,input().split()))
cnt = 0
if x[0] == x[1] :
    cnt += 1
    num = x[0]
if x[0] == x[2]:
    cnt += 1
    num = x[0]
if x[1] == x[2]:
    cnt += 1
    num = x[1]
if cnt == 3:
    print(10000 + num * 1000)
elif cnt == 1:
    print(1000 + num * 100)
elif cnt == 0:
    print(max(x) * 100)