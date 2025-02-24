import sys
input = sys.stdin.readline
d = {}
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

for i in b:
    d[i] = int(0)



for i in a:
    if i in d:
        d[i] +=1

for i in b:
    print(d[i],end=" ")