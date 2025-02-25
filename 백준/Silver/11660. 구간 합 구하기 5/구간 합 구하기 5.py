import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())

board = []
for i in range(n):
    board.append(list(map(int, input().rstrip().split())))

dp =  [[0 for _ in range(n+1)] for _ in range(n+1)]
dp[1][1] = board[0][0]
for i in range(1, n+1):
    dp[1][i] = dp[1][i-1]+board[0][i-2]
    dp[i][1] = dp[i-1][1]+board[i-2][0]

for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i-1][j-1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().rstrip().split())
    sum = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]
    print(sum)