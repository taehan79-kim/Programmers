#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
#define SIZE (5)

int N,M;
int r, c;
int d; // 0북,1동,2남.3서
int dr;
int dir[4] = { 0,3,2,1 }; // dir[i]로 사용 i 가 증가하면 반시계방향 회전
int t = 0;
int board[52][52]; // 0 청소해야됨, 1: 벽, 
int dis[52][52];
int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
int cnt = 1;
bool isend = false;

pair<int,int> checkdir(int r, int c) {
    for (int i = 1; i <= 4; i++) {
        int temd = dr + i;
        if (temd > 3)temd -= 4;
        int nx = r + dx[dir[temd]];
        int ny = c + dy[dir[temd]];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
        if (board[nx][ny] != 0 || dis[nx][ny] > 0)continue;
        dis[nx][ny] = 1;
        cnt++;
        dr = temd;
        return { nx, ny };
    }
    return { 52,52 };
}

bool goback() {
    int i = dr + 2;
    if (i > 3)i -= 4;
    int tmpr = r + dx[dir[i]];
    int tmpc = c + dy[dir[i]];
    if (board[tmpr][tmpc] == 1)return false;
    else {
        r = tmpr;
        c = tmpc;
        return true;
    }
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> curpos;

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    if (d == 0)dr = 0;
    if (d == 1)dr = 3;
    if (d == 2)dr = 2;
    if (d == 3)dr = 1;
    dis[r][c] = 1;
    while (!isend) {
        //cout << "pos : " << r <<", "<< c<<"\n";
        curpos = checkdir(r, c);
        if (curpos.X == 52 && curpos.Y == 52) { // 4 방향모두 청소가 되어 있으면 
            if (!goback()) isend = true;
        }
        else {
            r = curpos.X;
            c = curpos.Y;
        }
    }
    //cout << "\n";
    cout << cnt;
}