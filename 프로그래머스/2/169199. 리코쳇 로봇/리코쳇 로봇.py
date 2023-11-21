import sys
from collections import deque

def BFS(board, root):
    dx=[1,0,-1,0]
    dy=[0,1,0,-1]
    n = len(board)
    m =len(board[0])
    visited = [[0 for _ in range(m)] for _ in range(n)]
    dist = [[0 for _ in range(m)] for _ in range(n)]
    rooty,rootx = root
    
    Q =deque()
    Q.append((rooty,rootx))
    visited[rooty][rootx] = 1
    
    while Q:
        y,x = Q.popleft()
        for k in range(4):
            for i in range(1, 100):
                nx = x+dx[k]*i
                ny = y+dy[k]*i
                if ny < 0 or ny >= n or nx <0 or nx >= m: # 벗어나면
                    if visited[ny-dy[k]][nx-dx[k]]!=0: # 그 전꺼 방문했는지 확인
                        break # 방문했으면 다음 방향으로
                    visited[ny-dy[k]][nx-dx[k]] = 1 # 방문표시
                    dist[ny-dy[k]][nx-dx[k]] = dist[y][x] + 1 # 걸린 최소 시간 표시
                    if board[ny-dy[k]][nx-dx[k]] == "G": # 도착점인지 확인
                        # print(dist)
                        return dist[ny-dy[k]][nx-dx[k]] # 도착점이면 최소 시간 리턴하고 함수 종료
                    
                    Q.append((ny-dy[k],nx-dx[k])) # 도착점이 아니면 큐에 추가
                    break # 방문처리했으면 다음 방향으로
                
                if board[ny][nx] == "D": # 벽을 만나면
                    if visited[ny-dy[k]][nx-dx[k]]!=0: # 그전꺼 방문했는지 확인
                        break # 방문했으면 다음 방향으로
                        
                    visited[ny-dy[k]][nx-dx[k]] = 1 # 방문표시
                    dist[ny-dy[k]][nx-dx[k]] = dist[y][x] +1
                    
                    if board[ny-dy[k]][nx-dx[k]] == "G":
                        # print(dist)
                        return dist[ny-dy[k]][nx-dx[k]]
                    
                    Q.append((ny-dy[k],nx-dx[k])) # 도착점이 아니면 큐에 추가
                    break
    
    return -1
              
def solution(board):
    answer = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "R":
                root = [i,j]
    answer = BFS(board, root)
    return answer