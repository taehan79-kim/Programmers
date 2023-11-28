def dfs(sheep, wolf, edges): # DFS 완전 노드 탐색
    if sheep > wolf:
        a.append(sheep)
    else:
        return 
        
    for p, c in edges: # 현재까지 진행 노드에서 완전 탐색
        if visited[p] and not visited[c]: 
            visited[c] = 1
            if _info[c] == 0:
                dfs(sheep+1, wolf, edges)
            else:
                dfs(sheep, wolf+1, edges)
            visited[c] = 0

def solution(info, edges):
    global visited
    visited = [0] * len(info)
    global _info
    global a
    answer = []
    a =[]
    
    _info = info
        
	# 루트 노드부터 시작
    visited[0] =1
    dfs(1,0, edges)
    print(a)
    return max(a)