#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> a[105];
int d[100005];
int dtmp[100005];
// d[i] : i 무게 내 넣을 수 있는 최대 밸류 값

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i].first;
        for (int j = a[i].first; j <= k; j++) {
            if (j < sum)
                dtmp[j] = max(d[j], d[j - a[i].first] + a[i].second);
            else
                dtmp[j] += a[i].second;
        }
        for (int j = a[i].first; j <= k; j++) {
            d[j] = dtmp[j];
        }
    }
    cout << d[k];
}