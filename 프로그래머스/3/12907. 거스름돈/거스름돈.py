# dp 사용
# D[n] n을 만드는 경우의 수
# 점화식 D[n] = D[n-1] + D[n-2] -D[n-1-2] +D[n-5]-D[n-2-5] -D[n-1-5] +D[n-1-2-5]

def solution(n, money):
    answer = 0
    d = [0 for i in range(n+1)]
    d[0] = 1
    
    for k in money:
        for i in range(k,n+1):
            d[i] += d[i-k]
    # print(d)
    answer = d[n]
    return answer