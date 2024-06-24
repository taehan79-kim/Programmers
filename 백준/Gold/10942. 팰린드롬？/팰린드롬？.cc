#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2005], d[2005][2005];

// d[i][j] = i부터 j 까지 펠린드롬인지 저장
// a[i] == a[j]이고 d[i+1]d[j-1]가 펠린드롬이면 d[i][j]도 펠린드롬 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // dp
    for (int i = 1; i <= n; i++)
        d[i][i] = 1;
    for (int i = 1; i <= n-1; i++)
        if (a[i] == a[i+1])
            d[i][i + 1] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j - i] == a[j]) {
                if (d[j - i + 1][j - 1]) {
                    d[j - i][j] = 1;
                }
            }
        }
    }
    
    cin >> m;
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << d[i][j] << "\n";
    }
}