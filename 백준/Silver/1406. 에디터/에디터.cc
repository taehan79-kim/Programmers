#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // C 표준 stream과 C++ 표준 stream의 동기화를 끊는다.
    // 따라서 속도를 보다 가속시키기 위해 사용한다.
    list<char> N;
    string S;
    int M;
    char c;

    cin >> S;
    cin >> M;
    for (auto c : S)N.push_back(c);
    auto t = N.end();

    for (int i = 0; i < M; i++) {
        
        cin >> c;
        if (c == 'P') {
            char pc;
            cin >> pc;
            N.insert(t, pc);
            //for (auto iter = N.begin(); iter != N.end(); iter++) { cout << *iter << " "; }
        }
        else if (c == 'L') {
            if (t != N.begin()) {
                t--;
            }
        }
        else if (c == 'D') {
            if (t != N.end()) {
                t++;
            }
        }
        else if (c == 'B') {
            if (t != N.begin()) {
                t--;
                t= N.erase(t);
                //for (auto iter = N.begin(); iter != N.end(); iter++) { cout << *iter << " "; }
            }
        }
    }

    for (auto iter = N.begin(); iter != N.end(); iter++) { cout << *iter; }
}