#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[1000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> n;
        long long sum = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (mx < a[i]) {
                mx = a[i];
            }
            else {
                sum += mx - a[i];
            }
        }
        cout << sum << "\n";
    }
}