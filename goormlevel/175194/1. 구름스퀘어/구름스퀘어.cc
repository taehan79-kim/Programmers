#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[200005];
int main() { // 현재 시각에 가능한 행사 중 가장 빠르게 끝나는 것을 찾는다.
	int n;
	cin >> n;
	int t = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i].second >> p[i].first;
	}
	sort(p, p + n);
	for(int i = 0; i < n; i++){
		if(t < p[i].second){ // 현재 시각이 시작 시각보다 먼저면
			t = p[i].first;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}