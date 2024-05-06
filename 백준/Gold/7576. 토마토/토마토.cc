#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[1002][1002]; 
int vis[1002][1002]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
int cntTmp = 0;
int cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > Q;
    int n, m;
    bool isComplete = false;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({ i,j });
            if (board[i][j] == 0)
                vis[i][j] = -1;
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        //cout << cur.X <<"," <<cur.Y << "\n";
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny]>=0 || board[nx][ny] != 0) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = vis[cur.X][cur.Y] + 1; // (nx, ny)를 방문했다고 명시
            cntTmp = vis[nx][ny];
            if (cntTmp > cnt) cnt = cntTmp;
            Q.push({ nx,ny });
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;
}