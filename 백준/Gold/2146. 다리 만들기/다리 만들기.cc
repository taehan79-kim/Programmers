#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[105][105];
int dis[105][105]; // 해당 칸을 방문했는지 여부를 저장
int dis1[105][105]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int,int> island[10005];
int disi[10005];

int n, m, cnt, dist;

void BFS(queue<pair<int, int>>& Q) {
    while (!Q.empty()) {
        auto cur = Q.front();
        if (island[cnt].X < 0 && island[cnt].Y < 0) {
            island[cnt] = { cur.X, cur.Y };
        }
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
                //board[cur.X][cur.Y]--;
                continue;
            }
            dis[nx][ny] = 1;
            board[nx][ny] = cnt;
            
            Q.push({ nx,ny });
        }
    }
}

int BuildBFS(deque<pair<int, int>>& DQ, int a) {
    while (!DQ.empty()) {
        auto cur = DQ.front();
        DQ.pop_front();
        //cout << "cur: " << cur.X << "," << cur.Y << "\n";
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (dis1[nx][ny] > 0) continue; // 이미 방문한 칸인 경우
            //cout << "next: " << nx << "," << ny << "\n";
            //cout << "board: " << board[nx][ny] << "\n";
            //cout << "dis1: " << dis1[nx][ny] << "\n";
            if (board[nx][ny] > 0 && board[nx][ny] != a) { // 다른 섬인 경우
                while (!DQ.empty())DQ.pop_front();
                return dis1[cur.X][cur.Y]-1;
            }
            if (board[nx][ny] > 0 && board[nx][ny] == a) { // 자기 섬인 경우
                dis1[nx][ny] = dis1[cur.X][cur.Y];
                DQ.push_front({ nx,ny });
            }
            if (board[nx][ny] < 1) { // 물인 경우
                dis1[nx][ny] = dis1[cur.X][cur.Y]+1;
                DQ.push_back({ nx,ny });
            }
            
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    deque<pair<int, int>> DQ;
    cin >> n;
    m = n;
    dist = 300;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            board[i][j] = k;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0 && dis[i][j] == 0) {
                cnt++;
                island[cnt] = { -1,-1 };
                //cout << "--------cnt: " << cnt << "\n";
                dis[i][j] = 1;
                board[i][j] = cnt;
                Q.push({ i,j });
                BFS(Q);
                //cout << "--------board: " << board[i][j] << "\n";
                //cout << "대표위치: " << island[cnt].X << island[cnt].Y<< "\n";
            }
        }
    }
    //cout << "---4,1 값: " << board[4][1] << "\n";
    for (int a = 1; a <= cnt; a++) {
        //cout << "--------cnt: " << a << "\n";
        auto c = island[a];
        //cout << "--처음 값: " << c.X << c.Y << "\n";
        DQ.push_back(c);
        dis1[c.X][c.Y] = 1;
        int disTmp;
        disTmp = BuildBFS(DQ, a);
        //cout << "가장짧은 거리: " << disTmp << "\n";
        if (dist > disTmp) {
            dist = disTmp;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis1[i][j] = 0;
            }
        }

    }

    cout << dist << "\n";
}