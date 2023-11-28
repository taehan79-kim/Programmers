# dp
# d[k][j] = k줄 j 번째 최대값
# 점화식
# d[k][j] = max(d[k-1][j],d[k-1][j-1]) + S[k][j]
# S[k][j] = k줄 j번째 원소의 값
def solution(triangle):
    answer = 0
    d = [[0 for j in range(0, k+1)] for k in range(len(triangle))]
    tempd = [[0 for j in range(0, k+1)] for k in range(len(triangle))]
    num = len(triangle)
    # print(d)
    d[0][0]=triangle[0][0]
    for k in range(1, len(triangle)):
        for j in range(0,k+1):
            #print(k,j)
            if j>0 and j < k:
                tempd[k][j] = max(d[k-1][j],d[k-1][j-1]) + triangle[k][j]
            elif j==0:
                tempd[k][j] = d[k-1][0] + triangle[k][0]
            elif j == k:
                tempd[k][j] = d[k-1][j-1] + triangle[k][j]
            if tempd[k][j] > d[k][j]:
                d[k][j] = tempd[k][j]
    # print(d)
    answer = max(d[num-1])
            
    return answer