#include <bits/stdc++.h>
using namespace std;

int n,m;
int s[100005];
int d[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    d[1] = s[1];
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + s[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << d[b] - d[a-1]  << "\n";
    }
}