import sys

input = sys.stdin.readline

a = input().rstrip()
b = input().rstrip()

a_c=[0 for _ in range(26)]
b_c=[0 for _ in range(26)]

for i in a:
    a_c[ord(i) - 97] += 1
for i in b:
    b_c[ord(i) - 97] += 1

cnt = 0
for i in range(26):
    cnt += abs(a_c[i] - b_c[i])

print(cnt)