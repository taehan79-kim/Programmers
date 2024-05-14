#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M;
char board[15][8];
int v[15][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q;
queue<pair<int, int>> d[5];

string rgb = "RGBPY";
int color;
int pcnt = 0;
int stacks = 0;
int nchk = 0;

int bfs(queue<pair<int, int>> q,int color) {
    int bcnt = 0;
    int bcntTmp = 0;
    queue<pair<int, int>> dt;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] == rgb[color] && v[i][j] == 0) {
                bcntTmp = 1;
                v[i][j] = 1;
                dt.push({ i,j });
                q.push({ i,j });
                //cout << i << "," << j << " value: " << bcntTmp << "\n";

                while (!q.empty()) {
                    auto c = q.front();
                    q.pop();
                    //cout << c.X << "," << c.Y << " value: " << board[c.X][c.Y] << "\n";
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = c.X + dx[dir];
                        int ny = c.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] != rgb[color]) continue;
                        if (v[nx][ny])continue;
                        bcntTmp++;
                        v[nx][ny] = 1;
                        dt.push({ nx,ny });
                        q.push({ nx,ny });
                    }
                }
                if (bcntTmp >= 4) {
                    bcnt = bcntTmp;
                    auto aaa = dt.front();
                    //cout << aaa.X << "," << aaa.Y << " value: " << bcntTmp << "\n";
                    while(!dt.empty()){
                        d[color].push(dt.front());
                        dt.pop();
                    }
                }
                else {
                    while (!dt.empty()) {
                        dt.pop();
                    }
                }
            }
        }
    }
    
    //cout <<"bcount: " << rgb[color] << bcnt << "\n";
    return bcnt;
}

void gravity() { // 
    for (int j = 0; j < M; j++) {
        int idx = -1;
        int cnttmp = 0;
        for (int k = N - 1; k > -1; k--) {
            if (board[k][j] == '.') { // 그 방향에 숫자가 없음
                cnttmp++;
            }
            else { // 그 방향에 숫자가 있음
                if (idx > -1) { // 그전 값이 있으면
                    idx = k + cnttmp;
                    if (cnttmp > 0) {
                        board[k + cnttmp][j] = board[k][j];
                        board[k][j] = '.';
                    }
                }
                else { // 땡기기
                    idx = k + cnttmp;
                    if (cnttmp > 0) {
                        board[k + cnttmp][j] = board[k][j];
                        board[k][j] = '.';
                    }
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    N = 12;
    M = 6;
    int k[5] = {0,0,0,0,0};
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[i][j] = str[j];
        }
    }
    nchk = 1;
    bool canpop = false;
    while (nchk>0) {
        nchk--;
        for (int i = 0; i < 5; i++) {
            int b = bfs(q, i);
            if (b >= 4)canpop = true;
        }
        if (canpop) {
            for (int k = 0; k < 5; k++) {
                while (!d[k].empty()) {
                    auto c = d[k].front();
                    board[c.first][c.second] = '.';
                    d[k].pop();
                }
            }
            stacks++;
            gravity();
            /*for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 6; j++) {
                    cout << board[i][j] << " ";
                }
                cout << "\n";
            }
            */
            canpop = false;
            nchk++;
        }

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                v[i][j] = 0;
            }
        }
    }

    cout << stacks;
}