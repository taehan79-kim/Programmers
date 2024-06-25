#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100005];
int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool compare1(pair<int,int> a, pair<int,int> b ) {
    if (a.second == b.second)
        return a.first < a.first;
    return a.second > b.second;
}

int changeMtoD(int m, int d) {
    int day = 0;
    for (int i = 0; i < m - 1; i++)
        day += months[i];
    return day + d;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n ;
    for (int i = 0; i < n; i++) {
        int m, d;
        cin >> m >> d;
        a[i].first = changeMtoD(m, d);
        cin >> m >> d;
        a[i].second = changeMtoD(m, d);
    }

    sort(a, a + n, compare1);
    int sum = 0;
    int sday = changeMtoD(3, 1);
    int eday = changeMtoD(11, 30);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sday >= a[i].first && sday < a[i].second) { // 꽃이 현재 펴있으면
            ans++;
            sday = a[i].second;
            if (sday > eday)
                break;
            i = -1;
        }
    }
    if (sday > eday)
        cout << ans;
    else
        cout << 0;
    
}