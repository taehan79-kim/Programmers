#include <bits/stdc++.h>
using namespace std;

#define X first;
#define Y second;

int arr[27];
int isused[5][5];
char board[5][5];
int v[5][5];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int scnt = 0;
int ans = 0;

bool check(int k) {
    int cntbfs = 0;
    queue<pair<int, int>> q;
    v[k / 5][k % 5] = 1;
    q.push({k/5, k%5});
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        //cout << "cur : " << c.first << ", " << c.second << "\n";
        for (int dir = 0; dir < 4; dir++) {
            int nx = c.first + dx[dir];
            int ny = c.second + dy[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)continue;
            if (v[nx][ny] > 0 || isused[nx][ny] == 0)continue;
            v[nx][ny] = 1;
            cntbfs++;
            q.push({ nx,ny });
        }
    }
    //cout <<"cntbfs:" << cntbfs << "\n";
    if (cntbfs == 6) {
        //cout << "cntbfs:" << cntbfs << "\n";
        return true;
    }
    else return false;
}

void func(int n) {
    if (n == 7) {
        if (scnt >= 4) { // 4명이상인지 확인
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    v[i][j] = 0;
                }
            }
            if (check(arr[0])) { // BFS로 인접한지 확인
                ans++;
            }
        }
        return;
    }
    int st = 0;
    if (n > 0)st = arr[n - 1];
    for (int i = st; i < 25; i++) {
        if (!isused[i / 5][i % 5]) {
            isused[i / 5][i % 5] = 1;
            if (board[i / 5][i % 5] == 'S')scnt++;
            arr[n] = i;
            //cout << n << "n자리 " << i << " 추가";
            func(n + 1);
            if (board[i / 5][i % 5] == 'S')scnt--;
            isused[i / 5][i % 5] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++) {
            board[i][j] = str[j];
        }
    }

    func(0);
    cout << ans;
}