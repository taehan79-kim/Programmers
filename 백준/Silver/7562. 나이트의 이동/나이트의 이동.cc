#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[302][302];
int dis[302][302]; // 해당 칸을 방문했는지 여부를 저장
queue<pair<int, int> > Q;
int dx[4] = { 2, 0, -2, 0 };
int dy[4] = { 0,2,0,-2 };
int dz[2] = { 1,-1 };
//int dz[6] = { 0,0,1,0,0,-1 };
int n, m;
int N = 0;
int cnt = 0;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N ;
    for (int a = 0; a < N;a++) {
        cin >> m;
        n = m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dis[i][j] = -1;
            }
        }

        int x, y;
        cin >> x >> y;
        Q.push({ x,y });
        dis[x][y] = 0;
        int x1, y1;
        cin >> x1 >> y1;
        if (x == x1 && y == y1)
        {
            cout << 0 << "\n";
            Q.pop();
        }
        board[x1][y1]= 1;
        
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            int curX, curY;
            tie(curX, curY) = cur;
            //cout << "cur:" << curX <<","<< curY  << "\n";
            for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                for (int dir1 = 0; dir1 < 2; dir1++) { // 대각선 2개 살펴보기
                    int nx, ny;
                    if (dx[dir] == 0) {
                        nx = curX + dx[dir] + dz[dir1];
                        ny = curY + dy[dir];
                    }
                    else {
                        nx = curX + dx[dir];
                        ny = curY + dy[dir] + dz[dir1];
                    }
                    //int nz = curZ + dz[dir];
                    if (nx < 0 || nx >= n || ny <0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                    if (dis[nx][ny] >= 0) continue; // 이미 방문한 칸인 경우, 0인경우
                    if (board[nx][ny] == 1)
                    {
                        cout << dis[curX][curY] + 1 << "\n";
                        int qs = Q.size();
                        while (!Q.empty())Q.pop();
                        dir = 4;
                        dir1 = 2;
                        break;
                    }
                    dis[nx][ny] = dis[curX][curY] + 1;
                    cnt = dis[nx][ny];
                    Q.push({ nx,ny });
                    //cout << "cNT:" << cnt << "\n";
                }
            }
        }
        board[x1][y1] = 0;
    }
}