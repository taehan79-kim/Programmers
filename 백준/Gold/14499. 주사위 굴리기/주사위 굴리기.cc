#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M,x,y,K;
int mv;
int dice[6] = { 1,2,3,5,4,6 }; //현재 위, 남, 서, 북, 동, 아래 순
int dicetmp[6]; 
int dv[7];
int board[22][22];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int k = 0; k < K; k++) {
        cin >> mv;
        if (mv == 1) { // 동
            int nx = x;
            int ny = y + 1;
            if (ny >= M)continue;
            dicetmp[0] = dice[4];
            dicetmp[1] = dice[1];
            dicetmp[2] = dice[0];
            dicetmp[3] = dice[3];
            dicetmp[4] = dice[5];
            dicetmp[5] = dice[2];
            cout << dv[dicetmp[0]]<< "\n";

            if (board[nx][ny] == 0) {
                board[nx][ny] = dv[dicetmp[5]];
            }
            else {
                dv[dicetmp[5]] = board[nx][ny];
                board[nx][ny] = 0;
            }

            for (int i = 0; i < 6; i++) {
                dice[i] = dicetmp[i];
            }
            x = nx;
            y = ny;
        }
        if (mv == 2) { // 서
            int nx = x;
            int ny = y - 1;
            if (ny < 0 )continue;
            dicetmp[0] = dice[2];
            dicetmp[1] = dice[1];
            dicetmp[2] = dice[5];
            dicetmp[3] = dice[3];
            dicetmp[4] = dice[0];
            dicetmp[5] = dice[4];
            cout << dv[dicetmp[0]] << "\n";

            if (board[nx][ny] == 0) {
                board[nx][ny] = dv[dicetmp[5]];
            }
            else {
                dv[dicetmp[5]] = board[nx][ny];
                board[nx][ny] = 0;
            }

            for (int i = 0; i < 6; i++) {
                dice[i] = dicetmp[i];
            }

            x = nx;
            y = ny;
        }
        if (mv == 3) { // 북
            int nx = x -1;
            int ny = y;
            if (nx < 0)continue;
            dicetmp[0] = dice[3];
            dicetmp[1] = dice[0];
            dicetmp[2] = dice[2];
            dicetmp[3] = dice[5];
            dicetmp[4] = dice[4];
            dicetmp[5] = dice[1];
            cout << dv[dicetmp[0]] << "\n";

            if (board[nx][ny] == 0) {
                board[nx][ny] = dv[dicetmp[5]];
            }
            else {
                dv[dicetmp[5]] = board[nx][ny];
                board[nx][ny] = 0;
            }

            for (int i = 0; i < 6; i++) {
                dice[i] = dicetmp[i];
            }
            x = nx;
            y = ny;
        }
        if (mv == 4) { // 남
            int nx = x + 1;
            int ny = y;
            if (nx >= N)continue;
            dicetmp[0] = dice[1];
            dicetmp[1] = dice[5];
            dicetmp[2] = dice[2];
            dicetmp[3] = dice[0];
            dicetmp[4] = dice[4];
            dicetmp[5] = dice[3];
            cout << dv[dicetmp[0]] << "\n";

            if (board[nx][ny] == 0) {
                board[nx][ny] = dv[dicetmp[5]];
            }
            else {
                dv[dicetmp[5]] = board[nx][ny];
                board[nx][ny] = 0;
            }

            for (int i = 0; i < 6; i++) {
                dice[i] = dicetmp[i];
            }
            x = nx;
            y = ny;
        }
    }
}