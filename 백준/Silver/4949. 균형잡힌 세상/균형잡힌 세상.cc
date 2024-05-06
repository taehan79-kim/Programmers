#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        string str;
        stack<char> s;
        bool bal = true;
        getline(cin, str);
        if (str == ".") break;
        for (auto c:str) {
            if (c == '.') {
                break;
            }
            else if (c == '[') {
                s.push('[');
            }
            else if (c == '(') {
                s.push('(');
            }
            else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    bal = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
            else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    bal = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
        }
        if (!s.empty())bal = false;
        if (bal) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
}