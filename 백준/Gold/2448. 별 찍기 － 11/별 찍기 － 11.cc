#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
char board[3075][6145];
string str[3];

void func1(int n, pair<int,int> p) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = -2; j < 3; j++) {
                board[p.X + i][p.Y+j] = str[i][j+2];
            }
        }
        return;
    }
    int k = n / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 && j == 2) {
                func1(k, { p.X, p.Y });
            }
            if (i == 1 && j == 1) {
                func1(k, { p.X + i * k, p.Y - k });
            }
            if (i == 1 && j == 3) {
                func1(k, { p.X + i * k, p.Y + k });
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    str[0] = "  *  ";
    str[1] = " * * ";
    str[2] = "*****";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            board[i][j] = ' ';
        }
    }


    func1(N, { 0,N-1 });
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}