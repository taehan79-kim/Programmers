#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[42][2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 2; j <= m; j++) {
            d[j][0] = d[j - 1][0] + d[j - 2][0];
            d[j][1] = d[j - 1][1] + d[j - 2][1];
        }
        cout << d[m][0] << " " << d[m][1] << "\n";
    }
}