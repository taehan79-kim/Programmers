#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int j;
            cin >> j;
            dq.push_front(j);
        }
        else if (s == "push_back") {
            int j;
            cin >> j;
            dq.push_back(j);
        }
        else if (s == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else cout << -1 << "\n";
        }
        else if (s == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else cout << -1 << "\n";
        }
        else if (s == "size") {
            cout << dq.size() << "\n";
        }
        else if (s == "empty") {
            cout << dq.empty() << "\n";
        }
        else if (s == "front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
            }
            else cout << -1 << "\n";
        }
        else if (s == "back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
            }
            else cout << -1 << "\n";
        }
    }
}