#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int board[130][130];
int cnt[2];

int check(int n, pair<int, int> p) { // 모든 칸 확인 후 모두 같으면 그 칸의 값, 다르면 -1 반환
    int t = board[p.X][p.Y];
    for (int i = p.X; i < p.X + n; i++)
        for (int j = p.Y; j < p.Y + n; j++)
            if (board[p.X][p.Y] != board[i][j])
                return -1;
    return t;
}

void func1(int n, pair<int,int> p) {
    pair<int, int> TmpPos = p;
    int c = check(n, p);
    if (c >-1) {
        cout << c;
        return;
    }
    int k = n / 2;
    cout << "(";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            
            func1(k, { p.X + i * k, p.Y + j * k });
            
        }
    }
    cout << ")";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            board[i][j] = str[j]-'0';
        }
    }
    func1(N, {0,0});
    
}
