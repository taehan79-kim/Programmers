#include <bits/stdc++.h>
using namespace std;

int n, t;
pair<int,int> a[100005];

bool compare1(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, compare1);
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t <= a[i].first) {
            t = a[i].second;
            ans++;
        }
    }
    cout << ans;
}