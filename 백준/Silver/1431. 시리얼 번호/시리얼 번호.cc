#include <bits/stdc++.h>
using namespace std;

int n;
string a[52];

bool cmp(const string& a, const string& b) {
    if (a.length() != b.length())return a.length() < b.length();
    else{
        int suma = 0;
        int sumb = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] - '0' < 10) suma += a[i] - '0';
            if (b[i] - '0' < 10) sumb += b[i] - '0';
        }
        if (suma != sumb)return suma < sumb;
        else {
            if (a != b)return a < b;
            else return a < b;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // STL Compare Sort
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}