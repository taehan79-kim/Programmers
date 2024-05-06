#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[1002][1002]; 
int fvis[1002][1002]; // 해당 칸을 방문했는지 여부를 저장
int hvis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
int cntTmp = 0;
int cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > Q;
    queue<pair<int, int> > R;
    int n, m;
    bool isComplete = false;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j];
            if (board[i][j] == 'F') {
                Q.push({ i,j });
                hvis[i][j] = -1;
            }
            else if (board[i][j] == 'J') {
                if (i == n - 1 || j == m - 1 || i == 0 || j == 0) {
                    cout << 1;
                    return 0;
                }
                R.push({ i,j });
                fvis[i][j] = -1;
            }
            else {
                hvis[i][j] = -1;
                fvis[i][j] = -1;
            }
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
            if (fvis[nx][ny]>=0 || board[nx][ny] == '#') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            if (fvis[nx][ny] == -1 || fvis[nx][ny] > fvis[cur.X][cur.Y] + 1) {
                fvis[nx][ny] = fvis[cur.X][cur.Y] + 1; // (nx, ny)를 방문했다고 명시
            }
            Q.push({ nx,ny });
        }
    }
    while (!R.empty()) {
        pair<int, int> cur = R.front();
        R.pop();
        //cout << cur.X <<"," <<cur.Y << "\n";
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (hvis[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            if (fvis[nx][ny] > -1 && hvis[cur.X][cur.Y] + 1 >= fvis[nx][ny])continue; // 불이 도착하면서 불보다 늦은 경우
            hvis[nx][ny] = hvis[cur.X][cur.Y] + 1; // (nx, ny)를 방문했다고 명시
            if (nx == n - 1 || ny == m - 1 || nx == 0 || ny == 0) {
                cout << hvis[nx][ny]+1;
                return 0;
            }
            R.push({ nx,ny });
        }
    }

    cout << "IMPOSSIBLE";
}