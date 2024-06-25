#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[55], b[55];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    int sum = 0;
    for (int k = 0; k < n; k++) {
        sum += a[k] * b[k];
    }
    cout << sum;
}