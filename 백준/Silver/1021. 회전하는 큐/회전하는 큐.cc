#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
const int MX = 1000005;
int dis[MX];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int pos=1;
    int cnt=0;
    for (int i = 1; i <= N; i++) {
            dq.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        int idx = find(dq.begin(), dq.end(), k) - dq.begin();
        while (dq.front() != k) {
            if (idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        } 
        dq.pop_front();
    }
    cout << cnt;
}