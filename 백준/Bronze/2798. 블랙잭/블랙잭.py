N, M = map(int, input().split())
num = list(map(int, input().split()))
num.sort(reverse=True)
result = 0
flag = False
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            sum = num[i] + num[j] + num[k]
            if sum == M:
                result = sum
                flag = True
                break
            elif result < sum < M:
                result = sum
                break
        if flag:
            break
    if flag:
        break
print(result)