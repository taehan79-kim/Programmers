#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[1005][1005];

int combin(int n, int k) {
    int c = 1;
    for (int i = n; i >= n - k; i--)c *= i;
    for (int i = 1; i <= n - k; i++)c /= i;
    return c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k ;
    for (int i = 1; i <= 1000; i++) {
        d[i][0] = d[i][i] = 1;
        for (int j = 1; j < i; j++) {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % 10007;
        }
    }
    
    cout << d[n][k];
}