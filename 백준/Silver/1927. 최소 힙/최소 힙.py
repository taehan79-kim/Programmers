import sys
input = sys.stdin.readline

import heapq

n = int(input())
l = []
for _ in range(n):
    num = int(input())
    if num == 0:
        if len(l) > 0:
            print(heapq.heappop(l))
        else:
            print(0)
    else:
        heapq.heappush(l, num)