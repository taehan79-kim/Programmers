import sys
n = int(input())

a = []
for i in range(n):
    num = int(sys.stdin.readline())
    a.append(num)
a.sort()
for i in a:
    print(i)