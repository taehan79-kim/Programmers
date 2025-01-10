from collections import deque
N = int(input())
tree = [[] for i in range(N+1)]
p = [0 for i in range(N+1)]

for i in range(N-1):
    s, e = list(map(int, input().split()))
    tree[s].append(e)
    tree[e].append(s)

def BFS(root):
    q = deque()
    q.append(root)
    while q:
        cur = q.popleft()
        for nxt in tree[cur]:
            if p[cur] == nxt:
                continue
            q.append(nxt)
            p[nxt] = cur

BFS(1)
for i in range(N-1):
    print(p[i+2])