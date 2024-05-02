#include <bits/stdc++.h>
using namespace std;


const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
    cout << dat[pos] << "\n";
}

void top() {
    cout << dat[pos-1] << "\n";
}

bool empty() {
    if (pos == 0)return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string c;
        cin >> c;
        if (c == "push") {
            int k;
            cin >> k;
            push(k);
        }
        else if (c == "top") {
            if (!empty())top();
            else cout << -1 << "\n";
        }
        else if (c == "pop") {
            if (!empty())pop();
            else cout << -1 << "\n";
        }
        else if (c == "size")cout << pos << "\n";
        else if (c == "empty") cout << empty() << "\n";
    }
}