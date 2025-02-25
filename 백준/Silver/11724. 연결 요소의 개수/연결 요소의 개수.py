import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
board = [[] for _ in range(1001)]
visit = [0 for _ in range(1001)]
for _ in range(m):
    node1, node2 = map(int, input().rstrip().split())
    board[node1].append(node2)
    board[node2].append(node1)
cnt = 0
for i in range(1, n+1):
    if visit[i] == 1:
        continue
    else:
        cnt+=1
        q = []
        q.append(i)
        visit[i] = 1
        while len(q) > 0:
            num = q.pop()
            for nd in board[num]:
                if visit[nd] == 1:
                    continue
                else:
                    visit[nd] = 1
                    q.append(nd)
print(cnt)