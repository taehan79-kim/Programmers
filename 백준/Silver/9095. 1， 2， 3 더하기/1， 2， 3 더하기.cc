#include <bits/stdc++.h>
using namespace std;

int n;
int d[15];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 4; j <= k; j++) {
            d[j] = d[j - 1] + d[j - 2] + d[j - 3];
        }
        cout << d[k] << "\n";
    }
}