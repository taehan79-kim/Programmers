
#include <bits/stdc++.h>
using namespace std;


long long A, B, C;

int func1(int a, int b, int c) {
    if (b == 1) return a % c; // base condition
    long long val = 1;
    val = func1(a, b/2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cout << func1(A, B, C);

}
