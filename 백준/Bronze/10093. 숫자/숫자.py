a, b = map(int, input().split())
result = []
if b > a:
    print(b - a - 1)
    for i in range(a + 1, b):
        result.append(str(i))
    print(' '.join(result))
elif a > b:
    print(a - b - 1)
    for i in range(b + 1, a):
        result.append(str(i))
    print(' '.join(result))
else:
    print(0)