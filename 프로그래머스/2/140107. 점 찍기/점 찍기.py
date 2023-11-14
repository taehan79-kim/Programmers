def solution(k, d):
    cnt = 0
    for x in range(0,d+1,k):
        maxy= (d**2-x**2)**0.5
        plus = int(maxy/k)+1
        cnt = cnt+plus
    return cnt