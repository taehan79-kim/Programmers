#include <bits/stdc++.h>
using namespace std;


int A, B, N, c;

int func1(int a, int b, int n) {
    if (n==0) { 
        return 0;
    }  // base condition
    int half = 1 << (n - 1);
    if(b < half && a < half)return func1(a, b, n - 1);
    if(b >= half && a < half)return half* half + func1(a, b-half, n - 1);
    if (b < half && a >= half)return half* half*2 + func1(a - half, b, n - 1);
    return half* half*3 + func1(a - half, b - half, n - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> A >> B;
    cout << func1(A, B, N);

}