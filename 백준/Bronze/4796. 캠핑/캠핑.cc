#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, p, v;
    int cnt = 0;
    while (1) {
        cnt++;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)return 0;
        cout << "Case " << cnt << ": " << (v / p) * l + min(v % p, l) << "\n";
    }
    return 0;
}
