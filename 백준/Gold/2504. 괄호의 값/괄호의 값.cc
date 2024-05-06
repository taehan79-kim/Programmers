#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool isValid = true;

    string str;
    stack<long> s;
    cin >> str;
    for (auto c : str) {
        int cnt = 0;
        if (!isValid)break;
        if (c == '(' || c == '[') {
            s.push(c);
        }
        else if (c == ')') {
            if (!s.empty()) {
                if (s.top() == '(') {
                    s.pop();
                    s.push(2+94);
                }
                else { // number
                    while (s.top() != '(') {
                        if (s.empty() || s.top() == '[') {
                            isValid = false;
                            break;
                        }
                        else {
                            cnt += (int)s.top()-94;
                        }
                        s.pop();
                        if (s.empty()) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!s.empty()) {
                        s.pop();
                        s.push((cnt * 2) + 94);
                        cnt = 0;
                    }
                }
            }
            else {
                isValid = false;
                break;
            }
        }
        else if (c == ']') {
            if (!s.empty()) {
                if (s.top() == '[') {
                    s.pop();
                    s.push(3 + 94);
                }
                else { // number
                    while (s.top() != '[') {
                        if (s.empty() || s.top() == '(') {
                            isValid = false;
                            break;
                        }
                        else {
                            cnt += (int)s.top()-94;
                        }
                        s.pop();
                        if (s.empty()) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!s.empty()) {
                        s.pop();
                        s.push((cnt * 3)+94);
                        cnt = 0;
                    }
                }
            }
            else {
                isValid = false;
                break;
            }
        }
    }
    int sum = 0;
    if (isValid) {
        int k = s.size();
        for (int i = 0; i < k; i++) {
            if (!s.empty()) {
                if (s.top() == '(' || s.top() == '[') {
                    sum = 0;
                    break;
                }
                sum += s.top()-94;
                s.pop();
            }
        }
    }
    cout << sum;
}