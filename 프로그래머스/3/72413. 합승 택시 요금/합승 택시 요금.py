import heapq

def solution(n, s, a, b, fares):
    answer = 0
    global vertex
    global graph
    vertex = n
    start = a
    graph = [[] for _ in range(0, vertex+1)]
    fares.sort(key = lambda x:x[0])
    for i in fares:
        src, dst, weight = i
        graph[src].append([dst, weight])
        graph[dst].append([src, weight])
        # print(graph)

    a_weights = dijkstra(a)
    b_weights = dijkstra(b)
    s_weights = dijkstra(s)
    print (a_weights) # [inf, 0, 3, 5, 6, 8]
    print (b_weights)
    print (s_weights)
    sum = float('inf')
    for i in range(len(a_weights)):
        sumTem = a_weights[i]+b_weights[i] + s_weights[i]
        if sum > sumTem:
            sum = sumTem
    answer = sum
    return answer

def dijkstra(start):
    heap = []
    heapq.heappush(heap, [0, start]) # 최소힙은 배열의 첫 번째 값을 기준으로 배열을 정렬.
    INF = float('inf')
    weights = [INF] * (vertex+1) # DP에 활용할 memoization 테이블 생성
    weights[start] = 0 # 자기 자신으로 가는 사이클은 없으므로.
    
    while heap:
        weight, node = heapq.heappop(heap)
        if weight > weights[node]: # 비용 최적화 전부터 큰 비용일 경우 고려할 필요 없음.
            continue
        
        for n, w in graph[node]: # 최소 비용을 가진 노드를 그리디하게 방문한 경우 연결된 간선 모두 확인
            W = weight + w
            if weights[n] > W: # 여러 경로를 방문해 합쳐진 가중치 W가 더 비용이 적다면 
                weights[n] = W # 업데이트
                heapq.heappush(heap, (W, n)) # 최소 비용을 가진 노드와 합쳐진 가중치 추가

    return weights