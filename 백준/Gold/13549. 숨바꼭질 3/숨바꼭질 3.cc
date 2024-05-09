#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[200002];
long long int dis[200002]; // 해당 칸을 방문했는지 여부를 저장
long long int dx[2] = { 1,-1 };
int ans = 0;
int cnt = 0;
bool isEnd = false;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<long long int> Q;
    long long int n, m;
    for (long long int i = 0; i < 200002; i++) {
        dis[i] = -1;
    }
    cin >> n >> m;
    if (n == m) {
        cout << 0;
        return 0;
    }
    Q.push_back(n);
    dis[n] = 0;
    while (!Q.empty()) {
        long long int cur = Q.front();
        Q.pop_front();
        //cout << "cur:" << cur << ", dis:" << dis[cur] << "\n";
        for (int dir = 0; dir < 1; dir++) { // 점프 칸을 살펴볼 것이다.
            long long int nx = cur * 2;
            if (nx <= 0 || nx > 200000) continue; // 범위 밖일 경우 넘어감
            if (nx > 2*m) continue; // 범위 밖일 경우 넘어감
            if (dis[nx] >= 0){ 
                if (dis[nx] < dis[cur] )
                    continue;
            }
            if (nx == m) {
                cout << dis[cur];
                return 0;
            }
            
            if (!isEnd) {
                dis[nx] = dis[cur];
                Q.push_front(nx);
            }
            
        }
        for (int dir = 0; dir < 2; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            long long int nx = cur + dx[dir];

            if (nx < 0 || nx > 200000) continue; // 범위 밖일 경우 넘어감
            if (dis[nx] >= 0) {
                if(dis[nx]< dis[cur] + 1)
                continue; // 이미 방문한 칸인 경우
            }
            if (nx == m) {
                //cout << dis[cur] + 1;
                ans = dis[cur] + 1;
                isEnd = true;
            }
            if (!isEnd) {
                dis[nx] = dis[cur] + 1;
                Q.push_back(nx);
            }
        }
    }
    cout << ans;
}