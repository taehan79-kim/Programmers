#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N;
int board[22][22];
int arr[12];
int isused[22];
long sumused = 0;
long sumnotused = 0;
long dismin = -1;
int cnt = 0;

void func(int n) { // N개중 n/2 조합 N C N/2
    if (n == N / 2) {
        /*cnt++;
        for (int i = 0; i < N / 2; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        */
        
        
        sumused = 0;
        sumnotused = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isused[i] == 1) {
                    if (isused[j] == 1) {
                        sumused += board[i][j];
                    }
                }
                if (isused[i] == 0) {
                    if (isused[j] == 0) {
                        sumnotused += board[i][j];
                    }
                }
            }
        }
        
        long dis = sumused - sumnotused;
        if (sumused < sumnotused)dis = dis * -1;
        //cout << "dis : " << dis << "\n";
        if (dismin == -1 || dismin > dis)dismin = dis;

        return;
    }

    int st = 0;
    if (n > 0)st = arr[n - 1];
    for (int i = st; i < N; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            arr[n] = i;
            func(n + 1);
            isused[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func(0);
    //cout << cnt <<"\n";
    cout << dismin;
}