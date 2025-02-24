import sys
n = int(sys.stdin.readline())
a = []
for i in range(n):
    age, name = map(str, sys.stdin.readline().split())
    age = int(age)
    a.append((age, name))

a.sort(key= lambda x : x[0])

for i in a:
    print(i[0], i[1])
