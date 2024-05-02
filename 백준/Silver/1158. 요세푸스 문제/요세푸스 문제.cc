#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // C 표준 stream과 C++ 표준 stream의 동기화를 끊는다.
    // 따라서 속도를 보다 가속시키기 위해 사용한다.
    list<int> L;
    int N, M;
    char c;

    cin >> N;
    cin >> M;
    for (int i = 1; i <= N;i++)L.push_back(i);
    
    auto t = L.begin();
    cout << "<";
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (t == L.end())t = L.begin();
            t++;
        }
        if (t != L.begin()) {
            t--;
            cout << *t;
            t = L.erase(t);
        }
        else
        {
            t = L.end();
            t--;
            cout << *t;
            t = L.erase(t);
        }
        if(i != N)cout << ", ";
        //for (auto iter = L.begin(); iter != L.end(); iter++) { cout << *iter << " "; }
        //cout << "\n";
    }
    cout << ">";
}