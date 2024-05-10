#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int arr[10];
bool isused[10];

void func1(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func1(k+1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func1(0);
}