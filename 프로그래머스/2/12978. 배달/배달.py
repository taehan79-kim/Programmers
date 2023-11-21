from collections import deque

def greedy(graph, root): # 노드형 그리디
    m = len(graph)   # 전체 노드 갯수
    dist = [float('inf') for _ in range(m)] # 각 노드까지 걸리는 거리
    
    Q = deque()
    Q.append(root) # 시작 노드 추가
    dist[root] = 0
    while Q:
        node = Q.popleft() # 가까운 노드부터 탐색
        for n, d in graph[node]: # 노드로부터 출발하는 모든 경로 탐색
            if dist[n] > dist[node] + d: # 이번에 온게 더 적은 시간이면
                dist[n] = dist[node] + d # 거리 저장
                Q.append(n)
    return dist

def solution(N, road, K):
    answer = 0
    graph = [[] for _ in range(0, N+1)]
    road.sort(key = lambda x:x[0])
    for i in road:
        src, dec, dst = i
        graph[src].append([dec, dst])
        graph[dec].append([src, dst])
        
    dist = greedy(graph, 1)
    for i in dist:
        if i <= K :
            answer += 1
    # print(graph)
    # print(graph[1])


    return answer