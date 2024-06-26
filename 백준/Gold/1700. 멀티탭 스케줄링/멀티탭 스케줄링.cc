#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q[105]; // q[i] : i 전기용품의 사용 순서
int a[105];
int p[105]; // 멀티탭

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int usedC = 0; // 사용중인 플러그 수
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
        q[a[i]].push(i);
    }

    for (int i = 0; i < k; i++) {
        if (p[a[i]]) { // 이미 a[i]가 멀티탭에 꽂혀있는 경우
            q[a[i]].pop(); // 사용 처리
            continue;
        }

        // a[i]가 꽂혀있지 않은 경우
        if (usedC < n) { // 멀티탭에 사용가능한 플러그가 있을때
            p[a[i]] = 1;
            q[a[i]].pop(); // 사용했음 표시
            usedC++;
        }
        else { // 한 개 빼야할때
            int mx = 0;
            int mxp = 0;
            bool needChange = false;
            for (int j = 0; j <= k; j++) { 
                if (p[j]) { // 꽂혀있는 전기용품중
                    if (q[j].empty()) { // 이제 안쓰는 경우
                        p[j] = 0;
                        p[a[i]] = 1;
                        q[a[i]].pop();
                        cnt++;
                        needChange = false;
                        break;
                    }
                    else if (q[j].front() > mx) { // 가장 나중에 쓰는지 체크
                        mx = q[j].front();
                        mxp = j;
                        needChange = true;
                    }
                }
            }
            if (needChange) { // 가장 나중에 쓰는 전기 용품 교체
                needChange = false;
                p[mxp] = 0;
                p[a[i]] = 1;
                q[a[i]].pop();
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}