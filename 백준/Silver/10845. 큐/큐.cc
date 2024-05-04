#include <bits/stdc++.h>
using namespace std;


int main(void) {
    queue<int> q;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int j;
            cin >> j;
            q.push(j);
        }
        else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << -1 << "\n";
        }
        else if (s == "front") {
            if (!q.empty()) {
                cout << q.front() << "\n";
            }
            else cout << -1 << "\n";
        }
        else if (s == "back") {
            if (!q.empty()) {
                cout << q.back() << "\n";
            }
            else cout << -1 << "\n";
        }
        else if (s == "size") {
            cout << q.size() << "\n";
        }
        else if (s == "empty") {
            cout << q.empty() << "\n";
        }
    }
}