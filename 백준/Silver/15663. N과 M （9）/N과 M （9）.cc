#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int arr[10];
int num[10];
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
    int tmp = 0;
    //if (cur > 0) st = arr[cur - 1];
    for (int i = 0; i < N; i++) {
        if (!isused[i] && num[i] != tmp) {
            arr[cur] = num[i];
            isused[i] = true;
            tmp = arr[cur];
            func1(cur + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)cin >> num[i];
    sort(num, num + N);
    func1(0);
}