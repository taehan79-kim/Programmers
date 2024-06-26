#include <bits/stdc++.h>
using namespace std;

int n;
int gcd(int a, int b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;
    int M, N, x, y;
    
    for (int i = 0; i < n; i++) {
        bool chk = false;
        cin >> M >> N >> x >> y;
        if (x == M) x = 0;
        if (y == N) y = 0;
        int l = lcm(M, N);
        for (int i = x; i <= l; i += M) {
            if (i == 0)continue;
            if (i % N == y) {
                cout << i << "\n";
                chk = true;
                break;
            }
        }
        if (!chk)
            cout << -1 << "\n";
    }
}