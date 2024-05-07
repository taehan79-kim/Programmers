#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[102][102];
int dis[102][102]; // 해당 칸을 방문했는지 여부를 저장
int dis1[102][102];
queue<pair<int, int> > Q;
queue<pair<int, int> > Q1;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };
int cntTmp = 0;
int n, m;
int cntrgb = 0;
int cntrb = 0;
char cTmp;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m;
    n = m;
    int x, y;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[j][i] = s[j];
        }
    }
    string str = "RGB";
    for (auto c : str) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                //cout << "pos:" << board[i][j] <<","<< dis[i][j] << "\n";
                if (board[i][j] == c && dis[i][j] == 0) {
                    dis[i][j] = 1;
                    cntrgb++;
                    //cout << "pos:" << i << "," << j << "\n";
                    Q.push({ i,j });

                    while (!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        //cout << "cur:" << cur.X<<","<<cur.Y << "\n";
                        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                            if (dis[nx][ny] > 0 || board[nx][ny] != c) continue; // 이미 방문한 칸인 경우, 0인경우
                            dis[nx][ny] = 1;
                            Q.push({ nx,ny });
                        }

                    }
                    //cout << "cout" << c << ":" << cntrgb << "\n";
                }
            }
        }
    }
    str = "RGB";
    for (auto c : str) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << "pos:" << board[i][j] <<","<< dis[i][j] << "\n";
                if (board[i][j] == c && dis1[i][j] == 0) {
                    dis1[i][j] = 1;
                    cntrb++;
                    //cout << "pos:" << i << "," << j << "\n";
                    Q1.push({ i,j });

                    while (!Q1.empty()) {
                        auto cur = Q1.front();
                        Q1.pop();
                        //cout << "cur:" << cur.X<<","<<cur.Y << "\n";
                        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                            if (dis1[nx][ny] > 0 ) continue; // 이미 방문한 칸인 경우, 0인경우
                            if (c == 'R' && board[nx][ny] == 'B')continue;
                            if (c == 'G' && board[nx][ny] == 'B')continue;
                            if (c == 'B' && board[nx][ny] != 'B')continue;
                            dis1[nx][ny] = 1;
                            Q1.push({ nx,ny });
                        }

                    }
                    //cout << "cout" << c << ":" << cntrgb << "\n";
                }
            }
        }
    }
    cout << cntrgb << " " << cntrb << "\n";

}