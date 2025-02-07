n, target = map(int, input().split())
q = [(1, n)]
result = -1
while True:
    if len(q) == 0:
        print(result)
        break
    dist, now = q.pop(0)

    if now > 10**9 or now > target:
        continue
    
    if now == target:
        print(dist)
        break

    q.append((dist+1, int(str(now)+'1')))
    q.append((dist+1, now*2))