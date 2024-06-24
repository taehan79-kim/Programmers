#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005], d[1005][1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int mx1 = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            if (a[i][j] == 1) {
                d[i][j] = 1;
                mx1 = 1;
            }
        }
    }
        
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j]) {
                if (a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1]) {
                    d[i][j] = min(d[i - 1][j], d[i][j - 1]);
                    d[i][j] = min(d[i][j], d[i - 1][j - 1]) + 1;
                    if (mx1 < d[i][j]) {
                        mx1 = d[i][j];
                    }
                }
            }
        }
    }
    cout << mx1 * mx1 << "\n";
}