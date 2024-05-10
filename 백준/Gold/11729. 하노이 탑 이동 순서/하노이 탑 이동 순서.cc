#include <bits/stdc++.h>
using namespace std;


int A, B, N, c;

void func1(int a, int b, int n) {
    if (n == 1) {
        cout << a<< " " << b<< "\n";
        return;
    }  // base condition
    func1(a, 6 - a - b, n - 1);
    c++;
    cout << a << " " << b <<"\n";
    func1(6 - a - b, b, n-1);
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << (1 << N) - 1 << "\n";
    func1(1, 3, N);

}