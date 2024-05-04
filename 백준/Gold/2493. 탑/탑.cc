#include <bits/stdc++.h>
using namespace std;


stack<int> Laser;
stack<int> LaserPos;
int T[1000005];
int pos = 1;
int ans[1000005];

void push(int k) {
    T[pos] = k;
    pos++;
}

int top() {
    return T[pos-1];
}

void pop() {
    pos--;
}

void chkLaser(int N) {
    while (pos > 1) {
        while (!Laser.empty() && pos > 1) {
            //cout << "Laser : " << Laser.top() << " / Top " << top() << "\n";
            if (top() >= Laser.top()) {
                // TOP에 부딪힌경우
                ans[LaserPos.top()] = pos-1;
                //cout << "Ans : " << LaserPos.top() << " data :  " << pos -1 << "\n";
                Laser.pop();
                LaserPos.pop();
                
            }
            else {
                LaserPos.push(pos-1);
                Laser.push(top());
                //cout << "Laser : " << top() << " and " << pos-1 << "\n";
                pop();
            }
        }
        if (Laser.empty()) {
            LaserPos.push(pos - 1);
            Laser.push(top());
            //cout << "Laser : " << top() << " and " << pos-1 << "\n";
            pop();
        }
    }
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        push(k);
        //cout << k << "\n";
    }

    chkLaser(N);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}