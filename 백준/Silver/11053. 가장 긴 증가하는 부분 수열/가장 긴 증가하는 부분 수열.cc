#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010], d[2][1010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[0][i] = a[i];
        d[1][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                if (d[1][i] < d[1][j] + 1) {
                    d[1][i] = d[1][j] + 1;
                    d[0][i] = d[0][j] + a[i];
                }
            }
        }
    }

    cout << *max_element(d[1], d[1] + n);
}