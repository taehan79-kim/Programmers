#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int arr[40];
bool isused[40];
bool isused1[40];
bool isused2[40];
int cnt;

void func1(int cur) {
    if (cur == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isused[i] || isused1[i + cur] || isused2[cur - i + N - 1])
            continue;
        isused[i] = true;
        isused1[cur + i] = true;
        isused2[cur - i + N - 1] = true;
        func1(cur + 1);
        isused[i] = false;
        isused1[cur + i] = false;
        isused2[cur - i + N - 1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func1(0);
    cout << cnt;
}