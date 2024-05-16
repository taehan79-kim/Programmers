#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
#define SIZE (5)

int N,K;
int L;

int snake[100002][2];
int head = 1;
int tail;
int dr=1;

int board[102][102];
int appcnt;

int dx[4] = { 1,0,-1,0 }; // 남,동,북,서 증가하면 반시계, 감소하면 시계
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
bool isend = false;

int size() {
    return head - tail;
}

void pop() {
    tail++;
}

void push(int x, int y) {
    snake[head][0] = x;
    snake[head][1] = y;
    head++;
}

pair<int,int> front() {
    int a = snake[head-1][0];
    int b = snake[head-1][1];
    return { a, b };
}

bool move(int dr) {
    auto cur = front();
    int nx = cur.X + dx[dr];
    int ny = cur.Y + dy[dr];
    //cout << "move : " << nx << ", " << ny << "\n";
    //cout << "tail : " << snake[tail][0] << ", " << snake[tail][1] << "\n";
    int sz = size();
    if (nx < 0 || nx >= N || ny < 0 || ny >= N)return true; // 벽에 닿으면 끝
    for (int i = tail+1; i < head;i++) {
        if (snake[i][0] == nx && snake[i][1] == ny) {
            //cout << i <<" 꼬리에 닿음" << snake[i][0]<<", " << snake[i][1] << "\n";
            return true; // 꼬리에 닿으면 끝
        }
    }
    if (board[nx][ny] == 0) { // 빈공간
        push(nx, ny);
        pop();
    }
    else if (board[nx][ny] == 1) { // 사과
        board[nx][ny] = 0;
        push(nx, ny);
        //cout << "사과먹음!" << "\n";
    }
    
    return false;
}

int mvt[10002];
char dir[10002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> curpos;

    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 1;
    }
    cin >> L;
    push(0, 0);
    dr = 1;
    for (int i = 0; i < L; i++) {
        cin >> mvt[i] >> dir[i];
    }
    for (int i = 0; i < L; i++) {
        isend = false;
        //cout << i << "---------------------------------\n";
        while (!isend || i==L-1) {
            cnt++;
            //cout << "dr" << dr << ", cnt : " << cnt << "\n";
            
            bool dontkeepmove = move(dr);
            if (dontkeepmove) {
                cout << cnt;
                return 0;
            }
            if (cnt == mvt[i]) {
                if (dir[i] == 'L') {
                    dr++;
                    if (dr > 3)dr -= 4;
                }
                if (dir[i] == 'D') {
                    dr--;
                    if (dr < 0)dr += 4;
                }
                isend = true;
            }
            //cout << "end? :" << isend << "\n";
        }
    }
    //cout << cnt;
}
