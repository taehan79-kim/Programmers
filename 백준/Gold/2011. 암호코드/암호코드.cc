#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5005], d[5005];
// d[i] = 해당 숫자의 i번째 자릿수에서의 해석 경우의 수 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        a[i+1] = s[i] - '0';
    }
    if (a[1] == 0) { // 시작이 0 인 경우 
        cout << 0;
        return 0;
    }
    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            d[i] += d[i - 1] % 1000000;
            d[i] = d[i] % 1000000;
            if (i > 1) {
                int x = a[i - 1] * 10 + a[i];
                if (x <= 26 && x >= 11) {
                    d[i] += d[i - 2] % 1000000;
                    d[i] = d[i] % 1000000;
                }
            }
        }
        else { // a[i]가 0
            if (i > 1 && a[i - 1] == 0) { // 00 인 경우
                cout << 0;
                return 0;
            }
            if (i > 1) { 
                int x = a[i - 1] * 10 + a[i];
                if (x == 20 || x == 10) { // 220 혹은 110 인 경우
                    if (i > 2)d[i] = d[i - 2];
                    else d[i] = d[i - 1]; // 20, 10
                }
                else { // 30 혹은 40 인 경우
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << d[n];
}