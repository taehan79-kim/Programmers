#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int sum = 0;
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        sum1 += sum;
    }
    cout << sum1;
}