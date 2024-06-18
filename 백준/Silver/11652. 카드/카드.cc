#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort
    sort(a,a+n);

    // counting
    int cnt = 0;
    int mxcnt = 0;
    long long mxval = -(1ll << 62) - 1;  // (1LL) = 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cnt++;
            mxcnt = cnt;
            mxval = a[0];
            continue;
        }
        if (a[i] != a[i - 1]) {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxval = a[i - 1];
            }
            cnt = 0;
        }
        cnt++;
        if (i == n-1) {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxval = a[i - 1];
            }
        }
    }
    cout << mxval;
}