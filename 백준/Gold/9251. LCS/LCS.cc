#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
int d[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int lena = a.length();
    int lenb = b.length();

    if (a[0] == b[0])d[1][1] = 1;

    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (a[i - 1] == b[j - 1])d[i][j] = d[i - 1][j - 1] + 1;
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    cout << d[lena][lenb];
}