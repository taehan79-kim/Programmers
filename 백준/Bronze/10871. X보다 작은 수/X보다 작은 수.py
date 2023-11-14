n, x = map(int,input().split())
b = list(map(str, input().split()))
for i in b[:]:
    if int(i) >= x :
        b.remove(i)
a= ' '.join(b)
print(a)