#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // C 표준 stream과 C++ 표준 stream의 동기화를 끊는다.
    // 따라서 속도를 보다 가속시키기 위해 사용한다.
    int n;
    int x;
    int ans = 0;
    cin >> n;
    int* a = new int[n]();
    bool occur[2000001] = { false };
    for (int i = 0; i < n; i++)cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (x - a[i] > 0 && occur[x - a[i]])ans++;
        occur[a[i]] = true;
    }
    cout << ans;
}