import sys
input = sys.stdin.readline

n = int(input())
x = list(map(int, input().rstrip().split()))
x_sorted = sorted(x)

cur = min(x)
num = 0
d = {min(x) : 0}
result = []
for i in range(1, n):
    if cur != x_sorted[i]:
        num += 1
        cur = x_sorted[i]
        d[x_sorted[i]] = num
    else:
        d[x_sorted[i]] = num
for i in x:
    result.append(d[i])
print(" ".join(map(str, result)))