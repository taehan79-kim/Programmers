import sys
n = int(input())

a = list(map(int, sys.stdin.readline().split()))

m = int(input())

b = list(map(int, sys.stdin.readline().split()))

a.sort()

for i in b:
    isin = 0
    stt = 0
    end = n - 1 
    if i < a[stt]:
        print(isin)
        continue
    if i > a[end]:
        print(isin)
        continue
    if i == a[end]:
        isin = 1
        print(isin)
        continue
    while stt <= end:
        mid = int((stt + end)/2)
        if i == a[mid]:
            isin = 1
            break
        elif i < a[mid]:
            end = mid - 1
        else:
            stt = mid + 1

    print(isin)