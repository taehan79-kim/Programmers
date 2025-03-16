from queue import PriorityQueue
import sys 

input = sys.stdin.readline

N, M, X = map(int, input().rstrip().rsplit(' '))

i_graph = [[] for i  in range(N+1)]
o_graph = [[] for i  in range(N+1)]

INF = int(1e9)
i_d = [INF for i in range(N+1)]
o_d = [INF for i in range(N+1)]

for i in range(M):
    a, b, t = map(int, input().rstrip().rsplit(' '))
    i_graph[a].append([b, t])
    o_graph[b].append([a, t])


pq = PriorityQueue()

i_d[X] = 0
pq.put([0, X])
while pq.qsize():
    cur = pq.get()
    if i_d[cur[1]] != cur[0]:
        continue
    for nxt_idx, nxt_dist in i_graph[cur[1]]:
        if i_d[nxt_idx] <= cur[0] + nxt_dist:
            continue
        i_d[nxt_idx] = cur[0] + nxt_dist
        pq.put([i_d[nxt_idx], nxt_idx])

o_d[X] = 0
pq.put([0, X])

while pq.qsize():
    cur_dist, cur_idx = pq.get()
    if o_d[cur_idx] != cur_dist:
        continue
    for nxt_idx, nxt_dist in o_graph[cur_idx]:
        if o_d[nxt_idx] <= cur_dist + nxt_dist:
            continue
        o_d[nxt_idx] = cur_dist + nxt_dist
        pq.put([o_d[nxt_idx], nxt_idx])

max_dist = 0
for i in range(1, N+1):
    if max_dist < i_d[i] + o_d[i]:
        max_dist = i_d[i] + o_d[i]

print(max_dist)