#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
#define SIZE (5)

int N;
int board[5][5][5];
int board1[5][5][5]; // 층,세로,가로
int dis[5][5][5];
int board2[5][4][5][5]; // 각 방향에 대한 층 변환 (층,방향,i,j )
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };
queue<tuple<int, int, int>> q;

int isused[5];
int farr[5];
int flarr[120][5]; // {0, 1, 2, 4, 3 } 층조합 120개
int fcnt = 0;

int dismin = -1;
int rotarr[5]; // {0, 0,2,3,3} 층별 방향에대한 정보

int BFS() {
    q.push({ 0,0,0 });
    dis[0][0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        //cout << get<0>(cur) << ", " << get<1>(cur) << ", " << get<2>(cur) << "\n";
        q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || nz < 0 || nz >= SIZE)continue;
            if (board1[nx][ny][nz] != 1 || dis[nx][ny][nz] > 0)continue;
            dis[nx][ny][nz] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            if (nx == SIZE-1 && ny == SIZE-1 && nz == SIZE-1) {
                //cout << dis[nx][ny][nz] << "\n";
                while (!q.empty())q.pop();
                return dis[nx][ny][nz];
            }
            q.push({ nx,ny,nz });
        }
    }
    //cout << -1;
    return -1;
}


void copyMap(int src[SIZE][SIZE], int dest[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int k = 0; k < SIZE; k++)
            src[i][k] = dest[i][k];
}

void rotateClockwise90(int map[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    copyMap(temp, map);

    for (int i = 0; i < SIZE; i++)
        for (int k = 0; k < SIZE; k++)
            map[i][k] = temp[SIZE - 1 - k][i];
}

void rotateClockwise180(int map[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    copyMap(temp, map);

    for (int i = 0; i < SIZE; i++)
        for (int k = 0; k < SIZE; k++)
            map[i][k] = temp[SIZE - 1 - i][SIZE - 1 - k];
}

void rotateClockwise270(int map[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    copyMap(temp, map);

    for (int i = 0; i < SIZE; i++)
        for (int k = 0; k < SIZE; k++)
            map[i][k] = temp[k][SIZE - 1 - i];
}

void rotate(int board1[SIZE][SIZE], int board[SIZE][SIZE],int r) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board1[i][j] = board[i][j];
        }
    }
    if (r == 0) return;
    if (r == 1) rotateClockwise90(board1);
    if (r == 2) rotateClockwise180(board1);
    if (r == 3) rotateClockwise270(board1);
}
int ppp=0;
void backt(int n) {
    if (n == 5) {/*
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";*/
        for (int j = 0; j < 120; j++) {// flarr[j][i]의 층조합으로 쌓기
            if (board2[flarr[j][0]][rotarr[0]][0][0] == 0) continue;
             // arr[i]에 맞게 회전
            for (int i = 0; i < 5; i++) { // 각층에 회전조합에 맞게
                for (int x = 0; x < 5; x++) { // 세로
                    for (int y = 0; y < 5; y++) { // 가로
                        board1[i][x][y] = board2[flarr[j][i]][rotarr[i]][x][y];
                    }
                }
            }
            // 3D BFS
            for (int k = 0; k < 5; k++) {
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        dis[k][i][j] = -1;
                    }
                }
            }
            int tmpdis = BFS();
            if (tmpdis != -1) {
                if (dismin == -1 || dismin > tmpdis) {
                    dismin = tmpdis;
                }
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotarr[n] = i;
        backt(n + 1);
    }
}


void fbtra(int n) {
    if (n == 5) {
        for (int k = 0; k < 5; k++) {
            flarr[fcnt][k] = farr[k];
        }
        fcnt++;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            farr[n] = i;
            fbtra(n + 1);
            isused[i] = 0;
        }
    }
}

void boardset() {
    for (int i = 0; i < 5; i++) { // 층수
        for (int k = 0; k < 4; k++) { // 방향
            rotate(board2[i][k], board[i], k);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fbtra(0);
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[k][i][j];
                dis[k][i][j] = -1;
            }
        }
    }
    
    boardset();
    backt(0);
    //cout << "\n";
    cout << dismin;
}