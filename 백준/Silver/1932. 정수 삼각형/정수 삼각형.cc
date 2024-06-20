#include <bits/stdc++.h>
using namespace std;

int n;
int d[505][505];
int s[505][505];
int mm[505];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> s[i][j];
        }
    }
    d[0][0] = s[0][0];
    d[1][0] = d[0][0] + s[1][0];
    d[1][1] = d[0][0] + s[1][1];

    for (int i = 2; i < n; i++) {
        d[i][0] = d[i - 1][0] + s[i][0];
        d[i][i] = d[i - 1][i - 1] + s[i][i];
        for (int j = 1; j < i; j++) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];
        }
    }
    sort(d[n-1], d[n-1] + n );
    cout << d[n - 1][n-1] << "\n";
    
}