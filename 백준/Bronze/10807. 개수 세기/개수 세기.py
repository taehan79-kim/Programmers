a= int(input())
b= list(map(int, input().split()))
c = int(input())
cnt = 0
for i in range(a):
    if b[i]==c:
        cnt+=1
print(cnt)