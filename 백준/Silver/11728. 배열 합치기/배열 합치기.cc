#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];
int apointer = 0;
int b[1000005];
int bpointer = 0;
int c[2000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Merge Sort
    for (int i = 0; i < n + m; i++) {
        if (bpointer == m) {
            c[i] = a[apointer];
            apointer++;
            continue;
        }
        if (a[apointer] > b[bpointer] || apointer == n) {
            c[i] = b[bpointer];
            bpointer++;
        }
        else {
            c[i] = a[apointer];
            apointer++;
        }
    }

    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
}