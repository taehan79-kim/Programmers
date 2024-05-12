#include <bits/stdc++.h>
using namespace std;

int N, M;
int C = 0;
int board[8][8];
int v[8][8];
tuple<int, int, int> campos[8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
int zerocnt=0;
int camState[8];

int checkf(int dir, int cammodel) { // 앞
    int camcnt = 0;
    pair<int, int> cur = { get<0>(campos[cammodel]), get<1>(campos[cammodel]) };
    int mx = N;
    if (dx[dir] == 0)mx = M;
    //cout << "mx : " << mx <<"\n";
    for (int k = 1; k < mx; k++) {
        int nx = cur.first + dx[dir] * k;
        int ny = cur.second + dy[dir] * k;
        //cout << "pos : " << nx <<", "<< ny << "\n";
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            k = mx;
            continue;
        }
        if (board[nx][ny] == 6) {
            k = mx;
            continue;
        }
        if (board[nx][ny] == 0 && !v[nx][ny]) {
            camcnt++;
            v[nx][ny] = 1;
        }
    }
    return camcnt;
}


int func(int cs[]) { // 카메라의 모든방향 체크
    int camcnt = 0;
    for (int i = 0; i < 8; i++) { // 방문여부 초기화
        for (int j = 0; j < 8; j++) {
            v[i][j] = 0;
        }
    }

    for (int i = 0; i < C; i++) { // 모든 카메라에 대해
        int dir = camState[i];
        pair<int, int> cur = { get<0>(campos[i]), get<1>(campos[i]) };
        int camnum = get<2>(campos[i]);

        if (camnum == 1) { // 한 방향
            camcnt += checkf(dir, i);
            //cout <<"camcnt : "<< camcnt << "\n";
        }
        else if (camnum == 2) { // 앞뒤 방향
            camcnt += checkf(dir, i);
            dir = dir + 2;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
        }
        else if (camnum == 3) {
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
        }
        else if (camnum == 4) {
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
        }
        else if (camnum == 5) {
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
            dir = dir + 1;
            if (dir > 3) {
                dir = dir - 4;
            }
            camcnt += checkf(dir, i);
            
        }
    }
    return camcnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6) { // 카메라
                campos[C] = { i,j, board[i][j] };
                C++;
            }
            if (board[i][j] == 0)zerocnt++;
        }
    }
    for (int i = 0; i < pow(4,C); i++) {
        //cout <<"-------------------i:" << i<<"\n";
        for (int j = 0; j < C; j++) {
            int k = j;
            int tmp = i;
            while (k) {
                tmp = tmp / 4;
                k--;
            }
            
            camState[j] = tmp % 4;
            //cout << "cam"<<j<< ", [" << get<2>(campos[j]) << "]: " << camState[j] << "\n";
        }

        int TmpCnt = func(camState);
        if (cnt == 0 || cnt < TmpCnt)cnt = TmpCnt;
        //cout <<"zero - TmpCnt:" << zerocnt - TmpCnt<< "\n";
    }
    
    //func(0, 0);
    cout << zerocnt - cnt;
}