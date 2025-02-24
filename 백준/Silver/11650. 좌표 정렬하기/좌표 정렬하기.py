import sys

n = int(input())
a = []
for i in range(n):
    j, k = map(int, sys.stdin.readline().split())
    a.append((j, k))

a.sort(key= lambda x: (x[0], x[1]))

for i in a:
    print(i[0], i[1])