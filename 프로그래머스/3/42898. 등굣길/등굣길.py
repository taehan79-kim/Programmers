def solution(m, n, puddles):
    answer = 0
    MOD = 1_000_000_007
    dp = [[0 for _ in range(m+1)] for __ in range(n+1)]
    
    # 초기값 설정
    dp[1][1] = 1
    
    # 점화식: 최단 거리는 왼쪽까지의 최단 거리와 위쪽의 최단 거리의 합이다.
    for i in range(1, n + 1):
        for j in range(1, m+1):
            print(f"{i}, {j}")
            if i == 1 and j == 1:
                continue
            if [j, i] in puddles:
                dp[i][j] = 0
            else:
                dp[i][j] = (dp[i-1][j] % MOD) + (dp[i][j-1] % MOD)
            dp[i][j] %= MOD
        
    for i in range(len(dp)):
        print(dp[i])
    answer = dp[n][m] % MOD
    return answer