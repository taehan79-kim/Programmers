import sys

input = sys.stdin.readline

n= int(input().rstrip())

b = [[1e9 + 1, 0]]
sum = 0
for i in range(n):
    height = int(input().rstrip())
    
    while b[-1][0] <= height:
        b.pop()
    sum += len(b)-1
    # print(f"{height}높이의 건물이 보여지는 수: {len(b)-1}")
    b.append([height, i])
print(sum)