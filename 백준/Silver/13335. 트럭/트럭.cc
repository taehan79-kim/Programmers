#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int N,W,L;
int truckw[1005];
int truckpos[1005];
int _time = 0;
int sumw = 0;

int cur[1005];
int head=1;
int tail = 1;

bool isend = false;

int size() {
    return tail - head;
}

void pop() {
    head++;
}

int front() {
    return cur[head];
}

int back() {
    return cur[tail-1];
}

void push(int i) {
    cur[tail] = i;
    tail++;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> W >> L;
    for (int i = 1; i <= N; i++) {
        cin >> truckw[i];
    }
    sumw += truckw[1];
    _time++;
    truckpos[1]++;
    push(1);
    while (!isend) {
        _time++;

        for (int a = head; a < tail; a++) {
            truckpos[cur[a]]++;
            //cout << "cur[a] " << cur[a] << " truckpos : " << truckpos[cur[a]] << "\n";
            if (truckpos[front()] > W) {
                sumw -= truckw[front()];
                //cout << "시간 : " << _time << " 트럭나감 : " << front() << "\n";
                if (front() >= N)isend = true;

                pop();
            }
        }
        if (sumw + truckw[back() + 1] <= L && back() + 1 <= N) { // 건널 수 있음
            sumw += truckw[back() + 1];
            truckpos[back() + 1]++;
            //cout << "시간 : " << _time << " 트럭탑승 : " << back() + 1 << "\n";
            push(back() + 1);
        }
        
    }
    cout << _time;
}