n, k = map(int,input().split())
l = [i+1 for i in range(n)]

idx = 0
result = []
for i in range(n):
    for j in range(k):
        if len(l) <= idx:
            idx = 1
        else:
            idx += 1 
    num = l.pop(idx-1)
    idx -= 1
    result.append(num)

st = ", ".join(map(str, result))
print(f"<{st}>")