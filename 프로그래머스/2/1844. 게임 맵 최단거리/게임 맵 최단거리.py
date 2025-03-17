from collections import deque

def solution(maps):
    answer = -1
    n = len(maps)
    m = len(maps[0])
    distance = [[-1 for i in range(m)] for j in range(n)]
    dx = [1, -1, 0, 0]
    dy = [0, 0, +1, -1]
    
    # DFS
    queue = deque([(0, 0)])
    distance[0][0] = 1
    while len(queue)>0:
        cur_x, cur_y = queue.popleft()
        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]
            if nx >= n or nx < 0 or ny >= m or ny < 0:
                continue
            if maps[nx][ny] == 0:
                continue
            if distance[nx][ny] > -1:
                continue
            queue.append([nx, ny])
            distance[nx][ny] = distance[cur_x][cur_y] + 1
            if nx == n-1 and ny == m-1:
                answer = distance[cur_x][cur_y] + 1
                return answer
    return answer