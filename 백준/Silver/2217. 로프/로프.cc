#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = 0;
    for (int k = 1; k <= n; k++) {
        if(mx < a[n - k] * k)
            mx = a[n - k] * k;
    }
    cout << mx;
}