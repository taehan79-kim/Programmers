#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[1000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);

    int s = a[0].first;
    int e = a[0].second;
    if (n == 1) {
        cout << e - s;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i].first <= e) { // 선분 이어서 그리기
            if(e < a[i].second)
                e = a[i].second;
        }
        else { // 선분을 마무리하고 다음 이어서 그리기
            sum += e - s;
            s = a[i].first;
            e = a[i].second;
        }
    }
    
    cout << sum + e - s << "\n";
}
