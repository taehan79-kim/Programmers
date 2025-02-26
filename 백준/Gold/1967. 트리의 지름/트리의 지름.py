import sys

input = sys.stdin.readline

n = int(input())

tree = [[] for _ in range(n+1)]
dist = [-1] * (n+1)
for _ in range(n-1):
    u, v, w = map(int, input().split())
    tree[u].append((v, w))
    tree[v].append((u, w))

q = []
q.append(1)
dist[1] = 0
max = [0,0]
while q:
    cur = q.pop(0)

    for i in tree[cur]:
        nxt, dis = i
        if dist[nxt] > -1:
            continue
        q.insert(0, (nxt))
        dist[nxt] = dist[cur] + dis
        if dist[nxt] > max[0]:
            max[0] = dist[nxt]
            max[1] = nxt

q = []
dist = [-1] * (n+1)

q.append(max[1])
dist[max[1]] = 0

while q:
    cur = q.pop(0)

    for i in tree[cur]:
        nxt, dis = i
        if dist[nxt] > -1:
            continue
        q.insert(0, (nxt))
        dist[nxt] = dist[cur] + dis
        if dist[nxt] > max[0]:
            max[0] = dist[nxt]
            max[1] = nxt
print(max[0])