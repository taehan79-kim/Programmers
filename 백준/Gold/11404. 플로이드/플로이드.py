import sys

input = sys.stdin.readline

INF = 1000000000
n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
table = [[INF for _ in range(n+1)] for __ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))
    table[a][a] = 0
    if table[a][b] <= c:
        continue
    table[a][b] = c

def floyd():
    for i in range(1, n+1):
        for s in range(1, n+1):
            if s == i:
                continue
            for t in range(1, n+1):
                if t == s or t == i:
                    continue
                if table[s][t] > table[s][i] + table[i][t]:
                    table[s][t] = table[s][i] + table[i][t]

floyd()
for i in range(1, n+1):
    for j in range(1, n+1):
        if table[i][j] == INF:
            table[i][j] = 0
for i in range(1, n+1):
    print(" ".join(map(str, table[i][1:])))