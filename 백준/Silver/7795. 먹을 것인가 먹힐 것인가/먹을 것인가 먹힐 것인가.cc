#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20005];
int b[20005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a, a + n);
        for (int k = 0; k < m; k++) {
            cin >> b[k];
        }
        sort(b, b + m);

        // 비교
        int cnt = 0;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (cnt == m) {
                sum += cnt;
                continue;
            }
            for (int k = cnt; k < m; k++) {
                if (a[j] > b[k]) {
                    cnt++;
                }
                else {
                    sum += cnt;
                    break;
                }
                if (cnt == m) {
                    sum += cnt;
                }
            }
        }
        cout << sum << "\n";
    }
}