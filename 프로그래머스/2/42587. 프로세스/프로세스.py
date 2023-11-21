import sys
from collections import deque


def solution(priorities, location):
    answer = 0
    Q = deque()
    prior = deque()
    
    for i in range(len(priorities)):
        Q.append((i,priorities[i]))
    priorities.sort(reverse = True)
    for i in priorities:
        prior.append(i)
        
    cnt = 0
    while Q:
        loc, pri = Q.popleft()
        # print(loc, pri)
        for p in prior: 
            # print(p)
            if pri >= p: # 우선순위가 제일 높으면
                prior.popleft() # 우선순위 삭제하고 다음 큐 진행
                cnt+=1
                
                if loc == location:
                    return cnt
                break
            elif pri < p: # 우선순위가 더 높은게 있으면
                Q.append((loc, pri)) # 큐에 다시 넣기
                break
                
    
    # Q.append((idx,pri))
    # Q.popleft()
    return answer