from itertools import combinations
def solution(number):
    cnt = 0
    for i in combinations(number, 3):
        if sum(i) == 0:
            #print(i, end=" ")
            cnt+=1
    answer = cnt
    return answer