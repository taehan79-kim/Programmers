#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M;
int board[52][52];
pair<int, int> house[102];
int hdismin[102];
pair<int, int> chkh[15];
bool isclosed[15];
int kkk[15];
int hcnt = 0;
int chcnt = 0;
int cnt = 0;
int towndismin = 0;
int temtowndis = 0;


int checkdis() { // 도시의 최소 치킨거리 구하는 함수
    int towndis = 0;
    for (int i = 0; i < hcnt; i++) {
        auto curh = house[i];
        for (int j = 0; j < chcnt; j++) {
            if (!isclosed[j])continue;
            auto curch = chkh[j];
            //cout << i << "집 위치: " << curh.X << ", " << curh.Y << "\n";
            int tmpdisX = curh.X - curch.X;
            if (tmpdisX < 0)tmpdisX = tmpdisX * -1;
            int tmpdisY = curh.Y - curch.Y;
            if (tmpdisY < 0)tmpdisY = tmpdisY * -1;
            if (tmpdisX + tmpdisY < hdismin[i] || hdismin[i] == 0)hdismin[i] = tmpdisX + tmpdisY;
            //cout << i << "집에서 "<<j<< "치킨집까지 거리 차이x,y : " << hdismin[i] << "\n";
        }
    }
    for (int i = 0; i < hcnt; i++)towndis = towndis + hdismin[i];
    //cout << towndis << "\n";
    return towndis;
}


void func1(int n) { // 전체 치킨집 중 문을 열 치킨 집 조합 백트레킹 구현, n번째 치킨집 선택
    if (n == M) {
        for (int i = 0; i < hcnt; i++) {
            hdismin[i] = 0;
        }
        
        // 도시거리 구하는 함수
        temtowndis = checkdis();
        if (towndismin > temtowndis || towndismin == 0) {
            towndismin = temtowndis;
            //cout << "도시거리 최소값 갱신: " << towndismin << "\n";
        }
        return;
    }
    int st = 0;
    if (n > 0)st = kkk[n - 1];
    for (int i = st; i < chcnt;i++) {
        if (!isclosed[i]) {
            isclosed[i] = true;
            kkk[n] = i;
            func1(n + 1);
            isclosed[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                house[hcnt] = { i, j };
                //cout << hcnt << "번 집 위치: " << i << ", " << j << "\n";
                hcnt++;
                
            }
            else if (board[i][j] == 2) {
                chkh[chcnt] = { i, j };
                //cout << chcnt << "번 치킨집 위치: " << i << ", " << j << "\n";
                chcnt++;
                
            }
        }
    }
    func1(0);
    cout << towndismin;
}