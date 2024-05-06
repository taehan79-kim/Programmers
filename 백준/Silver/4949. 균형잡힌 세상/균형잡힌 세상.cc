#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        string str;
        stack<char> s;
        getline(cin, str);
        if (str == ".") break;
        for (auto c:str) {
            if (c == '.') {
                if(!s.empty())cout << "no" << "\n";
                else cout << "yes" << "\n";
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
                    cout << "no" << "\n";
                    break;
                }
                else {
                    s.pop();
                }
            }
            else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    cout << "no" << "\n";
                    break;
                }
                else {
                    s.pop();
                }
            }
        }
    }
}