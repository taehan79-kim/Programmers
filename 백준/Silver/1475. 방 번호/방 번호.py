import math
num = str(input())
arr = [0 for _ in range(9)]
ans = 0
for n in num:
    if int(n) == 9:
        arr[6] += 1
    else:
        arr[int(n)] += 1
arr[6] = math.ceil(arr[6]/2)
print(max(arr))