#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, s;
int arr[40];
int cnt = 0;

void func1(int cur, int tot) {
    if (cur == N) {
        if (tot == s) cnt++;
        return;
    }
    func1(cur + 1, tot);
    func1(cur + 1, tot + arr[cur]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> s;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    func1(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}