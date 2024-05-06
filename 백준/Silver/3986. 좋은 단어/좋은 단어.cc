#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        stack<char> s;
        cin >> str;
        for (auto c:str) {
            if (s.empty()) {
                s.push(c);
            }
            else {
                if (s.top() != c) {
                    s.push(c);
                }
                else {
                    s.pop();
                }
            }
        }
        if (s.empty())cnt++;
    }
    cout << cnt;
}