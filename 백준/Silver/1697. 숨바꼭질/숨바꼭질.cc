#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
char board[100002];
int dis[100002]; // 해당 칸을 방문했는지 여부를 저장
int dx[2] = { 1,-1 };
int cntTmp = 0;
int cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << 0;
        return 0;
    }
    Q.push(n);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        //cout << "cur:" << cur << "\n";
        for (int dir = 0; dir < 2; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur + dx[dir];
            
            if (nx < 0 || nx > 100000 ) continue; // 범위 밖일 경우 넘어감
            if (dis[nx]>0) continue; // 이미 방문한 칸인 경우
            if (nx == m) {
                cout << dis[cur] + 1;
                return 0;
            }
            dis[nx] = dis[cur] + 1;
            Q.push(nx);
        }
        for (int dir = 0; dir < 1; dir++) { // 점프 칸을 살펴볼 것이다.
            int nx = cur * 2;
            if (nx < 0 || nx > 100000) continue; // 범위 밖일 경우 넘어감
            if (dis[nx] > 0) continue; // 이미 방문한 칸인 경우
            if (nx == m) {
                cout << dis[cur] + 1;
                return 0;
            }
            dis[nx] = dis[cur] + 1;
            Q.push(nx);
        }
    }

}