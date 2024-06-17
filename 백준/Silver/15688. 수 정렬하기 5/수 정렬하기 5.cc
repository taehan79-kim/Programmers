#include <bits/stdc++.h>
using namespace std;

int n;
int freq[2000005];
int a[1000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        freq[k+1000000]++;
    }

    // Counting Sort
    for (int i = 0; i < 2000005; i++) {
        if (freq[i]>0) {
            for(int k = 0; k < freq[i]; k++)
                cout << i - 1000000 << "\n";
        }
    }
}