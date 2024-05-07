#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[102][102][102];
int dis[102][102][102]; // 해당 칸을 방문했는지 여부를 저장
queue<tuple<int, int, int> > Q;
int dx[6] = { 1, 0,0, -1, 0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };
int cntTmp = 0;
int n, m, h;
int cnt = 0;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m >> n >>h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dis[i][j][k] = -1;
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    Q.push({ i,j,k });
                    dis[i][j][k] = 0;
                }
            }
        }
    
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        //cout << "cur:" << curX <<","<< curY << ","<< curZ << "\n";
        for (int dir = 0; dir < 6; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue; // 범위 밖일 경우 넘어감
            if (dis[nx][ny][nz] >= 0 || board[nx][ny][nz] != 0) continue; // 이미 방문한 칸인 경우, 0인경우
            dis[nx][ny][nz] = dis[curX][curY][curZ]+1;

            cnt = dis[nx][ny][nz];
            //cout << "cNT:" << cnt << "\n";
            Q.push({ nx,ny,nz });
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (dis[i][j][k] < 0 && board[i][j][k] >= 0) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << cnt << "\n";

}