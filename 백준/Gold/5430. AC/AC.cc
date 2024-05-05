#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
deque<int> dq;
int dis[MX];

void flip() {
    deque<int> rd;
    int k = dq.size();
    for (int i = 0; i < k; i++) {
        rd.push_front(dq.front());
        dq.pop_front();
    }
    k = rd.size();
    for (int i = 0; i < k; i++) {
        dq.push_back(rd.front());
        rd.pop_front();
    }
}

void parse(string& tmp, deque<int>& d) {
    int cur = 0;
    for (int i = 1; i + 1 < tmp.size(); i++)
    {
        if (tmp[i] == ',') {
            d.push_back(cur);
            cur = 0;
        }
        else {
            cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if (cur != 0)
        d.push_back(cur);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    bool err = false;
    for (int i = 0; i < T; i++) {
        string s, k;
        cin >> s;
        int n;
        int rev = 0;
        cin >> n;
        cin >> k;
        parse(k, dq);
        for (char c : s) {
            if (c == 'R' && !err) {
                rev = 1 - rev;
            }
            else if (c=='D' && !err) {
                if (!dq.empty() && !err) {
                    if (!rev) dq.pop_front();
                    else dq.pop_back();
                }
                else {
                    err = true;
                    break;
                }
            }
        }
        if (err) {
            cout << "error\n";
            err = false;
        }
        else {
            if (rev) reverse(dq.begin(), dq.end());
            int k = dq.size();
            cout << "[";
            for (int i = 0; i < k; i++) {
                cout << dq.front();
                dq.pop_front();
                if (i != k-1)cout << ",";
            }
            cout << "]\n";
        }

    }
}