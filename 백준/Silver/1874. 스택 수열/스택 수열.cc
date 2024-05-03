#include <bits/stdc++.h>
using namespace std;


stack<int> S;
stack<int> M;
char ans[1000005];
int pos = 0;

bool makepushpop(int N) {
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;

        if (!S.empty()) {
            while (S.top() < c) {
                M.push(S.top());
                //cout << S.top() << "\n";
                ans[pos] = '+';
                pos++;
                S.pop();
            }
            if (S.top() == c) {
                M.push(S.top());
                //cout << S.top() << "\n";
                ans[pos] = '+';
                pos++;
                S.pop();
            }
        }
        if (!M.empty()) {
            if (M.top() == c) {
                ans[pos] = '-';
                pos++;
                //cout << "M.pop : " << M.top();
                M.pop();
            }
            else {
                cout << "NO";
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = N; i > 0; i--) {
        S.push(i);
        //cout << S.top();
    }
    if (makepushpop(N)) {
        for (int i = 0; i < pos; i++) {
            cout << ans[i] << "\n";
        }
    }
    
}