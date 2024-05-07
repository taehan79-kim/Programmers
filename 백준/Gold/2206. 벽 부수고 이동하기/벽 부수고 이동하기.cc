#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[1005][1005];
int dis[1005][1005]; // 해당 칸을 방문했는지 여부를 저장
int dis1[1005][1005]; // 해당 칸을 방문했는지 여부를 저장
int power[1005][1005];
queue<pair<int, int> > Q;
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
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
            dis[i][j] = -1;
            dis1[i][j] = -1;
        }
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    Q.push({ 0,0 });
    dis[0][0] = 0;
    power[0][0] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curP;
        tie(curX, curY) = cur;
        curP = power[curX][curY];
        //cout << "cur:" << curX <<","<< curY  << "\n";
        //cout << "cNT:" << cnt << "\n";
        //cout << "power:" << power[curX][curY] << "\n";
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx, ny;
            nx = curX + dx[dir];
            ny = curY + dy[dir];
            //int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (dis[nx][ny] >= 0 && curP == 0) continue; // 이미 방문한 칸인 경우 + 이미 벽을 부순 경우
            if (board[nx][ny] != '0' && curP == 0) continue;
            if (board[nx][ny] != '0' && curP > 0) power[nx][ny] = 0;
            else power[nx][ny] = curP;
            //cout << "bb:::" << dis[nx][ny] << "," << curP << "\n";
            if (dis[nx][ny] >= 0 && curP == 1) { // 이미 방문한 칸인 경우 + 아직 벽을 안부순 경우
                if(dis1[nx][ny] >=0) continue; // 이미 방문
                dis1[nx][ny] = dis[curX][curY] + 1;
                //cout << "bb:" << nx << "," << ny << "\n";
                Q.push({ nx,ny });
            }
            if (nx == n - 1 && ny == m - 1 ) {
                cout << dis[curX][curY] + 2;
                return 0;
            }
            dis[nx][ny] = dis[curX][curY] + 1;
            cnt = dis[curX][curY] + 1;
            Q.push({ nx,ny });
        }
    }
    cout << -1;
}
