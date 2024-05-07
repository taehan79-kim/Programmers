#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[100005];
int dis[100005]; // 해당 칸을 방문했는지 여부를 저장
int dis1[100005]; // 해당 칸을 방문했는지 여부를 저장
queue<int> Q;
queue<int> Q1;
int n;
int N = 0;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int a = 0; a < N; a++) {
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            board[i] = k;
            dis[i] = 0;
            dis1[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            Q.push(i);
            Q1.push(i);
            dis[i] = 1;
            //cout << "i : " << i << "\n";
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                if (dis1[cur] > 0) { // 이미 팀이 있는 사람
                    while (!Q1.empty()) {
                        dis[Q1.front()] = 0;
                        dis1[Q1.front()] = -1;
                        Q1.pop();
                    }
                    break;
                }
                if (dis1[cur] < 0) { // 이미 팀을 못가지는 사람
                    while (!Q1.empty()) {
                        dis[Q1.front()] = 0;
                        dis1[Q1.front()] = -1;
                        Q1.pop();
                    }
                    break;
                }
                //cout << "cur:" << cur  << "\n";
                int nx;
                nx = board[cur];
                
                if (dis[nx] > 0 ) { // 이미 방문한 사람이면
                    if (nx == i) { // 처음 사람이면 팀완성
                        while (!Q1.empty()) {
                            cnt++;
                            //cout << Q1.front();
                            dis[Q1.front()] = 0;
                            dis1[Q1.front()] = 1;
                            Q1.pop();
                        }
                        //cout << "\n";
                        break;
                    }
                    else { 
                        //cout << "Q1.FRONT: " << Q1.front()<< ", nx: " << nx << "\n";
                        while (Q1.front() != nx) {
                            //cout << "Q1.FRONT: " << Q1.front() << "\n";
                            dis[Q1.front()] = 0;
                            dis1[Q1.front()] = -1;
                            Q1.pop();
                        }
                        if (!Q1.empty()) {
                            while (!Q1.empty()) {
                                cnt++;
                                dis[Q1.front()] = 0;
                                dis1[Q1.front()] = 1;
                                Q1.pop();
                            }
                        }
                        break;
                    }
                }
                Q1.push(nx);
                dis[nx] = 1;
                //cout << "nx:" << nx << "\n";
                Q.push(nx);
            }
        }
        cout << n - cnt << "\n";
    }
}