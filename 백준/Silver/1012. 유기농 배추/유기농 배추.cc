#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[52][52];
int dis[52][52]; // 해당 칸을 방문했는지 여부를 저장

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };
int cntTmp = 0;
int N, n, m, k;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N;
    for (int a = 0; a < N; a++) {
        queue<pair<int, int> > Q;

        
        int cnt = 0;
        cin >> m >> n >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> y >> x;
            board[x][y] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << "pos:" << board[i][j] <<","<< dis[i][j] << "\n";
                if (board[i][j] == 1 && dis[i][j] == 0) {
                    dis[i][j] = 1;
                    cnt++;
                    //cout << "pos:" <<i << "," << j << "\n";
                    Q.push({ i,j });

                    while (!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        //cout << "cur:" << cur.X<<","<<cur.Y << "\n";
                        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                            if (dis[nx][ny] > 0 || board[nx][ny] == 0) continue; // 이미 방문한 칸인 경우, 0인경우
                            //board[nx][ny] = 0;
                            dis[nx][ny] = 1;
                            Q.push({ nx,ny });
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = 0;
                dis[i][j] = 0;
            }
        }
    }
}