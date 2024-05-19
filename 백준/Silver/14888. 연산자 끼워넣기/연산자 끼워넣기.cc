#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N;
int sum;
int num[12];
int cal[12];
int cal1[12];
int arr[12];
int mx = -2000000000;
int mn = 2000000000;

int pluss(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int divide(int a, int b) {
    int k;
    if (a < 0) {
        a = a * -1;
        k = a / b;
        k = k * -1;
    }
    else {
        k = a / b;
    }
    return k;
}
int multiple(int a, int b) {
    return a * b;
}

void func(int n) {
    if (n == N - 1) {

        int ccc = num[0];
        for (int i = 0; i < N-1; i++) {
            if (arr[i] == 0) { // 덧셈
                ccc = pluss(ccc, num[i + 1]);
            }
            if (arr[i] == 1) { // 뺄셈
                ccc = subtract(ccc, num[i + 1]);
            }
            if (arr[i] == 2) { // 곱셈
                ccc = multiple(ccc, num[i + 1]);
            }
            if (arr[i] == 3) { // 나눗셈
                ccc = divide(ccc, num[i + 1]);
            }
        }
        if (mn > ccc)mn = ccc;
        if (mx < ccc)mx = ccc;

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (cal1[i] < cal[i]) {
            cal1[i]++;
            arr[n] = i;
            func(n + 1);
            cal1[i]--;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int j = 0; j < 4; j++) {
        cin >> cal[j];
    }
    func(0);
    cout << mx << "\n";
    cout << mn;
}
