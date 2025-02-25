a,b=map(int,input().split())
c=set()
d=set()
for i in range(a):
    c.add(input())
for i in range(b):
    d.add(input())
e=sorted(list(c&d))
print(len(e))
for i in range(len(e)):
    print(e[i])