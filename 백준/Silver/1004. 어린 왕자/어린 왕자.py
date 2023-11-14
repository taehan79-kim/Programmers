T = int(input())

# 테스트 케이스 진행
for _ in range(T):
    x1,y1,x2,y2 = list(map(int,input().split()))
    
    n = int(input())
    cnt = 0
    # n개의 행성계 계산
    for _ in range(n):
        c_x,c_y, c_r = map(int, input().split())
        distance1 = (x1 - c_x)**2 + (y1 - c_y)**2
        distance2 = (x2 - c_x)**2 + (y2 - c_y)**2
        
        if c_r**2 > distance1 and c_r**2 > distance2:
            # 출발점과 도착점이 둘다 행성계 안에 있는 경우
            pass
        elif c_r**2 > distance1:
            # 출발점만 행성계 안에 있는 경우
            cnt += 1
        elif c_r**2 > distance2:
            # 도착점만 행성계 안에 있는 경우
            cnt += 1
            
    print(cnt)
        