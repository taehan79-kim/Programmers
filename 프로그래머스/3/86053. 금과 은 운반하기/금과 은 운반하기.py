import math

def solution(a, b, g, s, w, t):
    answer = 4*10**14
    start = 0
    end = 4*10**14
    while end>=start:
        mid = (end + start)//2 
        gold = 0 
        silver = 0 
        add = 0 
        for i in range(len(t)):
            now_g = g[i]
            now_s = s[i]
            now_w = w[i]
            now_t = t[i]
            mw = math.floor((mid+now_t)/(2*now_t))*now_w
            gold += min(now_g, mw) 
            silver += min(now_s, mw)
            add += min(now_g+now_s, mw)
        if gold >= a and silver >= b and add >=a+b: 
            end = mid - 1
            answer = min(mid, answer)
        else: 
            start = mid + 1
    return answer