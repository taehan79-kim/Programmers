n, m = map(int, input().split())

namu = list(map(int,input().split()))
namu = sorted(namu, reverse=True)

st = 0
end = max(namu)

def sum_of_tree(mid):
    sum = 0
    for i in namu:
        if i > mid:
            sum += i - mid
        else:
            break
    return sum

for _ in range(max(namu)):
    mid = (st + end)//2
    sum = sum_of_tree(mid)
    if sum >= m:
        sum1 = sum_of_tree(mid+1)
        if sum1 < m:
            print(mid)
            break
        else:
            st = mid + 1
    else:
        end = mid - 1