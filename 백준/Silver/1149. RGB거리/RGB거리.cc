#include <bits/stdc++.h>
using namespace std;

int n;
int scr[1005][3];
int d[1005][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> scr[i][0];
        cin >> scr[i][1];
        cin >> scr[i][2];
    }
    d[1][0] = scr[1][0];
    d[1][1] = scr[1][1];
    d[1][2] = scr[1][2];
    for (int i = 2; i <= n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + scr[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + scr[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + scr[i][2];
    }
    int min1 = min(d[n][0], d[n][1]);
    int min2 = min(min1, d[n][2]);
    cout << min2 << "\n";
}