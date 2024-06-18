#include <bits/stdc++.h>
using namespace std;

int n;
int c;

vector<pair<int, int>> v(1000);

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second; // 더 많이 나왔으면 true
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        bool chk = true;
        cin >> a;
        for (int j = 0; j < cnt; j++) {
            if (v[j].first == a) { // 이미 나온 숫자인 경우
                v[j].second++;
                chk = false;
            }
        }
        if (chk) { // 처음 나온 숫자인 경우
            v[cnt] = { a, 1 };
            cnt++;
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        while(v[i].second--)
            cout << v[i].first << " ";
    }
}