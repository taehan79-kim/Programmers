#include <bits/stdc++.h>
using namespace std;

int n, t;
long long a[105], d[105];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        d[1] = 1;
        d[2] = 1;
        d[3] = 1;
        d[4] = 2;
        d[5] = 2;
        for (int i = 6; i <= n; i++) {
            d[i] = d[i - 1] + d[i - 5];
        }
        cout << d[n] << "\n";
    }
}