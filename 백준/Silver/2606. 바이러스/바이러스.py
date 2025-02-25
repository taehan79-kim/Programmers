import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
board = [[] for i in range(101)]
visit = [0 for i in range(101)]
for _ in range(m):
    c1, c2 = map(int, input().rstrip().split())
    board[c1].append(c2)
    board[c2].append(c1)
q = [1]
visit[1] = 1
cnt = 0
while len(q) > 0:
    num = q.pop()
    for i in range(len(board[num])):
        if visit[(board[num][i])]==0:
            q.append(board[num][i])
            cnt+=1
            visit[board[num][i]] = 1
print(cnt)