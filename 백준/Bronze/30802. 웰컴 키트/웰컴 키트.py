N = int(input())
size = input().split(" ")
T, P = input().split(" ")

cnt = 0
for shirt in size:
    cnt += int(int(shirt) / int(T))
    if int(shirt) % int(T) != 0:
        cnt += 1
p_share = int(N / int(P))
p_rest = N % int(P)

print(cnt)
print(f"{p_share} {p_rest}")