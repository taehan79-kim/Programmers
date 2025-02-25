import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
board = []
dist = [[-1 for i in range(m)] for j in range(n)]
q = []
for i in range(n):
    row = list(map(int, input().rstrip().split()))
    board.append(row)
    if 2 in row:
        q.append((i, row.index(2)))
        dist[i][row.index(2)] = 0
while len(q) > 0:
    cx, cy = q.pop(0)
    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]
        if nx >= n or ny >= m or nx < 0 or ny < 0 or dist[nx][ny] > -1:
            continue
        if board[nx][ny] == 0:
            dist[nx][ny] = 0
            continue
        elif board[nx][ny] == 1:
            q.append((nx, ny))
            dist[nx][ny] = dist[cx][cy] + 1
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            dist[i][j] = 0

for i in range(n):
    print(" ".join(map(str, dist[i])))