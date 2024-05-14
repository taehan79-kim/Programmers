#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int K, w,m;

deque<int> dq[4];

void protate(deque<int>& dq) { // 
    dq.push_front(dq.back());
    dq.pop_back();
}

void mrotate(deque<int>& dq) { // 
    dq.push_back(dq.front());
    dq.pop_front();
}

void rotate(deque<int>& dq, int i) {
    if (i > 0) {
        protate(dq);
        //cout << " protate!" << "\n";
    }
    else {
        mrotate(dq);
        //cout << " mrotate!" << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++) {
            dq[i].push_back(str[j] - '0');
            //cout << dq[i][j] << " ";
        }
        //cout << "\n";
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> w >> m;
        w--;
        int ww = w;
        int mm = m * -1;
        while (ww < 3) {
            if (dq[ww][2] != dq[ww + 1][6]) {
                q.push({ ww + 1, mm });
            }
            else break;
            mm = mm * -1;
            ww++;
        }
        ww = w;
        mm = m * -1;
        while(ww > 0) {
            
            if (dq[ww][6] != dq[ww - 1][2]) {
                q.push({ ww - 1, mm });
            }
            else break;
            mm = mm * -1;
            ww--;
        }
        
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            //cout << c.X << "를 돌리기 : ";
            rotate(dq[c.X], c.Y);
        }

        //cout << w << "를 돌리기 : ";
        rotate(dq[w], m);
        /*
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 8; k++) {
                cout << dq[i][k] << " ";
            }
            cout << "\n";
        }*/

    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum = sum + dq[i].front()* pow(2,i);
    }
    cout << sum;
}