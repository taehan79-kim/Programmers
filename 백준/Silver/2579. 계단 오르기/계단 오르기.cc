#include <bits/stdc++.h>
using namespace std;

int n;
int scr[305];
int d[305][305];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> scr[i];
    }
    d[1][0] = scr[1];
    d[1][1] = scr[1];
    d[2][0] = scr[2];
    d[2][1] = d[1][0] + scr[2];
    for (int i = 3; i <= n; i++) {
        d[i][1] = d[i - 1][0] + scr[i];
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + scr[i];
    }
    cout << max(d[n][0], d[n][1]) << "\n";
}