#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

long long num_Get(int idx, int cnt, string s){
	long long p = 1;
	long long num = 0;
	for(int k = 0; k < cnt; k++){ // 지금까지의 숫자 계산
		num += int(s[idx - k] - '0') * p;
		p *= 10;
	}
	return num;
}

long long calculate(string a){
	long long sumA = 0;
	long long numa[20];
	char cala[20];
	int calCntA = 0;
	int cnt = 0;
	int len = a.length();
	deque<long long> numq;
	queue<char> calq;
	
	for(int i = 0; i < len; i++){
		if(a[i] >= '0' && a[i] <= '9'){ //숫자인 경우
			cnt++;
		}
		else{ // 연산자인 경우
			long long num = num_Get(i - 1, cnt, a);
			
			cnt = 0;
			numa[calCntA] = num;
			cala[calCntA] = a[i];
			calCntA++;
		}
	}
	long long num = num_Get(len - 1, cnt, a);
	cnt = 0;
	numa[calCntA] = num;
	
	numq.push_back(numa[0]);
	bool ismulti = false;
	// 곱셈 먼저 계산
	for(int i = 0; i < calCntA; i++){
		if(cala[i] == '*'){
			long long k = 0;
			if(!ismulti){
				k = numa[i] * numa[i+1];
				ismulti = true;
			}
			else{
				long long nb = numq.back();
				k  = nb * numa[i+1];
			}
			numq.pop_back();
			numq.push_back(k);
		}
		else{
			ismulti = false;
			numq.push_back(numa[i+1]);
			calq.push(cala[i]);
		}
	}
	sumA += numq.front();
	numq.pop_front();
	while(!calq.empty()){
		char c = calq.front();
		calq.pop();
		long long n = numq.front();
		numq.pop_front();
		if(c == '+'){
			sumA += n;
		}
		else if(c == '-'){
			sumA -= n;
		}
	}
	return sumA;
}

int main() {
	string a, b;
	cin >> a >> b;
	
	long long sumA = calculate(a);
	long long sumB = calculate(b); 

	cout << max(sumA, sumB);
	
	return 0;
}