#include <iostream>
#include <algorithm>
using namespace std;

int BinOneCnt(int a){
	int tmp = a;
	int cnt = 0;
	while(tmp >= 2){
		if(tmp % 2 == 1)
			cnt++;
		tmp /= 2;
	}
	if(tmp == 1)
		cnt++;
	return cnt;
}
int a[500005];
pair<int, long long> p[500005];

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int cnt = BinOneCnt(a[i]);
		p[i] = {cnt, a[i]};
	}
	sort(p, p + n);
	cout << p[n - k].second;
	return 0;
}