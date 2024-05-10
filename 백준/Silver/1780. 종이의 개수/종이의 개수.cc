#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int board[2190][2190];
int cnt[3];

bool check(int n, pair<int, int> p) {
    for (int i = p.X; i < p.X + n; i++)
        for (int j = p.Y; j < p.Y + n; j++)
            if (board[p.X][p.Y] != board[i][j])
                return false;
    return true;
}

void func1(int n, pair<int,int> p) {
    pair<int, int> TmpPos = p;
    if (check(n, p)) {
        cnt[board[p.X][p.Y] + 1] += 1;
        return;
    }
    int k = n / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func1(k, { p.X + i * k, p.Y + j * k });
        }
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
    func1(N, {0,0});
    for (int i = 0; i < 3; i++)cout << cnt[i]<<"\n";
    
}