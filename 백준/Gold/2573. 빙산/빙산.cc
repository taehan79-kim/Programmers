#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[305][305];
int dis[305][305]; // 해당 칸을 방문했는지 여부를 저장
int dis1[100005]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m, cnt, year;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    queue<pair<int, int>> Q1;
    bool isFirst = true;
    bool isIce = true;

    
    cin >> n >> m;
    cnt = 1;
    year = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            board[i][j] = k;
            if (isFirst && k > 0) {
                Q.push({ i,j });
                dis[i][j] = 1;
                isFirst = false;
            }
            Q1.push({ i,j });
        }
    }
    while (!Q.empty()) {
        auto c = Q.front();
        dis[c.X][c.Y] = 1;
        year++;
        isFirst = true;
        //cout << "-------year: " << year << "\n";
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            //cout << "cur: " << cur.X << "," << cur.Y << "\n";
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                if (dis[nx][ny] > 0) continue; // 이미 방문한 칸인 경우
                //cout << "next: " << nx << "," << ny << "\n";
                //cout << "board: " << board[nx][ny] << "\n";
                if (board[nx][ny] < 1) { // 물인 경우
                    board[cur.X][cur.Y]--;
                    continue;
                }
                dis[nx][ny] = 1;
                Q.push({ nx,ny });
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0) { 
                    if (dis[i][j] <= 0) {// 방문안한 빙산이 있는 경우
                        //cout << "pos:" << i << ", " << j<<"\n";
                        cout << year-1 << "\n";
                        return 0;
                    }
                    if (isFirst) {
                        Q.push({ i,j });
                        dis[i][j] = 1;
                        isFirst = false;
                    }
                }
                dis[i][j] = 0;
            }
        }
    }
    cout << 0 << "\n";
    //cout << cnt << "\n";
}