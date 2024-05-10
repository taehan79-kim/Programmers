#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int arr[10];
int cnt = 0;
bool isused[10];

void func1(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        arr[cur] = i;
        func1(cur + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func1(0);
}