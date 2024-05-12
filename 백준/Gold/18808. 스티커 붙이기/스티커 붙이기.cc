#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int notebook[41][41];
int isused[41][41];
int sticker[11][11];
int sticker1[11][11];
int stcnt=0;
int cnt = 0;
int n, m;

bool checks(int i, int j, int n, int m) {
    bool ispossible = true;
    for (int x = 0; x < n; x++) { // 스티커 확인
        for (int y = 0; y < m; y++) {
            if (notebook[i + x][j + y] && sticker1[x][y]) {
                //cout <<"position : " << i+x << ", " << j+y << "\n";
                ispossible = false;
            }
        }
    }
    if (ispossible) {
        for (int x = 0; x < n; x++) { // 스티커 확인
            for (int y = 0; y < m; y++) {
                if (sticker1[x][y])
                    notebook[i + x][j + y] = 1;
            }
        }
    }
    else return false;
    return true;
}

bool check(int n, int m) { // 스티커 가능한지 확인
    for (int i = 0; i <= N-n; i++) { // 노트북 확인
        for (int j = 0; j <= M-m; j++) {
            //if (i == 0 && j == 2) {
                //cout <<"0,2일때 확인 : " << checks(i, j, n, m) << "\n";
            //}
            
            if (checks(i, j,n,m)) return true;
        }
    }
    return false;
}


bool checkf() { // 4 방향 확인, 성공하면 cnt 리턴, 실패하면 -1리턴 
    int cnt = 0;
    for (int i = 0; i < n; i++) { // 0도
        for (int j = 0; j < m; j++) {
            sticker1[i][j] = sticker[i][j];
        }
    }
    if (check(n, m)) {
        //cout << "0도 에서 스티커 붙이기 성공!\n";
        return true;
    }
    else {
        //cout << "0도 에서 스티커 붙이기 실패ㅠㅠ\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sticker1[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) { // 90도
        for (int j = 0; j < m; j++) {
            sticker1[j][n-1-i] = sticker[i][j];
        }
    }
    
    if (check(m,n)) {
       // cout << "90도 에서 스티커 붙이기 성공!\n";
        return true;
    }
    else {
        //cout << "90도 에서 스티커 붙이기 실패ㅠㅠ\n";
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sticker1[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) { // 180도
        for (int j = 0; j < m; j++) {
            sticker1[i][j] =  sticker[n - 1 - i][m - 1 - j];
        }
    }
    

    if (check(n,m)) {
        //cout << "180도 에서 스티커 붙이기 성공!\n";
        return true;
    }
    else {
        //cout << "180도 에서 스티커 붙이기 실패ㅠㅠ\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sticker1[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) { // 270도
        for (int j = 0; j < m; j++) {
            sticker1[m-1-j][i] = sticker[i][j];
        }
    }

    if (check(m,n)) {
        //cout << "270도 에서 스티커 붙이기 성공!\n";
        return true;
    }
    else {
        //cout << "270도 에서 스티커 붙이기 실패ㅠㅠ\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sticker1[i][j] = 0;
        }
    }

    return false;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int a = 0; a < K; a++) {
        cin >> n >> m;
        stcnt = 0;
        //cout << "-------------------------" << a << "번 스티커\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> sticker[i][j];
                if(sticker[i][j] == 1)stcnt++;
            }
        }
        // 여기서 함수를 부를까
        if (checkf()) {
            //cout << "possible\n";
            cnt = cnt + stcnt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sticker[i][j] = 0;
            }
        }
    }
    cout << cnt;
    
}