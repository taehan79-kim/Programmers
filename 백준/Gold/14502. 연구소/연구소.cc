#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M;

int board[10][10];
int board1[10][10];
int arr[5];
int isused[66];
int zcnt = 0;
int tcnt = 0;
int bcnt = 0;
int deadarea = -1;
pair<int, int> zerop[66];
pair<int, int> twop[66];
queue<pair<int, int>> q;
int v[10][10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS(queue<pair<int,int>> q) {
    bcnt = 0;
    for (int i = 0; i < tcnt; i++) {
        auto zp = twop[i];
        v[zp.X][zp.Y] = 1;
        bcnt++;
        q.push(zp);
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board1[nx][ny] != 0 || v[nx][ny] > 0)continue;
            v[nx][ny] = 1;
            bcnt++;
            q.push({ nx,ny });
        }
    }
    return bcnt;
}

void func(int n) {
    if (n == 3) {
        /*for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        */
        

        for (int i = 0; i < n; i++) { // 3개 벽 세우기
            auto zp = zerop[arr[i]];
            board1[zp.X][zp.Y] = 1;
        }

        for (int i = 0; i < N; i++) { // 초기화
            for (int j = 0; j < M; j++) {
                v[i][j] = 0;
            }
        }
        // BFS
        int ttcnt = BFS(q);
        if (deadarea == -1 || deadarea > ttcnt) {
            deadarea = ttcnt;
        }
        for (int i = 0; i < n; i++) {
            auto zp = zerop[arr[i]];
            board1[zp.X][zp.Y] = 0;
        }
        return;
    }


    for (int i = 0; i < zcnt; i++) { // 모든 0 중에서 
        if (!isused[i]) {
            arr[n] = i;
            isused[i] = 1;
            func(n+1);
            isused[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            board1[i][j] = board[i][j];
            if (board[i][j] == 0) {
                zerop[zcnt] = { i,j };
                zcnt++;
            }
            if (board[i][j] == 2) {
                twop[tcnt] = { i, j };
                tcnt++;
            }
        }
    }
    
    func(0);

    cout << zcnt - deadarea - 3 + tcnt ;
}