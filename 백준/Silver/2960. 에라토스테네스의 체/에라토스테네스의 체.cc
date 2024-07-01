#include<iostream>
#include<algorithm>

using namespace std;
int state[1000];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (!state[j]) {
                state[j] = true;
                cnt++;
                if (cnt == k) {
                    cout << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}