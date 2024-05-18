#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,M;

char bd[12][12];
char board[11][12][12];
int arr[10];
int arr1[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int cnt = -1;
int nend = -1;

int lean(int dir, int n) { // 1 성공, 0 계속, -1 실패
    int pos = -1;
    bool isgoal = false; 
    bool redin = false; // red가 들어간 경우
    if (dir == 0) { // 왼
        for (int i = 0; i < N; i++) {
            pos = -1;
            for (int k = 0; k < M; k++) {
                if (board[n][i][k] == '#') {
                    board[n + 1][i][k] = '#';
                    pos = -1;
                    if (isgoal) {
                        isgoal = false;
                    }
                    continue;
                }
                if (board[n][i][k] == '.'){
                    board[n + 1][i][k] = '.';
                    if (pos < 0) {
                        pos = k;
                    }
                }
                if (board[n][i][k] == 'O') { // 골라인이 기울인 방향에 있으면
                    board[n + 1][i][k] = 'O';
                    isgoal = true;
                }
                if (board[n][i][k] == 'B') {
                    if (isgoal) return -1;
                    if (pos > 0) { // 파랑공
                        board[n + 1][i][k] = '.';
                        
                        board[n + 1][i][pos] = board[n][i][k];
                        pos++;
                    }
                    else {
                        board[n + 1][i][k] = 'B';
                    }
                }
                if (board[n][i][k] == 'R') {
                    if (isgoal) redin = true;
                    if (pos > 0) { // 빨강공
                        
                        board[n + 1][i][k] = '.';
                        board[n + 1][i][pos] = board[n][i][k];
                        pos++;
                    }
                    else {
                        board[n + 1][i][k] = 'R';
                    }
                }
            }
        }
    }
    if (dir == 1) { // 위
        for (int i = 0; i < M; i++) {
            pos = -1;
            for (int k = 0; k < N; k++) {
                if (board[n][k][i] == '#') {
                    board[n + 1][k][i] = '#';
                    pos = -1;
                    if (isgoal) {
                        isgoal = false;
                    }
                    continue;
                }
                if (board[n][k][i] == '.') {
                    board[n + 1][k][i] = '.';
                    if (pos < 0) {
                        pos = k;
                    }
                }
                if (board[n][k][i] == 'O') { // 골라인이 기울인 방향에 있으면
                    board[n + 1][k][i] = 'O';
                    isgoal = true;
                }
                if (board[n][k][i] == 'B') {
                    if (isgoal) return -1;
                    if (pos > 0) { // 파랑공
                        board[n + 1][k][i] = '.';
                        board[n + 1][pos][i] = board[n][k][i];
                        pos++;
                    }
                    else {
                        board[n + 1][k][i] = 'B';
                    }
                }
                if (board[n][k][i] == 'R') {
                    if (isgoal) {
                        redin = true;
                    }
                    if (pos > 0) { // 빨강공
                        board[n + 1][k][i] = '.';
                        board[n + 1][pos][i] = board[n][k][i];
                        pos++;
                    }
                    else {
                        board[n + 1][k][i] = 'R';
                    }
                }
            }
        }
    }
    if (dir == 2) { // 오
        for (int i = 0; i < N; i++) {
            pos = -1;
            for (int k = M-1; k >= 0; k--) {
                if (board[n][i][k] == '#') {
                    board[n + 1][i][k] = '#';
                    pos = -1;
                    if (isgoal) {
                        isgoal = false;
                    }
                    continue;
                }
                if (board[n][i][k] == '.') {
                    board[n + 1][i][k] = '.';
                    if (pos < 0) {
                        pos = k;
                    }
                }
                if (board[n][i][k] == 'O') { // 골라인이 기울인 방향에 있으면
                    board[n + 1][i][k] = 'O';
                    isgoal = true;
                }
                if (board[n][i][k] == 'B') {
                    if (isgoal) return -1;
                    if (pos > 0) { // 파랑공
                        board[n + 1][i][k] = '.';
                        
                        board[n + 1][i][pos] = board[n][i][k];
                        pos--;
                    }
                    else {
                        board[n + 1][i][k] = 'B';
                    }
                }
                if (board[n][i][k] == 'R') {
                    if (isgoal) redin = true;
                    if (pos > 0) { // 빨강공
                        
                        board[n + 1][i][k] = '.';
                        board[n + 1][i][pos] = board[n][i][k];
                        pos--;
                    }
                    else {
                        board[n + 1][i][k] = 'R';
                    }
                }
            
            }
        }
    }
    if (dir == 3) { // 아래
        for (int i = 0; i < M; i++) {
            pos = -1;
            for (int k = N - 1; k >= 0; k--) {
                if (board[n][k][i] == '#') {
                    board[n + 1][k][i] = '#';
                    pos = -1;
                    if (isgoal) {
                        isgoal = false;
                    }
                    continue;
                }
                if (board[n][k][i] == '.') {
                    board[n + 1][k][i] = '.';
                    if (pos < 0) {
                        pos = k;
                    }
                }
                if (board[n][k][i] == 'O') { // 골라인이 기울인 방향에 있으면
                    board[n + 1][k][i] = 'O';
                    isgoal = true;
                }
                if (board[n][k][i] == 'B'){
                    if (isgoal) return -1;
                    if (pos > 0) { // 파랑공
                        
                        board[n + 1][k][i] = '.';
                        board[n + 1][pos][i] = board[n][k][i];
                        pos--;
                    }
                    else {
                        board[n + 1][k][i] = 'B';
                    }
                }
                if (board[n][k][i] == 'R'){
                    if (isgoal) redin = true;
                    if (pos > 0) { // 빨강공
                        
                        board[n + 1][k][i] = '.';
                        board[n + 1][pos][i] = board[n][k][i];
                        pos--;
                    }
                    else {
                        board[n + 1][k][i] = 'R';
                    }
                }
            }
        }
    }

    if (redin) {
        return 1;
    }
    return 0;
}


void func(int n) {
    
    if (n == 10) {
        int tcnt = 0;
        for (int i = 0; i < 10; i++) {
            
            if (nend > 0 && nend == i) {
                //cout << "\n";
                return; // 이미 끝났으면
            }
            //cout << arr[i] << " ";
            if (arr1[i] == arr[i]) {
                tcnt++;
                continue; // 이미 저장된 값과 같으면 스킵
            }
            if (arr1[i] != arr[i]) nend = -1;
            
            // 기울이기 함수
            
            arr1[i] = arr[i];
            int res = lean(arr[i], i); // 방향 보드
            tcnt++;
            if (res > 0) {
                if (cnt == -1 || cnt > tcnt)
                    cnt = tcnt;
                nend = i;
                //cout << "성공 : " << tcnt<< "\n";
                return;
            }
            if (res < 0) {
                nend = i+1;
                //cout << "실패 \n";
                return;
            }
        }
        //cout << "\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (n > 0 && arr[n - 1] == i) continue; // 그 전과 값이 같다면 스킵
        arr[n] = i;
        func(n + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> curpos;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[0][i][j] = str[j];
        }
    }
    
    func(0);
    cout << cnt;
}