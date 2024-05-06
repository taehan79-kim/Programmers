
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int pipe = 0;
    string str;
    stack<char> s;

    cin >> str;

    for (auto c : str) {
        if (c == '(') {
            pipe++;
            s.push(c);
        }
        else {
            if (!s.empty()) {
                if (s.top() == '(') {
                    pipe--;
                    cnt += pipe;
                    s.push(c);
                }
                else {
                    s.push(c);
                    cnt += 1;
                    pipe--;
                }
            }
        }
    }
    cout << cnt;
}