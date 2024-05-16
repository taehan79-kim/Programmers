#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M;

int board[502][502];
int appcnt;

int n[5] = { 1,2,3,3,2 };
int m[5] = { 4,2,2,2,3 };
int tetro[5][4][4] = { 
    { {1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0} },
    {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
    {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
    {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
    {{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}}
};
int n1[5];
int m1[5];
int tetro1[5][4][4];

int addtet(int i, int x, int y) { // 해당 칸에 테트노미노를 넣었을때의 값 반환
    int sum = 0;
    for (int a = 0; a < n[i]; a++) {
        for (int b = 0; b < m[i]; b++) {
            if (tetro1[i][a][b]==1) {
                sum += board[x + a][y + b];
                //cout << "addtet+=: " << board[x + a][y + b] << "\n";
            }
        }
    }
    return sum;
}

int sumtet(int a) { // 테트로미노가 모든 칸에 들어갔을때 그 수의 합의 최대값 반환
    int mx = 0;
    for (int i = 0; i < N-n[a]+1; i++) {
        for (int j = 0; j < M-m[a]+1; j++) {
            int sum = addtet(a, i, j);
            //cout << "sumtsum: " << sum << "\n";
            if (mx == 0 || mx < sum)mx = sum;
        }
    }
    return mx;
}
void rotatet(int kk) { // 90도 회전
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (kk > 0)tetro[i][j][k] = tetro1[i][j][k];
                tetro1[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n[i]; j++) {
            for (int k = 0; k < m[i]; k++) {
                tetro1[i][k][n[i] - 1 - j] = tetro[i][j][k];
            }
        }
        int tmp = n[i];
        n[i] = m[i];
        m[i] = tmp;
    }
}

void symmetry() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                tetro[i][j][k] = tetro1[i][j][k];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n[i]; j++) {
            for (int k = 0; k < m[i]; k++) {
                tetro1[i][j][m[i] - 1 - k] = tetro[i][j][k];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                tetro[i][j][k] = tetro1[i][j][k];
            }
        }
    }
}

int func() {
    int mx = 0;
    
    for (int a = 0; a < 2; a++) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) { // 4방향 회전
            
            rotatet(cnt);

            //cout << "------------------------------------------\n";
            for (int j = 0; j < 5; j++) { // 모든 모양
                //cout << "-------------next tetro------------------\n";
                int sum = sumtet(j);
                //cout << "funcsum: " << sum << "\n";
                if (mx == 0 || mx < sum)mx = sum;
            }
            cnt++;
        }
        symmetry();
    }
    
    return mx;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> curpos;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int mx = func();

    cout << mx;
}