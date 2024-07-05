#include <iostream>
using namespace std;
bool chk(string n, string k){
	int lenk = k.length();
	int lenn = n.length();
	bool iseq = false;
	for(int i = 0; i < lenn; i++){
		if(n[i] == k[0]){
			iseq = true;
			for(int j = 1; j < lenk; j++){
				if(n[i + j] != k[j]){
					iseq = false;
					break;
				}
			}
			if(iseq)
				return true;
		}
	}
	return false;
}

int main() {
	int n;
	string k;
	int cnt = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		string num;
		cin >> num;
		if(!chk(num, k))
			cnt++;
	}
	cout << cnt;
	return 0;
}