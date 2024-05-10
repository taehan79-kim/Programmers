#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
char board[6563][6563];

void func1(int n, pair<int,int> p) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(i != 1 || j != 1)board[i + p.X][j + p.Y] = '*'; 
                else board[i + p.X][j + p.Y] = ' ';
            }
        }
        return;
    }
    int k = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1) {
                func1(k, { p.X + i * k, p.Y + j * k });
            }
            else {
                for (int a = 0; a < k; a++) {
                    for (int b = 0; b < k; b++) {
                        board[p.X + i * k + a][p.Y + j * k + b] = ' ';
                    }
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func1(N, { 0,0 });
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}