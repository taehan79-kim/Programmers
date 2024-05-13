#include <bits/stdc++.h>
using namespace std;

int N, K;
int board[21][21];
int board1[21][21][6];
int kkk[5];
int cnt = 0;


void move(int n, int dir) {
    if (dir == 0) { // 위
        for (int j = 0; j < N; j++) {
            int idx = -1;
            int cnttmp = 0;
            for (int k = 0; k < N; k++) {
                if (board1[k][j][n] == 0) { // 그 방향에 숫자가 없음
                    cnttmp++;
                }
                else { // 그 방향에 숫자가 있음
                    if (idx > -1) { // 그전 값이 있으면
                        if (board1[idx][j][n] == board1[k][j][n]) { // 전 값과 같으면 두배
                            board1[idx][j][n] = board1[idx][j][n] * 2;
                            board1[k][j][n] = 0;
                            idx = -1;
                            cnttmp++;
                        }
                        else { // 다르면 땡기고 전 값으로
                            idx = k - cnttmp;
                            if (cnttmp > 0) {
                                board1[k - cnttmp][j][n] = board1[k][j][n];
                                board1[k][j][n] = 0;
                            }
                        }
                    }
                    else { // 땡기기
                        idx = k - cnttmp;
                        if (cnttmp > 0) {
                            board1[k - cnttmp][j][n] = board1[k][j][n];
                            board1[k][j][n] = 0;
                        }
                    }
                }
            }
        }
    }
    if (dir == 1) { // 왼
        for (int j = 0; j < N; j++) {
            int idx = -1;
            int cnttmp = 0;
            for (int k = 0; k < N; k++) {
                if (board1[j][k][n] == 0) { // 그 방향에 숫자가 없음
                    cnttmp++;
                }
                else { // 그 방향에 숫자가 있음
                    if (idx > -1) { // 그전 값이 있으면
                        if (board1[j][idx][n] == board1[j][k][n]) { // 전 값과 같으면 두배
                            board1[j][idx][n] = board1[j][idx][n] * 2;
                            board1[j][k][n] = 0;
                            idx = -1;
                            cnttmp++;
                        }
                        else { // 다르면 땡기고 전 값으로
                            idx = k - cnttmp;
                            if (cnttmp > 0) {
                                board1[j][k - cnttmp][n] = board1[j][k][n];
                                board1[j][k][n] = 0;
                            }
                        }
                    }
                    else { // 땡기기
                        idx = k - cnttmp;
                        if (cnttmp > 0) {
                            board1[j][k - cnttmp][n] = board1[j][k][n];
                            board1[j][k][n] = 0;
                        }
                    }
                }
            }
        }
    }
    if (dir == 2) { // 아래
        for (int j = 0; j < N; j++) {
            int idx = -1;
            int cnttmp = 0;
            for (int k = N-1; k > -1; k--) {
                if (board1[k][j][n] == 0) { // 그 방향에 숫자가 없음
                    cnttmp++;
                }
                else { // 그 방향에 숫자가 있음
                    if (idx > -1) { // 그전 값이 있으면
                        if (board1[idx][j][n] == board1[k][j][n]) { // 전 값과 같으면 두배
                            board1[idx][j][n] = board1[idx][j][n] * 2;
                            board1[k][j][n] = 0;
                            idx = -1;
                            cnttmp++;
                        }
                        else { // 다르면 땡기고 전 값으로
                            idx = k + cnttmp;
                            if (cnttmp > 0) {
                                board1[k + cnttmp][j][n] = board1[k][j][n];
                                board1[k][j][n] = 0;
                            }
                        }
                    }
                    else { // 땡기기
                        idx = k + cnttmp;
                        if (cnttmp > 0) {
                            board1[k + cnttmp][j][n] = board1[k][j][n];
                            board1[k][j][n] = 0;
                        }
                    }
                }
            }
        }
    }
    if (dir == 3) { // 오른
        for (int j = 0; j < N; j++) {
            int idx = -1;
            int cnttmp = 0;
            for (int k = N - 1; k > -1; k--) {
                if (board1[j][k][n] == 0) { // 그 방향에 숫자가 없음
                    cnttmp++;
                }
                else { // 그 방향에 숫자가 있음
                    if (idx > -1) { // 그전 값이 있으면
                        if (board1[j][idx][n] == board1[j][k][n]) { // 전 값과 같으면 두배
                            board1[j][idx][n] = board1[j][idx][n] * 2;
                            board1[j][k][n] = 0;
                            idx = -1;
                            cnttmp++;
                        }
                        else { // 다르면 땡기고 전 값으로
                            idx = k + cnttmp;
                            if (cnttmp > 0) {
                                board1[j][k + cnttmp][n] = board1[j][k][n];
                                board1[j][k][n] = 0;
                            }
                        }
                    }
                    else { // 땡기기
                        idx = k + cnttmp;
                        if (cnttmp > 0) {
                            board1[j][k + cnttmp][n] = board1[j][k][n];
                            board1[j][k][n] = 0;
                        }
                    }
                }
            }
        }
    }
}


void func1(int n) { // 위왼아래오른 순서로 방향 순열 백트레킹 구현, n번째 이동
    if (n == 5) { // 이동을 5번 했으면 그 최대값을 리턴
        int mx=0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //cout << board1[i][j][n-1] << " ";
                if (board1[i][j][n-1] > mx) {
                    mx = board1[i][j][n-1];
                }
            }
            //cout << "\n";
        }
        if (cnt < mx) {
            cnt = mx;
        }
        return;
    }
    for (int i = 0; i < 4; i++) { // 방향 순으로 진행
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (n == 0) {
                    board1[x][y][n] = board[x][y];
                }
                else {
                    board1[x][y][n] = board1[x][y][n-1];
                }
            }
        }
        kkk[n] = i;
        move(n, i);
        func1(n + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    func1(0);
    cout << cnt;
}