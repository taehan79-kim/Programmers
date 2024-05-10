#include <bits/stdc++.h>
using namespace std;

int N;
int hp[8];
int dmg[8];
int isused[8];
int cnt = 0;

void func(int n, int Tmpcnt) {
    if (n >= N) {
        //cout << "n :" << n << "Tcnt : " << Tmpcnt<< "\n";
        if (cnt < Tmpcnt) {
            //cout << "tmp :" << Tmpcnt<<"\n";
            cnt = Tmpcnt;
        }
        return;
    }
    if (hp[n] <= 0 or Tmpcnt == N - 1) {
        func(n + 1, Tmpcnt);
        return;
    }
    for (int i = 0; i < N; i++) { // 모든 달걀에 대해 
        if (n != i && hp[i] > 0) { // 체력이 남아있는
            
            hp[i] = hp[i] - dmg[n];
            hp[n] = hp[n] - dmg[i];
            if (hp[n] <= 0) Tmpcnt++;
            if (hp[i] <= 0) Tmpcnt++;
            //cout << n << "가 " << i << "에게 공격" << "\n";
            //cout << "현재 CNT: " << Tmpcnt <<  "\n";
            func(n + 1, Tmpcnt);
            if (hp[i] <= 0) Tmpcnt--;
            if (hp[n] <= 0) Tmpcnt--;
            hp[i] = hp[i] + dmg[n];
            hp[n] = hp[n] + dmg[i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> hp[i];
        cin >> dmg[i];
    }
    func(0, 0);
    cout << cnt;
}
