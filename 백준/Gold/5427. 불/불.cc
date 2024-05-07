#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[1005][1005];
int dis[1005][1005]; // 해당 칸을 방문했는지 여부를 저장
int dis1[1005][1005]; // 해당 칸을 방문했는지 여부를 저장
queue<pair<int, int> > Q;
queue<pair<int, int> > Q1;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { 1,-1 };
//int dz[6] = { 0,0,1,0,0,-1 };
int n, m;
int N = 0;
int cnt = 0;
bool isPossible = false;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N ;
    for (int a = 0; a < N;a++) {
        isPossible = false;
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                board[i][j] = s[j];
                dis[i][j] = -1;
                dis1[i][j] = -1;
                if (s[j] == '*') {
                    Q.push({ i,j });
                    dis[i][j] = 0;
                }
                else if (s[j] == '@') {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        cnt = 1;
                        isPossible = true;
                    }
                    else {
                        Q1.push({ i,j });
                        dis1[i][j] = 0;
                    }
                }
            }
        }
        
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            int curX, curY;
            tie(curX, curY) = cur;
            //cout << "cur:" << curX <<","<< curY  << "\n";
            for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                int nx, ny;
                nx = curX + dx[dir];
                ny = curY + dy[dir];
                //int nz = curZ + dz[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                if (dis[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문한 칸인 경우, 0인경우
                dis[nx][ny] = dis[curX][curY] + 1;
                Q.push({ nx,ny });
                //cout << "cNT:" << cnt << "\n";
            }
        }
        while (!Q1.empty()) {
            auto cur = Q1.front();
            Q1.pop();
            int curX, curY;
            tie(curX, curY) = cur;
            //cout << "cur1:" << curX <<","<< curY  << "\n";
            for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                int nx, ny;
                nx = curX + dx[dir];
                ny = curY + dy[dir];
                //int nz = curZ + dz[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                if (dis1[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문한 칸인 경우, 0인경우
                if (dis1[curX][curY] + 1 >= dis[nx][ny] && dis[nx][ny] != -1) continue; // 불이 더 먼저 온 경우
                if (nx == 0 || nx == n-1 || ny == 0 || ny == m-1) { // 탈출
                    cnt = dis1[curX][curY] + 2 ;
                    while (!Q1.empty()) Q1.pop();
                    isPossible = true;
                    break;
                }
                dis1[nx][ny] = dis1[curX][curY] + 1;
                Q1.push({ nx,ny });
                //cout << "cNT:" << cnt << "\n";
            }
        }
        if (!isPossible) {
            cout << "IMPOSSIBLE" << "\n";
        }
        else {
            cout << cnt << "\n";
            isPossible = false;
        }
    }
}