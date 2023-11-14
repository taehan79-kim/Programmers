x = []
y = []
for i in range(7):
    x.append(int(input()))
    if (x[i]%2) == 1:
        y.append(x[i])
if y:
    print(sum(y))
    print(min(y))
else:
    print(-1)