#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000005];
long long b[1000005];

long long rev(long long a) {
    string s = to_string(a);
    reverse(s.begin(), s.end());
    return atoll (s.c_str());
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = rev(a[i]);
    }
    sort(b,b+n);
    for (int i = 0; i < n; i++) {
        cout << b[i] <<"\n" ;
    }
}