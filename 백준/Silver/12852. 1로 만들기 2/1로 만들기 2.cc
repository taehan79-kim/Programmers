#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005][2];
queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    d[1][0] = 0;
    d[2][0] = 1;
    d[2][1] = 1;
    d[3][0] = 1;
    d[3][1] = 1;
    for (int i = 4; i <= n; i++) {
        d[i][0] = d[i - 1][0] + 1;
        d[i][1] = i - 1;
        if (i % 2 == 0) {
            if (d[i / 2][0] + 1< d[i][0])d[i][1] = i / 2;
            d[i][0] = min(d[i / 2][0] + 1, d[i][0]);
        }
        if (i % 3 == 0) {
            if (d[i / 3][0] + 1 < d[i][0])d[i][1] = i / 3;
            d[i][0] = min(d[i / 3][0] + 1, d[i][0]);
        }
    }
    cout << d[n][0] << "\n";
    int k = n;
    for (int i = 0; i < d[n][0]+1; i++) {
        cout << k << " ";
        k = d[k][1];
    }
}