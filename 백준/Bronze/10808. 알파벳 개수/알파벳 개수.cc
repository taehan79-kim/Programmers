#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // C 표준 stream과 C++ 표준 stream의 동기화를 끊는다.
    // 따라서 속도를 보다 가속시키기 위해 사용한다.
    string S;
    
    int freq[26];
    cin >> S;
    fill(freq, freq +26,0);
    for (auto c :S) {
        freq[c - 'a']++;
        //cout << c - 'a' << ' ';
    }
    for (int i = 0; i < 26; i++) {
        cout << freq[i] << ' ';
    }

}