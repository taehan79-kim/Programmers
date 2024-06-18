#include <bits/stdc++.h>
using namespace std;

int n;
string a[20005];

bool cmp(const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() < b.length();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])return a[i] < b[i];
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    string tmp;
    for (int i = 0; i < n; i++) {
        if (tmp == a[i]) {
            continue;
        }
        cout << a[i] << "\n";
        tmp = a[i];
    }
}