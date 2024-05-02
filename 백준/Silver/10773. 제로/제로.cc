#include <bits/stdc++.h>
using namespace std;


const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

int pop() {
    pos--;
    return dat[pos];
    //cout << dat[pos] << "\n";
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
        int c;
        cin >> c;
        if (c == 0 && !empty()) {
            int j = pop();
        }
        else {
            push(c);
        }
    }
    int cnt = 0;
    int p = pos;
    for (int i = 0; i < p; i++) {
        cnt += pop();
    }
    cout << cnt;
}