#include <bits/stdc++.h>
using namespace std;

int n;
int s[100005];
long long d[100005];
int mn = 0;
bool chk = false;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    d[1] = s[1];
    if (d[1] < 0) {
        chk = true;
        mn = d[1];
    }

    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + s[i];
        if (chk) {
            d[i] = d[i] - mn;
            chk = false;
        }
        if (d[i] < 0) {
            chk = true;
            mn = d[i];
        }
    }
    sort(d+1, d + n+1);
    cout << d[n];
}