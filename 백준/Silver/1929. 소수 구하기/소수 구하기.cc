#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> is_primenum(int n, int m) {
    vector<int> prime_num;
    vector<bool> state(m + 1, true);
    state[1] = false;
    for (int i = 2; i * i <= m; i++) {
        if (!state[i])continue;
        for (int j = i * i; j <= m; j+=i) {
            state[j] = false;
        }
    }
    for (int i = n; i <= m; i++) {
        if (state[i])
            prime_num.push_back(i);
    }
    return prime_num;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> prime = is_primenum(n, m);

    for (int i : prime) {
        cout << i << "\n";
    }
}