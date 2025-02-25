import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    stk = [list(map(int, input().rstrip().split()))]
    stk.append(list(map(int, input().rstrip().split())))

    dp = [[0 for i in range(n)] for j in range(2)]
    
    # dp 초기값 설정
    dp[0][0] = stk[0][0]
    dp[1][0] = stk[1][0]

    for i in range(1,n):
        for j in range(2):
            nxt = j + 1
            if nxt == 2:
                nxt = 0
                
            tmp1 = dp[nxt][i-1] + stk[j][i]
            tmp2 = dp[j][i-1]
            if tmp1 > tmp2:
                dp[j][i] = tmp1
            else:
                dp[j][i] = tmp2

    print(max([dp[0][n-1], dp[1][n-1]]))

