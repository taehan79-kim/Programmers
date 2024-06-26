#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[55];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    int cntP = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        if (a[i].first > 0)cntP++;
    }
    sort(a, a + n);

    for (int i = 0; i < n - cntP; i++) {
        if (i > 0 && !a[i - 1].second && !a[i].second) { 
            sum += a[i].first * a[i - 1].first;
            a[i].second = 1;
            a[i-1].second = 1;
        }
    }
    for (int i = n - 1; i >= n - cntP; i--) {
        if (i < n - 1 && !a[i + 1].second && !a[i].second && a[i].first != 1) {
            sum += a[i].first * a[i + 1].first;
            a[i].second = 1;
            a[i + 1].second = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!a[i].second)
            sum += a[i].first;
    }
    cout << sum << "\n";
}