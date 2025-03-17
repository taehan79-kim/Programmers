def solution(n, computers):
    answer = 0
    queue = []
    visited = [0 for _ in range(n)]
    print(visited)
    
    for i in range(n):
        if visited[i] == 0:
            queue.append(i)
            visited[i] = 1
            answer += 1
        while len(queue) > 0:
            cur = queue.pop()
            # print("cur: ", cur)
            for idx, com in enumerate(computers[cur]):
                
                if com == 0:
                    continue
                if visited[idx] == 1:
                    continue
                # print("idx: ", idx)
                queue.append(idx)
                visited[idx] = 1
        
    
    return answer